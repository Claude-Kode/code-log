// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, m, k; cin >> n >> m >> k;
  cout << "OUTPUT: " << n << ' ' << m << ' ' << k << endl; 
  if (m <= 1) {cout << (n == 1 ? 1 : 2) << endl; return;}
  m --;
  int ans = 2;
  int l = k - 1, r = n - k + 1;

  int lst = 0;
  if (l > r) lst = k - 1;
  else lst = k + 1;
  if (k > lst) swap(k, lst);
  r = max(0LL, n - lst);
  l = max(0LL, k - 1);

  // cout << "K: " << k << ' ' << "lst: " << lst << endl; 
  // cout << "L: " << l << " R: " << r << endl; 

  ans += min(r, m);
  ans += min(l, m);
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
    cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}