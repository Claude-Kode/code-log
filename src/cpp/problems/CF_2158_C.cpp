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
#include <utility>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

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


// ========================== Functions ========================================


// ========================== Idea =============================================
/*
对于每次选择来说 都选择最优的那个 那么每次对方只能修复你的选择 可以是这样吗
对于 a 来说 每次选择 max ( a[i] - b[i] , a[i] + b[i] ) 进行修改
或者说是增量最大 而不是数值最大
如果 k 是奇数 直接只修改一 alice 进行的操作
如果是偶数 直接求解非空子数组最大和即可
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n , k ; cin >> n >> k ; 
        vector<int> a( n ) , b( n ) ;
        for ( auto &x : a ) cin >> x ;
        for ( auto &x : b ) cin >> x ; 
        vector<int> L( n ) , R( n ) ;
        L[0] = a[0] ; R[n - 1] = a[n - 1] ;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( i > 0 ) {
                L[i] = max ( L[i - 1] + a[i] , a[i] ) ;
            } 
        } 
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
            if ( i < n - 1) {
                R[i] = max ( R[i + 1] + a[i] , a[i] ) ;
            }
        }
        if ( k % 2 == 0 ) cout << *max_element( L.begin() , L.end() ) << endl ; 
        else {
            int res = INT_MIN ; 
            for ( int i = 0 ; i < n ; i ++ ) {
                res = max ( res , L[i] + R[i] - a[i] + b[i] ) ;
            }
            cout << res << endl ; 
        }
        // ans 代表 a[i] 位置的增量
        // 这里逻辑可能有个问题 就是最后最大的子数组跟这次改动没有关系
        // wtf
        // 那就很麻烦了 肯定是要用遍历的方式来确定 最多数组和的
        // 而且肯定是设计逻辑然后直接算出来的
        // 
        // int index = 0 , ans = LONG_LONG_MIN ;
        // for ( int i = 0 ; i < n ; i ++ ) {
        //     // cout << -b[i] << ' ' ;
        //     if ( ans < labs( b[i] ) ) {
        //         index = i ; ans = labs( b[i] ) ;
        //     }
        // }
        // // cout << endl ;
        // if ( k % 2 == 1 ) a[index] += ans ; 
        // if ( k % 2 == 0 ) {
        //     int cur_dp = 0 , pre_dp = a[0] , res = a[0] ; 
        //     for ( int i = 1 ; i < n ; i ++ ) {
        //         // cur_dp 代表算到当前位置位置的最大子数组是多少?
        //         // 要么以这个数字为结尾 就是上一位的结果接上这个数字
        //         // 要么这个数字 + 0 , 也就是自己重新开头
        //         cur_dp = max ( pre_dp + a[i] , a[i] ) ;
        //         res = max ( res , cur_dp ) ;
        //         pre_dp = cur_dp ;
        //     }
        //     cout << res << endl ; 
        // } else {
        //     vector<int> dp ( n ) ;  
        //     int res = max ( a[0] , a[0] + labs( b[0] ) ) ; dp[0] = a[0] ;
        //     for ( int i = 1 ; i < n ; i ++ ) {
        //         // cur_dp 代表算到当前位置位置的最大子数组是多少?
        //         // 要么以这个数字为结尾 就是上一位的结果接上这个数字
        //         // 要么这个数字 + 0 , 也就是自己重新开头
        //         dp[i] = max ( dp[i - 1] + a[i] , a[i] ) ;
        //         res = max ( res , dp[i] + labs( b[i] ) ) ;
        //         dp[i - 1] = dp[i] ;
        //     }
        //     cout << res << endl ;
        // }
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/

// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n,k;
//     cin >> n >> k;
//     vector<int> a(n),b(n);
//     for(int i = 0;i < n;i++)cin >> a[i];
//     for(int i = 0;i < n;i++)cin >> b[i];
//     k &= 1; //It can be reduced as 0/1 move game

//     vector<long long> L(n); //maximum sum non empty subarray ending at each position
//     for(int i = 0;i < n;i++){
//         L[i] = (i && L[i-1]>0 ? L[i-1] : 0ll) + a[i]; 
//     }   

//     vector<long long> R(n); //maximum sum non empty subarray starting at each position
//     for(int i = n-1;i >= 0;i--){
//         R[i] = (i+1<n && R[i+1]>0 ? R[i+1] : 0ll) + a[i];
//     }
//     cout << "L :" ;
//     for ( auto &a : L ) cout << a << ' ' ;
//     cout << endl ;
//     cout << "R :" ;
//     for ( auto &a : R ) cout << a << ' ' ;
//     cout << endl << endl ;
//     if(k == 0){
//         long long ans = *max_element(L.begin(),L.end());
//         cout << ans << "\n";
//     }
//     else{
//         long long ans = LONG_MIN;
//         for (int i = 0 ; i < n ; i ++){
//             // 这里是算的是以 a[i] 为中心的最大的一个子数组 然后减去 a[i] 是去重
//             // + b[i] 是在枚举改变
//             // 但还是有个疑问 如果以 a[i] 或者 a[i + 1] 为中心的数组
//             // 对于他们来说的最优操作都不是对中心元素a[i] 进行 + b[i] 呢
//             // ...
//             // 其实可以证明 如果操作的应该是 a[k] 
//             // 那么对a[k] 进行操作的时候一定范围跟 a[i] 是一样的甚至更大吗
//             // 也就是说如果 a[k] 是最优解 那么当遍历到 a[k] 的时候进行操作的子数组一定是
//             // 包括a[i] 的这个子数组的?
//             // 首先由于遍历的缘故 每个元素都会有被改变的机会
//             // 既然是遍历的那应该一定是对的 e ...
//             ans = max(ans,L[i]+R[i]-a[i]+b[i]);
//         }
//         cout << ans << "\n";
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){
//         solve();
//     }
// }