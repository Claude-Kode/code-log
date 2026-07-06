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
// #include <list>
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
    


// }

// // ========================== Idea =============================================
// /*

// 以后这种枚举所有的 k 的题想着用递推式子写出来就好了

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
//     int tt ; cin >> tt ; 
//     while ( tt -- ) {
//         int n ; cin >> n ; 
//         vector<int> arr( 2 * n + 1 ) , diff( 2 * n + 1 ) ;  
//         for ( int i = 1 ; i <= 2 * n ; i ++ ) {
//             cin >> arr[i] ;
//         }

//         for ( int i = 2 * n ; i >= 1 ; i -- ) {
//             arr[i] -= arr[i - 1] ; 
//         }

//         int sumo = 0 , sume = 0 ; 
//         for ( int i = 3 ; i <= 2 * n ; i += 2 ) {
//             sumo += arr[i] ; 
//         }
//         for ( int i = 2 ; i <= 2 * n ; i += 2 ) {
//             sume += arr[i] ;
//         }

//         int ans = sume ; 
//         for( int k = 1 ; k <= n ; k ++ ) {
//             cout << ans << ' ' ; 
//             if ( k & 1 ) { 
//                 sume -= arr[k + 1] , sume -= arr[2 * n - k + 1] ; 
//                 ans += 2 * sumo ; 
//             }
//             else {
//                 sumo -= arr[k + 1] , sumo -= arr[2 * n - k + 1 ] ; 
//                 ans += 2 * sume ; 
//             }
//         }
//         cout << endl ;

//     }
    

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */
/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream> 
#include <utility>
#include <bitset>
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <deque> 
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned int int
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 1e9 + 7 ; 
const int MOD2 = 998244353 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;



// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void solve() {
    


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ;
        vector<int> arr( 2 * n + 1 ) , diff( 2 * n + 1 ) ; 
        for ( int i = 1 ; i <= 2 * n ; i ++ ) {
            cin >> arr[i] ; 
        }
        for ( int i = 1 ; i <= 2 * n ; i ++ ) {
            diff[i] = arr[i] - arr[i - 1] ; 
        }

        int sumo = 0 , sume = 0 ; 
        for ( int i = 3 ; i <= 2 * n ; i += 2 ) {
            sumo += diff[i] ; 
        }
        for ( int i = 2 ; i <= 2 * n ; i += 2 ) {
            sume += diff[i] ; 
        }

        int ans = sume ; 
        for ( int k = 1 ; k <= n ; k ++ ) {
            cout << ans << ' ' ;
            if ( k & 1 ) {
                ans += 2 * sumo ; 
                sume -= (diff[k + 1] + diff[2 * n - k + 1]) ; 
            }
            else {
                ans += 2 * sume ; 
                sumo -= (diff[k + 1] + diff[2 * n - k + 1]) ;                
            }
        }
        cout << endl ; 
    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/



// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	ll t;
// 	cin>>t;
// 	while(t--){
// 	    ll n;
// 		cin>>n;
// 		vector<ll> a(2*n+1);
// 		for(int i=1;i<=2*n;i++) cin>>a[i];
// 		vector<ll> pre;
// 		vector<ll> pre1;
// 		for(int i=1;i<=2*n-1;i+=2){
// 			pre.push_back(a[i+1]-a[i]);
// 		}
// 		ll l=0;
// 		for(int i=2;i<=2*n-1;i+=2){
// 			pre1.push_back(a[i+1]-a[i]);
// 			l++;
// 		}
// 		vector<ll> sum(n+1);
// 		for(int i=1;i<=n;i++){
// 			sum[i]=sum[i-1]+pre[i-1];
// 		}
// 		vector<ll> sum1(n+1);
// 		for(int i=1;i<=n;i++){
// 			if(i<=l) sum1[i]=pre1[i-1]+sum1[i-1];
// 		}
// 		vector<ll> sum2(n+1);
// 		for(int i=1;i<=n;i++){
// 			sum2[i]=a[2*n-i+1]-a[i];
// 		}
// 		vector<ll> sum3(n+1);
// 		for(int i=1;i<=n;i++){
// 			sum3[i]=sum3[i-1]+sum2[i];
// 		}
// 		for(int i=1;i<=n;i++){
// 			ll ans=0;
// 			ans+=sum3[i-1];
// 		    if(i%2){
// 				ans+=sum[n-i/2]-sum[(i/2)];
// 			}
// 			else ans+=sum1[n-i/2]-sum1[i/2-1];
// 			cout<<ans<<" "; 
// 		}
// 		cout<<'\n';
// 	}
// 	return 0;
// }
