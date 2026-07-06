#ifdef __GNUC__
  #pragma GCC optimize("fast-math")
  #pragma GCC optimize("Ofast, unroll-loops = full")
  #pragma GCC optimize("avx, avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; i ++) {
    int temp; cin >> temp;
    adj[temp].push_back(i);
  }

  int ans = 0;
  auto dfs = [&](auto && sef, int u, int f) -> int {
    if (adj[u].empty()) {
      return 0;
    }
    int res = INT_MAX;
    for (int& v : adj[u]) {
      int temp = 1 + sef(sef, v, u);
      res = min(res, temp);
      ans = max(ans, temp);
    }

    return res;
  };

  dfs(dfs, 1, 0);
  cout << ans << "\n";

  // vector<int> dis(n + 1);
  // queue<int> q;
  // q.push(1);
  // while (!q.empty()) {
  //   auto u = q.front();
  //   q.pop();
  //   for (int &v : adj[u]) {
  //     dis[v] = dis[u] + 1;
  //     q.push(v);
  //   }
  // }

  // vector<int> v;
  // for (int i = 1; i <= n; i ++) {
  //   if (adj[i].empty()) {
  //     v.push_back(dis[i]);
  //   }
  // }
  // sort(v.begin(), v.end());
  // if (v.size() > 1) {
  //   cout << (v[0] + v[1] + 1) / 2 << "\n";
  // } else {
  //   cout << v[0] << "\n";
  // }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  cin >> tt;
  while (tt --) {
    solve();
  }
}