// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
如果要让删掉的数字最小
原则 高位的数字小更优先
其次是不能改变数字的相对顺序
从高位开始优先删掉最大的数字
从小到大统计每个数字出现的个数，从小到大依次累加到 n - k 个
大汉掉的数字从大到小要遵循高位优先删掉的原则
不要瞎思考，贪心就是局部最优到全局最优
这里的全局是删除k个数字让剩下的最大
局部是删掉一个数字让剩下的最大
局部到全局是，每次都删掉一个数，都使删掉以后剩下的数最小，最后能得到删掉k个以后最小的数
现在的问题变成了，如何删掉一个数字，让剩下的最小呢
数小，要求高位尽可能小，低位没有高位优先
所以最后的答案应该是尽可能严格递增的
所以删掉每个递增区间的最后一个或者递减区间的第一个
如果都递增，直接删掉最大的即可
删掉后的数的大小由这个数字前面的序列决定的于后面无关
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	string sample ;
	cin >> sample ;
	int k ;
	cin >> k ;
	string str ;
	for ( auto &a : sample ) {
		// // empty stack sj
		// if ( str.empty() ) str.push_back( a ) ;
		// // delete the last num of decending serial 
		// else {
		// 	// if increasing , take into the stack
		// 	if ( a >= str.back() ) str.push_back( a ) ;
		// 	// if not , && can be deleted , delete and cal the delete times 
		// 	else if ( k > 0 )   { k -- ; continue ; }
		// 	// if delete times is 0 , push back remaing elements 
		// 	else if ( k == 0 )    str.push_back( a ) ;
		// }
		while ( k > 0 && !str.empty() && a < str.back() ) {
			str.pop_back() ; k -- ;
		}
		str.push_back( a ) ;
//		cout << k << ' ' << str << endl ;
	}
//	cout << str << ' ' ;
	while ( !str.empty() && str.front() == '0' ) str.erase( str.begin() ) ; 
	while ( k && !str.empty() ) { str.pop_back() ; k -- ; }
	if ( str.empty() ) cout << 0 << endl ;
    else cout << str << endl ;
	return 0 ;
}
//questions ：
/*

*/