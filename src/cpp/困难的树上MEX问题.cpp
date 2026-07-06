// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n; 
vector<int> dep, vec, ans;
vector<vector<int>> adj, fa;

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

void solve() { 
  cin >> n;
  adj.assign(n + 1, {}); dep.assign(n + 1, 0);
  fa.assign(__lg(n) + 1, vector<int>(n + 1, 0));
  vec.assign(n + 1, 0);
  ans.assign(n + 1, 0);

  unordered_map<int, int> nod;
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
    nod[vec[i]] = i;
  }

  for(int i = 1; i < n; i ++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0); init();

  ans[nod[0]] = 1;

  int mn = nod[0], mn_dep = dep[nod[0]], mx = nod[0], mx_dep = dep[nod[0]];
  auto work = [&](int L, int v) -> void {
    if (mn_dep > dep[L]) mn_dep = dep[L], mn = L;
    if (mx_dep < dep[L]) mx_dep = dep[L], mx = L;
    if (mx_dep < dep[v]) mx_dep = dep[v], mx = v;
  };

  for(int i = 0; i < n - 1; i ++) {
    // int u = mn, 
    int v = nod[i + 1];
    // int L = lca(u, v);
    int u1 = mn, u2 = mx;
    int L1 = lca(mn, v);
    int L2 = lca(mx, v);
    // 每次判断是判断是不是和深度最低的是一起的

    bool f = (
      L1 == mn && L2 == v or
      L1 == mn && L2 == mx or
      L1 == v && L2 == v
    );
    if (!f) break;
    work(L1, v);
    // cout << "val: " << i << ' ' << i + 1 << ' ' << L1 << endl;
    // cout << "node: " << mn << ' ' << mx << ' ' << v << endl;
    ans[mn] = i + 2;
  } 

  for(int i = mx; fa[0][i]; i = fa[0][i]) {
    ans[fa[0][i]] = max(ans[fa[0][i]], ans[i]);
  }

  for(int i = 1; i <= n; i ++) {
    cout << ans[i] << " \n"[i == n];
  }
}

/*
对于 mex 问题而言 可能就是继承下面的最优路径
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}