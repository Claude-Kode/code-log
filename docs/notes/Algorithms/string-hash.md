# Modern C++ 自定义哈希函数 & 字符串哈希（ACM 竞赛向）

## 1. `std::hash` 基础

- `std::hash` 是一个**类模板**，不是函数模板
- 通过特化（explicit specialization）支持不同类型：`std::hash<int>`, `std::hash<std::string>` 等
- 内部重载了 `operator()`，使其成为**函数对象**（functor）
- 用法：
  ```cpp
  std::hash<int> hasher;
  size_t h = hasher(42);                // 调用 operator()(int)

  // 匿名对象 + 立即调用 (modern C++ 推荐 {})
  size_t h2 = std::hash<int>{}(42);
  // 等价于 std::hash<int>()(42)，但 {} 更安全、更现代
  ```

`unordered_map` / `unordered_set` 在内部会自动调用 `std::hash<Key>` 的 `operator()` 将键转换为 `size_t`，然后定位桶。

---

## 2. 自定义结构体哈希

### 2.1 核心思想

1. 对每个成员调用 `std::hash<T>` 得到 `size_t`
2. 将所有 `size_t` 组合成一个最终哈希值
3. 组合必须满足：
  - **顺序敏感**：`(x=1,y=2)` 与 `(x=2,y=1)` 得到不同哈希
  - **雪崩效应**：微小输入差异导致输出约一半比特翻转，减少碰撞并使分布均匀

### 2.2 `hash_combine` 经典实现

```cpp
inline void hash_combine(size_t& seed, size_t val) noexcept {
  seed ^= val + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
```

**各成分作用：**

- **`seed`**：累积的中间值，从 0 开始，依次混入各成员哈希，最终成为对象的哈希值
- **`seed << 6` + `seed >> 2`**：模拟比特旋转，打破对称，将高低位信息扩散
- **魔数 `0x9e3779b9`**：黄金比例倒数 `φ⁻¹` 的 32 位定点表示，无理数，打破周期性，增强随机性
- **加法 (`+`)**：利用进位链实现非线性扩散（低位变化传到高位）
- **异或 (`^`)**：最终融合，保留扰动，保证成员顺序敏感

### 2.3 自定义哈希的两种写法

两种方式都必须搭配 `operator==`，因为 `unordered_map` 在桶内使用相等比较定位具体键。

**方式一：特化 `std::hash`（侵入式，最省心）**

```cpp
struct Point {
  int x, y;
  bool operator==(const Point& o) const {
    return x == o.x && y == o.y;
  }
};

namespace std {
  template<>
  struct hash<Point> {
    size_t operator()(const Point& p) const noexcept {
      size_t seed = 0;
      auto hash_combine = [&seed](size_t val) {
        seed ^= val + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      };
      hash_combine(hash<int>{}(p.x));
      hash_combine(hash<int>{}(p.y));
      return seed;
    }
  };
}

// 使用：自动找到 std::hash<Point>
std::unordered_map<Point, int> pointMap;
```

**方式二：自定义函数对象（非侵入式）**

```cpp
struct PointHash {
  size_t operator()(const Point& p) const noexcept {
    size_t seed = 0;
    auto hash_combine = [&seed](size_t val) {
      seed ^= val + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    };
    hash_combine(std::hash<int>{}(p.x));
    hash_combine(std::hash<int>{}(p.y));
    return seed;
  }
};

// 使用：显式传入哈希模板参数
std::unordered_map<Point, int, PointHash> pointMap;
```

> 如果 `Point` 已有 `operator==`，则不需要传第四个相等比较模板参数（默认使用 `std::equal_to<Point>`，内部调用 `operator==`）。
> 如果需要自定义相等逻辑，可另外编写函数对象并作为第四个参数传入。

---

## 3. 字符串哈希

### 3.1 作用与优势

- **O(1)** 判断两个（子）字符串是否相等（朴素比较是 O(L)）
- 适用于大量子串判重、回文判定、最长公共子串等问题
- 核心思想：将字符串看作 `base` 进制的大整数，对模数取模作为指纹

### 3.2 前缀哈希与子串计算

设字符串 `s[0..n-1]`，选择底数 `base`（如 131 或 13331）和模数 `MOD`。

**预处理：**

```cpp
vector<unsigned long long> h(n + 1), p(n + 1);
h[0] = 0;
p[0] = 1;
for (int i = 0; i < n; ++i) {
  h[i + 1] = (h[i] * base + s[i]) % MOD;
  p[i + 1] = (p[i] * base) % MOD;
}
```

**获取子串 `[l, r)` 的哈希值：**

```cpp
auto sub_hash = (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD;
```

**公式解释：**  
类比十进制：从 `123456` 中取子串 `345`（位置 `[2,5)`）：
- 前缀到 5：`12345`
- 前 2 位左移 `10^(5-2)=1000`：`12 * 1000 = 12000`
- 相减：`12345 - 12000 = 345`

字符串哈希同理，`p[r-l]` 即 `base^(r-l)`，将 `h[l]` 提升到与 `h[r]` 对齐的高位，相减得到子串的“数值指纹”。

### 3.3 双哈希防冲突

单哈希可能被精心构造的数据卡成碰撞。使用两个不同的大质数模数（如 `1e9+7` 和 `1e9+9`），只有两个哈希值均相等才判定字符串相等，碰撞概率近乎为零。

**标准双哈希模板：**

```cpp
#include <vector>
#include <string>
#include <utility>

using ull = unsigned long long;
const ull base = 131;
const ull MOD1 = 1000000007;
const ull MOD2 = 1000000009;

struct StrHash {
  std::vector<ull> h1, h2, p1, p2;

  StrHash(const std::string& s) {
    int n = s.size();
    h1.resize(n + 1); h2.resize(n + 1);
    p1.resize(n + 1); p2.resize(n + 1);
    p1[0] = p2[0] = 1;
    for (int i = 0; i < n; ++i) {
      h1[i + 1] = (h1[i] * base + s[i]) % MOD1;
      h2[i + 1] = (h2[i] * base + s[i]) % MOD2;
      p1[i + 1] = (p1[i] * base) % MOD1;
      p2[i + 1] = (p2[i] * base) % MOD2;
    }
  }

  // 返回 [l, r) 的双哈希对
  std::pair<ull, ull> get(int l, int r) const {
    ull v1 = (h1[r] - h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1;
    ull v2 = (h2[r] - h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;
    return {v1, v2};
  }
};

// 使用示例
// std::string s = "abcabc";
// StrHash sh(s);
// auto v1 = sh.get(0, 3); // "abc"
// auto v2 = sh.get(3, 6); // "abc"
// assert(v1 == v2);
```

---

## 4. 总结

- **通用结构体哈希**：实现 `operator()`，内部用 `hash_combine` 搅拌各成员的 `std::hash` 值
- **字符串哈希**：`base` 进制 + 前缀和，O(1) 子串比较；双哈希确保安全
- **所有用作 `unordered_map` 键的自定义类型**：必须有 `operator==`，且哈希与相等逻辑一致




<!-- cpp 的 std;::hash 是一个模板类
可以通过 hash<int> 实例化, 
hash<int> hasher 创建对象之后, 可以通过类似函数调用的方式, hasher((int)(1114514))
因为 hash 里面重载了 operator() 
顺带一提, std::hash<int>{}(key) 中的 {} 是一个匿名对象,  也可以写成 std::hash<int>()(key)
但是 modern cpp 的普遍规范是用 {}

自定义哈希函数可以先把每个单位转换成哈希函数, 之后再进行哈希函数之间的组合
```cpp
struct point {
  int x;
  int y;
};

std::hash<int> hasher
size_t h1 = hasher(x);
size_t h2 = hasher(y);
```
组合的哈希需要满足这样的规则: 
- 顺序敏感(x=1, y=2 和 x=2, y=1 产生不同的哈希, 引入不对称的运算)
- 把小改变扩散到结果的高位和低位 (雪崩效应 - 让小变化变大)
补充: 
关于雪崩: 
如果你把输入的每一个二进制位（0或1）都翻转了一下，那么输出的哈希值里，每一个二进制位都有大约 50% 的概率发生翻转。
目的：这个特性非常重要。它能防止别人通过一点点修改输入来伪造出和原数据一样的哈希值（防碰撞），同时也能让哈希值在整个取值范围内分布得非常均匀，避免大量数据扎堆在同一个位

所以常用的就是异或 + 位移 + 加法干扰(引入不对称的运算)
```cpp
inline void hash_combine(size_t& seed, size_t val) noexcept {
  // 假设我们要组合 x 和 y
  seed ^= hash_value(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
```


**一句话总结**：  
把结构体变成哈希键，核心就是实现一个 `operator()`，内部用 `hash_combine` 将各成员的 `std::hash` 值搅拌成一个 `size_t`。

---

### 1. 自定义哈希的两种写法
- **特化 `std::hash`**：在 `namespace std` 里为你的类型全特化 `hash`，重载 `operator()`，容器自动识别。
- **自定义函数对象**：写一个带 `operator()` 的普通结构体，作为模板参数传给 `unordered_map`/`set`。  
两种方式都要搭配 `operator==`。

### 2. `hash_combine` 的精简原理
```cpp
seed ^= val + 0x9e3779b9 + (seed << 6) + (seed >> 2);
```
- **`seed`**：累积的中间值，从0开始，依次混入各成员的哈希，最后就是整个对象的哈希。
- **位移 (`<< 6`, `>> 2`)**：把旧种子的比特“旋转”扩散，让高低位信息交换。
- **魔数 `0x9e3779b9`**：黄金比例倒数，无理数，打破任何周期模式，让微小变化产生巨大差异。
- **加法**：利用进位链，将低位变化非线性地传到高位。
- **异或 (`^`)**：最终融合，既保留所有扰动信息，又保证**成员顺序敏感**（先 x 后 y 与先 y 后 x 结果不同）。

### 3. 竞赛标准用法
无论 `pair`、三元组还是自定义结构体，只需：
```cpp
size_t seed = 0;
hash_combine(seed, std::hash<T1>{}(obj.m1));
hash_combine(seed, std::hash<T2>{}(obj.m2));
// ... 其他成员
return seed;
```
就能安全地作为 `unordered_map` / `unordered_set` 的键，碰撞率极低，不会被构造特殊数据卡成 O(n)。

使用方面: 
1. 由于 unordered_map 会默认调用 std::hash<T>, 你需要在 std 实现一个 std::hash 即可
比如
```cpp
namespace std{
  template<>
  struct hash<Point> {
    size_t operator() (const Point& t) const noexcept {
      size_t seed = 0;
      auto hash_combine = [&](const size_t& val) -> size_t {
        return seed ^= val + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      };

      hash_combine(std::hash<int>{}(p.x));
      hash_combine(std::hash<int>{}(p.y));
      return seed;
    }
  };
};
```
或者自定义模板参数
```cpp
struct PointHash {
  size_t operator()(const Point& p) const noexcept {
    size_t seed = 0;
    auto hash_combine = [](size_t& s, size_t v) {
      s ^= v + 0x9e3779b9 + (s << 6) + (s >> 2);
    };
    hash_combine(seed, std::hash<int>{}(p.x));
    hash_combine(seed, std::hash<int>{}(p.y));
    return seed;
  }
};

unordered_map<Point, int, PointHas> ump;  
```

最后都别忘了重载操作符 == 
```cpp
struct Point {
  int x, y;
  bool operator==(const Point& o) const {
    return x == o.x && y == o.y;
  }
};
```

## 字符串哈希: 
我们希望能 O(1) 比对两个字符串是否相等, 能够很容易联想到, 
通过类似哈希函数的映射能够实现低碰撞和高准确度以及 O(1) 比较

字符串哈希就很简单, 把一个字符串换成一个 base 进制的数(确保每个字符都有一个独立的数字即可)
这个过程可以 % mod 或者自然溢出(就是爆 LL\INT 了)
比如`hash = (97 * 131^2 + 98 * 131^1 + 99 * 131^0) % MOD`
一般来说直接通过前缀幂来算即可
```cpp

vector<int> p(n + 1);
int num = base;
for (int i = 1; i <= n; i ++) {
  p[i] = base;
  num = num * base % mod;
}

h[0] = 0;
for (int i = 0; i < n; i ++) {
  h[i + 1] = (h[i] * base + s[i]) % MOD;
}
```
然后就有 `sub_string` 的 `hash_value` = `(h[r] - h[l] * p[r-l] % MOD + MOD) % MOD;`
这个公式就是从“大数字”里截取一小段数字的数学操作，和十进制取子串一个道理。

假设有个数字 `s = 123456`，我们想取子串 `"345"`（位置从 `l=2` 到 `r=5`，长度 `len=3`）。

- 整个前缀（到第5位）的值是 `12345`
- 前2位是 `12`
- 怎么得到 `345`？  
  把 `12345` 减去 `12 * 1000`，即 `12345 - 12000 = 345`。  
  这个 `1000` 就是 `10^3`，也就是 `10^{len}`。

所以公式：`子串 = 前缀[r] - 前缀[l] * 10^{len}`。



```cpp
using ull = unsigned long long;
const ull base = 131;
const ull MOD1 = 1e9 + 7;
const ull MOD2 = 1e9 + 9;

struct StrHash {
  vector<ull> h1, h2, p1, p2;
  StrHash(const string& s) {
    int n = s.size();
    h1.resize(n + 1); h2.resize(n + 1);
    p1.resize(n + 1); p2.resize(n + 1);
    p1[0] = p2[0] = 1;
    for (int i = 0; i < n; i ++) {
      h1[i + 1] = (h1[i] * base + s[i]) % MOD1;
      h2[i + 1] = (h2[i] * base + s[i]) % MOD2;
      p1[i + 1] = (p1[i] * base) % MOD1;
      p2[i + 1] = (p2[i] * base) % MOD2;
    }
  }
  // 返回区间 [l, r) 的双哈希对
  pair<ull, ull> get(int l, int r) {
    ull v1 = (h1[r] - h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1;
    ull v2 = (h2[r] - h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;
    return {v1, v2};
  }
};

// 使用
string s = "abcabc";
StrHash sh(s);
auto v1 = sh.get(0, 3); // "abc"
auto v2 = sh.get(3, 6); // "abc"
assert(v1 == v2);       // 哈希相等，子串相等
``` 
-->
