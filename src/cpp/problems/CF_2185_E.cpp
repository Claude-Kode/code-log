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
     
    int n , m , k ; cin >> n >> m >> k ;

    vector<int> rob( n + 1 ) ;
    vector<int> spi( m + 1 ) ; 
    vector<int> com( k + 1 ) ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> rob[i] ; 
    }

    for ( int i = 1 ; i <= m ; i ++ ) {
        cin >> spi[i] ; 
    }

    unordered_map<int, int> coms ; 
    for ( int i = 1 ; i <= k ; i ++ ) {
        char temp ; cin >> temp ; 
        if ( temp == 'R' ) com[i] = com[i - 1] + 1 ; 
        else com[i] = com[i - 1] - 1 ;
        // cout << com[i] << ' ' ;
        if ( coms[com[i]] ) coms[com[i]] = min( coms[com[i]] , i ) ;
        else coms[com[i]] = i ; 
        // cout << com[i] << ' ' << coms[com[i]] << endl ;
    }

    // for ( auto &[dis , pos] : coms ) {
    //     cout << dis << ' ' << pos << endl ; 
    // }

    // cout << endl ; 

    sort( rob.begin() + 1 , rob.end() ) ; 
    sort( spi.begin() + 1 , spi.end() ) ; 
    
    // 不会写代码
    vector<vector<int>> spis( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        auto rspi = lower_bound( spi.begin() + 1 , spi.end() , rob[i] ) ; 
        auto lspi = rspi - 1 ; 
        
        if ( rspi == (spi.begin() + 1) ) spis[i].push_back( *rspi - rob[i] ) ;
        else if ( rspi == spi.end() ) spis[i].push_back( *lspi - rob[i] ) ;
        else if ( *rspi == rob[i] ) spis[i].push_back( 0 ) ; 
        else if ( *lspi == rob[i] ) spis[i].push_back( 0 ) ;
        else spis[i].push_back( *lspi - rob[i] ) , spis[i].push_back( *rspi - rob[i] ) ; 

    }

    vector<int> diff_ans( k + 1 , 0 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        int step = INT_MAX ; 
        for ( auto &dis : spis[i] ) {
            // cout << "i :" << i << ' ' << dis << endl ; 
            if ( dis == 0 ) step == 0 ; 
            else if ( coms[dis] ) step = min( step , coms[dis] ) ; 
        }
        // cout << step << ' ' ;
        if ( step != INT_MAX ) diff_ans[step] -- ; 
    }

    int ans = n + diff_ans[0] ; 
    // cout << ans << ' ' ; 
    for ( int i = 1 ; i <= k ; i ++ ) {
        ans += diff_ans[i] ; 
        // cout << diff_ans[i] << ' ' ;
        cout << ans << ' ' ;   
    }

    cout << endl ; 

}

// ========================== Idea =============================================
/*

对于每个机器人我们预处理一遍 看看他什么时候死 , 然后在死的时候对答案数组进行修改 
这个有点像树状数组进行维护

就是对移动进行前缀和 , 然后 n * k 遍历再用哈希表查询当前位置是否是坚持位置 ? 

利用二分预处理出每个机器人的死亡距离 然后查询他哪一步死 好像要开好多个哈希表啊

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) {
        solve() ;
    }
    

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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> robots(n); for (auto &x: robots) cin >> x;

        vector<int> lava(m); for (auto &x: lava) cin >> x;

        vector<bool> dead(n); 
        map<int, vector<int>> death_locations;

        string instructions;
        cin >> instructions;

        sort(lava.begin(), lava.end());

        for (int i = 0; i < n; i++) {
            if (lava[0] < robots[i]) {
                int left_dist = robots[i] - (*(lower_bound(lava.begin(), lava.end(), robots[i]) - 1));
                death_locations[-left_dist].push_back(i);
            }
            if (lava[m-1] > robots[i]) {
                int right_dist = *lower_bound(lava.begin(), lava.end(), robots[i]) - robots[i];
                death_locations[right_dist].push_back(i);
            }
            
        }

        int current_pos = 0;
        int alive = n;

        for (auto &x: instructions) {
            if (x == 'L') current_pos--;
            else current_pos++;

            for (int i: death_locations[current_pos]) {
                
                if (dead[i]) continue;
                dead[i] = true;
                alive--;
            }
            death_locations[current_pos].clear();
            cout << alive << " ";
        }

        cout << "\n";
    }
}```