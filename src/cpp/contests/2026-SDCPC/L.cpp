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

const int N = 1e6;
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

map<int, int> cal_fac(int n) {
  map<int, int> res;
  for (int& p : pr) {
    if (p * p > n) break;
    while (n % p == 0) { res[p]++; n /= p; }
  }
  if (n > 1) res[n] ++;
  return res;
}

void solve() {
  int a, b, q;
  cin >> a >> b >> q;
  int diff = abs(a - b);
  auto fac = cal_fac(diff);

  auto cal = [&](int a, int i) -> int {
    return (i - a % i) % i;
  };

  // 问题转化成, 对于一个 gcd(a, b) == 1 来说, 如何快速找到
  // gcd(a + k, b + k) == i 的最小 k 
  using pii = pair<int, int>;
  map<int, pii> ans;
  ans[0] = pair(a, b);
  while (fac.size()) {
    int g = 1, k = LLONG_MAX;
    auto [pre, TEMP] = *prev(ans.end());
    auto [cur_a, cur_b] = TEMP;
    // 找最小的 k, 且有 gcd(a + k, b + k) == g
    for (auto &[f, cnt] : fac) {
      int res = cal(cur_a, f);
      if (res < k) {
        k = res; 
        g = f;
      }
    }

    ans[pre + k] = pair((cur_a + k) / g, (cur_b + k) / g);
    if (!--fac[g]) fac.erase(g);
  }

  // dbug(ans);

  for (int i = 1; i <= q; i ++) {
    int k; cin >> k;
    auto it = prev(ans.upper_bound(k));
    int d = k - it -> first;
    int A = it -> second.first + d, 
        B = it -> second.second + d,
        G = __gcd(A, B);
    cout << A / G << ' ' << B / G << "\n";
  }
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