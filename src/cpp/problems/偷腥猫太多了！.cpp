/*
 * @Author: Your Name/Nickname
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
using namespace std;
// using namespace ranges;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int, int>
#define TUP tuple<int, int, int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

// ========================== Global Variables / Arrays ========================


// ========================== Functions ========================================



// ========================== Idea =============================================
/*
消灭最大的猫 伤害由两部分组成
一部分是前面所有的死猫造成的伤害 
另一部分是主动技能造成的伤害
每个猫都有需要主动释放伤害的大小 
我可能是把主动伤害需求 主动伤害对于每个猫的实时累加搞混了
换个角度想 每个猫对主动伤害是有需求的
如果前面有一万只猫是同时死亡的 只用最大生命值的猫减去索引算出来甚至会是负数 是不对的
但是逻辑层面我还没有想通
*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n ; cin >> n ; 
        vector<int> arr ( n ) ; 
        for ( auto &a : arr ) cin >> a ;
        sort ( arr.begin() , arr.end() ) ; 
        int ans = 0 ; 
        for ( int i = 0 ; i < n ; i ++ ) ans = max ( ans , arr[i] - i ) ; 
        cout << ans << endl ;
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
