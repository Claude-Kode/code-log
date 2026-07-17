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

  int x, y; cin >> x >> y;
  if (y < x) cout << "NO" << endl; 
  else if (x == 0 && !(y & 1)) cout << "NO" << endl; 
  else {
    cout << "YES" << endl; 
    int rem = y - x;
    if (rem & 1) {
      for(int i = 1 ; i <= 2 * x; i ++ ) {
        cout << i << ' ' << i + 1 << endl;  
      }

      for(int i = 1 ; i <= rem - 1; i ++ ) cout << 2 * x + 1 << ' ' << 2 * x + 1 + i << endl; 
    } else {
      for(int i = 1 ; i <= 2 * x - 1; i ++ ) {
        cout << i << ' ' << i + 1 << endl;  
      }
      for(int i = 1 ; i <= rem; i ++) cout << 2 * x << ' ' << 2 * x + i<< endl; 
    }
  }


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
