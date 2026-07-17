// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map> 
#include <map>
// macro definition
#define endl '\n'
#define int long long
#define gap ' ' 
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
这道题求的就是包含 1 - n 所有序号的最短区间
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m ;
	cin >> n >> m ;
	vector<int> arr ( n ) ;
	for ( auto &a : arr ) cin >> a ;

	int l = 0 , r = 0 ;
	unordered_map <int , int> mp ; 
	mp[arr[0]] ++ ;
	// 循环的终止条件是 当 r == n - 1 之后 l不再可以更新
	int ans_l , ans_r = r , min_len = 114514191810 ;
	while ( r < n - 1 ) {
		// cout << l << gap << r << gap << mp.size() << endl ;
		if ( mp.size() < m ) 
			mp[arr[++r]] ++ ; 
		while ( mp.size() == m ) {
			// legal and rec
			if ( min_len > r - l + 1 ) 
				{ ans_l = l + 1 ; ans_r = r + 1 ; min_len = r - l + 1 ; } 
			mp[arr[l]] == 1 ? mp.erase( arr[l++] ) : mp[arr[l++]] -- ;
		}
	}
	// cout << endl ;
	cout << ans_l << gap << ans_r << endl ;
	return 0 ;
}
//questions ：
/*

*/