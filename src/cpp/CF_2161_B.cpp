// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
// macro definition
#define endl '\n'
#define int long long
// #define define define
// #define define define
// #define define define
// #define define define
// #define define define
// #define define define
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	// 我的想法是就是建立判断公式来进行检验
	// 如果对于某个和别人链接不上的 , 任意位置加上以后都违规的输出-1
	// 对于一开始就是全部连接上的直接输出 0 
	// 但是这一步如果会输出-1会不会是由全面的非最优选择造成的
	// 如果初始有三个直连的直接输出 -1
	// 如果有2 * 2的矩阵 ， 整个图只能有这四个 ， 否则无论怎样都是输出 -1
	// 答案只能是一步一拐的图形而且不能变向变向就是 -1
	// 直接从一个点出发 搜索四个方向的一步一拐 ，如果有这条线以外的连接不到的直接就是-1否则就是yes
	int t ; cin >> t ;
	while ( t -- ) {
		int n ; cin >> n ;
		set<int> dg1 , dg2 , rows , cols ;
		for ( int i = 1  ; i <= n ; i ++ ) {
			for ( int j = 1 ; j <= n ; j ++ ) {
				char temp ; cin >> temp ;
				if ( temp== '#' ) {
					dg1.insert( i - j ) ;
					dg2.insert( i + j ) ; 
					rows.insert( i ) ;
					cols.insert( j ) ;
				}
			}
		}
		auto chk = [&]( set<int> s ) {
			return s.size() <= 1 || *s.rbegin() - *s.begin() == 1 ; 
		} ;
		chk( dg1 ) || chk( dg2 ) || chk( rows ) && chk( cols ) ? cout << "YES" << endl : cout << "NO" << endl ;
		// set<int> diag1 , diag2 ;
		// int blk = 0 ; 
		// for ( int i = 1 ; i <= n ; i ++ ) {
		// 	for ( int j = 1 ; j <= n ; j ++ ) {
		// 		char temp ; cin >> temp ;
		// 		if ( temp == '#' ) {
		// 			blk ++ ;
		// 			diag1.insert(i - j) ;
		// 			diag2.insert(i + j) ; 
		// 		}
		// 	}
		// }
		// if ( n == 1 ) { cout << "YES" << endl ; continue ; }
		// auto chk = [&] ( set<int> s1 , set<int> s2 ) -> bool {
		// 	return ( s1.size() <= 1 || *s1.rbegin() - *s1.begin() == 1 ) && s2.size() == blk || 
		// 		   ( s2.size() <= 1 || *s2.rbegin() - *s2.begin() == 1 ) && s1.size() == blk || 
		// 		   s1.size() == 3 && s2.size() == 3 && blk == 4 ;
		// } ;
		// chk( diag1 , diag2 ) ? cout << "YES" << endl : cout << "NO" << endl ;
		// 对角线和反对角线的特征系数 i - j & i + j 
		// 只能要两条相邻的正或反对角线 或者一个2 * 2 的矩阵
		// 如果只有两条正对角线 ， set diag1 会只有两种元素 同时diag2会有跟黑色点数量一样多的元素
		// 所以只要 return set<int> s1 set<int> s2 
		// return s1 == 2 && s2.size() == black || s1.size() == black && s2.size() == 2 || s1.size() == 3 && s2.size() == 3



	// 	int initial_black = 0  ;
	// 	bool sign = true ;
	// 	int first_x = 0 , first_y = 0 ;
	// 	vector<pair<int , int>> coordinate ;
	// 	for ( int i = 1 ; i <= n ; i ++ ) {
	// 		for ( int j = 1 ; j <= n ; j ++ ) {
	// 			char temp ; cin >> temp ;
	// 			if ( temp == '#' ) {
	// 				initial_black ;
	// 				if ( sign ) {
	// 					first_x = i ; 
	// 					first_y = j ;
	// 					sign = false ;
	// 				}
	// 				else {
	// 					coordinate.emplace_back( i , j ) ;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	if ( initial_black == 0 || n <= 2 ) { cout << "YES" << endl ; continue ; }
	// 	int k1 = first_y - first_x , k2 = first_x + first_y ;
	// 	// 找一个基准点统计六条对角线
	// 	for ( auto &[x , y] : coordinate ) {
	// 		if ( x + y == k2 ) 
	// 		else if ( x + y == k2 + 2 ) 
	// 		else if ( x + y == k2 - 2 ) 
	// 		else if ( y - x == k1 )
	// 		else if ( y - x == k1 + 2 )
	// 		else if ( y - x == k1 - 2 )
	// 	}
	}
	return 0 ;
}
//questions ：
/*

*/
// int main() {
//   multiCase() {
//     int n; cin >> n;
//     auto M = read<string>(n);
 
//     set<int> s1, s2, m1, m2;
 
//     for (int i = 0; i < n; i ++)
//       for (int j = 0; j < n; j ++)
//         if (M[i][j] == '#')
//           m1.insert(i - j), m2.insert(i + j), s1.insert(i), s2.insert(j);
 
//     auto chk = [&] (set<int> st) {
//       return st.size() <= 1 || *st.rbegin() == *st.begin() + 1;
//     };
 
//     bool flg = chk(m1) || chk(m2) || (chk(s1) && chk(s2));
 
//     YES(flg);
//   }
//   return 0;
// }