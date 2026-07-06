// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 10007; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 

  vector<int> w(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> w[i];
  }

  auto calc = [&](this auto&& dfs, int u) -> array<int, 2> {
    int s1 = 0, s2 = 0, mx1 = 0, mx2 = 0;
    for(const auto &v : adj[u]) {
      s1 += w[v]; s2 = (s2 + w[v] * w[v]) % mod;
      if (w[v] > mx1) mx2 = mx1, mx1 = w[v]; 
      else if (w[v] > mx2) mx2 = w[v];
    }
    return {(s1 * s1 + mod - s2) % mod, mx1 * mx2};
  };

  int ans = 0, mx = 0;
  for(int i = 1; i <= n; i ++) {
    auto f = calc(i);
    (ans += f[0]) %= mod;
    mx = max(mx, f[1]);
  }

  cout << mx << ' ' << ans << endl; 
}

/*
从菊花图入手优化公式即可
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}