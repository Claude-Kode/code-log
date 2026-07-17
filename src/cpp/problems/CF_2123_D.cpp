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
     


}

// ========================== Idea =============================================
/*

博弈论传统思维方式 某个条件直接定胜负
感觉这是一个收益问题 
如果 0 密集 那么 bob 的收益更大 反之
alice 赢就是收益更大 每次 bob 想要弥补 alice 的操作但是补不回来 那么alice 就赢了
这个弥补的长度应该是跟 k 有关的
其实如果局面上剩下的 1 的总数小于等于 k 那么bob输定了
alice 的操作就是让 bob 无法一下子挽回所有损失 所以一旦有两个 0 之间的距离大于等于 k 
alice 就能赢 ? 

bob 要确保每一轮之后都有 k >= sum_0 + 1 

只要 alice 选的 0 不连续 bob 就一定会亏兵儿


问题转变了 一个字符串 删掉k个 1 以后 , 怎么保证剩余的 0 一定有 k 个相连的

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n , k ; cin >> n >> k ; 
        string str ; cin >> str ; 
        if ( k >= count( str.begin() , str.end() , '1' ) || n < 2 * k )
            cout << "Alice" << endl ;
        else 
            cout << "Bob" << endl ; 

    }


    return 0 ;
}
// ========================== Question =========================================
/*

*/