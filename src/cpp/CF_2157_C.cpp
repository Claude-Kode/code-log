// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
// macro definition
#define endl '\n'
#define int long long
#define maxn 1000000000
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
c == 1 在 l 和 r 范围必须 有 k 且范围里只能出现 >= k 的数
c == 2 在 l 和 r 范围必须 没有 k 而且必须每个范围里都有 1 --- k - 1 所有数字出现
直接初始化全都是 1e9

一开始的思路
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int tt ; cin >> tt ;
	while ( tt -- ) {
		int n , k , q ; cin >> n >> k >> q ;
		vector<int> ans ( n + 1 , k ) ;
		vector<int> c1 ( n + 1 , 0 ) , c2 ( n + 1 , 0 ) ;
		while ( q -- ) { 
			int c , l , r ; cin >> c >> l >> r ;
			if ( c == 1 ) for ( int i = l ; i <= r ; i ++ ) c1[i] = 1 ;
			if ( c == 2 ) for ( int i = l ; i <= r ; i ++ ) c2[i] = 1 ;
		}
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( c1[i] && c2[i] ) ans[i] = 1e9 ;
			if ( !c1[i] && c2[i] ) ans[i] = i % k ;
			cout << ans[i] << ' ' ;
		}
		cout << endl ;
	}
	return 0 ; 
}
//questions ：
/*

// // */
// // #include <iostream>
// // #include <algorithm>
// // #include <vector>
// // #include <string>
// // // macro definition
// // #define endl '\n'
// // #define int long long
// // #define maxn 1000000000
// // // namespace declarations
// // using namespace std ;

// // // codes
// // signed main(){
// // 	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
// // 	int tt ; cin >> tt ;
// // 	while ( tt -- ) {
// // 		int n , k , q ; cin >> n >> k >> q ;
// // 		vector<int> ans ( n + 1 , 0 ) ;
// // 		vector<pair<int , int>> a1 , a2 ; 
// // 		while ( q -- ) {
// // 			int c , l , r ; cin >> c >> l >> r ;
// // 			if ( c == 1 ) 
// // 				a1.emplace_back( l , r ) ;
// // 			else 
// // 				a2.emplace_back( l , r ) ;
// // 		}
// // 		sort ( a2.begin() , a2.end() ) ;
		
// // 		for ( auto [l , r] : a1 ) 
// // 			for ( int i = l ; i <= r ; i ++ ) 
// // 				if ( ans[i] == k ) ans[i] = k ;  // 保留原有逻辑
				
// // 		for ( auto [l , r] : a2 ) {
// // 			vector<int> mark ( k , 0 ) ;
// // 			mark[0] = 1 ;
// // 			for ( int i = l ; i <= r ; i ++ ) {
// // 				// 重叠部分处理
// // 				if ( ans[i] == k ) 
// // 					ans[i] = 1000 ;
// // 				else if ( ans[i] > 0 && ans[i] <= k - 1 ) 
// // 					mark[ans[i]] = 1 ;  // 修复语法错误：原mark[i]改为mark[ans[i]]（避免越界）
// // 				else if ( ans[i] == 0 ) {  // 简化条件，保留原有赋值逻辑
// // 					for ( int j = 1 ; j <= k - 1 ; j ++ ) {
// // 						if ( !mark[j] )  { 
// // 							ans[i] = j ; 
// // 							mark[j] = 1 ;  // 标记已使用，确保所有数字都能出现
// // 							break ; 
// // 						}
// // 					}
// // 				}
// // 			}
// // 	return 0 ;
// // }
// // #include <iostream>
// // #include <algorithm>
// // #include <vector>
// // #include <string>
// // // macro definition
// // #define endl '\n'
// // #define int long long
// // #define maxn 1000000000
// // // namespace declarations
// // using namespace std ;
// // // global variables && arrays

// // // functions declarations

// // //idea
// // /*
// // c == 1 在 l 和 r 范围必须 有 k 且范围里只能出现 >= k 的数
// // c == 2 在 l 和 r 范围必须 没有 k 而且必须每个范围里都有 0 --- k - 1 所有数字出现
// // 直接初始化全都是 0（多余的不处理是0）
// // */
// // // codes
// // signed main(){
// // 	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
// // 	int tt ; cin >> tt ;
// // 	while ( tt -- ) {
// // 		int n , k , q ; cin >> n >> k >> q ;
// // 		vector<int> ans ( n + 1 , 0 ) ;  // 初始化0，多余保留0
// // 		vector<pair<int , int>> a1 , a2 ; 
// // 		while ( q -- ) {
// // 			int c , l , r ; cin >> c >> l >> r ;
// // 			if ( c == 1 ) 
// // 				a1.emplace_back( l , r ) ;
// // 			else 
// // 				a2.emplace_back( l , r ) ;
// // 		}
// // 		sort ( a2.begin() , a2.end() ) ;
// // 		for ( auto [l , r] : a1 ) 
// // 			for ( int i = l ; i <= r ; i ++ ) 
// // 				ans[i] = k ;
// // 		for ( auto [l , r] : a2 ) {
// // 			vector<int> mark ( k , 0 ) ;  
// // 			vector<int> free_pos ;  
// // 			for ( int i = l ; i <= r ; i ++ ) {
// // 				if ( ans[i] == k ) ans[i] = 1000 ; 
// // 				else free_pos.push_back(i) ; 
// // 			}
			
// // 			int idx = 0 ;
// // 			for ( int num = 0 ; num < k ; num ++ ) {  // 0~k-1
// // 				if ( idx < free_pos.size() ) { ans[free_pos[idx]] = num ; idx ++ ; }
// // 			}
// // 		}
		
// // 		for ( int i = 1 ; i <= n ; i ++ ) cout << ans[i] << ' ' ;
// // 		cout << endl ;
// // 	}
// // 	return 0 ;
// // }
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// // macro definition
// #define endl '\n'
// #define int long long
// #define maxn 1000000000
// // namespace declarations
// using namespace std ;
// // global variables && arrays

// // functions declarations

// //idea
// /*
// c==1: [l,r] min =k → 全≥k 且 至少有一个k
// c==2: [l,r] MEX=k → 含0~k-1所有数字 且 不含k
// 初始化全为0
// */
// // codes
// signed main(){
// 	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
// 	int tt ; cin >> tt ;
// 	while ( tt -- ) {
// 		int n , k , q ; cin >> n >> k >> q ;
// 		vector<int> ans ( n + 1 , 0 ) ;  // 初始化0
// 		vector<pair<int , int>> a1 , a2 ; 
// 		while ( q -- ) {
// 			int c , l , r ; cin >> c >> l >> r ;
// 			if ( c == 1 ) 
// 				a1.emplace_back( l , r ) ;
// 			else 
// 				a2.emplace_back( l , r ) ;
// 		}
// 		sort ( a2.begin() , a2.end() ) ;
// 		for ( auto [l , r] : a1 ) 
// 			for ( int i = l ; i <= r ; i ++ ) 
// 				ans[i] = k ;
// 		for ( auto [l , r] : a2 ) {
// 			vector<int> mark ( k , 0 ) ; 
// 			vector<int> aaa ;     

// 			for ( int i = l ; i <= r ; i ++ ) {
// 				if ( ans[i] == k ) {
// 					ans[i] = k + 1 ; 
// 				} else {
// 					aaa.push_back(i) ;
// 				}
// 			}
// 			int idx = 0 ;
// 			for ( int num = 0 ; num < k ; num ++ ) {
// 				if ( idx < aaa.size() ) {
// 					ans[aaa[idx]] = num ;
// 					mark[num] = 1 ;
// 					idx ++ ;
// 				}
// 			}
// 		}
// 		for ( int i = 1 ; i <= n ; i ++ ) cout << ans[i] << ' ' ;
// 		cout << endl ;
// 	}

// 	return 0 ;
// }
// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// #include <string>

// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         // 这里原Python中有一个input()未使用，C++中也读取并忽略
//         string dummy;
//         cin >> dummy;
//         string s;
//         cin >> s;
//         map<char, int> ct;
//         for (char c : s) {
//             ct[c]++;
//         }
//         vector<int> cnts;
//         for (auto& pair : ct) {
//             cnts.push_back(pair.second);
//         }
//         sort(cnts.begin(), cnts.end());
//         while (cnts.size() > 1) {
//             cnts.back()--;
//             cnts[cnts.size() - 2]--;
//             sort(cnts.begin(), cnts.end());
//             if (cnts[1] == 0) {
//                 cnts.erase(cnts.begin(), cnts.begin() + 2);
//             } else if (cnts[0] == 0) {
//                 cnts.erase(cnts.begin());
//             }
//         }
//         cout << (cnts.empty() ? 0 : cnts[0]) << endl;
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// #define nl "\n"
// #define nf endl
// #define ll long long
// #define pb push_back
// #define _ << ' ' <<

// #define INF (ll)1e18
// #define mod 998244353
// #define maxn 110

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     #if !ONLINE_JUDGE && !EVAL
//         ifstream cin("input.txt");
//         ofstream cout("output.txt");
//     #endif

//     ll t ; cin >> t ;
//     while ( t -- ) {
//         ll n , k , q ; cin >> n >> k >> q ;
//         vector<ll> a ( n + 1 , 0 ) ;
//         // 两组映射关系判断是不是重复的
//         vector<ll> mn ( n + 1, 0 ) , mx ( n + 1, 0 ) ;
//         while (q--) {
//             ll c , l , r ; cin >> c >> l >> r;
//             for ( ll i = l ; i <= r ; i ++ ) {
//                 if (c == 1) mn[i] = 1 ;
//                 else mx[i] = 1 ;
//             }
//         }
//         // 通过取模的方式就不用一组一组处理还要判断前面组用过哪些真的牛逼
//         for (ll i = 1 ; i <= n ; i++) {
//             if ( mn[i] == 1 && mx[i] == 1 ) a[i] = k + 1 ;
//             else if ( mx[i] == 1 ) a[i] = i % k ;
//             else a[i] = k ;
//         }

//         for ( ll i = 1 ; i <= n ; i ++ ) cout << a[i] << ' ' ;
//         cout << nl ;
//     }

//     return 0 ;
// }
