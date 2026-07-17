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
    map<int , int> ump ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        int len ; cin >> len ; 
        ump[len] ++ ; 
    }
    int sum = 0 ; 
    int usedSides = 0 ; 
    vector<int> remSides ; 
    for ( auto &[sideLen , cnt] : ump ) {
        sum += sideLen * (cnt / 2) * 2 , usedSides += (cnt / 2) * 2 ; 
        if ( cnt & 1 ) remSides.push_back( sideLen ) ;
    }

    if ( sum == 0 ) {
        cout << 0 << endl ;
        return ; 
    }

    int last = 0 , boostVal = 0 ; 
    for ( auto &a : remSides ) {
        if ( last + sum > a ) 
            boostVal = last + a ;
        last = a ;
    }
    if ( usedSides == 2 && boostVal == 0 ) 
        cout << 0 << endl ;
    else 
        cout << sum + boostVal << endl ;

}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    int tt ; cin >> tt ; 
    while( tt -- ) solve() ; 
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/




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
//     map<int , int> mp ; 
//     int temp ; 
//     for ( int i = 0 ; i < n ; i ++ ) 
//         cin >> temp , mp[temp] ++ ; 
//     int sum = 0 ; 
//     int cntSides = 0 ; 
//     vector<int> remLens ; 
//     for ( auto &[val , cnt] : mp ) {
//         if ( cnt > 1 ) {
//             // cout << cnt  ; 
//             // int delta_cnt = 1 ; 
//             sum += val * (cnt / 2) * 2 ;
//             cntSides += (cnt / 2) * 2 ; 
//             // cout << val << ' ' << cnt << endl ; 
//         }
//         if ( cnt & 1 ) remLens.push_back( val ) ; 
//     } 

//     // for ( auto &a : remLens ) cout << a << ' ' ; 

//     if ( sum == 0 ) {
//         cout << 0 << endl ; 
//         return ; 
//     }
//     int add = 0 ; 
//     int last = 0 ; 
//     // 值得一提的是添加边的逻辑
//     // 其实根本不是添加边
//     // 这道题完全可以用极限的思想 你把 sum 拆成相等的两部分作为等腰梯形的腰 
//     // 你要找一个上底 找一个下底
//     // 上底设为 x 下底设为 y 
//     // x + sum < y 要满足 注意 这里的腰是可以无限长的 无所谓的 重要的是上下底
//     // 也就是说 x + y 与 sum 根本就没有关系
//     // 重要是的这两个关系 sum + x < y || sum + y < x 
 
//     for ( auto &a : remLens ) {
//         // 这里是枚举过去的边 
//         // 这里的关键其实是一个 x , y , sum 的关系
//         // 最后的结果其实是要求 x < y + sum , y < x + sum 
//         // 我们这里假设 x < y 也就是说 sum + x < y 是一定成立的
//         // 我的一个重大误区就是两条边单独选 其实这道题是给 y 挑选一个合适的 x
//         // 我的误区是 x 应该要符合 x < sum 但是其实不用
//         // 比如 sum = 2 , x = 3 y = 4 
//         // x 按照我的逻辑是不能添加到里面的 但是其实和 y 一组合就可以
//         // 所以这里其实还真的差不多是一个动态规划   
//         if ( sum + last > a ) {
//             add = a + last ; 
//         }
//         last = a ;
//     }    
//     if ( cntSides == 2 && add == 0 ) cout << 0 << endl ; 
//     else cout << sum + add << endl ; 
//     // for ( auto &a : remLens ) 
//     //     if ( a < sum ) add = max( add , a ) ; 

//     // if ( add == 0 && cntSides == 2 ) {
//     //     cout << 0 << endl ; 
//     //     return ; 
//     // }
//     // // cout << "haihuozhe " ; 

//     // if ( add == 0 ) {
//     //     cout << sum << endl ;
//     //     return ;  
//     // }
//     // remLens.erase( find( remLens.begin() , remLens.end() , add ) ) ;
//     // sum += add ; 
//     // add = 0 ;
//     // for ( auto &a : remLens ) 
//     //     if ( a < sum ) add = max( add , a ) ;
//     // sum += add ; 
//     // cout << sum << endl ; 

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


// // Problem: C. Symmetrical Polygons
// // Contest: Codeforces - Codeforces Round 1057 (Div. 2)
// // URL: https://codeforces.com/contest/2153/problem/C
// // Memory Limit: 256 MB
// // Time Limit: 2000 ms

// // Powered by CP Editor (https://cpeditor.org)

// #include<bits/stdc++.h>
// // #pragma GCC optimize("Ofast")
// // #pragma GCC optimize("unroll-loops")
// // #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// using namespace std;
// #define int long long
// inline int read(){
//    int s=0,w=1;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
//    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
//    return s*w;
// }
// const int p=998244353;
// int qp(int x,int y)
// {
// 	int res=1;
// 	for(int t=x; y; y>>=1,t=1ll*t*t%p)
// 		if(y&1) res=1ll*res*t%p;
// 	return res;
// }
// int a[1<<20];
// signed main()
// {
// 	for(int T=read();T--;)
// 	{
// 		int n=read();
// 		map<int,int> mp;
// 		for(int i=1; i<=n; ++i) ++mp[read()];
// 		int ans=0,d=0,c=0,D=0;
// 		// for(int i=1; i<=n; ++i)
//         // D 是边的数量
// 		for(auto [x,y]:mp) ans+=(y/2)*2*x,D+=(y/2)*2;
// 		if(ans==0){puts("0");continue;}
// 		int last=0;
//         // 这里是一个类似的滚动更新 last 作为基量 c 是 last 和新增量的累加
// 		for(auto [x,y]:mp)
//         // 这里用到了 枚举右维护左
//         // 同时做了一个 c 作为整体 还运用了单调性保证答案最优性和更新限制
//         // 真牛逼
// 			if(y&1)
// 			{
// 				if(last+ans>x) c=last+x;
// 				last=x;
// 			}
// 		if(D==2&&c==0) puts("0");
// 		else printf("%lld\n",ans+c);
//         // cout << "ans:" << ans << endl ;
//         // cout << endl << "c:" << c << ' ' << "last:" << last << endl ; 

// 	}
// 	return 0;
// }
