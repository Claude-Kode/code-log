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

## 自动取模基本类型 : mint
```cpp
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
// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define ckmn(x, y) do { auto _v = (y); if (_v < (x)) (x) = _v; } while(0)
#define ckmx(x, y) do { auto _v = (y); if (_v > (x)) (x) = _v; } while(0)

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else
  #define dbug(...) 
#endif

// REGISTER_REFLECT()

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  int timer = 0, scc_cnt = 0;
  vector<int> low(n + 1), dfn(n + 1), instk(n + 1), scc(n + 1), stk;
  // low, dfn 是 点编号 -> 时间戳
  // 剩下的都是点编号的意义
  auto tarjan = [&](this auto&& tarjan, int u) -> void {
    dfn[u] = low[u] = ++timer;
    stk.push_back(u);
    instk[u] = true;

    for (int& v : g[u]) {
      if (dfn[v] == 0) {
        tarjan(v);
        ckmn(low[u], low[v]);
      } else if (instk[v]) {
        ckmn(low[u], dfn[v]);
      }
    } 

    if (low[u] == dfn[u] and ++scc_cnt) {
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

  for (int i = 1; i <= n; i ++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }

  vector<int> ans(scc_cnt + 1, 0);
  for (int i = 1; i <= n; i ++) {
    ans[scc[i]] += a[i];
  }

  cout << ranges::max(ans);

// 1. 建 DAG
// 你已经知道每个点属于哪个 SCC（scc[i]）。现在把原图的边"重定向"到 SCC 之间：
// // 读图时顺便把边存起来（你现在的代码只是 g[u].push_back(v)，边信息读后就丢了）
// vector<pair<int,int>> edges;    // 加这行
// for (int i = 1; i <= m; i++) {
//     int u, v;
//     cin >> u >> v;
//     g[u].push_back(v);
//     edges.push_back({u, v});    // 加这行
// }

// // tarjan 之后，建 DAG
// vector<vector<int>> dag(scc_cnt + 1);
// for (auto [u, v] : edges) {
//     int x = scc[u], y = scc[v];
//     if (x != y)
//         dag[x].push_back(y);
// }

// 去重（同一个 SCC 之间可能有多条原边，不处理会多跑 DP）
// // ... 见下
// 直观理解：原图的一条边 u→v，如果 u 和 v 缩进不同 SCC，那就变成 SCC(u) → SCC(v)。如果缩进同一个 SCC，这条边就是 SCC 内部的环边，DAG 上不出现在。
// 2. DAG 上 DP
// 这一步的关键是用拓扑序做 DP。Tarjan 的 scc_cnt 编号有一个天然性质：编号大的 SCC 在拓扑序上排在前面。
// 回忆代码：根 u 发现 low[u]==dfn[u] 时，把栈顶到 u 的所有点弹出来，标记为新的 scc_cnt。因为是 DFS 回溯时从叶子往根弹，所以叶子 SCC 编号小，靠近源的 SCC 编号大。
// 这意味着：从 scc_cnt 往 1 遍历，就是 DAG 的拓扑序。
// vector<int> dp(scc_cnt + 1, 0);

// // sum[x] = SCC x 内所有点的权值和（你代码里的 ans[x]）
// // 按逆拓扑序（scc_cnt → 1）DP
// for (int x = scc_cnt; x >= 1; x--) {
//     dp[x] += sum[x];                          // 自己点权和
//     for (int y : dag[x])
//         ckmx(dp[y], dp[x]);                   // 推给邻居
// }
// 或者等价地，正拓扑序拉式 DP：
// vector<int> dp = sum;    // 初始化为各自的 sum
// for (int x = scc_cnt; x >= 1; x--) {
//     for (int y : dag[x])
//         ckmx(dp[y], dp[x] + sum[y]);
// }

// cout << ranges::max(dp);
// 完整改动点（你现有代码上改 3 处）
// ① 读图时存边：edges.push_back({u, v});
// ② tarjan 之后建 dag + 去重：
// vector<vector<int>> dag(scc_cnt + 1);
// for (auto [u, v] : edges) {
//     int x = scc[u], y = scc[v];
//     if (x != y) dag[x].push_back(y);
// }
// // 去重：每个点的邻接表 sort + unique
// for (int i = 1; i <= scc_cnt; i++) {
//     sort(dag[i].begin(), dag[i].end());
//     dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
// }
// ③ DP 替掉 cout << ranges::max(ans)：
// vector<int> dp = ans;   // ans 是你原来算的每个 SCC 的 sum
// for (int x = scc_cnt; x >= 1; x--)
//     for (int y : dag[x])
//         ckmx(dp[y], dp[x] + ans[y]);

// cout << ranges::max(dp);
// }

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}
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
  
  bool merge(int x, int y, int w) {
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
      if (r & 1) res = std::max(res, seg[r ^ 1]);
    }
    return res;
  }
};
```

## 线段树(lazy)
```cpp
template <typename Info, typename Tag>
class SGT {
 public:
  int n;
  vector<Info> seg;
  vector<Tag> tag;

 private:
  void put(int p, int l, int r, const Tag& tg) {
    seg[p].apply(l, r, tg);  
    tag[p] += tg;
  }

  void push(int p, int l, int r) {
    if (tag[p].empty()) return;  
    int m = (l + r) >> 1;
    put(p << 1, l, m, tag[p]);
    put(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = Tag{};
  }

  void pull(int p) {
    seg[p] = seg[p << 1] + seg[p << 1 | 1];  
  }

  void build(int p, int l, int r, const vector<Info>& a) {
    if (l == r) {
      seg[p] = a[l - 1];
    } else {
      int m = (l + r) >> 1;
      build(p << 1, l, m, a);
      build(p << 1 | 1, m + 1, r, a);
      pull(p);
    }
  }

  void set(int p, int l, int r, int L, int R, const Tag& tg) {
    if (L <= l && r <= R) {
      put(p, l, r, tg);
    } else {
      push(p, l, r);
      int m = (l + r) >> 1;
      if (L <= m) set(p << 1, l, m, L, R, tg);
      if (R > m) set(p << 1 | 1, m + 1, r, L, R, tg);
      pull(p);
    }
  }

  Info get(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return seg[p];
    push(p, l, r);
    int m = (l + r) >> 1;
    if (R <= m) return get(p << 1, l, m, L, R);
    if (L > m) return get(p << 1 | 1, m + 1, r, L, R);
    return get(p << 1, l, m, L, R) + get(p << 1 | 1, m + 1, r, L, R);
  }

 public:
  SGT() : n(0) {}

  explicit SGT(int _n) : n(_n) {
    seg.assign(4 * n + 1, Info{});
    tag.assign(4 * n + 1, Tag{});
  }

  explicit SGT(int _n, int _v) : n(_n) {
    seg.assign(4 * n + 1, Info(_v));
    tag.assign(4 * n + 1, Tag(_v));
  }

  void build(const vector<Info>& a) {
    n = a.size();
    seg.assign(4 * n + 1, Info{});
    tag.assign(4 * n + 1, Tag{});
    build(1, 1, n, a);
  }

  void set(int l, int r, const Tag& tg) { 
    set(1, 1, n, l, r, tg); 
  }

  Info get(int l, int r) { 
    return get(1, 1, n, l, r); 
  }
};

struct Tag {
  int v = 0;

  Tag() = default;
  Tag(int _v): v(_v) {}

  Tag& operator+=(const Tag& other) {
    return *this;
  }

  bool empty() const {
    return v == 0;
  } 
};

struct Info {
  int sum = 0;

  Info() = default;
  Info(int _v): sum(_v) {}

  void apply(int l, int r, const Tag& tg);

  Info operator+(const Info& other) const {
    Info res; 
    return res;
  }

  Info& operator+=(const Info& other) {
    return *this;
  }
};

void Info::apply(int l, int r, const Tag& tg)  {

}
```
## 线段树(指针版) 
```cpp

struct SGT {
  SGT *ls, *rs;
  int sum, mx, l, r, mid;
  SGT (int L, int R, const vector<int>& vec) {
    l = L, r = R, mid = (l + r) / 2;
    if (l == r) {
      mx = sum = vec[l];
    } else {
      ls = new SGT(l, mid, vec);
      rs = new SGT(mid + 1, r, vec);
      pull();
    }
  }

  void pull() {
    sum = ls -> sum + rs -> sum;
    mx = std::max(ls -> mx, rs -> mx);
  }

  void mod(int L, int R, int M) {
    if (l > R || r < L || mx < M) {
      return; 
    } else if (l == r) {
      mx = (sum %= M);
    } else {
      ls -> mod(L, R, M);
      rs -> mod(L, R, M);
      pull();
    }
  }

  void set(int L, int R, int V) {
    if (l > R || r < L) {
      return;
    } else if (l == r) {
      mx = sum = V;
    } else {
      ls -> set(L, R, V);
      rs -> set(L, R, V);
      pull();
    }
  }

  int ask(int L, int R) {
    if (l > R || r < L) {
      return 0;
    } else if (L <= l && r <= R) {
      return sum;
    } else {
      return ls -> ask(L, R) + rs -> ask(L, R);
    }
  }
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
```cpp
int n, m; 
vector<int> lb(64);

void add(int x) {
  for(int i = 62; i >= 0; i --) if (x >> i & 1) {
    if (lb[i]) x ^= lb[i];
    else {lb[i] = x; return;}
  }
}

void solve() { 
  lb.assign(64, 0);
  cin >> n >> m;
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    add(u ^ v ^ w);
  }

  int ans = n ^ 1;
  for(int i = 62; i >= 0; i --) { if ((ans >> i & 1) && lb[i]) ans ^= lb[i]; }

  // assert(ans);
  cout << ans << endl; 
}
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
    if (l > r) {cerr << "wrong query" << endl; return; }
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

  int query(string s) {
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

  int query(string s) {
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

## KMP
```cpp
// 构建 next 数组（前缀函数）
// nxt[i] = 模式串 p[0..i] 的最长公共前后缀长度
vector<int> build_nxt(const string &p) {
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

// KMP 匹配，返回所有匹配起点的下标(0-based)
vector<int> kmp_match(const string &s, const string &p) {
  vector<int> res;
  int n = s.size(), m = p.size();
  vector<int> nxt = build_nxt(p);

  for (int i = 0, j = 0; i < n; i++) {
    while (j and s[i] != p[j]) {
      j = nxt[j - 1];
    }
    if (s[i] == p[j]) {
      j++;
    }
    if (j == m) {
      res.push_back(i - m + 1); // 匹配起点
      j = nxt[j - 1];           // 继续找下一个(允许重叠)
    }
  }
  return res;
}
```
## 字符串哈希
```cpp
using u64 = unsigned long long;

u64 BASE = 131;
u64 MOD1 = 1E9 + 7;
u64 MOD2 = 1E9 + 9;

struct StrHash {
  vector<u64> h1, h2, p1, p2;
  StrHash() = default;   
  StrHash(const string& s) { 
    int n = s.size(); 
    h1.assign(n + 1, 0); h2.assign(n + 1, 0);
    p1.assign(n + 1, 0); p2.assign(n + 1, 0);
    for (int i = 0; i < n; i ++) {
      h1[i + 1] = (h1[i] * BASE + s[i]) % MOD1;
      h2[i + 1] = (h2[i] * BASE + s[i]) % MOD2;
      p1[i + 1] = (p1[i] * BASE) % MOD1;
      p2[i + 1] = (p2[i] * BASE) % MOD2;
    }
  }

  // [l, r], 1 <= l <= r <= n
  pair<u64, u64> get(int l, int r) {
    u64 v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
    u64 v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
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

## AC-auto
```cpp
class AC_Auto {
 public: 
  vector<array<int, 26>> ch; // Trie树
  vector<int> cnt, fail;     // cnt:单词结尾标记, fail:失配指针
  int idx = 0;               // 节点编号

 public: 
  AC_Auto(int n) {
    ch.resize(n);
    cnt.resize(n);
    fail.resize(n);
  }

  // 1. 插入模式串
  void insert(string &s) {
    int p = 0;
    for (char c : s) {
      int &v = ch[p][c - 'a'];
      if (!v) v = ++idx;
      p = v;
    }
    cnt[p]++; 
  }

  // 2. 构建fail指针 (BFS)
  void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++)
      if (ch[0][i]) q.push(ch[0][i]);
  
    while (q.size()) {
      int u = q.front(); q.pop();
      for (int i = 0; i < 26; i++) {
        int &v = ch[u][i];
        if (v) {
          fail[v] = ch[fail[u]][i]; // 核心: KMP思想的体现
          q.push(v);
        } else {
          v = ch[fail[u]][i]; // 路径压缩(类似并查集)
        }
      }
    }
  }

  // 3. 查询文本串
  int query(string &s) {
    int p = 0, res = 0;
    for (char c : s) {
      p = ch[p][c - 'a'];
      for (int j = p; j && cnt[j] != -1; j = fail[j]) {
        res += cnt[j];
        cnt[j] = -1; // 防止重复计算（视题目要求而定）
      }
    }
    return res;
  }
};
```