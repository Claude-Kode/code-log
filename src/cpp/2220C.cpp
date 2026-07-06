// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 1e5 + 10;

void solve() { 
  int p, q; cin >> p >> q;
  int s = 2 * p + q, lim = sqrt(s);
  for(int i = 1; i <= s; i ++) if ((s - i) % (i + i + 1) == 0) {
    int j = (s - i) / (i + i + 1);
    if (j < 1) continue;
    if (j * i <= 2 * p) {
      cout << i << ' ' << j << endl; 
      return; 
    }
  }

  cout << -1 << endl;
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

  int tt, CNT = 0; cin >> tt;
  while(tt-- && ++CNT) solve();
  
  return 0;
}