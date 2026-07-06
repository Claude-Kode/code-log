// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif



int fp(int x, int p, int mod) {
  int res = 1, base = x;
  while (p) {
    if (p & 1) (res *= base) %= mod;
    (base *= base) %= mod, p >>= 1;
  }
  return res;
}

int inv(int x, int mod) { return fp(x, mod - 2, mod); }

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

const int mod = 998244353;
int mint::mod = mod;
const int inv_2 = inv(2, mod);
const int inv_6 = inv(6, mod);

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<mint> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  vector<int> cnt(n + 1);
  vector<vector<int>> sons(n + 1);
  auto dfs = [&](auto&& sef, int u, int f) -> void {
    sons[f].push_back(u);
    for (const int& v : adj[u]) {
      if (v != f) {
        sef(sef, v, u);
        cnt[u] += (1 + cnt[v]);
      }
    }
  };

  dfs(dfs, 1, 0);

  auto q = [](mint i) -> mint { 
    return i * i;
  };

  auto c = [](mint i) -> mint { 
    return i * i * i;
  };

  vector<mint> sum(n + 1), qsum(n + 1), csum(n + 1);
  auto calc = [&](auto&& sef, int u) -> void {
    sum[u] = vec[u];
    qsum[u] = q(vec[u]);
    csum[u] = c(vec[u]);
    for (const int& v : sons[u]) {
      sef(sef, v);
      sum[u] = sum[u] + sum[v];
      qsum[u] = qsum[u] + qsum[v];
      csum[u] = csum[u] + csum[v];
    }
  };

  calc(calc, 1);

  auto work2 = [&](mint x, mint y) -> mint {
    return q(x) - y * inv_2;
  };

  auto work3 = [&](mint x, mint y, mint z) -> mint {
    return c(x) - 3 * x * y + 2 * z * inv_6;
  };

  mint ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] < 2) continue;
    mint res1 = work2(sum[i] - vec[i], qsum[i] - q(vec[i]));
    for (const int& j : sons[i]) {
      if (cnt[j] < 1) continue;
      mint tmp = work2(sum[j], qsum[j]);
      res1 -= tmp;
    }

    ans += vec[i] * res1;

    if (cnt[i] < 3) continue;
    mint res2 = work3(sum[i] - vec[i], qsum[i] - q(vec[i]), csum[i] - c(vec[i]));
    mint other = sum[i] - vec[i];
    for (const int& j : sons[i]) {
      if (cnt[j] < 1) continue;
      mint tmp = work2(sum[j], qsum[j]) * (other - sum[j]);
      res2 -= tmp;
    }

    for (const int& j : sons[i]) {
      if (cnt[j] < 2) continue;
      mint tmp = work3(sum[j], qsum[j], csum[j]);
      res2 -= tmp;
    }

    ans += res2;
  }

  cout << ans << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}
