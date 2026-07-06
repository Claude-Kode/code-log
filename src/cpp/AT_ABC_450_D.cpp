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

  int n, k; cin >> n >> k;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i]; 
    (vec[i] += k) %= k;
  }

  sort(vec.begin() + 1, vec.end());
  int mx = *max_element(vec.begin() + 1, vec.end());
  int mn = *min_element(vec.begin() + 1, vec.end());
  int ans = mx - mn;

  cout << ans << endl; 

}

/*

*/

int_fast32_t main() {
  
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