// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 676767677; 
const int N = 2e5 + 10;


    
void solve() { 

  int n, m; cin >> n >> m ;
  vector<int> b(n + 1);
  for(int i = 1 ; i <= n ; i += 1) cin >> b[i];

  vector<int> buckle(n + 1);
  for(int i = 1 ; i <= n ; i ++) {
    buckle[b[i]] ++; 
  } 

  for(int i = 1 ; i <= m - 1 ; i ++ ) buckle[i] += buckle[i - 1];
  vector<vector<int>> tim(m);
  for(int i = 1 ; i <= n ; i ++ ) tim[b[i]].push_back(i);

  int ans = 1; 
  map<int, int> mp;
  for(int i = 0 ; i < m ; i ++ ) {
    int temp = 0;
    if ( i ) {

      for(const auto &v : tim[i]) if (mp[v - 1] || mp[v + 1]) {
        int temp = buckle[b[i] - 1];
        int mn = min(b[v - 1], b[v + 1]);
        if (mn < b[v] - 1) temp = 

      } else {cout << 0 << '\n'; return; }

    } else {
      for(const auto &a : tim[0]) mp[a] = 1;
    }
    (ans *= t)
  }


  cout << ans << endl; 

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

