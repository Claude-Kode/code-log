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

  string a, b; cin >> a >> b;

  // cout << a << endl << b << endl; 

  int n = a.size();
  for(int i = 0; i < n; i ++) if (a[i] == b[i] && a[i] == '0') {
    // cout << i << ' ';
    for(int j = i + 1; j < n; j ++) {
      if (a[j] != b[j]) {
        break;
      } 
      if (a[j] == b[j] && a[j] == '1') {
        cout << "YES" << endl; 
        return;
      }
    } 
  }

  cout << "NO" << endl; 

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



