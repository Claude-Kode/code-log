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
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i];

  int mn = vec[1], ans = 0, mnv = INT_MAX;
  for(int i = 2; i <= n; i ++) if (vec[i] > mn && vec[i] < mnv){
    ans ++; mnv = min(mnv, vec[i]);
  } else mn = min(mn, vec[i]);

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
