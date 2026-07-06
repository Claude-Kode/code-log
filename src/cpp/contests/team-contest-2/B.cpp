#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> vec(n + 1);
  vector<int> sum(n + 1);
  for (int i = 1; i <= n; i ++) {
    int f; cin >> f >> vec[i];
    adj[f].push_back(i);
  }

  auto dfs = [&](auto&& sef, int u) -> void {
    if (adj[u].empty()) {
      sum[u] = vec[u];
    } else {
      for (int& v : adj[u]) {
        sef(sef, v);
        sum[u] += sum[v];
      }
    }
  };

  dfs(dfs, 0);

  // cout << sum[0] << "\n";

  if (sum[0] > 2200) {
    cout << "NO" << "\n";
    return;   
  }

  vector<int> v1, v2;
  for (int i = 1; i <= n; i ++) {
    if (adj[i].empty()) continue;
    v1.push_back(sum[i]);
    v2.push_back(vec[i]);
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  for (int i = 0; i < v1.size(); i ++) {
    if (v1[i] > v2[i]) {
      cout << "NO" << "\n";
      return;
    }
  }

  cout << "YES" << "\n";
}

int32_t main() {
  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }
  return 0;
}