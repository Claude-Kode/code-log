// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

string bit(int x) {
  return bitset<6>(x).to_string() ;
  // str.substr(64 - __lg(n) - 1);
}

void solve() { 

  int n, k; cin >> n >> k;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n;i ++ ) {
    cin >> vec[i];
  }

  // cout << bit(k) << endl; 

  int len = __lg(k), ans = 0;
  bool flag = false; 
  for(int i = len; i >= 0 ; i -- ) {
    int d = (k >> i & 1);
    // cout << d ; 
    if (d == 0 && !flag) continue;
    else {
      int cnt1 = 0, cnt0 = 0;
      for(int j = 1 ; j <= n ; j ++) {
        if (vec[j] >> i & 1) cnt1 ++ ;
        else cnt0 ++ ; 
      } 
      if (cnt1 <= cnt0) {
        if (d == 1 || flag) ans += (1 << i);
      } else flag = true;
      
    }
  } cout << endl ;

  int res = 0;
  for(int i = 1 ; i <= n ; i++ ){
    res += ans ^ vec[i];
  }
  
  cout << res << endl; 

   // for (int i = 1;  i<= n ; i++ ) {
  //   ans1 += a ^ vec[i];
  // }

  // cout << ans1 << ' ' << ans2 << endl ;

  // int ans = 0, ansmx = 0;
  // for (int i = 1; i <= k; i ++ ) {
  //   int mx = 0 ;
  //   for (int j = 1 ;j <= n ; j ++ ) {
  //     mx += i ^ vec[j] ;
  //   }
  //   if (ansmx < mx) ansmx = mx, ans = i;
  // }

  // cout << ans << ' ' << ansmx << endl; 
  // for (int i = 1; i <= k; i ++ ) {
  //   int mx = 0 ;
  //   for (int j = 1 ;j <= n ; j ++ ) {
  //     mx += i ^ vec[j] ;
  //   }
  //   if (mx == ansmx) cout << bit(i) << endl ;
  // } cout << endl; 
  // for(int i = 1 ; i <= n ; i ++) cout << bit(vec[i]) << endl; 

}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}
