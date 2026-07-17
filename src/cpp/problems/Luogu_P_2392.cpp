// header file
#include <iostream>
#include <algorithm>
#include <vector>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int ans = 0 ;
// functions declarations
void DFS ( int step , int sum0 , int sum , vector<int> &arr ) {
	if ( step == arr.size() ) 
		ans = min ( ans , max ( sum , sum0 - sum ) ) ; 
	else {
		DFS ( step + 1 , sum0 , sum + arr[step] , arr ) ;
		DFS ( step + 1 , sum0 , sum , arr ) ;
	}
}
//idea
/*
把一个数组分成两组 , 如何分让各组的合的最大值最小
直接用子集型回溯 ， 0 是放进组1 1是放进组2
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int res = 0 ;
	vector<int> si ( 4 ) ;
	for ( auto &a : si ) cin >> a ;
	for ( auto &t : si ) {
		vector<int> arr ( t ) ;
		int sum0 = 0 ;
		for ( auto &a : arr ) { cin >> a ; sum0 += a ; }
		ans = sum0 ;
		DFS ( 0 , sum0 , 0 , arr ) ;
		// cout << ans << endl ;
		res += ans ;
	}
	cout << res << endl ;
	return 0 ;
}
//questions ：
/*

*/