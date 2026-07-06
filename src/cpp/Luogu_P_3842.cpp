/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
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
#define ull unsigned long long
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD1 = 998244353 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

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

我能想得到的 dp 的解法只是局限于单源的 , 也就是说的思路是把它分解成多个单源最短路求解 
这样的思维好像也是符合贪心的思想

我这样的思路其实跟贪心没有任何区别 , 这个题就是日常的像爬楼梯
每次你有两个选择 , 然后需要付出不同的代价

问题 : 为什么局部直接贪心不能直接得到最优解



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int n ; cin >> n ; 
    vector<int> l( n + 1 ) ;
    vector<int> r( n + 1 ) ; 
    
    // 左端点是 (i , l[i]) , 右端点是 (i , r[i]) 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> l[i] >> r[i] ; 
    }

    // dp数组的定义 dp[i][0] 代表当前我已经到达左端点的时候花费了多少 dp[i][1] 代表当前我已经到达右端点的时候花费了多少
    // 由于是算的是路程 , 所以相当于计算边的总权重
    vector<vector<int>> dp( n + 1 , vector<int>( 2 , INT_MAX )) ;
    // 这里 dp[1][0] 的计算我没有 -1
    // 因为我一开始是 r[1] - 1 + r[1] - l[1] + 1 
    // 但是 r[1] - l[1] + 1 是节点的数量 , 我搞错的不是 边的数量
    dp[1][0] = r[1] + r[1] - l[1] - 1 ; 
    dp[1][1] = r[1] - 1 ;  
    for ( int i = 2 ; i <= n ; i ++ ) {
        // 这里为什么要 + 1 
        // 因为行和行之间移动需要加 1 
        int curLen = r[i] - l[i] ; 

        dp[i][0] = min( dp[i - 1][0] + labs( r[i] - l[i - 1] ) + 1 + curLen , dp[i - 1][1] + labs( r[i] - r[i - 1] ) + 1 + curLen ) ; 
        dp[i][1] = min( dp[i - 1][0] + labs( l[i] - l[i - 1] ) + 1 + curLen , dp[i - 1][1] + labs( l[i] - r[i - 1] ) + 1 + curLen ) ; 
        
    } 
 
    // 这里输出为什么不 + 1
    int ans = min( dp[n][0] + n - l[n] , dp[n][1] + n - r[n] ) ; 
    
    cout << ans << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/
