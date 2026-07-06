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
// const int LINF = 1e18 ;
// const int MOD = 1e8 - 3 ; 
// const int MOD2 = 998244353 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// int n ;

// int lessRes = 0 , greaterRes = 0 ;

// vector<int> arr1 , arr2 ;
// vector<int> tree1 , tree2 ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// int lowbit( int i ) {
//     return i & -i ;
// }

// void update(int pos , int deltaVal , vector<int> &tree) {
//     for ( int i = pos ; i >= n ; i += lowbit(i) ){
//         tree[i] += deltaVal ;
//     }    
// }

// int query( int val , vector<int> &tree ) {
//     int ans = 0 ; 
//     for (int i = val ; i > 0 ; i -= lowbit(i) ) {
//         ans += tree[i] ; ans %= MOD ; 
//     } 
//     return ans ; 
// }

// void init() {
//     cin >> n ; 
//     arr1.resize( n + 1 ) , arr2.resize( n + 1 ) ;
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         cin >> arr1[i] ;
//     }
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         cin >> arr2[i] ;
//     }
//     vector<int> temp ( arr1 ) ; 
//     sort ( temp.begin() + 1 , temp.end() ) ; 
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         arr1[i] = lower_bound( temp.begin() , temp.end() , arr1[i] ) - temp.begin() ;
//     }
//     temp = arr2 ; 
//     sort( temp.begin() + 1 , temp.end() ) ; 
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         arr2[i] = lower_bound( temp.begin() , temp.end() , arr2[i] ) - temp.begin() ;
//     }
//     tree1.resize( n + 1 ) ; tree2.resize( n + 1 ) ;
// }

// void solve() {
    


// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
//     init() ;
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         update( arr1[i] , 1 , tree1 ) ; 
//         update( arr2[i] , 1 , tree2 ) ;  
//         lessRes += query( arr1[i] , tree1 ) ; lessRes %= MOD ;
//         lessRes += query( arr2[i] , tree2 ) ; lessRes %= MOD ; 
//         // greaterRes += query( arr2[i] , tree2 ) ; 
//         //  greaterRes %= MOD ;  
//     }

//     cout << min( lessRes , greaterRes ) << endl ; 

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */



// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

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
// #define TUP tuple<int , int , int>
// #define ull unsigned long long
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD1 = 998244353 ; 
// const int MOD2 = 1e9 + 7 ; 
// const int maxn = 1e9 ; 

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
     


// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     int tt ; cin >> tt ; 
//     while ( tt -- ) {
        
//     }
    

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */



// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// // C++ constexpr 常量定义，编译期确定，替代#define，更安全
// constexpr int MOD = 99999997;

// // C++ struct 规范写法，成员命名小驼峰，语义清晰
// struct Fire {
//     int height;   // 高度
//     int position; // 原始位置编号
// };

// // 排序规则：按高度升序，C++ const 引用传参避免拷贝，效率拉满
// bool compareByHeight(const Fire& a, const Fire& b) {
//     return a.height < b.height;
// }

// // 归并排序 + 统计逆序对 核心函数
// // 参数：原数组(vector引用)、临时数组(vector引用)、区间左右边界、答案(long long引用)
// void mergeSort(vector<long long>& arr, vector<long long>& temp, int left, int right, long long& ans) {
//     if (left >= right) {
//         return;
//     }

//     int mid = left + (right - left) / 2; // 防溢出写法，等价于(left+right)/2
//     mergeSort(arr, temp, left, mid, ans);
//     mergeSort(arr, temp, mid + 1, right, ans);

//     // 归并合并两个有序区间
//     int i = left;
//     int j = mid + 1;
//     int k = left;
//     while (i <= mid && j <= right) {
//         if (arr[i] <= arr[j]) {
//             temp[k++] = arr[i++];
//         } else {
//             temp[k++] = arr[j++];
//             ans = (ans + mid - i + 1) % MOD; // 统计逆序对核心公式
//         }
//     }

//     // 处理剩余元素
//     while (i <= mid) temp[k++] = arr[i++];
//     while (j <= right) temp[k++] = arr[j++];

//     // 临时数组数据回写原数组
//     copy(temp.begin() + left, temp.begin() + right + 1, arr.begin() + left) ;
// }

// int main() {
//     ios::sync_with_stdio(false);  // 关闭同步，加速cin/cout，媲美scanf/printf
//     cin.tie(nullptr);             // 解绑cin和cout，进一步提速

//     long long n;
//     cin >> n;

//     // C++ vector 替代静态数组，动态扩容，无越界风险，无需手动开大小
//     vector<Fire> fire1(n + 1);
//     vector<Fire> fire2(n + 1);
//     vector<long long> arr(n + 1);
//     vector<long long> temp(n + 1);
//     long long ans = 0;

//     // 输入第一组数据，记录高度和原始位置
//     for (int i = 1; i <= n; ++i) {
//         cin >> fire1[i].height;
//         fire1[i].position = i;
//     }

//     // 输入第二组数据，记录高度和原始位置
//     for (int i = 1; i <= n; ++i) {
//         cin >> fire2[i].height;
//         fire2[i].position = i;
//     }

//     // 按高度排序
//     sort(fire1.begin() + 1, fire1.end(), compareByHeight);
//     sort(fire2.begin() + 1, fire2.end(), compareByHeight);

//     // 核心映射逻辑，将问题转化为求逆序对
//     for (int i = 1; i <= n; ++i) {
//         arr[fire2[i].position] = fire1[i].position;
//     }


// //  上面是离散化 还他妈真是 然后把 1 的顺序映射到 2 的顺序上统计逆序对
// // 就是我的目标是数组 1 的相对顺序要和数组 2 的相对顺序是一样的
// // 所以把 1 映射到 2 上面

// // ? 这tm在求啥 ??

//     // 归并排序统计逆序对
//     mergeSort(arr, temp, 1, n, ans);

//     // 输出答案
//     cout << ans << endl;

//     return 0;
// }


// vector<int> temp( arr ) ; 
// void mergesort( vector<int>& arr , int l , int r , int& exchangeCnt ) {

//     if ( l >= r ) return ; 

//     int mid = ( l + r ) / 2 ;
//     mergesort( arr , l , mid , exchangeCnt ) ; 
//     mergesort( arr , mid + 1 , r , exchangeCnt ) ; 
    
//     int i = l ;
//     int j = mid + 1 ; 
//     int curPos = l ;
//     while ( i <= mid && j <= r ) {
//         if ( arr[i] <= arr[j] ) {
//             temp[curPos++] = arr[i++] ; 
//         } else {
//             temp[curPos++] = arr[j++] ;
//             exchangeCnt = (exchangeCnt + mid - i + 1) % MOD ; 
//         }
//     }

//     while( i <= mid ) temp[curPos++] = arr[i++] ; 
//     while( j <= r ) temp[curPos++] = arr[j++] ; 

//     copy(temp.begin() + l, temp.begin() + r + 1, arr.begin() + l) ;

// }


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
const int MOD1 = 1e8 - 3 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n ;
int exchangeCnt ;

struct fire{ int val ; int orinPos ; } ; 

vector<fire> matches1 , matches2 ; 
vector<int> arr ; 
vector<int> temp ; 



// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    matches1.resize( n + 1 ) ;
    matches2.resize( n + 1 ) ;
    arr.resize( n + 1 ) ;
    temp.resize( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> matches1[i].val ; matches1[i].orinPos = i ; 
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> matches2[i].val ; matches2[i].orinPos = i ; 
    }
}

void mergesort( int l , int r ) {
    if ( l >= r ) return ; 

    int mid = (l + r) / 2 ; 
    mergesort( l , mid ) ; 
    mergesort( mid + 1 , r ) ;

    int i = l ; 
    int j = mid + 1 ;
    int pos = l ; 
    while ( i <= mid && j <= r ) {
        if ( arr[i] <= arr[j] ) {
            temp[pos++] = arr[i++] ;  
        } else {
            temp[pos++] = arr[j++] ; 
            exchangeCnt = ( exchangeCnt + mid - i + 1 ) % MOD1 ; 
        }
        
    }

    while ( i <= mid ) temp[pos++] = arr[i++] ;
    while ( j <= r ) temp[pos++] = arr[j++] ;

    copy( temp.begin() + l , temp.begin() + r + 1 , arr.begin() + l ) ; 

}

void solve() {
     


}

// ========================== Idea =============================================
/*

同序积最大 , 所以要让两组火柴的元素的相对顺序是一致的

我一开始的思路就是把两个火柴全部变成有序序列
然后对原数组拥统计逆序对

1. 逆序对数量等于交换次数
2. 

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n ; 
    init() ;
    // temp = matches1 ; 
    // sort( temp.begin() , temp.end() ) ; 
    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     matches1[i] = lower_bound( temp.begin() , temp.end() , matches1[i] ) - temp.begin() ; 
    // }
    // temp = matches2 ; 
    // sort( temp.begin() , temp.end() ) ; 
    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     matches2[i] = lower_bound( temp.begin() , temp.end() , matches2[i] ) - temp.begin() ; 
    // }

    // for ( int i = 1; i <= n ; i ++ ) {
    //     arr[matches2[i]] = matches1[i] ; 
    // }

    // 按高度排序
    sort(matches1.begin() + 1, matches1.end(), [&] ( fire &a , fire &b ) {
        return a.val < b.val ; 
    });
    sort(matches2.begin() + 1, matches2.end(), [&] ( fire &a , fire &b ) {
        return a.val < b.val ; 
    });
    // 核心映射逻辑，将问题转化为求逆序对
    for (int i = 1; i <= n; ++i) {
        arr[matches2[i].orinPos] = matches1[i].orinPos;
    }

    mergesort( 1 , n ) ; 

    cout << exchangeCnt << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/
