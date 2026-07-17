#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

// 直接挑选最度数最小的三个节点 不记录即可

void solve1() {
  int n; cin >> n;
  vector<vector<int>> g(n + 1);
  vector<int> d(n + 1);
  int r = 0;
  for (int i = 1; i < n; i ++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    d[u] ++; d[v] ++;
  }

  for (int i = 1; i <= n; i ++) {
    if (d[i] == 1) {
      r = i;
      break;
    }
  }

  vector<int> vis(n + 1);
  queue<int> q;
  q.push(g[r].back());
  vis[r] = 1;

  vector<int> ans;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = 1;
    ans.push_back(u);
    for (auto &v : g[u]) {
      if (vis[v]) continue;
      q.push(v);
    }
  }

  cout << n - 3 <<"\n";
  for (int i = 0; i < n - 3; i ++) {
    cout << ans[i] << " \n"[i == n - 4];
  }
}

void solve2() {
  int n, m; cin >> n >> m;

  // cout << n << ' ' << m << "\n";

  vector<int> a(n + 1, 0), d(n + 1, 1);
  for (int i = 2; i <= m + 1; i ++) {
    cin >> a[i]; 
  }

  d[2] = a[2] - 1;

  vector<array<int, 2>> edges;
  edges.push_back({1, 2});

  int cur = 2;
  for (int i = 3; i <= n; i ++) {
    d[i] = a[i] - a[i - 1] + 1;
    while (!d[cur]) cur ++;
    d[cur] --;
    edges.push_back({cur, i});
  }

  for (auto &[u, v] : edges) {
    cout << u << ' ' << v << "\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1;
  cin >> tt;
  if (tt == 1) {
    solve1();
  } else {
    solve2();
  }

  return 0;
}