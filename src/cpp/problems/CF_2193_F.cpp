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

    int n , sx , sy , ex , ey ; 
    cin >> n >> sx >> sy >> ex >> ey ; 
    
    // 代码实现 : 怎么存这个坐标呢 1e9 的桶肯定开不了

    // 我的思路还是找左右端点 , 感觉这个确实是思路啊
    map<int, int> l , r ;
    // 找到同一个 x 的最小作为 l , 最大作为 r

    vector<int> X( n + 1 ) , Y( n + 1 ) ; 

    for ( int i = 1 ; i <= n ; i ++ ) cin >> X[i] ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> Y[i] ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        int x = X[i] , y = Y[i] ; 
        r[x] = max(r[x] , y) ; 
        if ( !l.count( x ) ) l[x] = y ;
        else l[x] = min(l[x] , y) ; 
    }

    // 需要一个前驱 , 还有一个 dp 数组的索引
    int idx = 1 ; 
    int lst_x = sx , lst_mxy = sy , lst_mny = sy ; 

    // dp[i][0] 代表 运动到 横坐标是 i , 线段的左端点的时候 花费是多少
    // dp[i][1] 代表 运动到 横坐标是 i , 线段的右端点的时候 花费是多少

    vector<vector<int>> dp( n + 5 , vector<int>(2 , INT_MAX)) ;


    // 注意这个题的 x 是开区间 , 没有和起点重复的边或者和重点重复的边
    // if ( r.count( sx ) ) {
    //     dp[1][0] = r[sx] - sy + r[sx] - l[sx] ;
    //     dp[1][1] = r[sx] - sy ;  
    //     idx ++ ; 
    // } 

    // for ( auto &a : r ) {
    //     int x = a.first ; 
    //     cout << "666" << x << ' ' << l[x] << ' ' << r[x] << endl ; 
    // } 

    dp[1][0] = dp[1][1] = 0 ; 

    for ( auto &a : r ) {

        idx ++ ; 
        int x = a.first , mny = l[x] , mxy = r[x] ;
         
        // 这里不能这样处理 , 因为要到达中最小的节点不一定和 sx 是一样的 , 前面的初始化是错的

        // if ( x == sx ) continue ; 
 
        int curLen = mxy - mny + x - lst_x ; 

        int l_l = labs(mny - lst_mny) ; 
        int r_l = labs(mny - lst_mxy) ; 
        int l_r = labs(mxy - lst_mny) ; 
        int r_r = labs(mxy - lst_mxy) ; 

        // cout << "curLen " << curLen << endl ; 
        // cout << "lst coor" << lst_mxy << ' ' << lst_mny << endl ; 
        // cout << "edge " << l_l << ' ' << r_l << ' ' << l_r << ' ' << r_r << endl ; 
        // cout << "lst" << dp[idx - 1][0] << ' ' << dp[idx - 1][1] << endl ; 
        dp[idx][0] = min( dp[idx - 1][0] + l_r , dp[idx - 1][1] + r_r ) + curLen ; 
        dp[idx][1] = min( dp[idx - 1][0] + l_l , dp[idx - 1][1] + r_l ) + curLen ; 

        // cout << idx << ' ' << dp[idx][0] << ' ' << dp[idx][1] << endl ;

        lst_x = x ; lst_mxy = mxy ; lst_mny = mny ; 

    }

    // cout << endl ;
 
    // 0 : ( lst_x , l[lst_x] ) , 1 : ( lst_x , r[lst_x] ) 
    // cout << "111" << ' ' << labs(l[lst_x] - ey) << ' ' << labs(r[lst_x] - ey) << endl ;
    int ans = min( dp[idx][0] + labs(l[lst_x] - ey)  , dp[idx][1] + labs(r[lst_x] - ey) ) + ex - lst_x ; 
    
    // cout << dp[idx][0] << ' ' << dp[idx ][0] << endl ;  

    cout << ans << endl ; 

    // cout << endl << endl ; 

}

// ========================== Idea =============================================
/*

按照 x 排序 , 同一个 x 走完了才能接着走下一个

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ; 
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/


// #include <bits/stdc++.h>
 
// #define F first
// #define S second
// #define int long long
 
// using namespace std;
 
// int t, n, ax, ay, bx, by;
 
// signed main()
// {
//     cin >> t;
    
//     while( t -- )
//     {
//         cin >> n >> ax >> ay >> bx >> by;
//         vector <int> x(n + 5), y(n + 5), dp[2];
        
//         dp[0] = dp[1] = vector <int> (n + 5, 0);
//         map <int, int> mx, mn;
        
//         // mn[ax] = mx[ax] = ay;
//         // mn[bx] = mx[bx] = by;
        
//         for( int i = 0; i < n; i ++ ) cin >> x[i];
//         for( int i = 0; i < n; i ++ ) cin >> y[i];
        
//         for( int i = 0; i < n; i ++ )
//         {
//             mx[x[i]] = max(mx[x[i]], y[i]);
            
//             if(!mn.count(x[i])) mn[x[i]] = y[i];
//             else mn[x[i]] = min(mn[x[i]], y[i]);
//         }

//         int lst = ax, cnt = 0;
        
//         for ( auto &a : mx ) {
//             cout << a.F << ' ' << a.second << ' ' << mn[a.F] << endl ; 
//         }

//         for( auto i : mx )
//         {
//             if( i.F == ax )
//             {
//                 dp[0][0] = dp[1][0] = 0;
//                 continue;
//             }
//             int need =  (mx[i.F] - mn[i.F]);
//             // 原本这个 dp[i][0] 的 i 是代表横坐标 , 现在是相当于把横坐标进行排序 , 然后这个 cnt 是他的索引
//             cnt ++;
//             //                                  上个左端点到这个右端点                        上个右端点到这个右端点
//             dp[0][cnt] = min(dp[0][cnt - 1] + abs(mx[i.F] - mn[lst]), dp[1][cnt - 1] + abs(mx[i.F] - mx[lst])) + need;
//             dp[1][cnt] = min(dp[0][cnt - 1] + abs(mn[i.F] - mn[lst]), dp[1][cnt - 1] + abs(mn[i.F] - mx[lst])) + need;
//             //                                  上个左端点到这个左端点                        上个右端点到这个左端点
//             lst = i.F;
//             // cout << dp[0][cnt] << ' ' << dp[1][cnt] << endl ;
//         }
//         // cout << dp[0][cnt] + bx - ax << '\n';
//         cout << endl ; 
//     }
// }

// 1 1
// 3 3

// 6 6
// 7 7
// 9 9

// 2 2
// 5 7
// 15 10
// 13 13

// 8 15
// 13 13

///////////
// 4 4 4


// 3 1 5
// 4 4 4


// 2 4 4
// 3 1 3
// 5 1 6

///

// 4 4 4

// 3 5 1
// 4 4 4

// 2 4 4
// 3 3 1
// 5 6 1

// 7 8 1
