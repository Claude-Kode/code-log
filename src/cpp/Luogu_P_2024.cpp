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
// #define TUP tuple<int , int , int>
// #define ull unsigned int int
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD2 = 998244353 ; 
// const int MOD = 1e9 + 7 ; 
// const ll LINF = 1e18 ;

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// vector<int> parent , hunter , prey ; 

// int n , k ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void init() {
//     parent.resize( n + 1 ) ;
//     hunter.resize( n + 1 , 0 ) ;
//     prey.resize( n + 1 , 0 ) ;
//     for ( int i = 0 ; i <= n ; i ++ ) {
//         parent[i] = i ;
//         hunter[i] = i ;
//         prey[i] = i ;
//     }
// }

// int Find( int a ) {
//     if ( parent[a] == a ) 
//         return a ;
//     return parent[a] = Find( parent[a] ) ;
// }

// void Union( int a , int b , vector<int> &relationship ) {
//     int pa = Find( a ) ;
//     int pb = Find( b ) ;
//     if ( pa != pb ) {
//         relationship[pb] = pa ; 
//     }
// }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     cin >> n >> k ; 
//     init() ;
//     int yes = 0 , no = 0 ; 
//     while ( k -- ) {
//         int op , x , y ; cin >> op >> x >> y ; 
//         if ( op == 1 ) {
//             if ( Find( x ) == Find( y , parent ) || Find( x , prey ) == Find( y , parent ) ) {
//                 no ++ ; 
//                 continue ;
//             }
//             Union( x , y , parent ) ;
//             Union( hunter[x] , x , hunter ) ;
//             Union( prey[x] , y , prey ) ;
//         }
//         else {
//             if ( Find( x , parent ) == Find( y , parent ) || Find( x , prey ) == Find( y , parent ) ) {
//                 no ++ ; 
//                 continue ;
//             }
//             Union( prey[x] , y , parent ) ;
//             Union( parent[x] , y , hunter ) ;
//             Union( hunter[x] , y , prey ) ;
//         }
//     }

//     cout << no << endl ;

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */



// // #include <iostream>
// // using namespace std;

// // const int MAXN = 50005;
// // // 三个集合：
// // // fa[x]：x的同类集合（1~N）
// // // fa[x+N]：x捕食的动物集合（N+1~2N）
// // // fa[x+2*N]：捕食x的动物集合（2N+1~3N）
// // int fa[3 * MAXN];

// // // 查找根节点 + 路径压缩（确保并查集效率）
// // int find(int x) {
// //     if (fa[x] != x) {
// //         fa[x] = find(fa[x]); // 路径压缩，直接指向根节点
// //     }
// //     return fa[x];
// // }

// // // 合并两个集合
// // void union_set(int x, int y) {
// //     int fx = find(x);
// //     int fy = find(y);
// //     if (fx != fy) {
// //         fa[fy] = fx; // 合并到同一根节点下
// //     }
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr); // 关闭同步，加速输入输出

// //     int N, K;
// //     cin >> N >> K;

// //     // 初始化并查集：每个节点的父节点是自身
// //     for (int i = 1; i <= 3 * N; ++i) {
// //         fa[i] = i;
// //     }

// //     int lie_count = 0; // 假话总数

// //     while (K--) {
// //         int op, X, Y;
// //         cin >> op >> X >> Y;

// //         // 基础假话判定1：X或Y超出动物编号范围
// //         if (X > N || Y > N) {
// //             lie_count++;
// //             continue;
// //         }

// //         // 基础假话判定2：op=2（X吃Y）时，X和Y是同一个（自己吃自己）
// //         if (op == 2 && X == Y) {
// //             lie_count++;
// //             continue;
// //         }

// //         if (op == 1) { // 说法1：X和Y是同类
// //             // 逻辑矛盾（不可能是同类）：
// //             // 情况1：X在Y的捕食集合中（Y吃X）
// //             // 情况2：Y在X的捕食集合中（X吃Y）
// //             if (find(X) == find(Y + N) || find(Y) == find(X + N)) {
// //                 lie_count++;
// //             } else {
// //                 // 真话：合并三类对应集合，维持同类关系
// //                 union_set(X, Y); // 合并同类集合
// //                 union_set(X + N, Y + N); // 合并捕食集合
// //                 union_set(X + 2 * N, Y + 2 * N); // 合并天敌集合
// //             }
// //         } else { // 说法2：X吃Y
// //             // 逻辑矛盾（不可能X吃Y）：
// //             // 情况1：X和Y是同类（find(X) == find(Y)）
// //             // 情况2：Y在X的天敌集合中（即X在Y的捕食集合中，Y吃X）
// //             if (find(X) == find(Y) || find(X) == find(Y + N)) {
// //                 lie_count++;
// //             } else {
// //                 // 真话：按捕食闭环合并集合，维持逻辑一致
// //                 union_set(X + N, Y); // X的捕食集合 <-> Y的同类集合（X吃Y）
// //                 union_set(X + 2 * N, Y + N); // X的天敌集合 <-> Y的捕食集合
// //                 union_set(X, Y + 2 * N); // X的同类集合 <-> Y的天敌集合
// //             }
// //         }
// //     }

// //     cout << lie_count << endl;
// //     return 0;
// // }


// // /*
// //  * @Author: GoryK
// //  * @Date: Doomsday
// //  * @Description: TEMPLATE
// //  */

// // // ========================== Header Files =====================================
// // #include <unordered_map>
// // #include <unordered_set>
// // #include <algorithm>
// // #include <iostream>
// // #include <cstdlib>
// // #include <cstring>
// // #include <iomanip>
// // #include <numeric>
// // #include <sstream> 
// // #include <utility>
// // #include <bitset>
// // #include <chrono>
// // #include <random>
// // #include <string>
// // #include <vector>
// // #include <array>
// // #include <cmath>
// // #include <deque> 
// // #include <queue>
// // #include <stack>
// // #include <list>
// // #include <map>
// // #include <set>

// // // ========================== Namespace ========================================
// // using namespace std ;
// // // using namespace ranges ;

// // // ========================== Macro Definitions ================================
// // #define TUP tuple<int , int , int>
// // #define ull unsigned int int
// // #define PII pair<int , int>
// // #define int long long
// // #define ll long long
// // #define endl '\n'

// // // ========================== Constants ========================================
// // const int INF = 0x3f3f3f3f3f3f3f3f ;
// // const int MOD2 = 998244353 ; 
// // const int MOD = 1e9 + 7 ; 
// // const ll LINF = 1e18 ;

// // // ========================== Global Variables / Arrays ========================

// // // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // // unordered_set<int> st ;

// // vector<int> parent , hunter , prey ; 

// // int n , k ; 

// // // ========================== Functions ========================================


// // // int rand_num( int l , int r, bool unique = false) {
// // //     while (1) {
// // //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// // //         if ( !unique || st.insert(x).second ) return x ;
// // //     }
// // // }

// // void init() {
// //     parent.resize( n + 1 ) ;
// //     hunter.resize( n + 1 , 0 ) ;
// //     prey.resize( n + 1 , 0 ) ;
// //     for ( int i = 0 ; i <= n ; i ++ ) {
// //         parent[i] = i ;
// //         hunter[i] = i ;
// //         prey[i] = i ;
// //     }
// // }

// // int Find( int a , vector<int> &relationship ) {
// //     if ( relationship[a] == a ) 
// //         return a ;
// //     return relationship[a] = Find( relationship[a] , relationship ) ;
// // }

// // void Union( int a , int b , vector<int> &relationship ) {
// //     int pa = Find( a , relationship ) ;
// //     int pb = Find( b , relationship ) ;
// //     if ( pa != pb ) {
// //         relationship[pb] = pa ; 
// //     }
// // }

// // void solve() {
     


// // }

// // // ========================== Idea =============================================
// // /*



// // */
// // // ========================== Main Function ====================================
// // signed main() {
// //     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

// //     cin >> n >> k ; 
// //     init() ;
// //     int yes = 0 , no = 0 ; 
// //     while ( k -- ) {
// //         int op , x , y ; cin >> op >> x >> y ; 
// //         if ( op == 1 ) {
// //             if ( Find( Find( x , hunter ) , parent ) == Find( y , parent ) || Find( Find( x , prey ) , parent ) == Find( y , parent ) ) {
// //                 no ++ ; 
// //                 continue ;
// //             }
// //             Union( x , y , parent ) ;
// //             Union( hunter[x] , x , hunter ) ;
// //             Union( prey[x] , y , prey ) ;
// //         }
// //         else {
// //             if ( Find( x , parent ) == Find( y , parent ) || Find( Find( x , prey ) , parent ) == Find( y , parent ) ) {
// //                 no ++ ; 
// //                 continue ;
// //             }
// //             Union( prey[x] , y , parent ) ;
// //             Union( parent[x] , y , hunter ) ;
// //             Union( hunter[x] , y , prey ) ;
// //         }
// //     }

// //     cout << no << endl ;

// //     return 0 ;
// // }
// // // ========================== Question =========================================
// // /*

// // */


// // // /*
// // //  * @Author: GoryK
// // //  * @Date: Doomsday
// // //  * @Description: TEMPLATE
// // //  */

// // // // ========================== Header Files =====================================
// // // #include <unordered_map>
// // // #include <unordered_set>
// // // #include <algorithm>
// // // #include <iostream>
// // // #include <cstdlib>
// // // #include <cstring>
// // // #include <iomanip>
// // // #include <numeric>
// // // #include <sstream> 
// // // #include <utility>
// // // #include <bitset>
// // // #include <chrono>
// // // #include <random>
// // // #include <string>
// // // #include <vector>
// // // #include <array>
// // // #include <cmath>
// // // #include <deque> 
// // // #include <queue>
// // // #include <stack>
// // // #include <list>
// // // #include <map>
// // // #include <set>

// // // // ========================== Namespace ========================================
// // // using namespace std ;
// // // // using namespace ranges ;

// // // // ========================== Macro Definitions ================================
// // // #define TUP tuple<int , int , int>
// // // #define ull unsigned int int
// // // #define PII pair<int , int>
// // // #define int long long
// // // #define ll long long
// // // #define endl '\n'

// // // // ========================== Constants ========================================
// // // const int INF = 0x3f3f3f3f3f3f3f3f ;
// // // const int MOD2 = 998244353 ; 
// // // const int MOD = 1e9 + 7 ; 
// // // const ll LINF = 1e18 ;

// // // // ========================== Global Variables / Arrays ========================

// // // // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // // // unordered_set<int> st ;

// // // vector<int> parent , hunter , prey ; 

// // // int n , k ; 

// // // // ========================== Functions ========================================


// // // // int rand_num( int l , int r, bool unique = false) {
// // // //     while (1) {
// // // //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// // // //         if ( !unique || st.insert(x).second ) return x ;
// // // //     }
// // // // }

// // // void init() {
// // //     parent.resize( n + 1 ) ;
// // //     hunter.resize( n + 1 , 0 ) ;
// // //     prey.resize( n + 1 , 0 ) ;
// // //     for ( int i = 0 ; i <= n ; i ++ ) {
// // //         parent[i] = i ;
// // //         hunter[i] = i ;
// // //         prey[i] = i ;
// // //     }
// // // }

// // // int Find( int a , vector<int> &relationship ) {
// // //     if ( relationship[a] == a ) 
// // //         return a ;
// // //     return relationship[a] = Find( relationship[a] , relationship ) ;
// // // }

// // // void Union( int a , int b , vector<int> &relationship ) {
// // //     int pa = Find( a , relationship ) ;
// // //     int pb = Find( b , relationship ) ;
// // //     if ( pa != pb ) {
// // //         relationship[pb] = pa ; 
// // //     }
// // // }

// // // void solve() {
     


// // // }

// // // // ========================== Idea =============================================
// // // /*



// // // */
// // // // ========================== Main Function ====================================
// // // signed main() {
// // //     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

// // //     cin >> n >> k ; 
// // //     init() ;
// // //     int yes = 0 , no = 0 ; 
// // //     while ( k -- ) {
// // //         int op , x , y ; cin >> op >> x >> y ; 
// // //         if ( op == 1 ) {
// // //             if ( Find( Find( x , hunter ) , parent ) == Find( y , parent ) || Find( Find( x , prey ) , parent ) == Find( y , parent ) ) {
// // //                 no ++ ; 
// // //                 continue ;
// // //             }
// // //             Union( x , y , parent ) ;
// // //             Union( hunter[x] , x , hunter ) ;
// // //             Union( prey[x] , y , prey ) ;
// // //         }
// // //         else {
// // //             if ( Find( x , parent ) == Find( y , parent ) || Find( Find( x , prey ) , parent ) == Find( y , parent ) ) {
// // //                 no ++ ; 
// // //                 continue ;
// // //             }
// // //             Union( prey[x] , y , parent ) ;
// // //             Union( parent[x] , y , hunter ) ;
// // //             Union( hunter[x] , y , prey ) ;
// // //         }
// // //     }

// // //     cout << no << endl ;

// // //     return 0 ;
// // // }
// // // // ========================== Question =========================================
// // // /*

// // // */



// // #include <iostream>
// // using namespace std;

// // const int MAXN = 50005;
// // // 三个集合：
// // // fa[x]：x的同类集合（1~N）
// // // fa[x+N]：x捕食的动物集合（N+1~2N）
// // // fa[x+2*N]：捕食x的动物集合（2N+1~3N）
// // int fa[3 * MAXN];

// // // 查找根节点 + 路径压缩（确保并查集效率）
// // int find(int x) {
// //     if (fa[x] != x) {
// //         fa[x] = find(fa[x]); // 路径压缩，直接指向根节点
// //     }
// //     return fa[x];
// // }

// // // 合并两个集合
// // void union_set(int x, int y) {
// //     int fx = find(x);
// //     int fy = find(y);
// //     if (fx != fy) {
// //         fa[fy] = fx; // 合并到同一根节点下
// //     }
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr); // 关闭同步，加速输入输出

// //     int N, K;
// //     cin >> N >> K;

// //     // 初始化并查集：每个节点的父节点是自身
// //     for (int i = 1; i <= 3 * N; ++i) {
// //         fa[i] = i;
// //     }

// //     int lie_count = 0; // 假话总数

// //     while (K--) {
// //         int op, X, Y;
// //         cin >> op >> X >> Y;

// //         // 基础假话判定1：X或Y超出动物编号范围
// //         if (X > N || Y > N) {
// //             lie_count++;
// //             continue;
// //         }

// //         // 基础假话判定2：op=2（X吃Y）时，X和Y是同一个（自己吃自己）
// //         if (op == 2 && X == Y) {
// //             lie_count++;
// //             continue;
// //         }

// //         if (op == 1) { // 说法1：X和Y是同类
// //             // 逻辑矛盾（不可能是同类）：
// //             // 情况1：X在Y的捕食集合中（Y吃X）
// //             // 情况2：Y在X的捕食集合中（X吃Y）
// //             if (find(X) == find(Y + N) || find(Y) == find(X + N)) {
// //                 lie_count++;
// //             } else {
// //                 // 真话：合并三类对应集合，维持同类关系
// //                 union_set(X, Y); // 合并同类集合
// //                 union_set(X + N, Y + N); // 合并捕食集合
// //                 union_set(X + 2 * N, Y + 2 * N); // 合并天敌集合
// //             }
// //         } else { // 说法2：X吃Y
// //             // 逻辑矛盾（不可能X吃Y）：
// //             // 情况1：X和Y是同类（find(X) == find(Y)）
// //             // 情况2：Y在X的天敌集合中（即X在Y的捕食集合中，Y吃X）
// //             if (find(X) == find(Y) || find(X) == find(Y + N)) {
// //                 lie_count++;
// //             } else {
// //                 // 真话：按捕食闭环合并集合，维持逻辑一致
// //                 union_set(X + N, Y); // X的捕食集合 <-> Y的同类集合（X吃Y）
// //                 union_set(X + 2 * N, Y + N); // X的天敌集合 <-> Y的捕食集合
// //                 union_set(X, Y + 2 * N); // X的同类集合 <-> Y的天敌集合
// //             }
// //         }
// //     }

// //     cout << lie_count << endl;
// //     return 0;
// // }


// // /*
// //  * @Author: GoryK
// //  * @Date: Doomsday
// //  * @Description: TEMPLATE
// //  */

// // // ========================== Header Files =====================================
// // #include <unordered_map>
// // #include <unordered_set>
// // #include <algorithm>
// // #include <iostream>
// // #include <cstdlib>
// // #include <cstring>
// // #include <iomanip>
// // #include <numeric>
// // #include <sstream> 
// // #include <utility>
// // #include <bitset>
// // #include <chrono>
// // #include <random>
// // #include <string>
// // #include <vector>
// // #include <array>
// // #include <cmath>
// // #include <deque> 
// // #include <queue>
// // #include <stack>
// // #include <list>
// // #include <map>
// // #include <set>

// // // ========================== Namespace ========================================
// // using namespace std ;
// // // using namespace ranges ;

// // // ========================== Macro Definitions ================================
// // #define TUP tuple<int , int , int>
// // #define ull unsigned int int
// // #define PII pair<int , int>
// // #define int long long
// // #define ll long long
// // #define endl '\n'

// // // ========================== Constants ========================================
// // const int INF = 0x3f3f3f3f3f3f3f3f ;
// // const int MOD2 = 998244353 ; 
// // const int MOD = 1e9 + 7 ; 
// // const ll LINF = 1e18 ;

// // // ========================== Global Variables / Arrays ========================

// // // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // // unordered_set<int> st ;

// // vector<int> parent , hunter , prey ; 

// // int n , k ; 

// // // ========================== Functions ========================================


// // // int rand_num( int l , int r, bool unique = false) {
// // //     while (1) {
// // //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// // //         if ( !unique || st.insert(x).second ) return x ;
// // //     }
// // // }

// // void init() {
// //     parent.resize( n + 1 ) ;
// //     hunter.resize( n + 1 , 0 ) ;
// //     prey.resize( n + 1 , 0 ) ;
// //     for ( int i = 0 ; i <= n ; i ++ ) {
// //         parent[i] = i ;
// //         hunter[i] = i ;
// //         prey[i] = i ;
// //     }
// // }

// // int Find( int a , vector<int> &relationship ) {
// //     if ( relationship[a] == a ) 
// //         return a ;
// //     return relationship[a] = Find( relationship[a] , relationship ) ;
// // }

// // void Union( int a , int b , vector<int> &relationship ) {
// //     int pa = Find( a , relationship ) ;
// //     int pb = Find( b , relationship ) ;
// //     if ( pa != pb ) {
// //         relationship[pb] = pa ; 
// //     }
// // }

// // void solve() {
     


// // }

// // // ========================== Idea =============================================
// // /*



// // */
// // // ========================== Main Function ====================================
// // signed main() {
// //     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

// //     cin >> n >> k ; 
// //     init() ;
// //     int yes = 0 , no = 0 ; 
// //     while ( k -- ) {
// //         int op , x , y ; cin >> op >> x >> y ; 
// //         if ( op == 1 ) {
// //             if ( Find( Find( x , hunter ) , parent ) == Find( y , parent ) || Find( Find( x , prey ) , parent ) == Find( y , parent ) ) {
// //                 no ++ ; 
// //                 continue ;
// //             }
// //             Union( x , y , parent ) ;
// //             Union( hunter[x] , x , hunter ) ;
// //             Union( prey[x] , y , prey ) ;
// //         }
// //         else {
// //             if ( Find( x , parent ) == Find( y , parent ) || Find( Find( x , prey ) , parent ) == Find( y , parent ) ) {
// //                 no ++ ; 
// //                 continue ;
// //             }
// //             Union( prey[x] , y , parent ) ;
// //             Union( parent[x] , y , hunter ) ;
// //             Union( hunter[x] , y , prey ) ;
// //         }
// //     }

// //     cout << no << endl ;

// //     return 0 ;
// // }
// // // ========================== Question =========================================
// // /*

// // */



// // #include <iostream>
// // using namespace std;

// // const int MAXN = 50005;
// // // 三个集合：
// // // fa[x]：x的同类集合（1~N）
// // // fa[x+N]：x捕食的动物集合（N+1~2N）
// // // fa[x+2*N]：捕食x的动物集合（2N+1~3N）
// // int fa[3 * MAXN];

// // // 查找根节点 + 路径压缩（确保并查集效率）
// // int find(int x) {
// //     if (fa[x] != x) {
// //         fa[x] = find(fa[x]); // 路径压缩，直接指向根节点
// //     }
// //     return fa[x];
// // }

// // // 合并两个集合
// // void union_set(int x, int y) {
// //     int fx = find(x);
// //     int fy = find(y);
// //     if (fx != fy) {
// //         fa[fy] = fx; // 合并到同一根节点下
// //     }
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr); // 关闭同步，加速输入输出

// //     int N, K;
// //     cin >> N >> K;

// //     // 初始化并查集：每个节点的父节点是自身
// //     for (int i = 1; i <= 3 * N; ++i) {
// //         fa[i] = i;
// //     }

// //     int lie_count = 0; // 假话总数

// //     while (K--) {
// //         int op, X, Y;
// //         cin >> op >> X >> Y;

// //         // 基础假话判定1：X或Y超出动物编号范围
// //         if (X > N || Y > N) {
// //             lie_count++;
// //             continue;
// //         }

// //         // 基础假话判定2：op=2（X吃Y）时，X和Y是同一个（自己吃自己）
// //         if (op == 2 && X == Y) {
// //             lie_count++;
// //             continue;
// //         }

// //         if (op == 1) { // 说法1：X和Y是同类
// //             // 逻辑矛盾（不可能是同类）：
// //             // 情况1：X在Y的捕食集合中（Y吃X）
// //             // 情况2：Y在X的捕食集合中（X吃Y）
// //             if (find(X) == find(Y + N) || find(Y) == find(X + N)) {
// //                 lie_count++;
// //             } else {
// //                 // 真话：合并三类对应集合，维持同类关系
// //                 union_set(X, Y); // 合并同类集合
// //                 union_set(X + N, Y + N); // 合并捕食集合
// //                 union_set(X + 2 * N, Y + 2 * N); // 合并天敌集合
// //             }
// //         } else { // 说法2：X吃Y
// //             // 逻辑矛盾（不可能X吃Y）：
// //             // 情况1：X和Y是同类（find(X) == find(Y)）
// //             // 情况2：Y在X的天敌集合中（即X在Y的捕食集合中，Y吃X）
// //             if (find(X) == find(Y) || find(X) == find(Y + N)) {
// //                 lie_count++;
// //             } else {
// //                 // 真话：按捕食闭环合并集合，维持逻辑一致
// //                 union_set(X + N, Y); // X的捕食集合 <-> Y的同类集合（X吃Y）
// //                 union_set(X + 2 * N, Y + N); // X的天敌集合 <-> Y的捕食集合
// //                 union_set(X, Y + 2 * N); // X的同类集合 <-> Y的天敌集合
// //             }
// //         }
// //     }

// //     cout << lie_count << endl;
// //     return 0;
// // }
// #include <cstdio>

// inline int read() {
// 	char c = getchar(); int n = 0;
// 	while (c < '0' || c > '9') { c = getchar(); }
// 	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
// 	return n;
// }

// const int maxN = 100005;

// int n, m, ans, fa[maxN * 3];

// int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

// int main() {
// 	n = read(), m = read();
// 	for (int i = 1; i <= n * 3; i++) { fa[i] = i; }
// 	for (; m; m--) {
// 		int opt = read(), u = read(), v = read();
// 		if (u > n || v > n) { ans++; continue; }
// 		if (opt == 1) {
// 			if (find(u + n) == find(v) || find(u) == find(v + n)) { ans++; }
// 			else {
// 				fa[find(u)] = find(v);
// 				fa[find(u + n)] = find(v + n);
// 				fa[find(u + n + n)] = find(v + n + n);
// 			}
// 		} else {
// 			if (find(u) == find(v) || find(u) == find(v + n)) { ans++; }
// 			else {
// 				fa[find(u + n)] = find(v);
// 				fa[find(u + n + n)] = find(v + n);
// 				fa[find(u)] = find(v + n + n);
// 			}
// 		}
// 	}
// 	printf("%d\n", ans);
// 	return 0;
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
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
const int maxn = 1e9 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int  n , k ;
int fake ;

vector<int> fa ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {

	fa.resize( 3 * n + 1 ) ; 
	for ( int i = 1 ; i <= 3 * n ; i ++ ) {
		fa[i] = i ;
	}

}

int Find( int a ) {
	return fa[a] == a ? a : fa[a] = Find( fa[a] ) ;
}

void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

	cin >> n >> k ;
	init() ; 
	while ( k -- ) {
		int op , x , y ; 
		cin >> op >> x >> y ;
		if ( x > n || y > n ) {
			fake ++ ; 
			continue ; 
		}
		if ( op == 1 ) {
			if ( Find(x + n) == Find( y ) || Find( y + n ) == Find( x ) ) {
				fake ++ ; 
			} else {
				// 原来我是这样子写的
				// fa[Find(x)] = fa[Find(y)] ; 
				// fa[Find(x + n)] = fa[Find(y + n)] ; 
				// fa[Find(x + n + n)] = fa[Find(y + n + n)] ; 

				// 这个是正解 , 有个疑问 , 这里面 Find 的结果都是 n 以内的 
				// 也就是说 Fa 合并的时候只有小于 n 的参与合并操作
				// 但是 n 以内的不是都表示同类吗 , 其他的关系怎么表示的 

				// 表示同类的并查集是无向图 所以可以随意连接
				// 但是有向图怎么表示呢

				// 合并 x 和 y , 他俩是同类
				fa[Find( x )] = Find( y ) ; 
				// x的捕食者 和 y的捕食者 是同类
				fa[Find(x + n)] = Find(y + n) ; 
				// x的猎物 和 y的猎物 是同类
				fa[Find(x + 2 * n)] = Find(y + 2 * n) ; 
				

			}
		} 
		if ( op == 2 ) {

			if ( Find( x ) == Find( y ) || Find( y + n ) == Find( x ) ) {
				fake ++ ; 
			} else {
				// fa[Find( y + n )] = fa[Find( x )] ; 
				// fa[]

				// 正解
				// x 的猎人是 y
				fa[Find(x + n)] = Find(y);
				// x 的礼物是 y 的猎人
				fa[Find(x + n + n)] = Find(y + n);
				// x 的同类是 y的猎物
				fa[Find(x)] = Find(y + n + n);
				
			}
		}
	}
    
	cout << fake << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/


// #include <cstdio>

// inline int read() {
// 	char c = getchar(); int n = 0;
// 	while (c < '0' || c > '9') { c = getchar(); }
// 	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
// 	return n;
// }

// const int maxN = 100005;

// int n, m, ans, fa[maxN * 3];

// int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

// int main() {
// 	n = read(), m = read();
// 	for (int i = 1; i <= n * 3; i++) { fa[i] = i; }
// 	for (; m; m--) {
// 		int opt = read(), u = read(), v = read();
// 		if (u > n || v > n) { ans++; continue; }
// 		if (opt == 1) {
// 			if (find(u + n) == find(v) || find(u) == find(v + n)) { ans++; }
// 			else {
// 				fa[find(u)] = find(v);
// 				fa[find(u + n)] = find(v + n);
// 				fa[find(u + n + n)] = find(v + n + n);
// 			}
// 		} else {
// 			if (find(u) == find(v) || find(u) == find(v + n)) { ans++; }
// 			else {
// 				fa[find(u + n)] = find(v);
// 				fa[find(u + n + n)] = find(v + n);
// 				fa[find(u)] = find(v + n + n);
// 			}
// 		}
// 	}
// 	printf("%d\n", ans);
// 	return 0;
// }


/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

#include <bits/stdc++.h>

using namespace std ; 

#define int long long
#define endl '\n'

int n , k ;

vector<int> fa ; 
vector<int> dis ; 

void init() {
	cin >> n >> k ; 
	fa.resize( n + 1 ) ; 
	dis.resize( n + 1) ; 
	for ( int i = 1 ; i <= n ; i ++ ) fa[i] = i ; 
}

int Find( int a ) {
	if ( a == fa[a] ) return a ; 
	int faa = fa[a] ; 
	fa[a] = Find( faa ) ; 
	dis[a] += dis[faa] ; 
	dis[a] %= 3 ; 
	return fa[a] ;
}

void merge(int a, int b, int w) {
	int faa = Find( a ) ; 
	int fab = Find( b ) ; 
	if ( faa == fab ) return ; 
	fa[faa] = fab ; 
	dis[faa] = (dis[b] - dis[a] + w + 300000) % 3 ; 
} 

int query( int a , int b ) {
	int faa = Find( a ) ;
	int fab = Find( b ) ; 
	if ( a == b ) return (dis[a] - dis[b] + 300000) % 3 ; 
}

signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
	init() ; 
	
	int fake = 0 ; 

    while ( k -- ) {

		int op , x , y ; cin >> op >> x >> y ; 

		if (x > n || y > n || ( x == y && op == 2 ) ) { fake ++ ; continue ; }

		int fx = Find( x ) , fy = Find( y ) ; 
		if ( fx != fy ) {
			if ( op == 1 ) merge(x, y, 0) ; 
			else if ( op == 2 ) merge(x, y, 1) ;
		} else {
			if ( op == 1 && dis[x] != dis[y] ) fake ++ ; 
			else if ( op == 2 && query(x, y) != 1 ) fake ++ ; 
		}

	}

	cout << fake << endl ; 

    return 0 ;
}
