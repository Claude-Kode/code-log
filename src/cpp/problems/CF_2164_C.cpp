// // header file
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue> 
// // #include <bits/stl_iterator_base_funcs.h>
// // macro definition
// #define endl '\n'
// #define int long long
// // namespace declarations
// using namespace std ;
// // global variables && arrays

// // functions declarations

// //idea
// /*
// 贪心的想 ， 对于每个伤害我们选择尽可能大的可以杀死的怪物的生命值杀掉
// 直接暴力模拟写法安排上
// 有没有可能因为没杀死血量小但是回报高的怪物导致不是最优解呢
// 杀死怪物的优先级是什么
// */
// // codes
// signed main() {
// 	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
// 	int tt ; cin >> tt ;
// 	while ( tt -- ) {
// 		int n , m ; cin >> n >> m ;
// 		vector<int> dmg ( n ) ;
// 		vector<pair<int , int>> mons ( m ) ;
// 		for ( auto &a : dmg ) cin >> a ;
// 		for ( auto &[hp , fb] : mons ) cin >> hp ;
// 		for ( auto &[hp , fb] : mons ) cin >> fb ;
// 		sort ( dmg.begin() , dmg.end() ) ;
// 		sort ( mons.begin() , mons.end() , [&] (  pair<int , int> &a , pair<int , int> &b ) {
// 			// fb == 0 的排在后面 剩余的直接按照 hp 进行排列
//             if ( a.second == 0 && b.second == 0 ) return a.first < b.first ;
//             if ( a.second == 0 ) 			  	  return false ;
//             if ( b.second == 0 ) 			  	  return true ;
//             					  			  	  return a.first < b.first ;
// 		}) ;
// 		int i = 0 ; 
// 		while ( !dmg.empty() && i < m ) {
// 			auto &[hp , fb] = mons[i] ;
// 			if ( fb == 0 ) break ;
// 			int cur = dmg.back() ; dmg.pop_back() ;
// 			if ( cur >= hp ) {
// 				if ( fb ) dmg.push_back( max ( cur , fb ) ) ;
// 				i ++ ; 
// 			} 
// 		}
// 		int j = 0 , lim = dmg.size() ;
// 		while ( j < lim && i < m ) {
// 			int cur = dmg[j] ; j ++ ; 
// 			auto &[hp , fb] = mons[i] ;
// 			if ( cur >= hp ) i ++ ;
// 		}
// 		cout << i << endl ;
// 	}
// 	return 0 ;
// }
// //questions ：
// /*

// */
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #define endl '\n'
// #define int long long
// using namespace std;

// signed main() {
//     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//     int tt; cin >> tt;
//     while (tt--) {
//         int n, m; cin >> n >> m;
//         vector<int> dmg(n);
//         vector<pair<int, int>> mons(m);
        
//         // 读取伤害值
//         for (auto &a : dmg) cin >> a;
//         // 读取怪物hp和fb（分两次读，和输入格式匹配）
//         for (auto &[hp, fb] : mons) cin >> hp;
//         for (auto &[hp, fb] : mons) cin >> fb;
        
//         // 关键：伤害值降序排序，确保每次取最大伤害（贪心核心）
//         sort(dmg.rbegin(), dmg.rend());
        
//         // 怪物排序：有反馈的在前（优先赚反馈伤害），同类型按hp升序（少浪费伤害）
//         sort(mons.begin(), mons.end(), [](auto &a, auto &b) {
//             if (a.second == 0 && b.second == 0) return a.first < b.first;
//             if (a.second == 0) return false;
//             if (b.second == 0) return true;
//             return a.first < b.first;
//         });
        
//         int kill_cnt = 0;
//         // 循环条件：有伤害 + 还没杀完所有怪物
//         while (!dmg.empty() && kill_cnt < m) {
//             int cur_dmg = dmg.back();
//             dmg.pop_back(); // 取出当前最大伤害
            
//             auto &[mon_hp, mon_fb] = mons[kill_cnt];
//             if (cur_dmg >= mon_hp) { // 能杀死当前怪物
//                 kill_cnt++;
//                 if (mon_fb != 0) { // 有反馈伤害，入栈（取最大值，避免无效替换）
//                     dmg.push_back(max(cur_dmg, mon_fb));
//                 }
//             }
//             // 不需要额外break，kill_cnt >= m时循环自动退出
//         }
        
//         cout << kill_cnt << endl;
//     }
//     return 0;
// }
// header file
#include <iostream>
#include <algorithm>
#include <vector>
// #include <unordered_map>
// #include <stack>
// #include <map>
#include <queue>
// #include <deque>
// macro definition
#define endl '\n'
#define int long long
#define gap ' ' 
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

// idea
/*
我的问题是
1. 第一阶段的贪心策略是错的 伤害也应该从小到大贪心
2. 第一阶段处理剑的方式不对 用不到的剑应该存起来而不是直接 pop 掉
3. 对于第一阶段和第二阶段的处理方式比较麻烦 本题把 c == 1 和 c == 2 分开存储处理比较合适
*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int tt ; cin >> tt ; 
	while ( tt -- ) {
		int n , m ; cin >> n >> m ;
		priority_queue<int , vector<int> , greater<int>> pq ; 
		vector<pair<int , int>> mons ( m ) ; 
		for ( int i = 0 ; i < n ; i ++ ) { int temp ; cin >> temp ; pq.push( temp ) ; }
		for ( auto &[hp , fb] : mons ) cin >> hp ;
		for ( auto &[hp , fb] : mons ) cin >> fb ; 
		vector<pair<int , int>> mons1 , mons2 ; 
		for ( auto &[hp , fb] : mons ) {
			if ( fb ) mons1.emplace_back( hp , fb ) ;
			else mons2.emplace_back( hp , fb ) ;  
		}
		sort ( mons1.begin() , mons1.end() , [&] ( pair<int , int> &a , pair<int , int> &b ) {
			return a.first < b.first ; 
		}) ;
		sort ( mons2.begin() , mons2.end() , [&] ( pair<int , int> &a , pair<int , int> &b ) {
			return a.first < b.first ; 
		}) ;
		// main process 
		vector<int> temp ; 
		int cnt = 0 ;

		int i = 0 , lim1 = mons1.size() ;
		while ( !pq.empty() && i < lim1 ) {
			int dmg = pq.top() ; pq.pop() ; 
			auto [hp , fb] = mons1[i]  ;
			if ( dmg >= hp && ++ cnt && ++ i ) pq.emplace( max ( dmg , fb ) ) ;
			else temp.push_back( dmg ) ;
		} 

		for ( auto &a : temp ) pq.emplace( a ) ;

		int j = 0 , lim2 = mons2.size() ;
		while ( !pq.empty() && j < lim2 ) {
			int dmg = pq.top() ; pq.pop() ; 
			auto [hp , fb] = mons2[j]  ;
			if ( dmg >= hp && ++ j ) cnt ++ ;  
		}

		cout << cnt << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/