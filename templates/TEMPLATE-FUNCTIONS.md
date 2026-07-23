# Tools 

> **C++ 水平评估、知识点百科、学习路线** → 见 [`notes/CPP-LEVEL-AND-ROADMAP.md`](../notes/CPP-LEVEL-AND-ROADMAP.md)

## 文件 io
```cpp
注意 文件要在同一目录下
freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);
freopen("err.txt", "w", stderr);
```
## 编译指令
```cpp
g++ -std=c++14 -O2 -Wall -Wextra -Wshadow -o program main.cpp
```
```bash
#!/bin/bash
g++ -std=c++14 -O2 -Wall -Wextra -Wshadow -o program $1.cpp
```
调用时只需要
```powershell
./compile.sh main
```

## 手动扩栈
```cpp
#pragma comment(linker, "/STACK:268435456")
```

## Debug Tools head file

记得配置 include path 这个要放文件夹路径 然后实际上使用的时候
可以到 c_cpp_properties.json 里面配置 include path 还有在这个 json 里面配置宏
要不怕你交上去的时候没有那个宏就报错了

```cpp
#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

/* ================= 输出容器 ================= */

template<typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it)
    os << *it << (next(it) == v.end() ? "]" : ", ");
  return os;
}

template<typename T>
inline ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  for (auto it = s.begin(); it != s.end(); ++it)
    os << *it << (next(it) == s.end() ? "}" : ", ");
  return os;
}

template<typename K, typename V>
inline ostream& operator<<(ostream& os, const map<K,V>& m) {
  os << "{";
  for (auto it = m.begin(); it != m.end(); ++it)
    os << "{" << it -> first << ":" << it -> second << "}"
       << (next(it) == m.end() ? "}" : ", ");
  return os;
}

template<typename A, typename B>
inline ostream& operator<<(ostream& os, const pair<A,B>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

/* ================= dbug（用 cout） ================= */

template<typename T>
inline void _dbug(const char* name, const T& x) {
  cout << "[DBG] " << name << ": " << x << '\n';
}

inline void _dbug(const char* name, const string& x) {
  cout << "[DBG] " << name << ": \"" << x << "\"\n";
}

/* ================= 开关 ================= */

#ifdef LOCAL
#define dbug(x) _dbug(#x, x)
#else
#define dbug(x) ((void)0)
#endif

#endif // DEBUG_H
```
或者完全形态 : 
```cpp
#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

/* ================= 基础容器 ================= */

// vector
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i + 1 != v.size()) os << ", ";
  }
  return os << "]";
}

// vector<vector> —— 空时输出 []，非空时每个内层换行
template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
  if (v.empty()) {
    return os << "[]";
  }
  os << "[\n";
  for (size_t i = 0; i < v.size(); ++i) {
    os << "  " << v[i];
    if (i + 1 != v.size()) os << ",";
    os << "\n";
  }
  return os << "]";
}

// array
template<typename T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a) {
  os << "[";
  for (size_t i = 0; i < N; ++i) {
    os << a[i];
    if (i + 1 != N) os << ", ";
  }
  return os << "]";
}

// set
template<typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  for (auto it = s.begin(); it != s.end(); ++it) {
    os << *it;
    if (next(it) != s.end()) os << ", ";
  }
  return os << "}";
}

// map
template<typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
  os << "{";
  for (auto it = m.begin(); it != m.end(); ++it) {
    os << "{" << it->first << ":" << it->second << "}";
    if (next(it) != m.end()) os << ", ";
  }
  return os << "}";
}

// pair
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

/* ================= tuple ================= */
template<typename... Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
  os << "(";
  apply([&](const auto&... xs) {
    size_t i = 0;
    ((os << xs << (++i != sizeof...(Ts) ? ", " : "")), ...);
  }, t);
  return os << ")";
}

/* ================= 结构体宏 ================= */

#define DBG_STRUCT(StructType, ...) \
ostream& operator<<(ostream& os, const StructType& s) { \
  os << #StructType << "{"; \
  __VA_ARGS__ \
  os << "}"; \
  return os; \
}

#define DBG_MEMBER(m) os << #m << ":" << s.m << ", "

/* ================= dbug ================= */

template<typename T>
void _dbug(const char* name, const T& x) {
  cout << "[DBG] " << name << " = " << x << '\n';
}

inline void _dbug(const char* name, const string& x) {
  cout << "[DBG] " << name << " = \"" << x << "\"\n";
}

#ifdef LOCAL
#define dbug(x) _dbug(#x, x)
#else
#define dbug(x) ((void)0)
#endif

#endif // DEBUG_H
```

## 指令集 
```cpp
#ifdef __GNUC__
  // #pragma GCC optimize("fast-math") 
  #pragma GCC optimize("Ofast, unroll-loops")
  #pragma GCCtarget("avx2")
#endif
```
## bit-cal
```cpp

__builtin_popcount(x)  // 1的个数
__builtin_parity(x)    // 1的个数奇偶性
__builtin_ctz(x)       // 末尾0的个数
__builtin_clz(x)       // 开头0的个数
__builtin_ffs(x)       // 第1个1的位置(从1数)

x & -x            // 保留最低位1
x & (x - 1)       // 清除最低位1
x | (x + 1)       // 设置最低位0
~(x | -x)         // 保留最低位0
x & (x + (x & -x))  // 下一个有相同1个数的数
x &= x - 2        // 去掉 lowbit

0b10 // 二进制字面量

```
## 自定义哈希
```cpp
struct Point {
  int x;
  int y;
};

struct PointHash {
  std::size_t operator()(const Point& p) const noexcept {
    return 
    std::hash<int>{}(p.x) ^
    (std::hash<int>{}(p.y) << 1);
  }
};

bool operator==(const Point& a, const Point& b) const {
  return a.x == b.x && a.y == b.y;
}

template <typename T>
void hash_combine(std::size_t& seed, const T& v) {
  seed ^= 
  std::hash<T>{}(v) 
  + 0x9e3779b97f4a7c15
  + (seed << 6)
  + (seed >> 2);
}

template <typename... Ts>
size_t combined_hash(const Ts&... args) {
  size_t seed = 0;
  (hash_combine(seed, std::hash<Ts>{}(args)), ...);
  return seed;
}

```
## __int128 and usigned __int128 的输入输出重载
```cpp
using i128 = __int128;
std::ostream& operator<<(std::ostream& os, i128 x) {
  if (!x) return os << '0';
  if (x < 0) os << '-';
  u128 y = x < 0 ? (u128)0 - (u128)x : (u128)x;
  char s[40];
  int i = 0;
  while (y) s[i++] = '0' + y % 10, y /= 10;
  while (i) os << s[--i];
  return os;
}

std::istream& operator>>(std::istream& is, i128& x) {
  x = 0;
  int f = 1;
  is >> std::ws;
  if (is.peek() == '-') is.get(), f = -1;
  for (char c; (c = is.peek()) >= '0' && c <= '9'; is.get())
    x = x * 10 + (c - '0');
  x *= f;
  return is;
}

using u128 = unsigned __int128;
std::ostream& operator<<(std::ostream& os, u128 x) {
  if (!x) return os << '0';
  char s[40];
  int i = 0;
  while (x) s[i++] = '0' + x % 10, x /= 10;
  while (i) os << s[--i];
  return os;
}
std::istream& operator>>(std::istream& is, u128& x) {
  x = 0;
  is >> std::ws;
  if (is.peek() == '+') is.get();
  for (char c; (c = is.peek()) >= '0' && c <= '9'; is.get())
    x = x * 10 + (c - '0');
  return is;
}
```## 字符串哈希
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

# 对拍

## 高级种子
```cpp
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rn(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}
```
## 随机化题目常用手法
``` cpp
//最好在循环里面创建 可以保证每次生成的 种子都不一样

mt19937 rng(time(0));
int n = rng() % (lim);
```
## generator
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

mt19937 rng(time(0));

int rn(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

void p(int l, int r, vector<int>& vec) {
	iota(vec.begin() + 1, vec.end(), 1LL);
	shuffle(vec.begin() + 1, vec.end(), rng);
} 

void solve(){
	int n = rn(1, 10); cout << n << endl;
	for(int i = 1; i <= n; i ++) {
		cout << rn(1, 100) << " \n"[i == n];
	}

	vector<int> temp(n + 1);
	p(1, n, temp);
	for(int i = 1; i <= n; i ++) cout << temp[i] << " \n"[i == n];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();

	return 0;
}
```

## 对拍程序
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "duipai START !!! \n";
	
	for (int T = 1; T <= 10; T++) {
		system("generator.exe > in.txt");
		

		double mb = clock();
		system("..\\solve.exe < in.txt > my.out");
		double me = clock();
		double tim = double(me - mb) / CLOCKS_PER_SEC;
		
		system("brute.exe < in.txt > std.out");
		
		if (tim > 2.0) {
			ifstream in("in.txt"), my("my.out"), std("std.out");
			cout << "TLE on testcase " << T << " || " << " time: " << tim << "s\n"; 
			cout << "TEST INFOR : \n" << string(istreambuf_iterator<char>(in), {}) << endl;
			cout << "MY OUTPUT:\n" << string(istreambuf_iterator<char>(my), {}) << endl;
			cout << "STD OUTPUT:\n" << string(istreambuf_iterator<char>(std), {}) << endl;
			cout << endl << endl; 
			continue; 
		} else if (system("fc my.out std.out > nul")) {
			ifstream in("in.txt"), my("my.out"), std("std.out");
			cout << "WA on testcase: " << T << " || " << " time: " << tim << "s\n"; 
			cout << "TEST INFOR : \n" << string(istreambuf_iterator<char>(in), {}) << endl;
			cout << "MY OUTPUT:\n" << string(istreambuf_iterator<char>(my), {}) << endl;
			cout << "STD OUTPUT:\n" << string(istreambuf_iterator<char>(std), {}) << endl;
			cout << endl << endl; 
			continue; 
		}
		
		cout << "AC on testcase " << T << endl;
	}
	cout << "Done\n";
	int n; cin >> n;
	return 0;
}

wrong answer 和 tle 那里可以直接 break 然后去看 out 文件即可
文件目录 : 
duipai/
├── brute.cpp       # 暴力对拍程序
├── duipai.cpp      # 当前正在运行的对拍脚本
├── generator.cpp   # 数据生成器
├── in.txt          # 生成的测试输入数据
├── my.out          # 你的程序输出
├── std.out         # 标准/暴力程序输出
├── file/           # 文件夹
│   ├── input.txt
│   └── output.txt
└── solve.cpp       # 你的解题程序
```

# 公式

## 等比数列求和公式
$$ a_{0} \frac{1 - q^{n} }{1 - q} $$

## 完全 k 叉树公式
$$ child(i, j)=k(i − 1) + j + 1 $$
```cpp
int get_child(int i, int j, int k) {
  return k * (i - 1) + j + 1;
}
```
$$parent(i) = \left \lfloor \frac{i + k - 2}{k}\right \rfloor $$
```cpp
int get_fa(int i, int k) {
  return (i + k - 2) / k;
}
```
$$ dep(i) = \left \lceil \log_{k}{ i * (k - 1) + 1 }  \right \rceil   $$

$$ k = 2, dep(i) = log_{2}{i}  $$ 
```cpp
int get_dep(int i, int k) {
  return ceil(log(i * (k - 1) + 1) / log(k));
}
```

$$ dep = d, \frac{k^{d - 1} - 1}{k - 1} + 1  \le i \le \frac{k^{d} - 1}{k - 1} $$ 
```cpp
int get_num(int n, int i, int k) {
  int dep_i = get_dep(i, k), dep_n = get_dep(n, k);
  if (dep_i < dep_n) {
    return fp(k, dep_i - 1, mod);
  } else {
    if (dep_n == 1) return n % mod;  // 只有一层
    int pre = get_sum(k, dep_n - 1, mod);    
    return (n - pre + mod) % mod;
  }
}

```
# 数学函数

## 常用函数大全
```cpp
一、<cmath> — 浮点运算核心 基础运算 
double abs(double x);             // 绝对值（对整数用 std::abs 在 <cstdlib>）
double fabs(double x);            // 同上，C 风格
double fmod(double x, double y);  // 浮点取余（符号同 x）
double remainder(double x, double y);        // IEEE 余数，向最近偶数舍入
double fma(double x, double y, double z);    // x*y+z，只舍入一次，精确
double hypot(double x, double y);            // sqrt(x^2 + y^2)，防溢出
double hypot(double x, double y, double z);  // 三维（C++17）
double copysign(double x, double y);         // 取 y 的符号，x 的量值
double nextafter(double from, double to);    // from 往 to 方向的下一个可表示值
double fdim(double x, double y);             // max(x - y, 0.0)
double fmin / fmax;  // 浮点版 min/max，但对 NaN 行为不同
double clamp(double x, double lo, double hi);  // C++17
舍入 / 取整 double floor(double x);            // 向下取整
double ceil(double x);                         // 向上取整
double trunc(double x);                        // 向零取整（截断小数）
double round(double x);                        // 四舍五入（0.5 时远离零）
double nearbyint(double x);   // 四舍五入到最近整数，受当前舍入模式影响
double rint(double x);        // 同上，但可能抛 FE_INEXACT
long long llround(double x);  // round 后转 long long
long long llrint(double x);   // rint 后转 long long

竞赛中最常用的三个：floor, ceil,
round。 三角函数 double sin / cos / tan(double x);
double asin / acos / atan(double x);
double atan2(double y, double x);  // 极角 atan2(y, x)，返回 (-π, π]，处理象限
double sinh / cosh / tanh;         // 双曲函数
atan2 是计算几何的基石：求向量(x, y)
的极角，自动处理 x = 0 和象限问题。 指数 / 对数 /
                     幂 double pow(double base, double exp);  // base^exp
double sqrt(double x);                                        // √x
double cbrt(double x);                                        // ³√x（C++11）
double exp(double x);                                         // e^x
double exp2(double x);                                        // 2^x
double expm1(double x);  // e^x - 1，x 很小时更精确
double log(double x);    // ln(x)
double log2(double x);   // log₂(x)
double log10(double x);  // log₁₀(x)
double log1p(double x);  // ln(1 + x)，x 很小时更精确
误差函数（概率 /
    几何积分相关） double erf(double x);  // 误差函数 2/√π ∫₀ˣ e^(-t²) dt
double erfc(double x);                    // 1 - erf(x)
double tgamma(double x);                  // Γ 函数 = (x-1)!
double lgamma(double x);                  // ln|Γ(x)|

二、<complex> — 复数是二维向量 using C = complex<double>;

C a(1, 2), b(3, 4);

C c = a + b;  // 加法
C c = a - b;  // 减法
C c = a * b;  // 复数乘法 = 旋转+缩放
C c = a / b;  // 复数除法

double r = abs(a);        // 模长 |a| = sqrt(x²+y²)
double phase = arg(a);    // 辐角 = atan2(y, x)
double x = real(a);       // 实部
double y = imag(a);       // 虚部
C conj_a = conj(a);       // 共轭 (x, -y)
C pol = polar(r, theta);  // 极坐标 -> 复数 (r·cosθ, r·sinθ)

double norm_sq = norm(a);  // x² + y²（不开根，比 abs 快）
竞赛技巧：复数天然支持点旋转。点 p 绕原点旋转 θ 弧度：p *= polar(1.0, theta);

三、<numbers>(C++ 20) — 数学常数 using namespace std::numbers;

double pi_v = pi;              // π
double e_v = e;                // e
double sqrt2 = sqrt2;          // √2
double inv_sqrt3 = inv_sqrt3;  // 1/√3
double phi = phi;              // 黄金比例 (1+√5)/2
double ln2 = ln2;              // ln 2
double ln10 = ln10;            // ln 10
double gamma = egamma;         // 欧拉-马歇罗尼常数 γ
C++ 17 没有的话自己写：constexpr double PI = acos(-1.0);

四、<numeric> — 整数数学 int g = gcd(a, b);  // C++17

int l = lcm(a, b);                           // C++17
int t = midpoint(l, r);                      // C++20, l+(r-l)/2 不会溢出
int g = reduce(v.begin(), v.end(), 0, gcd<int, int>);  // C++17 参数化 reduce

五、<bit>(C++ 20) — 位操作

int p = __builtin_ctz(x);  // count_trailing_zeros, GCC/clang
int p = std::countr_zero(x);   // C++20 标准版

int p = __builtin_clz(x);  // count_leading_zeros
int p = std::countl_zero(x);

int cnt = __builtin_popcount(x);  // 1 的个数
int cnt = std::popcount(x);

int p = __builtin_ffs(x);  // 最低位 1 的 1-indexed 位置

bool ok = std::has_single_bit(x);  // 是不是 2 的幂
unsigned x = std::bit_ceil(x);     // ≥x 的最小 2 的幂
unsigned x = std::bit_floor(x);    // ≤x 的最大 2 的幂
unsigned w = std::bit_width(x);    // 表示 x 所需的位数
unsigned x = std::rotl(x, k);      // 循环左移
unsigned x = std::rotr(x, k);      // 循环右移

六、<valarray> — 向量数组运算 valarray<double> a = {1, 2, 3}, b = {4, 5, 6};

a += b;                                         // 逐元素加
a *= 2.0;                                       // 标量乘
a = a * b;                                      // 逐元素乘
a = pow(a, 2.0);                                // 逐元素平方
a = a.apply([](double x) { return sqrt(x); });  // 逐元素应用任意函数
double s = a.sum();                             // 求和
double mn = a.min(), mx = a.max();
a = a.shift(1);    // 逻辑左移（尾部补 0）
a = a.cshift(-1);  // 循环右移

// slice：子集操作
slice_array<double> sub = a[slice(0, 3, 2)];  // a[0], a[2], a[4]

七、<random> — 随机数 mt19937_64

rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<double> dis(0.0, 1.0);
uniform_int_distribution<int> idis(l, r);
double rnd = dis(rng);
int dice = idis(rng);
shuffle(v.begin(), v.end(), rng);

八、自定义几何模板 (非内置但必备) 这些没有内置，需要自己写，但格式非常固定：

using ld = long double;
const ld EPS = 1e-9;

int sgn(ld x) { return (x > EPS) - (x < -EPS); }

struct Pt {
  ld x, y;
  Pt operator+(Pt b) const { return {x + b.x, y + b.y}; }
  Pt operator-(Pt b) const { return {x - b.x, y - b.y}; }
  Pt operator*(ld k) const { return {x * k, y * k}; }
  Pt operator/(ld k) const { return {x / k, y / k}; }
  ld dot(Pt b) const { return x * b.x + y * b.y; }
  ld cross(Pt b) const { return x * b.y - y * b.x; }
  ld len() const { return hypot(x, y); }
  ld len2() const { return x * x + y * y; }
  ld angle() const { return atan2(y, x); }
  Pt rotate(ld t) const {  // 逆时针旋转 t 弧度
    ld c = cos(t), s = sin(t);
    return {x * c - y * s, x * s + y * c};
  }
  Pt norm() const { return *this / len(); }  // 单位向量
};

// 叉积：判断左右/面积
ld cross(Pt a, Pt b) { return a.cross(b); }
ld cross(Pt a, Pt b, Pt c) { return (b - a).cross(c - a); }

// 点积：投影/角度
ld dot(Pt a, Pt b) { return a.dot(b); }
ld dot(Pt a, Pt b, Pt c) { return (b - a).dot(c - a); }

// 距离
ld dist(Pt a, Pt b) { return (a - b).len(); }
ld dist2(Pt a, Pt b) { return (a - b).len2(); }

// 点 c 到线段 ab 的最近点
Pt project(Pt a, Pt b, Pt c) {
  Pt ab = b - a;
  ld t = (c - a).dot(ab) / ab.len2();
  t = clamp(t, 0.0L, 1.0L);
  return a + ab * t;
}
ld dist_to_seg(Pt a, Pt b, Pt c) { return dist(c, project(a, b, c)); }

// 两线段是否相交（严格）
bool intersect(Pt a, Pt b, Pt c, Pt d) {
  auto on = [](Pt a, Pt b, Pt c) {
    return sgn((a - c).cross(b - c)) == 0 && sgn((a - c).dot(b - c)) <= 0;
  };
  if (on(a, b, c) || on(a, b, d) || on(c, d, a) || on(c, d, b)) return true;
  return sgn(cross(a, b, c)) * sgn(cross(a, b, d)) < 0 &&
         sgn(cross(c, d, a)) * sgn(cross(c, d, b)) < 0;
}

// 点到直线的距离
ld dist_to_line(Pt a, Pt b, Pt c) { return abs(cross(a, b, c)) / dist(a, b); }

// 多边形面积（带符号：逆时针正，顺时针负）
ld polygon_area(vector<Pt> poly) {
  ld area = 0;
  for (int i = 0; i < sz(poly); i++)
    area += poly[i].cross(poly[(i + 1) % sz(poly)]);
  return area / 2;
}

// 两直线交点 (a->b 与 c->d)，假定不平行
Pt line_intersection(Pt a, Pt b, Pt c, Pt d) {
  ld s1 = cross(c, d, a), s2 = cross(c, d, b);
  return (a * s2 - b * s1) / (s2 - s1);
}

// 点是否在多边形内
int point_in_polygon(vector<Pt>& poly, Pt p) {
  int n = sz(poly), wn = 0;
  for (int i = 0; i < n; i++) {
    if (sgn(dist_to_seg(poly[i], poly[(i + 1) % n], p)) == 0) return 0;  // 边上
    if (poly[i].y <= p.y) {
      if (poly[(i + 1) % n].y > p.y &&
          sgn(cross(poly[i], poly[(i + 1) % n], p)) > 0)
        wn++;
    } else {
      if (poly[(i + 1) % n].y <= p.y &&
          sgn(cross(poly[i], poly[(i + 1) % n], p)) < 0)
        wn--;
    }
  }
  return wn ? 1 : -1;  // 1=内部, -1=外部
}
九、常用浮点技巧
// 比较
bool eq(ld a, ld b) { return sgn(a - b) == 0; }
bool ls(ld a, ld b) { return sgn(a - b) < 0; }
bool le(ld a, ld b) { return sgn(a - b) <= 0; }

// 弧度制角度转换
const ld PI = acos(-1.0L);
ld deg2rad(ld d) { return d * PI / 180; }
ld rad2deg(ld r) { return r * 180 / PI; }

// 角度标准化到[-PI, PI)
ld norm_angle(ld a) {
  while (a >= PI) a -= 2 * PI;
  while (a < -PI) a += 2 * PI;
  return a;
}

// 三角形面积（海伦公式）
ld triangle_area(ld a, ld b, ld c) {
  ld p = (a + b + c) / 2;
  return sqrt(max(0.0L, p * (p - a) * (p - b) * (p - c)));
}
```

## 自动取模基本类型 : mint
```cpp
template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ +
  static_cast<int>(M)) : x_) {} constexpr ModInt(long long x_) : x(((x_ %=
  static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x;
  return *this; } ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M)
  ? (x + M) : x; return *this; } ModInt &operator*=(const ModInt &a) { x =
  (static_cast<unsigned long long>(x) * a.x) % M; return *this; } ModInt
  &operator/=(const ModInt &a) { return (*this *= a.inv()); } ModInt pow(long
  long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a;
    } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a =
    b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return
  (ModInt(a) += b); } template <class T> friend ModInt operator-(T a, const
  ModInt &b) { return (ModInt(a) -= b); } template <class T> friend ModInt
  operator*(T a, const ModInt &b) { return (ModInt(a) *= b); } template
  <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a)
  /= b); } explicit operator bool() const { return x; } bool operator==(const
  ModInt &a) const { return (x == a.x); } bool operator!=(const ModInt &a)
  const { return (x != a.x); } friend std::ostream &operator<<(std::ostream
  &os, const ModInt &a) { return os << a.x; }
};

struct mint {
  static int mod;
  int val;

  // 构造函数
  mint() : val(0) {}
  mint(int x) : val(x % mod) {
    if (val < 0) val += mod;
  }

  explicit operator int() const { return val; }
  int get() const { return val; }

  mint operator-() const { return mint(-val); }

  mint& operator+=(const mint& rhs) {
    val += rhs.val;
    if (val >= mod) val -= mod;
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    val -= rhs.val;
    if (val < 0) val += mod;
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    val = static_cast<int>((long long)val * rhs.val % mod);
    return *this;
  }
  mint& operator/=(const mint& rhs) {
    *this *= rhs.inv();
    return *this;
  }

  friend mint operator+(mint lhs, const mint& rhs) { return lhs += rhs; }
  friend mint operator-(mint lhs, const mint& rhs) { return lhs -= rhs; }
  friend mint operator*(mint lhs, const mint& rhs) { return lhs *= rhs; }
  friend mint operator/(mint lhs, const mint& rhs) { return lhs /= rhs; }

  friend bool operator==(const mint& lhs, const mint& rhs) {
    return lhs.val == rhs.val;
  }
  friend bool operator!=(const mint& lhs, const mint& rhs) {
    return !(lhs == rhs);
  }

  friend mint& operator++(mint& x) {
    x += 1;
    return x;
  }

  friend mint operator++(mint& x, int32_t) {
    mint tmp = x;
    x += 1;
    return tmp;
  }

  friend mint& operator--(mint& x) {
    x -= 1;
    return x;
  }

  friend mint operator--(mint& x, int32_t) {
    mint tmp = x;
    x -= 1;
    return tmp;
  }

  mint inv() const { 
    return pow(mod - 2); }

  mint pow(int p) const {
    assert(p >= 0);
    mint res = 1, base = *this;
    while (p) {
      if (p & 1) res *= base;
      base *= base;
      p >>= 1;
    }
    return res;
  }

  friend std::istream& operator>>(std::istream& is, mint& x) {
    long long v;
    is >> v;
    x = mint(v);
    return is;
  }
  friend std::ostream& operator<<(std::ostream& os, const mint& x) {
    return os << x.val;
  }
};

int mint::mod = 998244353;
```

## 10 的幂次查表
```cpp
constexpr int64_t pow10[20] = {
  1LL,                   // 10^0
  10LL,                  // 10^1
  100LL,                 // 10^2
  1000LL,                // 10^3
  10000LL,               // 10^4
  100000LL,              // 10^5
  1000000LL,             // 10^6
  10000000LL,            // 10^7
  100000000LL,           // 10^8
  1000000000LL,          // 10^9
  10000000000LL,         // 10^10
  100000000000LL,        // 10^11
  1000000000000LL,       // 10^12
  10000000000000LL,      // 10^13
  100000000000000LL,     // 10^14
  1000000000000000LL,    // 10^15
  10000000000000000LL,   // 10^16
  100000000000000000LL,  // 10^17
  1000000000000000000LL, // 10^18
};

```

## FP
```cpp
int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int fp(int x, int p) {
  int res = 1, base = x; 
  while (p) {
    if (p & 1) res *= base;
    base *= base , p >>= 1 ;
  }
  return res ; 
}
```
```cpp
int lcm(int a , int b) { 
  return a / __gcd(a , b) * b ; 
} 
```

## 逆元
```cpp
// 存在条件 : x % mod != 0 , x 逆元存在 即 x 不能是 mod 的整数倍
int inv (int x , int mod) { 
  return fp(x , mod - 2 , mod) ; 
}
```

## 素数筛(线性筛)
```cpp
const int N = 1e7;
vector<int> pr;
vector<int> vis(N + 1, 0);

void prime(int n) {
  vis[1] = 1;
  for (int i = 2; i <= n; i ++) {
    if(!vis[i]) pr.push_back(i) ;  
    for (const auto& j : pr) {
      if (i * j > n) break; 
      vis[i * j] = 1; 
      if (i % j == 0) break; 
    }
  }
}
```

## 素数因子
```cpp
map<int, int> cal_fac(int n) {
  map<int, int> res;
  for (int& p : pr) {
    if (p * p > n) break;
    while (n % p == 0) {
      res[p]++; 
      n /= p;
    }
  }
  if (n > 1) res[n] ++;
  return res;
}
```
## 组合数预处理
```cpp
vector<vector<int>> C;

void generate_c(int n) {
  C.assign(n + 1, vector<int>(n + 1, 0));
  for (int i = 1 ; i <= n ; i ++) { 
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j ++ ) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

int cmb(int n, int k) {
  if (k < 0 || k > n) return 0;
  return C[n][k];
}

```

## 更好的组合数
```cpp

const int mod = 1e9 + 7;
const int N = 5e5 + 1;

vector<int> fact(N);
void init() {
  fact[0] = fact[1] = 1;
  for(int i = 2; i <= N - 1; i ++) fact[i] = (fact[i - 1] * i) % mod;
}

int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int inv (int x , int mod) { 
  return fp(x , mod - 2 , mod) ; 
}

int cmb(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * fact[n] * inv(fact[k], mod) % mod * inv(fact[n - k], mod) % mod;
}
```


## 阶乘
```cpp
vector<int> fact(N);
void inti() {
  fact[0] = fact[1] = 1;
  for(int i = 2; i <= N - 1; i ++) fact[i] = (fact[i - 1] * i) % mod;
}

```

# 常见工具

## 模运算自动类
```cpp
class mint {
public: 
  static int mod;
  int v = 0;
  
  mint() = default;
  mint(int val) : v(val % mod) {
    if (v < 0) v += mod;
  }
  
  mint(const mint& other) : v(other.v) {}
  
  mint& operator=(const int& other) {
    v = other % mod;
    if (v < 0) v += mod;
    return *this;
  }
  
  mint& operator=(const mint& other) {
    if (this != &other) {
      v = other.v;
    }
    return *this;
  }
  
  mint& operator+=(const mint& other) {
    v = (v + other.v) % mod;
    return *this;
  }
  
  mint& operator+=(int other) {
    v = (v + (other % mod)) % mod;
    if (v < 0) v += mod;
    return *this;
  }
  
  mint& operator-=(const mint& other) {
    v = (v - other.v + mod) % mod;
    return *this;
  }
  
  mint& operator-=(int other) {
    v = (v - (other % mod) + mod) % mod;
    return *this;
  }
  
  mint& operator*=(const mint& other) {
    v = (v * other.v) % mod;
    return *this;
  }
  
  mint& operator*=(int other) {
    v = (v * (other % mod)) % mod;
    if (v < 0) v += mod;
    return *this;
  }
  
  mint operator+(const mint& other) const {
    mint res = *this;
    res += other;
    return res;
  }
  
  mint operator+(int other) const {
    mint res = *this;
    res += other;
    return res;
  }
  
  mint operator-(const mint& other) const {
    mint res = *this;
    res -= other;
    return res;
  }
  
  mint operator-(int other) const {
    mint res = *this;
    res -= other;
    return res;
  }
  
  mint operator*(const mint& other) const {
    mint res = *this;
    res *= other;
    return res;
  }
  
  mint operator*(int other) const {
    mint res = *this;
    res *= other;
    return res;
  }

  friend ostream& operator<<(ostream& os, const mint& m) {
    return os << m.v;
  }
  
  friend istream& operator>>(istream& is, mint& m) {
    int val;
    is >> val;
    m.v = val % mod;
    if (m.v < 0) m.v += mod;
    return is;
  }
};
```

## 离散化三兄弟
```cpp
void dedup(vector<int>& vec) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

int getId(int x, vector<int>& vec) {
  return lower_bound(vec.begin() + 1, vec.end() , x) - vec.begin();
}

void ranked(vector<int>& vec) {
  auto temp = vec; dedup(temp);
  for(auto &x : vec) x = getId(x, temp);
}
```
## 数字二进制表示
```cpp
string bit(int x) {
  return bitset<10>(x).to_string(); //.substr(10 - __lg(x) - 1);
}
```

## 列表取模
```cpp
int MOD(vector<int> vec) {
  int res = 1;
  for(const auto &a : vec) res = (res % mod * a % mod) % mod;
  return res % mod;
}
```

# GRAPH

## tarjan
```cpp
// 缩点, 就是把一张有向有环图中的环缩成一个个点, 形成一个有向无环图
int timer = 0, scc_cnt = 0;
vector<int> low(n + 1), dfn(n + 1), instk(n + 1), scc(n + 1), stk;
// low, dfn 是 点编号 -> 时间戳
// 剩下的都是点编号的意义
auto tarjan = [&](auto&& sef, int u) -> void {
  dfn[u] = low[u] = ++timer;
  stk.push_back(u);
  instk[u] = true;

  for (int& v : g[u]) {
    if (dfn[v] == 0) {
      sef(sef, v);
      low[u] = std::min(low[u], low[v]);
    } else if (instk[v]) {
      low[u] = std::min(low[u], dfn[v]);
    }
  }

  if (low[u] == dfn[u]) {
    ++scc_cnt;
    // 这里 如果栈里面只有 u 自己一个, 直接
    int v = 0;
    do {
      v = stk.back();
      stk.pop_back();
      scc[v] = scc_cnt;
      instk[v] = false;
    } while (v != u);
  }
};

for (int i = 1; i <= n; i++) {
  if (!dfn[i]) {
    tarjan(tarjan, i);
  }
}

vector<int> ans(scc_cnt + 1, 0);
for (int i = 1; i <= n; i++) {
  ans[scc[i]] += a[i];
}

// 建立 DAG
vector<vector<int>> dag(scc_cnt + 1);
for (int u = 1; u <= n; u++) {
  for (int v : g[u]) {
    if (scc[u] != scc[v]) dag[scc[u]].push_back(scc[v]);
  }
}

vector<int> dp(scc_cnt + 1);
dp = ans;  
for (int u = scc_cnt; u >= 1; u--) {
  for (int v : dag[u]) {
    dp[v] = std::max(dp[v], dp[u] + ans[v]);
  }
}
```
## 二分图判定
```cpp
bool isBipartite (const vector<vector<int>>& adj) {
  int n = (int)adj.size() - 1;
  vector<int> col(n + 1, 0);

  auto dfs = [&](auto&& sef, int u, int c) -> bool {
    col[u] = c;
    for (int v : adj[u]) {
      if (col[v] == c) return false;   
      if (col[v] == 0 and !sef(sef, v, 3 - c))  
        return false;
    }
    return true;
  };

  for (int u = 1; u <= n; u++) 
    if (col[u] == 0 and !dfs(dfs, u, 1)) 
      return false;
  
  return true;
}
```

## 二分图最大匹配
```cpp

```

## prim
```cpp

int prim(const vector<vector<PII>>& g) {
  int n = g.size();
  vector<bool> vis(n);
  vector<int> dis(n, INF);
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  dis[0] = 0;
  pq.emplace(0, 0);
  int ans = 0, cnt = 0;
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    ans += d;
    cnt++;
    for (auto [v, w] : g[u]) {
      if (!vis[v] && w < dis[v]) {
        dis[v] = w;
        pq.emplace(w, v);
      }
    }
  }
  return ans;
}

int n , k ; 

struct edge { int head ; int w ; } ; 

vector<int> vis ;
vector<int> dis ; 

vector<vector<edge>> adj ; 

void init() {
  vis.resize( n + 1 ) ; 
  dis.resize( n + 1 , INT_MAX / 2 ) ; 
  adj.resize( n + 1 ) ; 
}

int prim( int start ) {
  vis[start] = true ; dis[start] = 0 ; 
  for ( const auto &[h , w] : adj[start] ) {
    dis[h] = min( dis[h] , w ) ;  
  }
  int res = 0 ; 
  while ( 1 ) { 
    int mnh = -1 , mnw = INT_MAX ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
      if ( !vis[i] && mnw > dis[i] ) {
        mnw = dis[i] ;  
        mnh = i ; 
      }
    }

    if ( mnh == -1 ) break ; 

    res += mnw ; 
    vis[mnh] = 1 ; 
    dis[mnh] = 0 ; 

    for ( auto &[h , w] : adj[mnh] ) {
      dis[h] = min( dis[h] , w ) ; 
    } 

  }

  for ( int i = 1 ; i <= n ; i ++ ) {
    dis[i] = INT_MAX / 2 ;
  }

  return res ; 
}
```
## kruskal
```cpp
这个太简单了 自己写
```

## basic data
```cpp
struct edge {
  int v; int w;
  bool operator< (edge other) const {
    return w > other.w;
  }
};
```

## Dijkstra
```cpp
auto cmp = [](const array<int, 2>& a, const array<int, 2>& b) {return a[1] > b[1];};
void dijkstra (int s, vector<vector<edge>>& adj, vector<int>& vis, vector<int>& dis) {
  priority_queue<array<int, 2>> pq; pq.push({s, 0}); dis[s] = 0;
  while (!pq.empty()) {
    auto [u, w] = pq.top(); pq.pop();
    if (vis[u]) continue; vis[u] = 1;
    for(const auto &[v, ww] : adj[u]) if (dis[v] > w + ww) {
       dis[v] = w + ww, pq.push({v, dis[v]});
    }
  }
}

auto cmp = [](const array<int, 2>& a, const array<int, 2>& b) {return a[1] > b[1];};

int dijkstra (int s, int t, vector<vector<array<int, 2>>>& adj, vector<int>& vis, vector<int>& dis) {
  priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> pq(cmp); pq.push({s, 0}); dis[s] = 0;
  while (!pq.empty()) {
    auto [u, w] = pq.top(); pq.pop();
    if (u == t) return w;
    if (vis[u]) continue; vis[u] = 1;
    for(const auto &[v, ww] : adj[u]) if (dis[v] > w + ww) {
       dis[v] = w + ww, pq.push({v, dis[v]});
    }
  }
  return -1; 
}
```
## Floyd
```cpp
// FLoyd
vector<vector<int>> floyd(int n, vector<array<int, 3>>& edges) {
  vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MAX));
  for(int i = 1; i <= n; i ++) f[i][i] = 0;
  for(const auto &[u, v, w] : edges) f[u][v] = min(f[u][v], w);

  for(int k = 1; k <= n; k ++) {
    for(int i = 1; i <= n; i ++) {
      if (f[i][k] == INT_MAX) continue; 
      for(int j = 1; j <= n; j ++) {
        if (f[k][j] == INT_MAX) continue;
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }

  return f;
}
```

## SPFA
```cpp
// SPFA
int spfa(int s, int t, vector<vector<array<int, 2>>>& adj) {
  vector<int> inque(n + 1, 0), dis(n + 1, INT_MAX), cnt(n + 1, 0);
  dis[s] = 0;
  queue<int> q;  // 只需要存储节点编号
  q.push(s);
  inque[s] = 1;
  cnt[s] = 1;  // 起始节点入队次数+1
  while (!q.empty()) {
    int u = q.front(); q.pop();
    inque[u] = 0;
    for (const auto &[v, ww] : adj[u]) if (dis[u] + ww < dis[v]) { // 只要可以松弛就更新
      dis[v] = dis[u] + ww;
      if (!inque[v]) {         // 不在队列中才入队
        inque[v] = 1;
        cnt[v]++;
        if (cnt[v] >= n) {   // 检测到负环，立即返回
          return -1;
        }
        q.push(v);
      }
    }
  }

  return dis[t];
}
```

## LCA
```cpp
// LCA
int n; 
vector<int> dep;
vector<vector<int>> adj, fa;
cin >> n;
adj.assign(n + 1, {}); dep.assign(n + 1, 0);
fa.assign(__lg(n) + 1, vector<int>(n + 1, 0));

void dfs(int u, int f) {
  fa[0][u] = f;
  dep[u] = dep[f] + 1;
  for(const int &v : adj[u]) if (v != f) dfs(v, u);
}

void init(){
  for(int i = 1; i <= __lg(n); i ++) {
    for(int j = 1; j <= n; j ++) {
      fa[i][j] = fa[i - 1][fa[i - 1][j]];
    }
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int lim = __lg(n);
  for(int i = lim; i >= 0; i --) if (dep[fa[i][u]] >= dep[v]) {
    u = fa[i][u];
  }
  if (u == v) return u;
  for(int i = lim; i >= 0; i --) if (fa[i][u] != fa[i][v]) {
    u = fa[i][u]; v = fa[i][v];
  }
  return fa[0][u];
}

```
## 找最小环 优雅实现
```cpp
auto bfs = [&](int s) -> int {
  vector<int> d(n + 1, -1), p(n + 1, 0);
  queue<int> q; q.push(s); d[s] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v = 1;v <= n; v ++) if (g[u][v] && v != p[u]){
      if(d[v] == -1) d[v] = d[u] + 1, p[v] = u, q.push(v);
      else return d[u] + d[v] + 1;
    }
  }

  return INT_MAX;
};
```

## O(n) 找前两大
```cpp
// Find two max in O(n)
if (w[v] > mx1) mx2 = mx1, mx1 = w[v]; 
else if (w[v] > mx2) mx2 = w[v];
```

# 树论

## 树的直径
 - 两遍 dfs 优雅实现
```cpp
int mx, far;
auto dfs = [&](this auto&& dfs, int u, int f, int d) -> void {
  if (d > mx) mx = d, far = u;
  for (auto v : g[u]) if (v != f) dfs(v, u, d + 1);
};

mx = -1; dfs(1, 0, 0);
mx = -1; dfs(far, 0, 0);
```

 - 树形 dp 实现

$$ 那我就有一个疑惑了, 点的搜索顺序是可能影响答案的, 因为  dfs 是线性算法, 那么会不会造成 
一个点由于后面被遍历, 于是他的某个根下的最长路径 被之前遍历过了 从而缺失了这条路经呢 ?  $$

`直径的最高点一定在某处"拐弯"，那个拐弯点就是 LCA(端点A, 端点B)。DP 枚举了所有点做拐弯点，每个点都能看到它所有儿子的最长向下路径，所以一个都不会漏。`

```cpp
int ans = 0;
auto dfs = [&](this auto&& dfs, int u, int f) -> int {
  int d1 = 0, d2 = 0;
  for(auto& v : g[u]) if (v != f) {
    int d = dfs(v, u);
    if (d > d1) d2 = d1, d1 = d;
    else if (d > d2) d2 = d;
  }

  return d1;
};

dfs(1, 0);
cout << ans << "\n";
```

## 树的中心(让最远路径最短)
```cpp
vector<int> ctr, fa(n + 1);
int A = 0, B = 0, diam = -1;

auto dfs = [&](this auto&& dfs, int u, int f, int d) -> void {
  if (d > diam) diam = d, B = u;
  for (auto v : g[u]) if (v != f) {
    fa[v] = u, dfs(v, u, d + 1);
  }
};

dfs(1, 0, 0);  A = B, diam = -1;
dfs(A, 0, 0);

int mid = B;
for (int i = 0; i < diam / 2; i ++) mid = fa[mid];
ctr.push_back(mid);
if (diam & 1) ctr.push_back(fa[mid]);
```

## 树的重心(树上最平衡之点)

`删掉该点后，剩下的每个连通块大小都 ≤ n/2。
直观理解：重心是整棵树最"平衡"的点，把它删了以后没有一棵子树超过总点数的一半。`

```cpp
vector<int> ctr;
auto dfs = [&](this auto&& dfs, int u, int f) -> int {
  int sz = 1, mx = 0;
  for (auto v : g[u]) if (v != f) {
    int s = dfs(v, u);
    sz += s;
    mx = max(mx, s);
  }
  mx = max(mx, n - sz);
  if (mx <= n / 2) ctr.push_back(u);
  return sz;
};

dfs(1, 0);
```
## 欧拉序
```cpp
vector<int> euler;
auto dfs = [&](this auto&& dfs, int u, int f) -> void {
  euler.push_back(u);        // 进
  for (auto v : g[u]) if (v != f) dfs(v, u);
  euler.push_back(u);        // 出
};

场景	
LCA(RMQ 法)	欧拉序上两点首次出现位置之间的最小值节点 = LCA

路径和	     
u 到 v 的路径 = 欧拉序上带正负号的前缀和(点权版: 进 +val, 出 -val)

```

# data structure
## 并查集
```cpp
// DSU
class DSU {
 public:
  vector<int> f, siz, dis; 
 public:  
  DSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
    dis.assign(n, 0);
  }
  
  int find(int x) {
    if (x != f[x]) {
      int ffx = find(f[x]);
      f[x] = ffx;
    }
    return f[x];
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
      return false;
    }
    f[fx] = fy;
    siz[fy] += siz[fx];
    return true;
  }
  
  int size(int x) {
    return siz[find(x)];
  }
};

```
## 可回滚并查集
```cpp

// RollbackDSU
class RollbackDSU {
 public:
  struct His {
    int x;
    int y;
  };

  vector<int> f, sz;
  vector<His> his;

 public:
  RollbackDSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    sz.assign(n, 1);
  }

  void init(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    sz.assign(n, 1);
    his.clear();
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x];
    }
    return x;
  }

  bool same(int x, int y) { 
    return find(x) == find(y); 
  }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    his.emplace_back(x, y);
    f[y] = x;
    sz[x] += sz[y];
    return true;
  }

  void rollback() {
    auto [x, y] = his.back();
    his.pop_back();
    f[y] = y;
    sz[x] -= sz[y];
  }
};

```
## 带权并查集
```cpp
// DSU
class DSU {
 public:
  vector<int> f, siz, dis; 
 public:  
  DSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
    dis.assign(n, 0);
  }
  
  int find(int x) {
    if (x != f[x]) {
      int ffx = find(f[x]);
      dis[x] += dis[f[x]];
      f[x] = ffx;
    }
    return f[x];
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  bool merge(int x, int y, int w) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    // fx -> fy 
    int nw = w + dis[y] - dis[x];
    siz[fy] += siz[fx];
    dis[fx] += nw;
    f[fx] = fy;
    return true;
  }
  
  int ask(int l, int r) {
    if (!same(l, r)) {
      return -1;
    }
    return dis[l] - dis[r]; 
  }

  int size(int x) {
    return siz[find(x)];
  }
};

```

## 树状数组
```cpp
class BIT {
public: 
  int n; 
  std::vector<int> tree;
public: 
  BIT(int _n = 1) : n(_n) {tree.assign(n + 1, 0);}
  static int lowbit(int i) {return i & -i;} 

  void set(int p, int v) { // 不能 update(0, ?) 会死循环
    if (p <= 0) return;
    for(int i = p; i <= n; i += lowbit(i)) {
      tree[i] += v;
    }
  }

  int ask(int p) {
    if (p <= 0) return 0;
    int res = 0;
    for(int i = p; i > 0; i -= lowbit(i)) {
      res += tree[i];
    }
    return res;
  }
};
```

## 链式前向星
```cpp
//链式前向星

// 从 u 出发的所有边 串联成一个链表 每个节点有自己的信息和尾指针
// 全部的边都存在一个一维数组里面 head[u] 代表从 u 出发的边的链表的头结点的位置
int n, m, cnt = 0; 
// v, w, nxt
vector<int> head;
vector<array<int, 3>> edges(N + 1);
inline void add(int u, int v, int w) {
  edges[++cnt] = {v, w, head[u]};
  head[u] = cnt;
} 
 
// 遍历节点u的所有出边
for (int i = head[u]; i; i = edges[i][2]) {
  int v = edges[i][0];  // 终点
  int w = edges[i][1];  // 权重
  // 处理边 u->v
}
```
## zkw 线段树
l 和 r 重叠的话 有可能 左指针超过右边, 右指针超过左边啊
i ++ off, 变成叶子节点
i ^ 1, 转换成兄弟节点
l ^ 1 == r 时, l ^ r == 1, 所以 l ^ r ^ 1 非 0 就证明此时不是兄弟节点
i >>= 1 上跳到父亲节点
```cpp
class SGT {
  std::vector<int> seg;
  int off = 0;
  void pull(int i) { seg[i] = std::max(seg[i << 1], seg[i << 1 | 1]); }

 public:
  SGT() = delete;
  SGT(int n) {
    off = std::bit_ceil(unsigned(n + 2));
    seg.assign(off << 1, 0);
  }
  void upd(int i, int v) {
    if (v <= seg[i += off]) return;
    seg[i] = v;
    while (i >>= 1) pull(i);
  }
  int ask(int l, int r) {
    if (l > r) return 0;
    int res = 0;
    
    for (l += off - 1, r += off + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) res = std::max(res, seg[l ^ 1]);
      if (r & 1)  res = std::max(res, seg[r ^ 1]);
    }
    return res;
  }
};
```
## 线段树
```cpp
class SGT {
 public:
  int n;
  vector<int> seg;

  SGT(int _n = 0) : n(_n) { seg.assign(4 * n + 1, 0); }

  SGT(const vector<int> &a) : n(a.size() - 1) {
    seg.assign(4 * n + 1, 0);
    build(1, 1, n, a);
  }

  void build(const vector<int> &a) { build(1, 1, n, a); }
  void upd(int pos, int v) { upd(1, 1, n, pos, v); }
  int ask(int l, int r) { return ask(1, 1, n, l, r); }

 private:
  void pull(int p) { seg[p] = seg[p << 1] + seg[p << 1 | 1]; }

  void build(int p, int l, int r, const vector<int> &a) {
    if (l == r) { seg[p] = a[l]; return; }
    int m = (l + r) >> 1;
    build(p << 1, l, m, a);
    build(p << 1 | 1, m + 1, r, a);
    pull(p);
  }

  void upd(int p, int l, int r, int pos, int v) {
    if (l == r) { seg[p] = v; return; }
    int m = (l + r) >> 1;
    if (pos <= m) upd(p << 1, l, m, pos, v);
    else          upd(p << 1 | 1, m + 1, r, pos, v);
    pull(p);
  }

  int ask(int p, int l, int r, int L, int R) {
    if (L <= l and r <= R) return seg[p];
    int m = (l + r) >> 1, res = 0;
    if (L <= m) res += ask(p << 1, l, m, L, R);
    if (R > m)  res += ask(p << 1 | 1, m + 1, r, L, R);
    return res;
  }
};
```

## 线段树(lazy)
```cpp
template<typename Info, typename Tag>
class SGT {
 public:
  int n;
  vector<Info> seg;
  vector<Tag> tag;

  SGT(int _n = 0) : n(_n) {
    seg.assign(4 * n + 1, Info());
    tag.assign(4 * n + 1, Tag());
  }

  SGT(const vector<int> &a) : n(a.size() - 1) {
    seg.assign(4 * n + 1, Info());
    tag.assign(4 * n + 1, Tag());
    build(1, 1, n, a);
  }

  void build(const vector<int> &a) { build(1, 1, n, a); }

  void upd(int l, int r, int v) { upd(1, 1, n, l, r, v); }

  Info ask(int l, int r) { return ask(1, 1, n, l, r).sum; }

 private:
  void put(int p, int l, int r, const Tag &tg) {
    seg[p].sum += tg.add * (r - l + 1);
    tag[p] = tag[p] + tg;
  }

  void push(int p, int l, int r) {
    if (tag[p].empty()) return;
    int m = (l + r) >> 1;
    put(p << 1, l, m, tag[p]);
    put(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = Tag();
  }

  void pull(int p) {
    seg[p] = seg[p << 1] + seg[p << 1 | 1];
  }

  void build(int p, int l, int r, const vector<int> &a) {
    if (l == r) {
      seg[p] = {a[l]};
    } else {
      int m = (l + r) >> 1;
      build(p << 1, l, m, a);
      build(p << 1 | 1, m + 1, r, a);
      pull(p);
    }
  }

  void upd(int p, int l, int r, int L, int R, int v) {
    if (L <= l and r <= R) {
      put(p, l, r, {v});
    } else {
      push(p, l, r);
      int m = (l + r) >> 1;
      if (L <= m) upd(p << 1, l, m, L, R, v);
      if (R > m)  upd(p << 1 | 1, m + 1, r, L, R, v);
      pull(p);
    }
  }

  Info ask(int p, int l, int r, int L, int R) {
    if (L <= l and r <= R) return seg[p];
    push(p, l, r);
    int m = (l + r) >> 1;
    if (R <= m) return ask(p << 1, l, m, L, R);
    if (L > m)  return ask(p << 1 | 1, m + 1, r, L, R);
    return ask(p << 1, l, m, L, R) + ask(p << 1 | 1, m + 1, r, L, R);
  }
};

struct Info {
  int sum = 0;
  Info operator+(const Info &o) const { return {sum + o.sum}; }
};

struct Tag {
  int add = 0;
  bool empty() const { return add == 0; }
  Tag operator+(const Tag &o) const { return {add + o.add}; }
};

```
## 主席树(静态区间第 k 大)
```cpp
// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Infor {
  int ls, rs;
  int cnt = 0;
};  

int cnt = 0;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<Infor> seg(n * 25 + 1);
  // 参数的 p 是为了知道当前的节点编号是多少
  // 然后我们保证 set 里面全部都在开新的点, 也就是 set 进入的一开始
  // 当前操作的节点永远是空的
  // 外部每一次调用 set 相当
  auto set = [&](auto && sef, int pre, int l, int r, int pos) -> int {
    int p = ++cnt;
    seg[p] = seg[pre];
    seg[p].cnt ++;
    if (l != r) {
      int m = (l + r) / 2;
      if (pos <= m)
        seg[p].ls = sef(sef, seg[pre].ls, l, m, pos);
      else
        seg[p].rs = sef(sef, seg[pre].rs, m + 1, r, pos);
    }
    return p;
  };

  auto ask = [&](auto && sef, int prev, int pres, int l, int r, int k) -> int {
    if (l == r) {
      return l;
    } else {
      int m = (l + r) / 2, 
          cnt_l = (
            seg[seg[pres].ls].cnt -
            seg[seg[prev].ls].cnt
          );
      if (k <= cnt_l)
        return sef(sef, seg[prev].ls, seg[pres].ls, l, m, k);
      else
        return sef(sef, seg[prev].rs, seg[pres].rs, m + 1, r, k - cnt_l);
    }
  };

  auto sorted = vec;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin() + 1, sorted.end()), sorted.end());

  auto get = [&](int i) -> int {
    return lower_bound(sorted.begin() + 1, sorted.end(), i) - sorted.begin();
  };

  int lim = sorted.size() - 1;

  vector<int> rt(n + 1); rt[0] = 0;
  for (int i = 1; i <= n; i ++) {
    rt[i] = set(set, rt[i - 1], 1, n, get(vec[i]));
  }

  for (int i = 1; i <= m; i ++) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << sorted[ask(ask, rt[l - 1], rt[r], 1, n, k)] << "\n";
  }
}

/*树是二维结构  主席树相当于三维, 新加的一维相当于是时间维度*/

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}
```

## 分块
```cpp
### 求前缀第一个小于等于
int n, block;
vector<int> vec, tag;
vector<vector<int>> sorted;

int begin(int blk) {return (blk - 1) * block + 1;}
int end(int blk) {return min(blk * block, n);}
int to(int i) {return (i - 1) / block + 1;}

void init(){
  vec.assign(n + 1, 0);
  tag.assign(n + 1, 0);
  sorted.assign(n + 1, {});
  block = sqrt(n);
}

void reset(int blk) {
  sorted[blk].clear();
  for(int i = begin(blk); i <= end(blk); i ++) sorted[blk].push_back(vec[i]);
  sort(sorted[blk].begin(), sorted[blk].end());
} 

void update(int l, int r, int val) {
  int bl = to(l), br = to(r);
  if (bl == br) {
    for(int i = l; i <= r; i ++) vec[i] += val;
    reset(bl); return; 
  }

  for(int i = l; i <= end(bl); i ++) vec[i] += val;
  for(int i = bl + 1; i < br; i ++) tag[i] += val;
  for(int i = begin(br); i <= r; i ++) vec[i] += val;
  reset(bl); reset(br);
}

int query(int l, int r, int c) {
  int bl = to(l), br = to(r), res = -1, t = c;
  if (bl == br) {
    for(int i = l; i <= r; i ++) if (vec[i] + tag[to(i)] < t) res = max(res, vec[i] + tag[to(i)]);
    return res;
  }

  for(int i = l; i <= end(bl); i ++) if (vec[i] + tag[to(i)] < t) res = max(res, vec[i] + tag[to(i)]);
  for(int i = bl + 1; i < br; i ++) {
    auto it = lower_bound(sorted[i].begin(), sorted[i].end(), t - tag[i]);
    if (it != sorted[i].begin()) res = max(res, *--it + tag[i]);
  }
  for(int i = begin(br); i <= r; i ++) if (vec[i] + tag[to(i)] < t) res = max(res, vec[i] + tag[to(i)]);

  return res;
}


### RMQ && 累加问题
int n, block; 
vector<int> vec, tag, sum; 

int begin(int i) {return (i - 1) * block + 1;}
int end(int i) {return min(i * block, n);}
int blk(int i) {return (i - 1) / block + 1;}
int sz(int i) {return end(i) - begin(i) + 1;}

void init() {
  vec.assign(n + 1, 0);
  sum.assign(n + 1, 0);
  tag.assign(n + 1, 0);
  block = sqrt(n);
}

void update(int l, int r, int val) {
  int bl = blk(l), br = blk(r);
  if (bl == br) {
    for(int i = l; i <= r; i ++) sum[bl] += val, vec[i] += val;
    return; 
  }

  for(int i = l; i <= end(bl); i ++) vec[i] += val, sum[bl] += val; 
  for(int i = bl + 1; i < br; i ++) tag[i] += val, sum[i] += val * sz(i);
  for(int i = begin(br); i <= r; i ++) vec[i] += val, sum[br] += val; 
}

int query(int l, int r) {
  int res = 0;
  int bl = blk(l), br = blk(r);
  if (bl == br) {    
    for(int i = l; i <= r; i ++) res += vec[i] + tag[bl];
    return res; 
  }  
  
  for(int i = l; i <= end(bl); i ++) res = res + vec[i] + tag[bl];
  for(int i = bl + 1; i < br; i ++) res = res + sum[i];
  for(int i = begin(br); i <= r; i ++) res = res + vec[i] + tag[br];
  return res;
}

```
## 珂朵莉树
```cpp

class ODT {
 public:
  int n;
  struct Node {
    int l, r;
    mutable int v;
    bool operator<(const Node& o) const { return l < o.l; }
  };
  set<Node> odt;

  ODT(int _n = 0) : n(_n) {
    if (n > 0) {
      odt.insert({1, n, 0});
    }
  }

  template<typename Iter>
  ODT(Iter first, Iter last) {
    n = distance(first, last);
    odt.clear();
    if (first == last) return;

    int pos = 1;
    int prev = *first;
    int s = 1;
    Iter it = first;
    ++ it;

    for (; it != last; ++ it , pos ++) {
      if (*it != prev) {
        odt.insert({s, pos, prev});
        s = pos + 1;
        prev = *it;
      }
    }
    odt.insert({s, n, prev});
  }

  std::set<Node>::iterator split(int p) {
    if (p > n) return odt.end();
    auto it = odt.lower_bound(Node{p, 0, 0});
    if (it != odt.end() && it -> l == p) return it;
    it --; // it == p - 1
    int l = it -> l, r = it -> r, v = it -> v;
    odt.erase(it);
    odt.insert(Node{l, p - 1, v});
    auto ret = odt.insert(Node{p, r, v}).first;
    return ret;
  }

  // 保证区间 [l, r] 两端的边界被分裂（先右后左，安全）
  void split_range(int l, int r) {
    split(r + 1);
    split(l);
  }

  void assign(int l, int r, int v) {
    split_range(l, r);
    odt.erase(odt.lower_bound({l, 0, 0}), odt.upper_bound({r, 0, 0}));
    odt.insert({l, r, v});
  }

  int sum(int l, int r) {
    split_range(l, r);
    int res = 0;
    auto it = odt.lower_bound({l, 0, 0});
    for (; it != odt.end() && it->l <= r; ++it) {
      res = (res + (it->r - it->l + 1) % mod * it->v) % mod;
    }
    return res;
  }

  void copy(int l1, int r1, int l2, int r2) {
    if (l1 < l2) {
      auto r2_it = split(r2 + 1);
      auto l2_it = split(l2);
      auto r1_it = split(r1 + 1);
      auto l1_it = split(l1);

      vector<Node> tmp;
      for (auto it = l1_it; it != r1_it; ++it) {
        tmp.push_back(*it);
      }

      odt.erase(l2_it, r2_it);
      int offset = l2 - l1;
      for (const auto& node : tmp) {
        odt.insert({node.l + offset, node.r + offset, node.v});
      }
    } else {
      auto r1_it = split(r1 + 1);
      auto l1_it = split(l1);
      auto r2_it = split(r2 + 1);
      auto l2_it = split(l2);

      vector<Node> tmp;
      for (auto it = l1_it; it != r1_it; ++it) {
        tmp.push_back(*it);
      }

      odt.erase(l2_it, r2_it);
      int offset = l2 - l1;
      for (const auto& node : tmp) {
        odt.insert({node.l + offset, node.r + offset, node.v});
      }
    }
  }

  void swap(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
      std::swap(l1, l2);
      std::swap(r1, r2);
    }
    vector<Node> v1, v2;

    auto r2_it = split(r2 + 1);
    auto l2_it = split(l2);
    auto r1_it = split(r1 + 1);
    auto l1_it = split(l1);
    
    for (auto it = l2_it; it != r2_it; ++it) {
      v2.push_back(*it);
    }
    
    for (auto it = l1_it; it != r1_it; ++it) {
      v1.push_back(*it);
    }
    
    odt.erase(odt.lower_bound({l1, 0, 0}), odt.upper_bound({r1, 0, 0}));
    odt.erase(odt.lower_bound({l2, 0, 0}), odt.upper_bound({r2, 0, 0}));

    int offset = l2 - l1;
    for (const auto node : v1) {
      odt.insert({node.l + offset, node.r + offset, node.v});
    }

    for (const auto node : v2) {
      odt.insert({node.l - offset, node.r - offset, node.v});
    }
  }

  void reverse(int l, int r) {
    split_range(l, r);
    vector<Node> tmp;
    auto it = odt.lower_bound({l, 0, 0});
    for (; it != odt.end() && it->l <= r; ++it) {
      tmp.push_back(*it);
    }
    odt.erase(odt.lower_bound({l, 0, 0}), odt.upper_bound({r, 0, 0}));
    for (int i = tmp.size() - 1; i >= 0; --i) {
      odt.insert({l + r - tmp[i].r, l + r - tmp[i].l, tmp[i].v});
    }
  }

  template <typename Func>
  void traverse(int l, int r, Func func) {
    split_range(l, r);
    auto it = odt.lower_bound({l, 0, 0});
    for (; it != odt.end() && it->l <= r; ++it) {
      func(it);
    }
  }
};

```

## pb_ds 的使用
```cpp

#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

/**
 * ============================================
 * 模块一：有序集合 (Ordered Set / Tree)
 * 基于红黑树，支持顺序统计 (第 K 小)
 * 注意：order_of_key 和 find_by_order 均为 0-based
 * ============================================
 */
template<typename T>
using ordered_set = tree<
  T,
  null_type,
  less<T>,
  rb_tree_tag,
  tree_order_statistics_node_update
>;

void demo_ordered_set() {
  ordered_set<int> os;

  // 插入元素 x
  // 返回值: pair<iterator, bool> (若已存在则插入失败)
  os.insert(10);

  // 删除元素 x
  // 返回值: size_t (1 表示删除成功, 0 表示不存在)
  os.erase(10);

  // 查找元素 x
  // 返回值: iterator (指向该元素, 若不存在则返回 os.end())
  auto it = os.find(10);

  // 返回第一个 >= x 的迭代器
  // 返回值: iterator
  os.lower_bound(10);

  // 返回第一个 > x 的迭代器
  // 返回值: iterator
  os.upper_bound(10);

  // [核心功能] 查询排名
  // 返回严格小于 x 的元素个数 
  // 返回值: size_t
  os.order_of_key(10);

  // [核心功能] 查询第 k 小
  // ⚠️ 警告: k 必须在 [0, size()) 范围内, 越界行为未定义
  // 返回值: iterator
  os.find_by_order(0);

  // 合并 another 到当前 set
  // ⚠️ 警告: 两个集合必须无交集 (无重复元素), 否则会 RE
  // ordered_set<int> another;
  // os.join(another);

  // 分裂: 将 >= x 的元素移动到 other 中
  // ordered_set<int> other;
  // os.split(10, other);

  // 大小与清空
  os.size();     // 返回值: size_t
  os.empty();    // 返回值: bool
  os.clear();
t 变量的计算存在差一错误（off-by-one）。
第 111 行：
int t = (k == 0 ? i : *os.find_by_order(cnt - k) - 1);
对于 k >= 1，find_by_order(cnt - k) 返回的是 p_{cnt-k+1}（第 cnt-k+1 个不同值最后出现的位置）。
左端点 L <= p_{cnt-k+1} 时子数组 [L, i] 恰好包含 k 个不同值，所以 t 应为 p_{cnt-k+1}，而非 p_{cnt-k+1} - 1。
修复： 去掉 - 1。
int t = (k == 0 ? i : *os.find_by_order(cnt - k));
举例验证：a = [1, 2, 1], k = 2，当 i = 2 时原代码 t = 0，导致漏算 [1, 2] 这个合法子数组。修复后 t = 1，计入答案。
}

/**
 * ============================================
 * 模块二：可修改优先队列 (Priority Queue)
 * 基于 Pairing Heap, 支持修改和合并
 * ============================================
 */
typedef priority_queue<
  int,
  less<int>,
  pairing_heap_tag
> pbds_pq;

void demo_priority_queue() {
  pbds_pq pq;

  // 入队
  // 返回值: point_iterator (可用于修改或删除)
  auto it = pq.push(10);

  // 出队 (删除堆顶)
  pq.pop();

  // 获取堆顶元素
  // 返回值: const int&
  pq.top();

  // 修改堆中任意元素的值
  // ⚠️ 警告: 修改后仍需保持堆的性质 (通常是增大大根堆的值或减小小根堆的值)
  pq.modify(it, 20);

  // 删除堆中任意元素
  pq.erase(it);

  // 合并另一个堆
  // pbds_pq other;
  // pq.join(other);

  // 根据谓词分裂堆
  // pq.split([](int x){ return x > 10; }, other);

  pq.size();     // 返回值: size_t
  pq.empty();    // 返回值: bool
  pq.clear();
}

/**
 * ============================================
 * 模块三：前缀字典树 (Trie)
 * 基于 PATRICIA Trie, 支持前缀查询
 * ============================================
 */
typedef trie<
  string,
  null_type,
  trie_string_access_traits<string>,
  pat_trie_tag,
  trie_prefix_search_node_update
> pbds_trie;

void demo_trie() {
  pbds_trie tr;

  // 插入字符串
  tr.insert("hello");

  // 删除字符串
  // 返回值: size_t (1 成功, 0 失败)
  tr.erase("hello");

  // 查找字符串
  // 返回值: iterator (找不到则返回 tr.end())
  tr.find("hello");

  // [核心功能] 前缀查询
  // 返回一个 pair<iterator, iterator> 表示范围 [first, second)
  auto range = tr.prefix_range("he");
  // 遍历所有以 "he" 开头的字符串
  for (auto it = range.first; it != range.second; ++it) {
    // *it 即为字符串
  }

  // 合并另一个 Trie
  // ⚠️ 警告: 不能有重复键, 否则行为未定义
  // pbds_trie other;
  // tr.join(other);

  tr.begin();    // 返回值: iterator
  tr.end();      // 返回值: iterator
  tr.size();     // 返回值: size_t
  tr.empty();    // 返回值: bool
  tr.clear();
}
```

## 线性基

把每个数字 看作一个 64 维度的向量
可以有这样的矩阵
b[9] = [1, 0, 0, 0, 0, 0...0]
b[8] = [0, 1, 0, 0, 0, 0...0]
...
b[1] = [1, 0, 0, 0, 0, 0...0]
b[0] = [1, 0, 0, 0, 0, 0...1]

可以注意矩阵的定义, 类似于 行变换消元后, 将矩阵变为行阶梯型矩阵
"拐角处" 为 矩阵 "主元", 主元可以组成一组矩阵的最大线性无关组

行的定义是, 从上到下代表从高到低 的矩阵的维度
同时, 相对应的, 异或线性基的 行变换运算从 +- 法 变为 ^ 运算

由于是要化简为 刚接提现矩阵, 而非 简化行阶梯型矩阵
所以 当前维度的元素, 以上 也可以存在一些

由于异或是 非进位的二进制加法, 所以 位和位 之间 线性无关, 就像正交基一样的
为了方便理解, 可以把 二进制数字局限成一个 三维向量(截断高位) 可以用可视化的方式表达出来

那么本质上我们是 按照行

`X + Y = S + 2 · (X & Y)` 

相 & 的结果是 第 i 位该向上进位, 相 & 的结果 左移 1 后 就是进位的部分
相 ^ 的结果是 非进位的部分

```cpp
struct LB {
  array<int, 64> b = {};
  LB() = default;

  bool ins(int x) {
    for (int i = 62; i >= 0; i--) if (x >> i & 1) 
      if (!b[i]) { b[i] = x; return true; }
      else x ^= b[i];
    return false;
  }

  bool chk(int x) {
    for (int i = 62; i >= 0; i--) 
      if (x >> i & 1) x ^= b[i];
    return x == 0;
  }
  
  int get_max() {
    int res = 0;
    for (int i = 62; i >= 0; i--) 
      res = max(res, res ^ b[i]);
    return res;
  }

  int get_min() {
    for (int i = 0; i <= 62; i++) 
      if (b[i]) return b[i];
    return -1;
  }

  int kth_min(int k) {
    auto t = vector<int>(); 
    for (int i = 0; i < 63; i++) if (b[i]) t.push_back(b[i]);
    for (int i = 0; i < (int)t.size(); i++)  
      for (int j = 0; j < i; j++)  
        t[i] = min(t[i], t[i] ^ t[j]);
    int res = 0; k--;
    for (int i = 0; i < (int)t.size(); i++)  
      if (k >> i & 1) res ^= t[i];
    return res;
  }

  int kth_max(int k) {
    auto t = vector<int>();
    for (int i = 62; i >= 0; i--) if (b[i]) t.push_back(b[i]);
    return kth_min((1LL << (int)t.size()) - k + 1);
  }

  void merge(const LB& o) {
    for (int i = 62; i >= 0; i--) {
      if (o.b[i]) ins(o.b[i]);
    }
  }
};
```

## st表
```cpp

struct ST {
  int n;
  vector<vector<int>> f;

  ST(const vector<int>& a) {
    n = (int)a.size();
    int K = __lg(n) + 1;
    f.assign(K, vector<int>(n));
    f[0] = a;
    for (int k = 1; k < K; k++) 
      for (int i = 0; i + (1 << k) <= n; i++)
        f[k][i] = max(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
  }

  int ask(int l, int r) {
    int k = __lg(r - l + 1);
    return max(f[k][l], f[k][r - (1 << k) + 1]);
  }
};

class ST {
 private:
  vector<vector<int>> st;
  function<int(int, int)> f;

 public:
  ST(const vector<int>& vec, auto func) : f(func) {
    int n = vec.size() - 1, exp = __lg(n);
    st.assign(exp + 2, vector<int>(n + 1));
    for(int i = 1; i <= n; i ++) st[0][i] = vec[i]; 
    for(int j = 1; j <= exp; j ++) {
      for(int i = 1; i + (1 << j) - 1 <= n; i ++) {
        st[j][i] = f(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      }
    }
  } 

  int ask(int l, int r) {
    if (l > r) { cerr << "wrong query" << endl; return -1; }
    int j = __lg(r - l + 1);
    return f(st[j][l], st[j][r - (1 << j) + 1]);
  }
};
```
## Trie
```cpp
class Trie {
private :
  int n, cnt_node = 0;
  vector<int> cnt;
  vector<array<int, 64>> trie;

public :
  Trie (int _n = 0) : n(_n) {cnt.assign(n + 1, 0); trie.assign(n + 1, {});}

  static int to(char c) {
    if (c <= '9') return c - '0';
    if (c <= 'Z') return c - 'A' + 10;
    if (c <= 'z') return c - 'a' + 36;
  }

  void insert(string s) {
    int len = s.size(), p = 0;
    for(int i = 0; i < len; i ++) {
      int c = to(s[i]);
      if (!trie[p][c]) trie[p][c] = ++ cnt_node; 
      p = trie[p][c];
      cnt[p] ++;
    }
  }

  int ask(string s) {
    int len = s.size(), p = 0;
    for(int i = 0; i < len; i ++) {
      int c = to(s[i]);
      if (!trie[p][c]) return 0;
      p = trie[p][c];
    }
    return cnt[p];
  }
};

class Trie {
 public:
  int n, cnt_node = 0;
  vector<int> cnt;
  vector<array<int, 64>> trie;

 public:
  Trie(int _n = 0) : n(_n) {
    cnt.assign(n + 1, 0);
    trie.assign(n + 1, {});
  }

  static int to(char c) {
    if (c <= '9') return c - '0';
    if (c <= 'Z') return c - 'A' + 10;
    if (c <= 'z') return c - 'a' + 36;
    return 0;  
  }

  void insert(string s) {
    int p = 0;
    for (char ch : s) {
      int c = to(ch);
      if (!trie[p][c]) {
        trie[p][c] = ++cnt_node;
        // 新建节点必须清空，否则旧数据残留会导致错误
        trie[cnt_node].fill(0);
        cnt[cnt_node] = 0;
      }
      p = trie[p][c];
      cnt[p]++;
    }
  }

  int ask(string s) {
    int p = 0;
    for (char ch : s) {
      int c = to(ch);
      if (!trie[p][c]) return 0;
      p = trie[p][c];
    }
    return cnt[p];
  }

  // 简洁删除：边走边减 cnt，遇到 cnt==0 就断开并返回
  void erase(string s) {
    int p = 0, parent = 0, last_c = 0;
    for (char ch : s) {
      int c = to(ch);
      parent = p;
      last_c = c;
      p = trie[p][c];
      if (--cnt[p] == 0) {
        trie[parent][last_c] = 0;
        return;  // 子树已废弃，后面的节点无需再处理
      }
    }
  }

  // 多组测试用：只重置根节点和节点计数器
  void clear() {
    trie[0].fill(0);
    cnt[0] = 0;
    cnt_node = 0;
  }
};
```
## bitset
```cpp
bitset<8> b1;                 // 全 0: 00000000
bitset<8> b2(13);             // 二进制: 00001101
bitset<8> b3("101100");       // 补前导0: 00101100
bitset<8> b4(string("110"));  // 00110010（注意字符串高位在右）

// ==================== 基础访问与修改 ====================
b1.set();          // 全置 1
b1.reset();        // 全置 0
b1.flip();         // 全部取反
b1.set(2);         // 第2位设为1（从0开始）
b1.reset(2);       // 第2位设为0
b1.flip(2);        // 翻转第2位
bool x = b1[2];    // 读取第2位
b1[2] = 1;         // 赋值第2位

// ==================== 常用查询 ====================
int c1 = b1.count();   // 1的个数（popcount）
int c2 = b1.size();    // 总位数
bool e = b1.any();     // 是否有1
bool n = b1.none();    // 是否全0
bool a = b1.all();     // 是否全1
cout << b1.test(3);    // 第3位是否为1

// ==================== 位运算 ====================
auto b5 = b1 & b2;     // 按位与
auto b6 = b1 | b2;     // 按位或
auto b7 = b1 ^ b2;     // 按位异或
auto b8 = ~b1;         // 按位取反
b1 <<= 2;              // 左移2位
b1 >>= 2;              // 右移2位
auto b9 = b1 << 2;
auto b10 = b1 >> 2;
```

# strings

## substr
```cpp
string s = "abcdefg"; // 0-base: [0]a [1]b [2]c [3]d [4]e [5]f [6]g

string t1 = s.substr(2);       // "cdefg" (pos=2 到尾)
string t2 = s.substr(1, 3);    // "bcd" (pos=1, 取3个)
string pre = s.substr(0, 3);   // "abc" (前缀)
string suf = s.substr(s.size() - 3); // "efg" (后缀)
string cut = s.substr(0, s.size() - 2); // "abcde" (删尾)

// 边界
string e1 = s.substr(s.size()); // "" (合法)
string e2 = s.substr(5, 100);   // "fg" (自动截断)
// s.substr(10); // RE (pos越界)
```

## KMP
```cpp
vector<int> border(const string& p) {
  int m = p.size();
  vector<int> nxt(m, 0);
  for (int i = 1, j = 0; i < m; i++) {
    while (j and p[i] != p[j]) {
      j = nxt[j - 1];
    }
    if (p[i] == p[j]) {
      j++;
    }
    nxt[i] = j;
  }
  return nxt;
}

vector<int> kmp(string& p, string& s) {
  auto nxt = border(p);
  int j = 0, n = (int)s.size(), m = (int)p.size();
  auto res = vector<int>();
  for (int i = 0; i < n; i++) {
    while (j and s[i] != p[j]) {
      j = nxt[j - 1];
    }
    j += (s[i] == p[j]);
    if (j == m) {
      res.push_back(i - m + 1);
      j = nxt[j - 1];
    }
  }

  return res;
}
```
## manacher
```cpp
vector<int> manacher(string& s) {
  string t = "#";
  for (char& ch : s) {
    t += ch; t += '#';
  }

  int n = t.size(), r = 0, c = 0;
  auto d = vector<int>(n);
  for (int i = 0; i < n; i++) {
    d[i] = i < r ? min(d[2 * c - i], r - i) : 1LL;
    while (i - d[i] >= 0 and i + d[i] < n and t[i - d[i]] == t[i + d[i]]) {
      d[i]++;
    }
    if (i + d[i] > r) c = i, r = i + d[i];
  }

  return d;
}
```

## 字符串哈希
```cpp
using u64 = uint64_t;

u64 BASE = 131;
u64 MOD1 = 1E9 + 7;
u64 MOD2 = 1E9 + 9;

struct StrHash {
  int n = 0;
  vector<u64> h1, h2, p1, p2;
  StrHash() = default;
  StrHash(const string& s): n(s.size()){
    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    p1.assign(n + 1, 1);
    p2.assign(n + 1, 1);
    for (int i = 0; i < n; i ++) {
      h1[i + 1] = (h1[i] * BASE + s[i]) % MOD1;
      h2[i + 1] = (h2[i] * BASE + s[i]) % MOD2;
      p1[i + 1] = p1[i] * BASE % MOD1;
      p2[i + 1] = p2[i] * BASE % MOD2;
    }
  }

  // 1 <= l <= r <= n
  pair<u64, u64> get(int l, int r) {
    if (r > n or l < 1 or r < l) return {-1, -1};
    u64 v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
    u64 v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return pair(v1, v2);
  }
};

// 使用
string s = "abcabc";
StrHash sh(s);
auto v1 = sh.get(0, 3); // "abc"
auto v2 = sh.get(3, 6); // "abc"
assert(v1 == v2);       // 哈希相等，子串相等
```

## AC-auto
```cpp
struct AC_auto {
  vector<array<int, 26>> trie;
  vector<int> fail, cnt, pass;
  vector<int> q;
  int tot;

  AC_auto(int n = 1) : tot(0) {
    trie.assign(n + 1, {});
    fail.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    pass.assign(n + 1, 0);
    q.assign(n + 1, 0);
  }

  void insert(const string &s) {
    int u = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (!trie[u][c]) {
        trie[u][c] = ++ tot;
        if (tot >= (int)trie.size()) {
          trie.resize(tot * 2);
          fail.resize(tot * 2);
          cnt.resize(tot * 2);
          pass.resize(tot * 2);
          q.resize(tot * 2);
        }
      }
      u = trie[u][c];
    }
    cnt[u] ++;
  }

  void build() {
    int p1 = 0, p2 = -1;
    for (int c = 0; c < 26; c ++) {
      int v = trie[0][c];
      if (v) {
        fail[v] = 0;
        q[++ p2] = v;
      }
    }
    while (p1 <= p2) {
      int u = q[p1 ++];
      for (int c = 0; c < 26; c ++) {
        int &v = trie[u][c];
        if (v) {
          fail[v] = trie[fail[u]][c];
          q[++ p2] = v;
        } else {
          v = trie[fail[u]][c];
        }
      }
    }
  }

  int ask(const string &t) {
    int u = 0, res = 0;

    for (char ch : t) {
      u = trie[u][ch - 'a'];
      pass[u] ++;
    }
    for (int i = tot - 1; i >= 0; i --) {
      int u = q[i];
      pass[fail[u]] += pass[u];
    }
    for (int i = 1; i <= tot; i ++) {
      if (cnt[i] and pass[i]) res ++;
    }
    return res;
  }

  void clear() {
    memset(trie[0].data(), 0, 26 * sizeof(int));
    for (int i = 1; i <= tot; i ++) {
      fail[i] = cnt[i] = pass[i] = 0;
      memset(trie[i].data(), 0, 26 * sizeof(int));
    }
    tot = 0;
  }
};
```
# 计算几何

## 一堆工具
```cpp
using ld = long double;
const ld PI = acos(-1.0L);
const ld EPS = 1e-9;

int sgn(ld x) { return (x > EPS) - (x < -EPS); }

// ==================== 点 / 向量 ====================
struct Pt {
  ld x, y;
  Pt() : x(0), y(0) {}
  Pt(ld _x, ld _y) : x(_x), y(_y) {}

  Pt operator+(Pt b) const { return {x + b.x, y + b.y}; }
  Pt operator-(Pt b) const { return {x - b.x, y - b.y}; }
  Pt operator*(ld k) const { return {x * k, y * k}; }
  Pt operator/(ld k) const { return {x / k, y / k}; }
  bool operator==(Pt b) const { return sgn(x - b.x) == 0 && sgn(y - b.y) == 0; }
  bool operator<(Pt b) const {
    return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : sgn(x - b.x) < 0;
  }

  ld dot(Pt b) const { return x * b.x + y * b.y; }    // 点积
  ld cross(Pt b) const { return x * b.y - y * b.x; }  // 叉积（二维外积模长）
  Pt perp() const { return {-y, x}; }                 // 逆时针旋转 90°
  Pt perp2() const { return {y, -x}; }                // 顺时针旋转 90°

  ld len() const { return hypot(x, y); }     // 模长
  ld len2() const { return x * x + y * y; }  // 模长平方
  ld angle() const { return atan2(y, x); }   // 极角 (-PI, PI]

  Pt norm() const {  // 单位向量
    ld l = len();
    return {x / l, y / l};
  }
  Pt rotate(ld t) const {  // 逆时针旋转 t 弧度
    ld c = cos(t), s = sin(t);
    return {x * c - y * s, x * s + y * c};
  }
  Pt rotate(Pt o, ld t) const {
    return o + (*this - o).rotate(t);
  }  // 绕 o 旋转
};

// 叉积（标量）：OA × OB，O 为原点
ld cross(Pt a, Pt b) { return a.cross(b); }
ld cross(Pt a, Pt b, Pt c) { return (b - a).cross(c - a); }

// 点积（标量）
ld dot(Pt a, Pt b) { return a.dot(b); }
ld dot(Pt a, Pt b, Pt c) { return (b - a).dot(c - a); }

// 距离
ld dist(Pt a, Pt b) { return (a - b).len(); }
ld dist2(Pt a, Pt b) { return (a - b).len2(); }

// 向量 a 在 b 上的投影长度（带符号）
ld proj_len(Pt a, Pt b) { return a.dot(b) / b.len(); }

// 极角排序比较器
bool angle_cmp(Pt a, Pt b) {
  if (sgn(a.cross(b)) == 0) return a.len2() < b.len2();
  return sgn(a.cross(b)) > 0;
}
// 用法: sort(p.begin(), p.end(), angle_cmp);  按逆时针排序

// ==================== 直线 / 线段 ====================
struct Line {
  Pt a, b;  // a -> b
  Line() {}
  Line(Pt _a, Pt _b) : a(_a), b(_b) {}
  Pt dir() const { return b - a; }          // 方向向量
  ld length() const { return dist(a, b); }  // 线段长度
};

// 点到直线的垂足
Pt project_to_line(Pt a, Pt b, Pt c) {
  Pt ab = b - a;
  return a + ab * ab.dot(c - a) / ab.len2();
}

// 点关于直线的对称点
Pt reflect(Pt a, Pt b, Pt c) { return project_to_line(a, b, c) * 2 - c; }

// 点到直线距离
ld dist_to_line(Pt a, Pt b, Pt c) { return abs(cross(a, b, c)) / dist(a, b); }

// 点到线段距离
ld dist_to_segment(Pt a, Pt b, Pt c) {
  if (sgn(dot(a, b, c)) <= 0) return dist(a, c);  // c 在 a 左侧
  if (sgn(dot(b, a, c)) <= 0) return dist(b, c);  // c 在 b 右侧
  return dist_to_line(a, b, c);                   // 垂足在线段上
}

// 点到线段的最近点
Pt closest_on_segment(Pt a, Pt b, Pt c) {
  Pt ab = b - a;
  ld t = clamp(dot(c - a, ab) / ab.len2(), 0.0L, 1.0L);
  return a + ab * t;
}

// 点是否在线段上
bool on_segment(Pt a, Pt b, Pt c) {
  return sgn(cross(a, b, c)) == 0 && sgn(dot(a, b, c)) >= 0 &&
         sgn(dot(b, a, c)) >= 0;
}

// 两直线交点（假设不平行/不重合）
Pt line_intersection(Pt a, Pt b, Pt c, Pt d) {
  Pt u = a - c, v = b - a, w = d - c;
  ld t = w.cross(u) / v.cross(w);
  return a + v * t;
}

// 两直线交点（表示成 a + t*(b-a), c + s*(d-c)）
pair<ld, ld> line_intersection_params(Pt a, Pt b, Pt c, Pt d) {
  Pt u = a - c, v = b - a, w = d - c;
  ld den = v.cross(w);
  ld t = w.cross(u) / den;
  ld s = v.cross(u) / den;
  return {t, s};
}

// 两线段是否相交（严格: 端点算相交）
bool segments_intersect(Pt a, Pt b, Pt c, Pt d) {
  if (on_segment(c, d, a) || on_segment(c, d, b) || on_segment(a, b, c) ||
      on_segment(a, b, d))
    return true;
  return sgn(cross(a, b, c)) * sgn(cross(a, b, d)) < 0 &&
         sgn(cross(c, d, a)) * sgn(cross(c, d, b)) < 0;
}

// 两直线是否平行
bool lines_parallel(Pt a, Pt b, Pt c, Pt d) {
  return sgn((b - a).cross(d - c)) == 0;
}

// 两直线是否重合
bool lines_collinear(Pt a, Pt b, Pt c, Pt d) {
  return sgn(cross(a, b, c)) == 0 && sgn(cross(a, b, d)) == 0;
}

// ==================== 圆 ====================
struct Circle {
  Pt o;
  ld r;
  Circle() : o(0, 0), r(0) {}
  Circle(Pt _o, ld _r) : o(_o), r(_r) {}
};

// 三点的外接圆
Circle circumcircle(Pt a, Pt b, Pt c) {
  Pt u = b - a, v = c - a;
  ld D = u.cross(v) * 2;
  if (sgn(D) == 0) return Circle(a, 0);  // 共线
  Pt center;
  center.x = a.x + (u.dot(u) * v.y - v.dot(v) * u.y) / D;
  center.y = a.y + (v.dot(v) * u.x - u.dot(u) * v.x) / D;
  return Circle(center, dist(center, a));
}

// 点与圆的位置关系: 0=外部, 1=内部, 2=边界上
int point_circle_relation(Pt p, Circle c) {
  ld d2 = dist2(p, c.o);
  if (sgn(d2 - c.r * c.r) == 0) return 2;
  return sgn(d2 - c.r * c.r) < 0 ? 1 : 0;
}

// 直线与圆的交点（返回两个交点的 pair）
int line_circle_intersection(Line L, Circle C, Pt& p1, Pt& p2) {
  Pt pr = project_to_line(L.a, L.b, C.o);
  ld d = dist(pr, C.o);
  if (sgn(d - C.r) > 0) return 0;  // 无交点
  if (sgn(d - C.r) == 0) {
    p1 = pr;
    return 1;
  }  // 相切
  ld h = sqrt(max(0.0L, C.r * C.r - d * d));
  Pt dir = L.dir().norm() * h;
  p1 = pr - dir;
  p2 = pr + dir;
  return 2;
}

// 两圆的交点
int circle_intersection(Circle c1, Circle c2, Pt& p1, Pt& p2) {
  ld d = dist(c1.o, c2.o);
  if (sgn(d) == 0) {                       // 同心
    if (sgn(c1.r - c2.r) == 0) return -1;  // 重合
    return 0;
  }
  if (sgn(d - c1.r - c2.r) > 0 || sgn(d - abs(c1.r - c2.r)) < 0) return 0;
  ld a = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d);
  ld h = sqrt(max(0.0L, c1.r * c1.r - a * a));
  Pt mid = c1.o + (c2.o - c1.o).norm() * a;
  Pt perp = (c2.o - c1.o).perp().norm() * h;
  p1 = mid - perp;
  p2 = mid + perp;
  return sgn(h) == 0 ? 1 : 2;
}

// 点到圆的切线
int tangent_from_point(Pt p, Circle c, Pt& t1, Pt& t2) {
  ld d2 = dist2(p, c.o);
  if (sgn(d2 - c.r * c.r) < 0) return 0;  // p 在圆内
  if (sgn(d2 - c.r * c.r) == 0) {         // p 在圆上
    t1 = p;
    return 1;
  }
  ld d = sqrt(d2);
  ld base_ang = atan2(c.o.y - p.y, c.o.x - p.x);
  ld ang = acos(c.r / d);
  t1 = Pt(p.x + c.r * cos(base_ang + ang), p.y + c.r * sin(base_ang + ang));
  t2 = Pt(p.x + c.r * cos(base_ang - ang), p.y + c.r * sin(base_ang - ang));
  return 2;
}

// 两圆公切线（外公切线 + 内公切线）—— 返回切点对的 pair
int common_tangents(Circle c1, Circle c2, vector<pair<Pt, Pt>>& res) {
  res.clear();
  if (c1.r < c2.r) swap(c1, c2);
  ld d = dist(c1.o, c2.o);
  if (sgn(d) == 0 && sgn(c1.r - c2.r) == 0) return -1;  // 重合
  ld ang = atan2(c1.o.y - c2.o.y, c1.o.x - c2.o.x);
  // 外公切线
  if (sgn(d - abs(c1.r - c2.r)) >= 0) {
    ld a = acos((c1.r - c2.r) / d);
    res.emplace_back(
        Pt(c1.o.x + c1.r * cos(ang + a), c1.o.y + c1.r * sin(ang + a)),
        Pt(c2.o.x + c2.r * cos(ang + a), c2.o.y + c2.r * sin(ang + a)));
    res.emplace_back(
        Pt(c1.o.x + c1.r * cos(ang - a), c1.o.y + c1.r * sin(ang - a)),
        Pt(c2.o.x + c2.r * cos(ang - a), c2.o.y + c2.r * sin(ang - a)));
  }
  // 内公切线
  if (sgn(d - c1.r - c2.r) >= 0) {
    ld a = acos((c1.r + c2.r) / d);
    res.emplace_back(
        Pt(c1.o.x + c1.r * cos(ang + a), c1.o.y + c1.r * sin(ang + a)),
        Pt(c2.o.x - c2.r * cos(ang + a), c2.o.y - c2.r * sin(ang + a)));
    res.emplace_back(
        Pt(c1.o.x + c1.r * cos(ang - a), c1.o.y + c1.r * sin(ang - a)),
        Pt(c2.o.x - c2.r * cos(ang - a), c2.o.y - c2.r * sin(ang - a)));
  }
  return res.size();
}

// 两圆相交面积
ld circle_intersection_area(Circle c1, Circle c2) {
  ld d = dist(c1.o, c2.o);
  if (sgn(d - c1.r - c2.r) >= 0) return 0;
  if (sgn(c1.r - c2.r - d) >= 0 || sgn(c2.r - c1.r - d) >= 0)  // 包含
    return PI * min(c1.r, c2.r) * min(c1.r, c2.r);
  ld a1 = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  ld a2 = acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));
  return c1.r * c1.r * (a1 - sin(2 * a1) / 2) +
         c2.r * c2.r * (a2 - sin(2 * a2) / 2);
}

// ==================== 多边形 ====================
using Polygon = vector<Pt>;

// 多边形面积（带符号：逆时针正，顺时针负）
ld polygon_area(const Polygon& poly) {
  ld area = 0;
  int n = sz(poly);
  for (int i = 0; i < n; i++) area += poly[i].cross(poly[(i + 1) % n]);
  return area / 2;
}

// 多边形周长
ld polygon_perimeter(const Polygon& poly) {
  ld p = 0;
  int n = sz(poly);
  for (int i = 0; i < n; i++) p += dist(poly[i], poly[(i + 1) % n]);
  return p;
}

// 多边形重心
Pt polygon_centroid(const Polygon& poly) {
  Pt c(0, 0);
  ld area = 0, total = 0;
  int n = sz(poly);
  for (int i = 0; i < n; i++) {
    area = poly[i].cross(poly[(i + 1) % n]);
    c.x += (poly[i].x + poly[(i + 1) % n].x) * area;
    c.y += (poly[i].y + poly[(i + 1) % n].y) * area;
    total += area;
  }
  total /= 2;
  return {c.x / (6 * total), c.y / (6 * total)};
}

// 点与多边形位置关系: 1=内部, 0=边上, -1=外部 (winding number)
int point_in_polygon(const Polygon& poly, Pt p) {
  int n = sz(poly), wn = 0;
  for (int i = 0; i < n; i++) {
    if (on_segment(poly[i], poly[(i + 1) % n], p)) return 0;
    if (poly[i].y <= p.y) {
      if (poly[(i + 1) % n].y > p.y &&
          sgn(cross(poly[i], poly[(i + 1) % n], p)) > 0)
        wn++;
    } else {
      if (poly[(i + 1) % n].y <= p.y &&
          sgn(cross(poly[i], poly[(i + 1) % n], p)) < 0)
        wn--;
    }
  }
  return wn ? 1 : -1;
}

// 判断多边形顶点顺序是否逆时针
bool is_ccw(const Polygon& poly) { return sgn(polygon_area(poly)) > 0; }

// 凸包 (Andrew's monotone chain)
Polygon convex_hull(vector<Pt> pts) {
  if (sz(pts) <= 1) return pts;
  sort(pts.begin(), pts.end());
  Polygon hull;
  for (int t = 0; t < 2; t++) {
    int base = sz(hull);
    for (Pt p : pts) {
      while (sz(hull) - base >= 2 &&
             sgn((hull.back() - hull[sz(hull) - 2]).cross(p - hull.back())) <=
                 0)
        hull.pop_back();
      hull.push_back(p);
    }
    hull.pop_back();
    reverse(pts.begin(), pts.end());
  }
  return hull;
}

// 旋转卡壳：凸多边形直径（最远点对距离）
ld rotating_calipers(const Polygon& hull) {
  int n = sz(hull);
  if (n <= 2) return dist(hull[0], hull[n - 1]);
  ld ans = 0;
  for (int i = 0, j = 1; i < n; i++) {
    while (sgn(abs(cross(hull[(i + 1) % n], hull[(j + 1) % n], hull[i]))) >
           sgn(abs(cross(hull[(i + 1) % n], hull[j], hull[i])))) {
      j = (j + 1) % n;
    }
    ans = max(ans, dist(hull[i], hull[j]));
  }
  return ans;
}

// 凸多边形最短距离（两凸包之间）
ld convex_polygon_distance(const Polygon& p, const Polygon& q) {
  // 省略实现，需要旋转卡壳的两个多边形版本
  return 0;
}

// ==================== 半平面交 ====================
// 直线 ax+by+c≥0 的半平面，法向量指向内侧
struct HalfPlane {
  Pt a, b;  // 有向直线 a -> b，左半平面
  HalfPlane() {}
  HalfPlane(Pt _a, Pt _b) : a(_a), b(_b) {}
  Pt dir() const { return b - a; }
  bool contains(Pt p) const {
    return sgn(cross(a, b, p)) <= 0;
  }  // ≤0 是左半平面
};

Pt hpi_intersection(HalfPlane u, HalfPlane v) {
  return line_intersection(u.a, u.b, v.a, v.b);
}

bool hpi_cmp(HalfPlane u, HalfPlane v) {
  ld a1 = u.dir().angle(), a2 = v.dir().angle();
  if (sgn(a1 - a2) == 0) return sgn(cross(u.a, u.b, v.b)) < 0;
  return a1 < a2;
}

vector<Pt> half_plane_intersection(vector<HalfPlane> hps) {
  sort(hps.begin(), hps.end(), hpi_cmp);
  deque<HalfPlane> dq;
  deque<Pt> pts;
  for (auto hp : hps) {
    if (!dq.empty() && sgn(dq.back().dir().angle() - hp.dir().angle()) == 0)
      continue;
    while (sz(pts) >= 2 && !hp.contains(pts.back())) {
      dq.pop_back();
      pts.pop_back();
    }
    while (sz(pts) >= 2 && !hp.contains(pts.front())) {
      dq.pop_front();
      pts.pop_front();
    }
    if (!dq.empty()) pts.push_back(hpi_intersection(dq.back(), hp));
    dq.push_back(hp);
  }
  while (sz(pts) >= 2 && !dq.front().contains(pts.back())) {
    dq.pop_back();
    pts.pop_back();
  }
  while (sz(pts) >= 2 && !dq.back().contains(pts.front())) {
    dq.pop_front();
    pts.pop_front();
  }
  pts.push_back(hpi_intersection(dq.back(), dq.front()));
  return vector<Pt>(pts.begin(), pts.end());
}

// ==================== 闵可夫斯基和 ====================
Polygon minkowski_sum(const Polygon& a, const Polygon& b) {
  int n = sz(a), m = sz(b), i = 0, j = 0;
  // 找到起始点（最低最左）
  Pt s = a[0] + b[0];
  Polygon res = {s};
  while (i < n || j < m) {
    if (j == m ||
        (i < n &&
         sgn((a[(i + 1) % n] - a[i]).cross(b[(j + 1) % m] - b[j])) >= 0))
      s = s + a[(i + 1) % n] - a[i], i++;
    else
      s = s + b[(j + 1) % m] - b[j], j++;
    if (i == n && j == m) break;
    res.push_back(s);
  }
  return res;
}

// ==================== 极角排序 / 最近点对 ====================
// 二维最近点对（分治 O(n log n)）
pair<Pt, Pt> closest_pair(vector<Pt> pts) {
  sort(pts.begin(), pts.end());
  set<Pt, decltype([](Pt a, Pt b) { return sgn(a.y - b.y) < 0; })> cand;
  ld best = 1e18;
  pair<Pt, Pt> ans;
  for (int i = 0, l = 0; i < sz(pts); i++) {
    while (sgn(pts[i].x - pts[l].x - best) > 0) cand.erase(pts[l++]);
    auto lo = cand.lower_bound(Pt(pts[i].x, pts[i].y - best));
    auto hi = cand.upper_bound(Pt(pts[i].x, pts[i].y + best));
    for (auto it = lo; it != hi; ++it) {
      ld d = dist(pts[i], *it);
      if (sgn(d - best) < 0) {
        best = d;
        ans = {pts[i], *it};
      }
    }
    cand.insert(pts[i]);
  }
  return ans;
}

// ==================== 实用工具 ====================
// 三点共线
bool collinear(Pt a, Pt b, Pt c) { return sgn(cross(a, b, c)) == 0; }

// 三角形面积
ld triangle_area(Pt a, Pt b, Pt c) { return abs(cross(a, b, c)) / 2; }

// 向量 a 在 b 的左侧/右侧
bool left_of(Pt a, Pt b, Pt p) { return sgn(cross(a, b, p)) > 0; }
bool right_of(Pt a, Pt b, Pt p) { return sgn(cross(a, b, p)) < 0; }

// 向量夹角（0 到 PI）
ld angle_between(Pt a, Pt b) {
  return acos(max(-1.0L, min(1.0L, a.dot(b) / (a.len() * b.len()))));
}

// 三角形重心 / 内心 / 垂心 / 外心
Pt centroid(Pt a, Pt b, Pt c) { return (a + b + c) / 3; }
Pt incenter(Pt a, Pt b, Pt c) {
  ld la = dist(b, c), lb = dist(c, a), lc = dist(a, b);
  return (a * la + b * lb + c * lc) / (la + lb + lc);
}
Pt orthocenter(Pt a, Pt b, Pt c) {
  return a + b + c - circumcircle(a, b, c).o * 2;
}

// 曼哈顿距离 → 切比雪夫变换
//  曼哈顿: |x1-x2| + |y1-y2|  ->  令 (x', y') = (x+y, x-y)
//  切比雪夫: max(|x1-x2|, |y1-y2|)  ->  (x', y') = (x, y)
Pt manhattan_to_chebyshev(Pt p) { return {p.x + p.y, p.x - p.y}; }
Pt chebyshev_to_manhattan(Pt p) { return {(p.x + p.y) / 2, (p.x - p.y) / 2}; }
```

# vscode 配置调试

## launch.json 初始化配置
 
launch 是调试程序 gdb 读取的参数文件
点击右侧调试中的 建立 launch.json, 选择 gdb 启动
program 是你编译出来的 exe 的位置, 所以要用 tasks 里面 -o 的文件地址
agrs 是可以进行配置输入输出的参数, 注意, 参数之间是独立的字符串, 要用 逗号 隔开
例子: 
```json
"program": "${workspaceFolder}/bin\\${fileBasenameNoExtension}.exe" ,
"args": [
  "<","'${workspaceFolder}/file/in'",
  ">","'${workspaceFolder}/file/out'",
  "2>","'${workspaceFolder}/file/err'",
],
```
## tasks.json

tasks 是编译器读取的 参数文件, 负责编译
ctrl + shift + b 点击页面上的齿轮进行 tasks.json 的新建
```json
"args": [
  "-fdiagnostics-color=always",
  "-g",
  "${file}",
  "-o",
  "${workspaceFolder}/bin\\${fileBasenameNoExtension}.exe"
],
```
这些都是你熟悉的编译参数