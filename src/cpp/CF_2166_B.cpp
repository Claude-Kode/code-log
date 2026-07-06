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

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		int a , b , n ;
		cin >> a >> b >> n ;
		// 证明最后一个标签也是不是
		// 如果一直是 a / m 或者一直是 b 就是需要一次
		if ( a <= b || b * n <= a ) cout << 1 << endl ;
		// 如果是 a / m 就到屏幕的最后 如果是b就到第一块
		else {
			cout << 2 << endl ;
		} 
	}
	return 0 ;
}
//questions ：
/*

*/