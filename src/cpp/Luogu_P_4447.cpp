// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
组内人数 = arr.back() - arr.front() + 1 
这题有点像那个区间的问题 ， 几个区间可以拼在一起
这个题要求最少的区间
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	vector<int> arr ( n ) ;
	for ( auto &a : arr ) cin >> a ;
	sort ( arr.begin() , arr.end() ) ;
	vector <vector<int>> groups ;
	for ( auto &a : arr ) {
		// 一开始 0 个小组 ， 初始化第一个小组
		if ( groups.empty() ) groups.push_back({ a }) ;
		else {
			// groups_num , 目前分出多少个小组
			int groups_num = groups.size() ;
			// index是要填充的小组的下标 , sentry_size是检测所有组的最少人数
			int index = -1 , sentry_size = 1145141919810 ;
			for ( int i = 0 ; i < groups_num ; i ++ ) {
				if ( groups[i].back() + 1 == a && groups[i].size() < sentry_size ) {
					// legal and rec
					index = i ; sentry_size = groups[i].size() ;
				}
			}
			// sj
			if ( index == -1 ) groups.push_back({ a }) ;
			// 分组
			else groups[index].push_back( a ) ;
		}
	}
	// cal ans
	int ans = 1145141919810 ;
	for ( auto &a : groups ) ans = min( ans , (long long )( a.size() ) ) ;
	cout << ans ; 
	return 0 ;
}
//questions ：
/*

*/