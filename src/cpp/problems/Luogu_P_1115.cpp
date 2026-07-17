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
	int n ;
	cin >> n ;
	vector<int> arr ( n ) ;
	for ( auto &a : arr ) cin >> a ;
	int sum = 0 , min_sum = 0 , ans = -1145141919810 ;
	for ( auto &a : arr ) {
		sum += a ;
		ans = max ( ans , sum - min_sum ) ;
		min_sum = min ( min_sum , sum ) ;
	}
	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*
为什么 min_sum 要初始化 0 
为什么要先全部读入再进行操作
*/