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

const int mod = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i ++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<array<int, 2>> dp(n + 1, {1, 1});
  auto dfs = [&](auto&& sef, int u, int f) -> void {
    for (auto& v : adj[u]) {
      if (v == f) continue;
      sef(sef, v, u);

      int sum0 = dp[v][0];
      int sum1 = dp[v][1];

      if (vec[v] == 1) {
        dp[u][0] = dp[u][0] * sum0 % mod;
        dp[u][1] = dp[u][1] * (sum0 + sum1) % mod;
      } else {
        dp[u][0] = dp[u][0] * (sum0 + sum1) % mod;
        dp[u][1] = dp[u][1] * (sum0 + sum1) % mod;
      }

      // dp[u][1] = dp[u][1] * (sum0 + sum1) % mod;
    }
  };

  dfs(dfs, 1, 0);
  if (vec[1] == 1) {
    cout << (dp[1][0] % mod + dp[1][1] % mod) % mod << '\n';
  } else {
    cout << dp[1][0] % mod << '\n';
  }
}

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
