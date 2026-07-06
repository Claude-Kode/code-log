// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  int n; cin >> n; 
  vector<int> a(n + 1), b(n + 1), c(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> a[i] >> b[i] >> c[i];
    // cout << a[i] << ' ' << b[i] << ' ' << c[i] << endl; 
    if (a[i] <= b[i]) swap(a[i], b[i]);
  } 

  vector<int> vis(n + 1, 0);
  vector<vector<int>> memo(4, vector<int>(4, 0));
  std::function <int(int, int)> dfs = [&](int l, int r) -> int {
    if (l == 0 || r == 0) return 0;
    if (memo[l][r]) return memo[l][r];

    // cerr << l << ' ' << r << endl; 

    int &res = memo[l][r];
    for(int i = 1; i <= n; i ++) if (!vis[i] && l >= a[i] && r >= b[i]) {
      vis[i] = 1;
      int nl = l - a[i], nr = r - b[i];
      // cout << l << ' ' << r << ' ' << nl << ' ' << nr << endl; 
      res = max(res, dfs(max(nl, r), min(nl, r)) + dfs(max(a[i], nr), min(a[i], nr)) + c[i]);
      res = max(res, dfs(max(l, nr), min(l, nr)) + dfs(max(nl, b[i]), min(nl, b[i])) + c[i]);
      vis[i] = 0;
    }
    return res;
  };

  cout << dfs(3, 3) << endl; 
}

/*

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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}



