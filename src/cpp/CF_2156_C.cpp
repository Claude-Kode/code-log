/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: buckleLATE
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
#include <utility>
#include <bitset>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

vector<int> prime_nums ;
vector<bool> isprime ( 2e5 + 1 , false ) ;  

// ========================== Functions ========================================

// void eulerSieve( int n ) {
//     for ( int i = 2 ; i <= n ; i ++ ) {
//         if ( !isprime[i] ) {
//             prime_nums.push_back( i ) ;
//         }
//         for ( auto &a : prime_nums ) {
//             if ( a * i > n ) break ;
//             isprime[a * i] = true ;
//             if ( i % a == 0 ) break ;
//         }
//     }
// }

void solve() {
    int n , k ; cin >> n >> k ; 
    vector<int> arr( n ) , buckle( n + 1 ) , pre_buckle( n + 1 ); 
    for ( auto &a : arr ) { cin >> a ; buckle[a] ++ ; } 
    for ( int i = 1 ; i <= n ; i ++ ) pre_buckle[i] = pre_buckle[i - 1] + buckle[i] ;
    // g means the enum value ans 
    int ans = 1 ; 
    for ( int g = 1 ; g <= n ; g ++ ) {
        int index = min( n , 4 * g - 1 ) ;
        int cnt = n - pre_buckle[index] ;     
        if ( g <= n ) cnt += buckle[g] ; 
        if ( 2 * g <= n ) cnt += buckle[2 * g] ;
        if ( 3 * g <= n ) cnt += buckle[3 * g] ;
        if ( cnt >= n - k ) ans = g ; 
    }
    cout << ans << endl ; 
    // int n , k ; cin >> n >> k ; 
    // // cout << 1 << endl ;
    // vector<int> arr ( n ) , buckle(); 
    // for ( auto &a : arr ) {  
    //     cin >> a ; 
    //     ans.push_back( max( 1LL , a / 4 ) ) ;
    // }    
    // sort( ans.begin() , arr.end() ) ; 
    // cout << ans[k] << endl ; 
    // return ; 
    // auto buckle = []( int a , int b ) -> bool {
    //     return a > b ;
    // } ;
    // set<int , decltype( buckle )> myset( buckle ) ; 
    // int mx = 0 ; 
    // for ( auto &a : arr ) { cin >> a ; if ( mx < a ) mx = a ; }
    // for ( int i = mx ; i >= 1 ; i -- ) {
    //     int cnt = 0 ; 
    //     for ( auto &a : arr ) 
    //         if ( a % i != 0 && a < i * 4 ) cnt ++ ; 
    //     if ( cnt <= k ) { cout << i << endl ; return ; }
    // }
    // auto check = [&] ( int test ) -> bool {
    //     // 接下来就是怎么拆的问题了
    //     int cnt = 0 ;
    //     for ( auto &a : arr ) 
    //         if ( a % test != 0 && a < test * 4 ) cnt ++ ; 
    //     cout << "test:" << test << ' ' << "cnt:" << cnt << endl ;
    //     return cnt <= k ;
    // } ;
    // int l = 1 , r = mx , ans = l ; 
    // while ( l <= r ) {
    //     int mid = ( l + r ) / 2 ;
    //     if ( check( mid ) ) 
    //         l = mid + 1 , ans = mid ;
    //     else 
    //         r = mid - 1 ;
    // }
    // cout << 1 << endl ;     
}

// ========================== Idea =============================================
/*
可能是跟 % 3 有一些关系
% 3 == 1 || 2 || 0 
0 --> x / 3 - 1 and x / 3 + 1 
1 --> x / 2 - 1 and x / 2
2 --> x / 2 - 2 and x / 2 - 1

首先删除肯定是有策略的 应该总结出被删除的数字的共同特征
其次删除操作可能是一种贪心操作 数字越大他们的最大 公因数就越可能重合
但是可有反例
6 12 17 
如果删除了 6 那么最大公因数就变成 1 了
如果是素数他一定要被删除 !!!! 
如果素数删不掉就要执行 spilt 策略 ? 
首先 spilt  会让最小公因数变大吗 ( 对素数执行 ) 
出来的一定会变小 

其次是 spilt operation
分割成 3  这个东西肯定是有一点的特殊性
素数进行 spilt , maximum divisor 一定会变大
至少是 两个偶数 加一个奇数
吗 ? 

可能有一种贪心是 1 要留着 
我懂了 保留最大数然后把所有都变成 1 是吗
erase 是针对小于 3 的数字卧槽
不对 就是针对 2 如果 2 的数量小于等于 k 那么直接就是输出最大值
反之直接输出 2
如果有 0 怎么办
不会有 题目规定边界了 

那如果 mx 就是 2 会怎么样

好像有个问题 就是 spilt 的时候不能有除了 1 以外的两个因子加合是 3 也不行

卧槽整错了 是最大公因数 因数啊卧槽 他妈的这么搞就全变成 1 了

spilt 的那个抹除操作是什么东西呢

想不出来啊

这种操作类的题目他先证明了操作的顺序是什么
然后题解固定了 公约数 g 感觉这是一种逆向思维 从答案的角度来考虑操作的行为
这样想来这个问题其实完全变了 
从制定最优策略问题 变成了固定转化问题 怎么通过 spilt 把 x 转化成公约数是 g 的数字
对 而且是公约数 所以应该能想到制定一个公约数来使用对齐策略来进行操作
是二分答案啊 ?
还 tm 真是啊 如果不能拆出 g 就 k -- 
深度了解二分答案 把问题的性质转化 从制定最优策略问题 变成了固定转化问题 

想到这里其实答案就很简单了 首先贪心的思维 最小的数字尽可能小 给后面操作空间
第一个数字和最后一个数字 都是被 g 整除的 
所以最小的数字就是 g 那第二个要被删掉就把不能整除的部分带走就是 g + x % g 
最后一个用和见一下就可以了
就是
g , g + x % g , x - g - g - x % g 
最后一项最小是 2g 
所以只要 x 比 四倍的 g 大 , 就可以通过 spilt 变成全都能被 g 整除的数

卧槽这题好像不能用 二分 没有单调性我操

那只能从大到小遍历出现过的数了啊 ? 

总结一下 这道题的思路是枚举答案然后验证
答案由两部分构成 一部分是 % g == 0 一部分是 >= 4 * g
用前缀和进行优化统计

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
