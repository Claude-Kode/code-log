// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
struct infor {
	int num ;
	int value ;
} ;
// functions declarations

//idea
/*
某个人的等待时间等于他前面的所有人时间之和除以人数
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	cout << fixed << setprecision( 2 ) ;
	int n ;
	cin >> n ;
	vector <infor> times ( n + 1 ) ;
	vector <int> preTimes ( n + 1 , 0 ) ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> times[i].value ; 
		times[i].num = i ;
		//preTimes[i] = preTimes[i-1] + times[i] ;
//		cout << times[i].value << ' ' << times[i].num << endl ;
	}
	sort ( times.begin() + 1 , times.end() , []( infor a , infor b ) {
		return a.value < b.value ;
	}) ;
	double answer = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		preTimes[i] = preTimes[i-1] + times[i].value ;
		if ( i < n ) answer += preTimes[i] ;
	}
	for ( int i = 1 ; i <= n ; i ++ ) cout << times[i].num << ' ' ;
	cout << endl << answer / n ;
	return 0 ;
}
//questions ：
/*

*/