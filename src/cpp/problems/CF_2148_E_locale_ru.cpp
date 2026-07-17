// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
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
		int n , k ;
		cin >> n >> k ;
		vector<int> arr ( n ) ;
		bool sign = true ;
		for ( auto &a : arr ) cin >> a ;
		// 如果没有元素能满足 fre[i] % k == 0 return 0
		// 因为是每个都处理所以不存在每个数组都有没有一个元素来达到awsome
		// 可能唯一的入手点是除了子数组范围内的元素其他的都不会被搞到1号数组里？
		
	}
	return 0 ;
}
//questions ：
/*

*/