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
     
    int n ; cin >> n ; 
    vector<int> arr( n + 1 ) ;
    vector<vector<int>> fre( n + 1 ) ; 
    vector<int> res( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ;
        fre[arr[i]].push_back( i ) ;
    }
    
    int ans = 1 ;
    for( int i = 1 ; i <= n ; i ++ ) {
        // i 是频率 fre[i](vector) 里面是 pos 
        if ( fre[i].size() % i ) {
            cout << -1 << endl ;
            return ; 
        }

        // 这里是在循环里面搞分段
        // 搞个指针
        // int j = 0 ; 
        // while ( j < fre[i].size() ) {
        //     for ( int k = j ; k < j + i ; k ++ , j ++ ) {
        //         res[]
        //     }
        //     ans ++ ; 
        // }

        int cnt = 0 ; 
        for ( auto &pos : fre[i] ) {
            cnt ++ ; 
            res[pos] = ans ;
            if ( cnt % i == 0 ) ans ++ ; 
        } 

    }
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << res[i] << ' ' ;
    }
    cout << endl ;

}

// ========================== Idea =============================================
/*



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



// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr); // 加速输入输出，避免超时
    
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }
        
//         // 初始化频率数组，FRQ[i] 存储数值 i 出现的所有下标
//         vector<vector<int>> FRQ(n + 1);
//         for (int i = 0; i < n; ++i) {
//             FRQ[a[i]].push_back(i);
//         }
        
//         vector<int> b(n, 0);
//         int cnt = 1;
//         bool flag = true; // 标记是否需要输出 -1
        
//         for (int i = 1; i <= n; ++i) {
//             // 如果出现次数不能被 i 整除，输出 -1
//             if (FRQ[i].size() % i != 0) {
//                 flag = false;
//                 break;
//             }
            
//             int c = 0;
//             while (c < FRQ[i].size()) {
//                 // 每 i 个元素分配同一个 cnt 值
//                 for (int v = 0; v < i; ++v) {
//                     b[FRQ[i][c]] = cnt;
//                     c++;
//                 }
//                 cnt++;
//             }
//         }
        
//         if (!flag) {
//             cout << -1 << '\n';
//         } else {
//             // 输出结果数组
//             for (int i = 0; i < n; ++i) {
//                 cout << b[i] << " ";
//             }
//             cout << '\n';
//         }
//     }
    
//     return 0;
// }