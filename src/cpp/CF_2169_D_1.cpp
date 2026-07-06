// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define endl '\n'
// #define int long long
// #define ll long long
// #define ull unsigned int int
// #define PII pair<int , int>
// #define TUP tuple<int , int , int>

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const ll LINF = 1e18 ;
// const int MOD = 1e9 + 7 ;
// const int MOD2 = 998244353 ;
// const int maxn = 10'000'000'000'000 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;



// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void solve() {
//     // 这道题正向是可以求解的 但是人类真的能写出来吗
//     // 还是那个思路 反向还原 根据 k 和操作数 x 反向还原
//     // 但是还是那个分段问题搞不明白哦 
//     int x , y , k ; cin >> x >> y >> k ; 
//     if ( y == 1 ) {
//         cout << -1 << endl ; return ; 
//     }
//     if ( k <= y - 1 ) {
//         cout << k << endl ; return ;
//     }
//     // check 的意思是 test 经过 x 次变换后能不能变成 k
//     // 确保删掉的不是最后一个
//     auto check = [&] ( int test ) -> bool {
//         for ( int i = 0 ; i < x ; i ++ )
//             test -= test / y ;
//         return test <= k ;
//     } ;
//     int l = 1 , r = maxn , ans = l ; 
//     while ( l <= r ) {
//         int mid = ( l + r ) / 2 ;
//         if ( check( mid ) )  
//             l = mid + 1 , ans = mid ; 
//         else 
//             r = mid - 1 ; 
//     }
//     if ( ans == maxn ) { cout << -1 << endl ; return ; }
//     cout << ans << endl ; 
//     // int x , y , k ; cin >> x >> y >> k ; 
//     // if ( y == 1 ) 
//     //     { cout << -1 << endl ; return ; }
//     // if ( k <= y - 1 ) 
//     //     { cout << k << endl ; return ; }
//     // for ( int i = 0 ; i < x ; i ++ ) {
//     //     k = k - ( (k - 1) / (y - 1) ) ;
//     //     if ( k > maxn ) 
//     //         { cout << -1 << endl ; return ; }
//     // }
//     // cout << k << endl ; 
//     // int x , y , k ; cin >> x >> y >> k ; 
//     // if ( k <= y - 1 ) {cout << k << endl ; continue ; }
//     // int seg =  maxn / y - 1 ; 
//     // int rem1 = y - 1 , rem2 = seg * ( y - x ) , rem3 = maxn % y + 1 - x ;
//     // int rem = 0 ; 
//     // rem += rem1 ; 
//     // rem += rem2 > 0 ? rem2 : 0 ;
//     // rem += rem3 > 0 ? rem3 : 0 ; 
//     // if ( rem < k ) cout << -1 << endl ; 
//     // else {
//     //     int i = ( k - y + 1 ) / ( y - x ) ; 
//     //     int remm = ( k - y + 1 ) % ( y - x ) ;
//     //     if ( remm == 0 ) remm = y - x ;
//     //     int ans = i * y + ( x - 1 ) + remm ; 
//     //     cout << ans << endl ;
//     // }    
// }

// // ========================== Idea =============================================
// /*

// after removal the original pos will change 
// maybe we can rec the number of rem op 
// rem is value to zero 
// the cnt of zero means the index should be index - cnt 

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
//     int tt ; cin >> tt ; 
//     while ( tt -- )     
//         solve() ; 
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */


#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1000000000000LL;

void solve(){
    int x;
    long long y, k;
 
    cin >> x >> y >> k;
 
    long long l = 1, r = INF;
    long long m;
    long long ans =1e18 ; 
    while(l <= r){
        m = l + (r - l) / 2;
        long long ost = ( m );
        for (int i = 0; i < x; i++){
            ost -= ost / y;
        }
        if (ost > k){
            r = m - 1;
            ans = m ; 
        }
        else{
            l = m + 1;
            // ans = m ; 
        }
    }
 
    if (ans == 1e18){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}
 
signed main()
{
#ifdef FELIX
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
 
#ifdef FELIX
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
    chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}