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
#define TUP tuple<int , int , int>
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
const ll LINF = 1e18 ;

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

int fp( int base , int index ) {
    int res = 1 ; 
    base %= MOD2 ; 
    while ( index ) {
        if ( index & 1 ) 
            res = ( res * base ) % MOD2 ; 
        base = ( base * base ) % MOD2 ;
        index >>= 1 ;
    }
    return res ; 
}

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
        int n , m , x ; cin >> n >> m >> x ; 
        int a = ( 5 * fp( x , m ) % MOD2 - 7 * (n % MOD2) * (m % MOD2) % MOD2 ) % MOD2 ;  
        int b = ( fp( 2 , n ) + fp( 3 , m ) + 11 ) % MOD2  ;
        b = fp( b , MOD2 - 2 ) ; 
        cout << ( (a % MOD2 * b % MOD2) % MOD2 + MOD2) % MOD2 << endl ;   
    }
    
    return 0 ;

}
// ========================== Question =========================================
/*

*/


// #include <iostream>

// typedef long long ll;
// ll const INF=998244353;
// ll fastpow(ll x,ll n){
//     ll ans=1;
//     while(n){
//         if(n&1) ans=(ans*x)%INF;
//         x=((x%INF)*(x%INF))%INF;
//         n>>=1;
//     }
//     return ans;
// }
// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0); 
//     std::cout.tie(0);
//     ll t;
//     std::cin>>t;
//     while(t--){
//         ll n,m,x;
//         std::cin>>n>>m>>x;
//         ll ak=(5*fastpow(x,m)%INF)-(7*(n%INF)*(m%INF))%INF;
//         ll ab=(fastpow(2,n)+fastpow(3,m)+11)%INF;
//         ll aks=fastpow(ab,INF-2)%INF;
//         ll ans=(ak%INF)*(aks%INF)%INF+INF;
//         std::cout<<ans%INF<<'\n';
//     }
// }