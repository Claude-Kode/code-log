// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int n , p ;
// functions declarations
bool check ( double test , vector <int> consume , vector <int> original ) {
	double cnt = 0 ; 
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( original[i] < consume[i] * test ) cnt += ( consume[i] * test - original[i] ) / p ;
	}
//	cout << cnt << endl << endl ;
	return cnt <= test ;
	// 如果需要的充电时间更多 cnt > test , l = mid + 1 
	// if cnt < test , r = mid - 1 ;
	// if cnt == test , you need to search for longer answer , so improve l and record answer
}
// idea
/*
但是最短时间只能代表所有设备充电时间的总和，不能代表单个设备的充电时间
在枚举的时间中如果 bi > test * ai 则不需要充电
如果需要充电则计算充电时间，加合起来，如果大于test说明
怎么计算最长时间呢
*/
// codes
signed main () {
	cout << fixed << setprecision ( 10 ) ;
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cin >> n >> p ;
	vector <int> consume ( n ) ;
	vector <int> original ( n ) ;
	int totalConsume = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> consume[i] >> original[i] ;
		totalConsume += consume[i] ;
	}
	if ( p >= totalConsume ) { cout << -1 << endl ; return 0 ; }
	double l = 0 , r = 1e9 , answer = 0 ;
	int cnt = 1 ;
	while ( r - l >= 1e-4 ) {
		double mid = ( l + r ) / 2 ;
		if ( check ( mid , consume , original ) ) { l = mid ; answer = mid ; }
		else r = mid ;
	} 
	cout << answer ;
	return 0 ;
} 
//questions ：
/*

*/