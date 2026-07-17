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
// #include <utility>
// #include <bitset>
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
// #define ull unsigned long long
// #define PII pair<int , int>
// #define TUP tuple<int , int , int>

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const ll LINF = 1e18 ;
// const int MOD = 1e9 + 7 ;
// const int MOD2 = 998244353 ;

// // ========================== Global Variables / Arrays ========================

// vector<int> prime_nums ;
// vector<bool> isprime( 2e5 + 1 , 0 ) ; 

// // ========================== Functions ========================================

// int gcd ( int a , int b ) { return b ? gcd( b , a % b ) : a ; }

// void eulerSieve( int n ) {
//     for ( int i = 2 ; i <= n ; i ++ ) {
//         if ( !isprime[i] ) 
//             prime_nums.push_back( i ) ; 
//         for ( auto &a : prime_nums ) {
//             if ( a * i > n ) break ;
//             isprime[a * i] = true ;
//             if ( i % a == 0 ) break ; 
//         }
//     }
// }

// void solve() {
//     int n ; cin >> n ; 
//     vector<int> arr( n ) , buckle( 2e5 + 1 , 0 ) ;
//     for ( auto &a : arr ) cin >> a;  
//     for ( int i = 0 ; i < n ; i ++ ) { int temp ; cin >> temp ; }
//     // check if ans is 0  , means there are at 
//     // 如果答案不是 0 那么每个数的最小素数因子会被标记 
//     for ( auto &a : arr ) {
//         for ( auto &p : prime_nums ) {
//             if ( a % p == 0 ) {
//                 if ( buckle[p] ) {
//                     cout << 0 << endl ;
//                     return ; 
//                 }
//                 buckle[p] ++ ; 
//             } 
//         }
//     } 
//     for ( auto &a : arr ) {
//         for ( auto &p : prime_nums ) {
//             if ( (a + 1) % p == 0 && buckle[p] )    
//                 { cout << 1 << endl ; return ; }
//         }
//     }
//     cout << 2 << endl ; 
// }

// // ========================== Idea =============================================
// /*

// 别沉浸在幻想里面了 你还是那个菜逼
// 果然 一个 c1 直接干翻你了
// 有可能一个数 加了 1 就又可以和某个数字不互质了 
// 我真的是艹了 c艹 真的 艹蛋

// 我发现很多题解都有一句 
// " 所以可以证明答案绝对不会超过2 答案绝对不会被四整除 答案一定要被四整除 "

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
//     eulerSieve( 2e5 ) ;
//     int tt ; cin >> tt ; 
//     while ( tt -- ) solve() ; 
//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */
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
// #include <utility>
// #include <bitset>
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
// #define ull unsigned long long
// #define PII pair<int , int>
// #define TUP tuple<int , int , int>

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const ll LINF = 1e18 ;
// const int MOD = 1e9 + 7 ;
// const int MOD2 = 998244353 ;

// // ========================== Global Variables / Arrays ========================

// vector<int> prime_nums ;
// vector<int> spf( 2e5 + 2 , 1 ) ; 
// vector<bool> isprime( 2e5 + 2 , false ) ;

// // ========================== Functions ========================================

// void eulerSieve () {
//     for ( int i = 2 ; i <= 2e5 + 1 ; i ++ ) {
//         if ( !isprime[i] ) 
//             prime_nums.push_back( i ) , spf[i] = i ;
//         for ( auto &a : prime_nums ) {
//             if ( a * i > 2e5 + 1 ) break ; 
//             isprime[a * i] = true ; 
//             spf[a * i] = a ; 
//             if ( a % i == 0 ) break ; 
//         }
//     }
// }

// void solve() {
//     int n ; cin >> n ; 
//     vector<int> arr( n ) , buckle( 2e5 + 2 ) ;
//     for ( auto &a : arr ) cin >> a ; 
//     for ( int i = 0 ; i < n ; i ++ ) { int temp ; cin >> temp ; }
//     for ( auto &a : arr ) {
//         // buckle 是每个数字的最小素数因子的 桶
//         // 如果这个数字是合数 而且他的最小素数因子出现过 输出 0 
//         if ( spf[a] != 1 && buckle[spf[a]] ) 
//             { cout << 0 << endl ; return ; }
//         buckle[spf[a]] ++ ; 
//     }
//     // cout << "spf" << ": "<< endl ;
//     // for ( int i = 0 ; i <= 11 ; i ++ ) {
//     //     cout << i << ' ' << spf[i] << endl ;
//     // }
//     // cout << endl ; 
//     // cout << "buckle" << ": " << endl ; 
//     // for ( int i = 0 ; i <= 11 ; i ++ ) {
//     //     cout << i << ' ' << buckle[i] << endl ; 
//     // }
//     for ( auto &a : arr ) {
//         if ( spf[a + 1] != 1 && buckle[spf[a + 1]] )
//             { cout << 1 << endl ; return ; }
//     }
//     cout << 2 << endl ; 
// }

// // ========================== Idea =============================================
// /*

// 马勒戈壁 用最小素数标记是错的卧槽尼玛
// 12 -> 2 
// 3 -> 3 
// wcnmd

// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
//     eulerSieve() ;
//     // for ( int i = 0 ; i < 100 ; i ++ ) 
//     //     cout << i << ':' << spf[i] << endl ; 
//     int tt ; cin >> tt ; 
//     while ( tt -- ) solve() ; 
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
#include <utility>
#include <bitset>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 1e9 + 7 ;
const int MOD2 = 998244353 ;

// ========================== Global Variables / Arrays ========================

vector<int> prime_nums ;
vector<bool> isprime( 2e5 + 2 , false ) ; 
vector<vector<int>> factors( 2e5 + 2 , vector<int>() ) ; 

// ========================== Functions ========================================

void factorsCals() {
    for ( int i = 2 ; i <= 2e5 ; i ++ ) {
        if ( !factors[i].empty() ) continue ;
        for ( int j = i ; j <= 2e5 ; j += i ) 
            factors[j].push_back( i ) ; 
    }
}

void solve() {
    int n , temp ; cin >> n ; 
    vector<int> arr( n ) ;
    unordered_map<int , int>  buckle ;
    for ( auto &a : arr ) cin >> a ; 
    for ( int i = 0 ; i < n ; i ++ ) cin >> temp ; 
    // cal whether the ans is 0 
    for ( auto &a : arr ) {
        for ( auto &p : factors[a] ) {
            if ( buckle[p] ) { cout << 0 << endl ; return ; }
            buckle[p] ++ ; 
        }
    }
    for ( auto &a : arr ) {
        for ( auto &p : factors[a + 1] ) {
            if ( buckle[p] ) { cout << 1 << endl ; return ; }
        }
    }
    cout << 2 << endl ; 
}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    factorsCals() ; 
    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ; 
    // for ( int i = 0 ; i < 10 ; i ++ ) {
    //     cout << i << ": " << endl ;  
    //     for ( auto &a : factors[i] ) 
    //         cout << a << ' ' ; 
    //     cout << endl ; 
    // }
    return 0 ;
}
// ========================== Question =========================================
/*

*/

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define debug(x) cout << #x << " = " << x << "\n";
// #define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
// ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

// const int N = 2e5 + 10;
// vector<vector<int>> pfac(N + 1);

// void solve(){
//     int n;
//     cin >> n;

//     vector<int> a(n), b(n);
//     for (int &x : a) cin >> x;
//     for (int &x : b) cin >> x;
//     // 把每个数的因子push进去
//     int ans = 2;
//     map<int, int> cnt;
//     for (int i = 0; i < n; i++){
//         for (int x : pfac[a[i]]){
//             if (cnt[x] > 0)
//                 ans = 0;
//             cnt[x]++;
//         }
//     }
//     // 把每个数 + 1 的因子push进去 重叠就out
//     for (int i = 0; i < n; i++){
//         for (int x : pfac[a[i]])
//             cnt[x]--;

//         for (int x : pfac[a[i] + 1]){
//             if (cnt[x] > 0)
//                 ans= min(ans, 1);
//         }

//         for (int x : pfac[a[i]])
//             cnt[x]++;
//     }

//     cout << ans << "\n";
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     for (int i = 2; i <= N; i++){
//         if (!pfac[i].empty())
//             continue;

//         for (int j = i; j <= N; j += i)
//             pfac[j].push_back(i);
//     }
    
//     int t;
//     cin >> t;
//     while (t--) solve();
// }

