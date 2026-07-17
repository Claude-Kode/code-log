#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long 

class DSU {
 public: 
  vector<int> f, siz, dis;
  DSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0LL);
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
    int fx = find(x), fy = find(y);
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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  map<int, int> spe;
  for (int i = 1; i <= k; i ++) {
    int v; cin >> v;
    spe[v] = 1;
  }

  vector<array<int, 3>> edges;
  for (int i = 1; i <= m; i ++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  
  vector<array<int, 3>> edges1, edges2;
  for (const auto&[u, v, w] : edges) {
    if (spe[u] or spe[v]) {
      edges2.push_back({u, v, w});
    } else {
      edges1.push_back({u, v, w});
    }
  }

  sort(edges1.begin(), edges1.end(), [&](const auto &a, const auto &b){
    return a[2] < b[2];
  });

  sort(edges2.begin(), edges2.end(), [&](const auto &a, const auto &b){
    return a[2] < b[2];
  });

  DSU dsu(n + 1);
  int ans = 0, cnt = 1;
  for (auto &[u, v, w] : edges1) {
    if (dsu.same(u, v)) {
      continue;
    } else {
      dsu.merge(u, v);
      ans += w;
      cnt ++;
    }
    if (cnt == n - k) break;
  }
  
  if (cnt < n - k) {
    cout << -1 << '\n';
    return;
  }

  for (auto &[u, v, w] : edges2) {
    if (n > 2 and spe[u] + spe[v] > 1 or dsu.same(u, v)) {
      continue;
    } else {
      dsu.merge(u, v);
      ans += w;
      cnt ++;
    }
    if (cnt == n) break;
  }

  if (cnt < n) {
    cout << -1 << "\n";
    return;
  }

  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1; 
  cin >> tt;
  while (tt --) {
    solve();
  }

  return 0;
}