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

int query ( int a , int b , int c ) {
    int x ;
    cout << a << ' ' << b << ' ' << c << ' ' << flush << endl ; 
    cin >> x ;
    return x ;  
}

void solve() {
    
}

// ========================== Idea =============================================
/*

他把问题拆解成了 求 l 和 r
求出 l 可以直接用过整个数组的增量算出 r
卧槽牛逼啊
但是这尼玛是个交互 我应该怎么写啊
注意 我们这里只是求 l 和 r 
有个问题 为什么题目说一定是排列啊 


*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ;
    while ( tt -- ) {
        int n ; cin >> n ; 
        auto check = [&] ( int test ) -> bool {
            int pre_p , pre_a ; 
            pre_p = query( 1 , 1 , test ) ;
            pre_a = query( 2 , 1 , test ) ; 
            return pre_a > pre_p  ;
        } ;
        int l = 1 , r = n , ans = l ; 
        while ( l <= r ) {
            int mid = ( l + r ) / 2 ;
            if ( check ( mid ) ) 
                r = mid - 1 ; 
            else 
                l = mid + 1 , ans = mid ;
        }
        ans ++ ; 
        int sum_p = query( 1 , 1 , n ) , sum_a = query( 2 , 1 , n ) ; 
        cout << '!' << ' ' << ans << ' ' << ans + sum_a - sum_p - 1 << flush << endl ; 
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/



// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long

// ll query(int type, int l, int r){
//     ll x;
//     cout << type << ' ' << l << ' ' << r << flush << endl;
//     cin >> x;
//     return x;
// }
 
// int main(){
 
//     int t;
//     cin >> t;
 
//     while(t--){
        
//         int n;
//         cin >> n;

//         ll sum = query(2, 1, n);
//         sum -= ((n * (n + 1)) / 2);

//         ll diff = sum - 1;

//         int l = 1, r = n , ans = l ;

//         while(l <= r){
//             int md = (l + r) / 2;
//             ll val1 = query(1, 1, md);
//             ll val2 = query(2, 1, md);

//             if(val1 < val2) r = md - 1 ;
//             else l = md + 1 , ans = md ;
//             cout << "l: " << l << endl ; 
//             cout << "ans: " << ans << endl << endl ;
//         }        
//         ans ++ ; 
//         cout << "!" << ' ' << l << ' ' << diff + l << flush << endl;

//     }
// }
// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// // l r 
// ll qury(ll x, ll y, ll z) {
//     ll m;
//     cout << x << " " << y << " " << z << '\n';
//     cout.flush();
//     cin >> m;
//     return m;
// }

// int main() {
//     ll t;
//     cin >> t;
//     while (t--) {
//         ll n;
//         cin >> n;
//         ll len = qury(2, 1, n);
//         len -= (n * (n + 1)) / 2;
//         ll l = 1, r = n - len+1, ans=1;
//         while (l <= r) {
//             ll midl = (r - l) / 2 + l;
//             ll val1 = qury(1, midl, n);
//             ll val2 = qury(2, midl, n);
//             if (val2 - val1 < len) {
//                 r = midl - 1 ;
//             }
//             else{
//                 l = midl + 1 ;
//                 ans = midl ;
//             }
//         }
//         cout << '!' << " " << ans << " " << ans + len - 1 << '\n';
//         cout.flush();
//     }
//     return 0;
// }