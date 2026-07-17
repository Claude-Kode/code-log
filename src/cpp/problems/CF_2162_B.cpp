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
双指针 ， 主要不相同就删左指针
如果一开始左指针是0 ， 左指针只能删到经过1后的第一个0前方
如果左指针一开始是1 ， 删到第一个0就停止
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ; cin >> n ;
		string str ; cin >> str ;
		vector<int> ans ;
		for ( int i = 0 ; i < n ; i ++ ) {
			if ( str[i] == '0' ) ans.push_back( i ) ;
		}
		cout << ans.size() << endl ;
		if ( !ans.empty() ) {
			for ( auto &a : ans ) cout << a + 1 << ' ' ;
		} 
		cout << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/