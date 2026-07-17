/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

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

int n ; 

struct girl { int a ; int b ; int pos ; } ; 
vector<girl> girls ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

class FenwickTree {
private:
    vector<int> tree;
    int n;
    
public:
    FenwickTree(int size) : n(size) , tree(size , 0) {}

    int lowbit( int i )  { return i & -i ; }

    // val is not delta
    void update( int pos , int val ) {
        for ( int i = pos ; i <= n - 1 ; i += lowbit(i) ) {
            tree[i] = max( tree[i] , val ) ; 
        }
    }

    int query( int val ) {
        int res = INT_MIN ; 
        for ( int i = val ; i > 0 ; i -= lowbit(i) ) {
            res = max( res , tree[i] ) ; 
        }
        return res ;
    } 
    
} ;

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n ; 
    girls.resize( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> girls[i].a >> girls[i].b ; 
        girls[i].pos = i ;
    }

    sort( girls.begin() + 1 , girls.end() , [&]( girl &a  , girl &b ) {
        return a.a > b.a ;
    }) ;
    
    vector<int> bVals(n + 1) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        bVals[i] = girls[i].b ;
    }

    // 接下来就是普通的离散化 
    sort( bVals.begin() + 1 , bVals.end() , greater<int>() ) ;
    bVals.erase( unique( bVals.begin() + 1 , bVals.end()) , bVals.end() ) ; 

    unordered_map<int, int> bValsToIndex ; 
    int cnt = 0 ; for ( auto &b : bVals ) {
        bValsToIndex[b] = ++cnt ; 
    }

    // 因为 按照 a 排序了 , 所以按照遍历顺序 , 算出来的重要值一定是单调递增的
    // 对于当前 girl 来说 , 他的 a 小于等于前面的
    // 他的 b 是不确定的 , 但是因为他的 

    // 为什么前面添加过的 girl 的里面比当前 b 大的那些 girl 的最大重要值( 就是最垃圾那个 )
    // 这个 girl 肯定比这个更拉  

    // 就是找比他牛逼还跟他最近那个 , 答案就是那个 + 1 
    FenwickTree premx( bVals.size() ) ; 
    // 树状数组是 b值离散后的索引 --> 这个值所在的妹子所对应的重要程度
    vector<int> ans( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        int a = girls[i].a , b = girls[i].b , pos = girls[i].pos ;  
        int mx = premx.query( bValsToIndex[b] - 1 ) ; 
        ans[pos] = mx + 1 ;  
        premx.update( bValsToIndex[b] , ans[pos] ) ; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << ans[i] << endl ; 
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/


/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

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

int n ; 

struct girl { int a ; int b ; int pos ; } ; 
vector<girl> girls ;

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



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n ; 
    girls.resize( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> girls[i].a >> girls[i].b ; girls[i].pos = i ;
    }
    sort( girls.begin() + 1 , girls.end() , [&] ( girl &a , girl &b ) {
        if ( a.a > b.a ) return true ; 
        else if ( a.b > b.b ) return true ;
        else return false ;  
    }) ; 
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << girls[i].a << ' ' << girls[i].b << endl ; 
    }

    int cnt = 0 ; 
    vector<int> ans ( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( i == 1 || girls[i].a < girls[i - 1].a && girls[i].b < girls[i - 1].b ) cnt ++ ; 
        ans[girls[i].pos] = cnt ;
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << ans[i] << endl ; 
    }

    return 0 ;
}
// ========================== Question =========================================
/*

*/





// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <map>

// using namespace std;

// struct Girl {
//     int a, b, id;
// };

// // 树状数组，维护最大值
// class FenwickTree {
// private:
//     vector<int> tree;
//     int n;
    
// public:
//     FenwickTree(int size) : n(size + 1), tree(size + 2, 0) {}
    
//     // 更新位置x的值为val（取最大值）
//     void update(int x, int val) {
//         while (x <= n) {
//             if (tree[x] >= val) {
//                 return;  // 已经更大，无需更新
//             }
//             tree[x] = max(tree[x], val);
//             x += x & -x;
//         }
//     }
    
//     // 查询前缀[1, x]的最大值
//     int query(int x) {
//         int res = 0;
//         while (x > 0) {
//             res = max(res, tree[x]);
//             x -= x & -x;
//         }
//         return res;
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int n;
//     cin >> n;
    
//     vector<Girl> girls(n);
//     for (int i = 0; i < n; i++) {
//         cin >> girls[i].a >> girls[i].b;
//         girls[i].id = i;
//     }
    
//     // 按a从大到小排序
//     sort(girls.begin(), girls.end(), [](const Girl& x, const Girl& y) {
//         return x.a > y.a;
//     });
    
//     // 对b值离散化，大的b对应小的下标
//     vector<int> b_vals(n);
//     for (int i = 0; i < n; i++) {
//         b_vals[i] = girls[i].b;
//     }
    
//     // b值从大到小排序并去重
//     sort(b_vals.begin(), b_vals.end(), greater<int>());
//     b_vals.erase(unique(b_vals.begin(), b_vals.end()), b_vals.end());
    
//     // 建立b值到离散化下标的映射（大的b对应小的下标）
//     map<int, int> b_to_idx;
//     for (int i = 0; i < (int)b_vals.size(); i++) {
//         b_to_idx[b_vals[i]] = i + 1;  // 1-based
//     }
    
//     // 可能两个相同等级的 a 值不同
//     // 但是两个不同等级的 a 一定不同
//     int m = b_vals.size();
//     FenwickTree bit(m);
    
//     vector<int> level(n);
    
//     // 树状数组的作用是 查询更新到当前的时候的区间最大元素是啥
//     // 到这里每个 b 值都有了一个 index , 存在 b_to_idx 里面
    
//     // 按a从大到小处理
//     for (const auto& girl : girls) {
//         // idx 是当前的姑娘的 b 值对应的 idx , 上上上行注释写的
//         int idx = b_to_idx[girl.b];
//         // 查询比当前b更大的最大level（对应下标更小的部分）
//         int max_level = bit.query(idx - 1);
//         level[girl.id] = max_level + 1;
//         // 更新树状数组
//         bit.update(idx, level[girl.id]);
//     }
    
//     // 输出结果
//     for (int l : level) {
//         cout << l << "\n";
//     }
    
//     return 0;
// }