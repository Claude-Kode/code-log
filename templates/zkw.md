# SGT 类详解 — 带剪枝的最大值线段树（zkw 式迭代实现）

> 一种 **只增不减**（point update, range max）的线段树，采用 **迭代（非递归）** 写法，又称 **zkw 线段树**。
> 不支持任意赋值，`upd(i, v)` 仅当 `v > 原值` 时生效。

---

## 目录

- [1. 数据结构概览](#1-数据结构概览)
- [2. 符号表](#2-符号表)
- [3. 核心公式与推导](#3-核心公式与推导)
  - [3.1 构造：`bit_ceil` 确定底层大小](#31-构造bit_ceil-确定底层大小)
  - [3.2 向上合并（pull）](#32-向上合并pull)
  - [3.3 单点更新（带剪枝）](#33-单点更新带剪枝)
  - [3.4 区间查询](#34-区间查询)
- [4. 代码逐段解读](#4-代码逐段解读)
- [5. 适用场景与限制](#5-适用场景与限制)
- [6. 完整代码](#6-完整代码)
- [7. 复杂度分析](#7-复杂度分析)

---

## 1. 数据结构概览

这是一个 **只增不减** 的线段树：

| 特性 | 说明 |
|------|------|
| 更新方式 | 单点「取 max 赋值」 |
| 查询方式 | 区间 max 查询 |
| 写法 | 迭代（非递归），zkw 风格 |
| 核心优化 | 剪枝 —— 新值不严格大于旧值时跳过整条更新链 |

---

## 2. 符号表

| 符号 | 类型 | 含义 |
|------|------|------|
| `n` | 输入参数 | 用户请求的区间长度（1-indexed, `[1, n]`） |
| `off` | 中间变量 | 2 的幂，满足 `off ≥ n + 2`，是底层数组偏移量（叶子层起始下标） |
| `seg` | 数据结构 | `std::vector<int>`，大小为 `2 × off`，下标 `1 .. 2×off−1` 构成完全二叉树 |
| `i` | 输入参数 | 待修改/查询的区间端点，1-indexed |
| `l`, `r` | 输入参数 | 查询的左右端点（闭区间），`1 ≤ l ≤ r ≤ n` |
| `v` | 输入参数 | 将要设置的新值 |
| `pull(i)` | 函数 | 合并操作：`seg[i] = max(seg[2i], seg[2i+1])` |

---

## 3. 核心公式与推导

### 3.1 构造：`bit_ceil` 确定底层大小

`bit_ceil(x)` 返回不小于 `x` 的最小 2 的幂。

$$
\text{off} = \lceil n+2 \rceil_{\text{po2}}
$$

> **为什么 +2？**
>
> 区间查询内部会用 `l += off - 1`，`r += off + 1`，即左右各额外扩一位（变成半开半闭区间 `(l-1, r+1)`）。这要求即使 `l=1` 或 `r=n`，对应的下标也在 `seg` 容量范围内。`+2` 是安全边界。

**叶子节点映射**：原数组第 `i` 个元素 → `seg[off + i]`

### 3.2 向上合并（pull）

$$
\text{seg}[i] = \max(\text{seg}[2i],\; \text{seg}[2i+1])
$$

这就是线段树的 **push-up**，自底向上维护区间最大值。

### 3.3 单点更新（带剪枝）

**剪枝条件**：若 `v ≤ seg[off + i]`，直接 `return`。因为该节点及其所有祖先的值都不可能因这次更新而变大。

否则执行：

$$
\begin{aligned}
&\text{seg}[\text{off}+i] \leftarrow v \\
&\text{while } i \leftarrow \lfloor i/2 \rfloor:\; \text{pull}(i)
\end{aligned}
$$

> 🔑 **这是「只增不减」的核心优化**：当新值不严格大于旧值时，跳过 `O(log n)` 的冒泡操作。在 LIS（最长上升子序列）等应用场景中，此剪枝能大幅减少常数。

### 3.4 区间查询

将闭区间 `[l, r]` 转为半开半闭的左右指针：

$$
L = \text{off} + l - 1,\quad R = \text{off} + r + 1
$$

**循环终止条件**：

$$
L \oplus R \oplus 1 = 0 \quad\Longleftrightarrow\quad L \text{ 与 } R \text{ 是兄弟（仅最末位不同）}
$$

等价于经典的 `while (L ^ R ^ 1)` 写法。

**收集规则**：

| 条件 | 含义 | 操作 |
|------|------|------|
| `L` 是偶数（`~L & 1`） | 左指针指向右儿子 | 收集 `seg[L ⊕ 1]`，L 右移 |
| `R` 是奇数（`R & 1`） | 右指针指向左儿子 | 收集 `seg[R ⊕ 1]`，R 左移 |
| 每轮结束 | 上跳到父节点 | `L >>= 1`，`R >>= 1` |

最终 `res = max(所有收集到的节点值)`。

---

## 4. 代码逐段解读

### 4.1 类定义与成员变量

```cpp
class SGT {
  std::vector<int> seg;   // 存储完全二叉树的数组，下标 1-based
  int off = 0;            // 叶子层的起始下标，总是 2 的幂

  void pull(int i) { seg[i] = std::max(seg[i << 1], seg[i << 1 | 1]); }
```

- `seg`：存储完全二叉树的数组，下标 1-based
- `off`：叶子层的起始下标，总是 2 的幂
- `pull`：合并左右儿子，写入父节点

### 4.2 构造函数

```cpp
  SGT(int n) {
    off = std::bit_ceil(unsigned(n + 2));
    seg.assign(off << 1, 0);
  }
```

- `bit_ceil(n+2)`：算出 ≥ n+2 的最小 2 的幂，例如 `n=10 → off=16`
- `seg.assign(off << 1, 0)`：分配 `2×off` 个元素，全部初始化为 0

### 4.3 单点更新（带剪枝）

```cpp
  void upd(int i, int v) {
    if (v <= seg[i += off]) return;  // 剪枝
    seg[i] = v;
    while (i >>= 1) pull(i);
  }
```

- `i += off`：定位到叶子下标
- `v <= seg[i]`：**剪枝** — 新值不大于旧值则跳过
- `while (i >>= 1)`：不断上跳到父节点，调用 `pull` 更新

### 4.4 区间查询

```cpp
int ask(int l, int r) {
  if (l > r) return 0;             // 空区间返回 0(单位元)
  int res = 0;
  for (l += off - 1, r += off + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) res = std::max(res, seg[l ^ 1]);
    if (r & 1)  res = std::max(res, seg[r ^ 1]);
  }
  return res;
}
```

- `l > r`：防御性处理空区间
- `l += off - 1`, `r += off + 1`：转为半开半闭，与 `+2` 预留空间对应
- `l ^ r ^ 1`：当 L 和 R 互为兄弟时终止
- `~l & 1` 即 `l % 2 == 0`：L 是右儿子，收集其兄弟（左儿子）
- `r & 1` 即 `r % 2 == 1`：R 是左儿子，收集其兄弟（右儿子）

---

## 5. 适用场景与限制

| 特性 | 说明 |
|------|------|
| ✅ 支持操作 | 单点「取 max 赋值」、区间 max 查询 |
| ❌ 不支持 | 单点任意赋值、区间加法、区间修改 |
| ✂️ 剪枝 | 仅当新值严格大于旧值时才向上冒泡 |
| ⏱️ 时间复杂度 | 构造 `O(n)`，单次 `upd / ask` 均摊 `O(log n)` |
| 🎯 典型应用 | LIS（最长上升子序列）、值域 DP 中的前缀最大值查询 |

---

## 6. 完整代码

```cpp
class SGT {
  std::vector<int> seg;
  int off = 0;

  void pull(int i) {
    seg[i] = std::max(seg[i << 1], seg[i << 1 | 1]);
  }

 public:
  SGT(int n) {
    off = std::bit_ceil(unsigned(n + 2));
    seg.assign(off << 1, 0);
  }

  // 单点更新：将位置 i 的值设为 max(原值, v)
  void upd(int i, int v) {
    if (v <= seg[i += off]) return;   // 剪枝：新值不更大则跳过
    seg[i] = v;
    while (i >>= 1) pull(i);          // 自底向上更新祖先
  }

  // 区间查询：返回 [l, r] 的最大值
  int ask(int l, int r) {
    if (l > r) return 0;
    int res = 0;
    // p ^= 1 会变成兄弟节点, p1 ^= 1 == p2 的话 也就是 p1 ^ 1 == p2, 就是 p1 ^ p2 == 1 的话 代表这个是兄弟
    for (l += off - 1, r += off + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) res = std::max(res, seg[l ^ 1]);
      if (r & 1)  res = std::max(res, seg[r ^ 1]);
    }
    return res;
  }
};
```

---

## 7. 复杂度分析

| 操作 | 时间复杂度 | 空间复杂度 |
|------|-----------|-----------|
| 构造 `SGT(n)` | `O(n)` | `O(n)` |
| 单点更新 `upd(i, v)` | `O(log n)`，剪枝后均摊更优 | — |
| 区间查询 `ask(l, r)` | `O(log n)` | — |

---

> 💡 **这段代码最巧妙的两点**：
> ① `bit_ceil(n+2)` 预留足够空间避免越界；
> ② `upd` 中的剪枝让很多更新变成 `O(1)`，在递增性保证的场景（如 DP 转移）中大幅优化常数。

<media_info>[{"type": "file", "description": "SGT 带剪枝最大值线段树（zkw 迭代实现）详解文档", "path": "/data/workspace/SGT线段树详解.md"}]</media_info>