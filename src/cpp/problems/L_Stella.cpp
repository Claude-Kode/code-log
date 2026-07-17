// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int to (char c) {
  if (c == 'O') return 10;
  if (c == 'B') return 9;
  if (c == 'A') return 8;
  if (c == 'F') return 7;
  if (c == 'G') return 6;
  if (c == 'K') return 5;
  if (c == 'M') return 4;
}
    
void solve() { 

  string a, b; cin >> a >> b;
  if (a == b) {
    cout << "same" << endl; 
    return;
  } else {
    int aa = to(a[0]), bb = to(b[0]);
    if (aa > bb) cout << "hotter" << endl; 
    if (aa == bb) {
      if (a[1] < b[1]) cout << "hotter" << endl;  
      if (a[1] > b[1]) cout << "cooler" << endl;  
    }
    if (aa < bb) cout << "cooler" << endl; 
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