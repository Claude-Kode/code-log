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

int n , q , sz ; 

vector<int> arr ;

vector<int> xorSum , frontCnt ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int lowbit( int i ) { return i & -i ; } 

void update( int pos , int del , vector<int>& tree ) {
    for ( int i = pos ; i <= sz ; i += lowbit(i) ) {
        tree[i] ^= del ;
    }
}

int query( int pos , vector<int>& tree ) {
    int res = 0 ; 
    for ( int i = pos ; i > 0 ; i -= lowbit(i) ) {
        res ^= tree[i] ; 
    }
    return res ; 
}



void solve() {
     
    cin >> n >> q ; 
    sz = (1 << n) ;
    arr.resize( sz , 0 ) ; 
    xorSum.resize( sz , 0 ) ; 
    frontCnt.resize( sz , 0 ) ; 
    
    for ( int i = 1 ; i <= sz ; i ++ ) {
        cin >> arr[i] ; update( i , arr[i] , xorSum ) ;
    }

    while ( q -- ) {
        int i , val ; cin >> i >> val ; 
        update( i , val , xorSum ) ;

    }

}

// ========================== Idea =============================================
/*

这道题就是从底向上合并成一个 大栈 , 
合并的规则是 左右相比异或和 , 大的在上面
最后求某个奶牛上面有多少奶牛

中间又药水要修改奶牛的值 , 最后也是问这只奶牛上面有多少只奶牛

一开始是想并查集 , 这个思路后面想

正解是用树状数组 , 支持动态修改 , 可以完美模拟这个场景

我计划开两个树状数组 , 一个维护异或和 , 一个维护他的前驱数量

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt - ) solve() ; 
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/



```
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        int num_cows = (1<<n);
        vector<int> cows(num_cows); for (auto &x: cows) cin >> x;

        vector<int> prefix(num_cows); prefix[0] = cows[0];
        for (int i = 1; i < num_cows; i++) {
            prefix[i] = cows[i] ^ prefix[i-1];
        }

        while (q--) {
            int cow_idx, skill_level;
            cin >> cow_idx >> skill_level;
            cow_idx--;

            int curr_position = 0;
            for (int i = 0; i < n; i++) {
                int size = (1<<i);
                int leader_idx = cow_idx / size;

                int leader_value = prefix[(size)*(leader_idx+1)-1] ^ (leader_idx == 0 ? 0 : prefix[(size)*(leader_idx)-1]);
                leader_value ^= cows[cow_idx];
                leader_value ^= skill_level;
                
                int enemy_value;
                if (leader_idx % 2 == 0) {
                    enemy_value = prefix[(size)*(leader_idx+2)-1] ^ prefix[(size)*(leader_idx+1)-1];
                }
                else {
                    enemy_value = prefix[(size)*(leader_idx)-1] ^ ((leader_idx-1) == 0 ? 0 : prefix[(size)*(leader_idx-1)-1]);
                }
                if (leader_value < enemy_value || (leader_value == enemy_value && leader_idx % 2 == 1)) {
                    curr_position += size;
                }
            }

            cout << curr_position << "\n";
        }
    } 
}```