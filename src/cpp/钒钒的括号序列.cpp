// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;



void solve() { 

  int n; cin >> n; 
  vector<vector<int>> son(n + 1, vector<int>(2));
  for(int i = 1; i <= n; i ++) {
    int l, r; cin >> l >> r;
    son[i][0] = l, son[i][1] = r;
  }

  function<string(int)> dfs = [&](int i) -> string {
    if (i == 0) return "";  
    return "(" + dfs(son[i][0]) + ")" + dfs(son[i][1]);
  }; 

  cout << dfs(1) << endl;

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
