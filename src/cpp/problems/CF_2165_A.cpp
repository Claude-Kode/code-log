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
    
//     int n ; cin >> n ; 
//     list<int> lst ;
//     int temp ;
//     for ( int i = 0 ; i < n ; i ++ ) 
//         cin >> temp , lst.push_back( temp ) ;
    
// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     int tt ; cin >> tt ; 
//     while ( tt -- ) solve() ;
    

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */



// In the name of Allah.
 
#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        list<int> alive;
        int a[n];
        // w[i] 表示 arr[i] 被插入的链表的迭代器是 w[i]
        list<int>::iterator w[n];
        auto c_next = [&alive](const list<int>::iterator& it) {
            return next(it) == alive.end() ? alive.begin() : next(it);
        };
        auto c_prev = [&alive](const list<int>::iterator& it) {
            return it == alive.begin() ? --alive.end() : prev(it);
        };
        auto hole = [&](const list<int>::iterator& it) {
            return a[*it] <= min(a[*c_next(it)], a[*c_prev(it)]);
        };
        // 插入链表 链表存的是 索引 
        // w[i] means the pos in list which val is arr[i]
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            w[i] = alive.insert(alive.end(), i);
        }
        // 这里是 queue 辅助进行 BFS 遍历链表 
        queue<int> q;
        {
            int i = 0;
            // if prev_it >= it <= next_it
            // q store that suit the condition 
            for (auto it = alive.begin(); it != alive.end(); ++it, ++i)
                if (hole(it))
                    q.push(i);
        }
        long long ans = 0;  
        bool mark[n] = {};     
        while (alive.size() > 1) {    
            auto i = q.front();      
            q.pop();      
            if (mark[i])          
            mark[i] = true;    
            // it 指的是w[i] 即 arr[i] 在链表中的迭代器具  
            auto it = w[i];
            ans += min(a[*c_next(it)], a[*c_prev(it)]);
            auto jt = c_next(it);
            alive.erase(it);
            it = jt;
            // 为什么先检查后面 再检查前面
            // 为什么要按顺序检查 不按顺序不行吗
            if (hole(it))
                q.push(*it);
            it = c_prev(it);
            if (hole(it))
                q.push(*it);
        }
        cout << ans << '\n';
    }
}