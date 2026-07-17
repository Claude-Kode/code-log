// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
我的问题是不够变通
本质上只有两种类型
一种无解一种有解

最重要的是这种题里面，是允许有无效操作的
也就是我可以选区间但是我什么都不敢
但是我钻牛角尖去想怎么算出一个准确的结果了
总结下来就是答案不是刚刚好的其实百分百可以
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ; cin >> n ;
		vector<int> arr ( n , 0 ) ; 
		int mn = 0 , mx = 0 ;
		for ( int i = 0 ; i < n ; i ++ ) {
			cin >> arr[i] ; 
			if ( arr[i] < arr[mn] ) mn = i ;
			if ( arr[i] > arr[mx] ) mx = i ; 
		}
		string x ; cin >> x ;
		if ( x.front() == '1' || x.back() == '1' ) { cout << -1 << endl ; continue ; }
		if ( x[mn] == '1' || x[mx] == '1' ) { cout << -1 << endl ; continue ; } 
		cout << 5 << endl ;
		cout << 1 << ' ' << min ( mn + 1 , mx + 1 ) << endl ;
		cout << min ( mn + 1 , mx + 1 ) << ' ' << max ( mn + 1 , mx + 1 ) << endl ;
		cout << max ( mn + 1 , mx + 1 ) << ' ' << n << endl ;
		cout << 1 << ' ' << max ( mn + 1 , mx + 1 ) << endl ;
		cout << min ( mn + 1 , mx + 1 ) << ' ' << n << endl ;
	}  
	return 0 ;
}
//questions ：
/*

*/