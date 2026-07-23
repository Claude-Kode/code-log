// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else
  #define dbug(...)
#endif

// REGISTER_REFLECT()

auto popcnt = __builtin_popcountll;

// __builtin_popcountll();

const int N = 1e7;
vector<int> pr;
vector<int> vis(N + 1, 0);

void prime(int n) {
  vis[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr.push_back(i);
    for (const auto& j : pr) {
      if (i * j > n) break;
      vis[i * j] = 1;
      if (i % j == 0) break;
    }
  }
}

map<int, int> cal_fac(int n) {
  map<int, int> res;
  for (int& p : pr) {
    if (p * p > n) break;
    while (n % p == 0) {
      res[p]++;
      n /= p;
    }
  }
  if (n > 1) res[n]++;
  return res;
}

int cal(int l, int r, int i) { 
  return r / i - (l - 1) / i; 
}

void solve() {
  int l, r, n;
  cin >> l >> r >> n;
  int r1 = r;
  if (n > 2000 and n - r < 100) {
    r = n - 100;
  }

  auto fac = cal_fac(n);
  vector<int> facs;
  for (auto& [f, _] : fac) {
    facs.push_back(f);
  }

  auto pop = [&](int x) -> int {
    int res = 0;
    for (int i = 0; i < 60; i++) {
      res += (x >> i & 1);
    }
    return res;
  };

  int ans = r - l + 1;
  int b = (int)facs.size();
  for (int i = r + 1; i <= r1; i++) {
    if (gcd(i, n) == 1LL) {
      ans++;
      continue;
    }

    bool f = 0;
    for (int j = i + 1; j < n; j++) {
      f |= (gcd(i, j) == 1LL and gcd(j, n) == 1LL);
    }

    ans += 2 + f;
  }

  for (int msk = 1; msk < (1 << b); msk++) {
    int f = 1, p = popcount((uint64_t)msk);
    for (int i = 0; i < b; i++) {
      if (msk >> i & 1) {
        f *= facs[i];
      }
    }

    p = (p & 1 ? 1 : -1);
    ans += p * cal(l, r, f);
  }

  cout << ans << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  prime(N);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}