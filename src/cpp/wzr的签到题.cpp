// header file
#include <iostream>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
这道题的关键在于什么时候天平会返回不相等
如果返回了不相等 ， 则只需要再进行一次比较就可以确定正品 ，所以再进行寻找最后一个物品可以用这个 + 1
特殊情况的判断
如果 x == 1 最多只需要两次 n <= 3的时候只需要一次
如果 x == n - 1 最多需要 x - 1 
如果 x < n - 1 最多需要 x - 1 次 
如果 n <= 3 
x == 1 1次 x == 2 2次
等等 似乎三个里面选出一个是子问题
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , x ;
	cin >> n >> x ;
	if ( n <= 3 ) {
		if ( x == 1 ) cout << 1 << endl ;
		if ( x == 2 ) cout << 2 << endl ;
	} else {
		if ( x == 1 ) cout << 2 << endl ;
		else cout << x - 1 ; 
	}
	return 0 ;
}
//questions ：
/*

*/