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
struct infor {
	int pass ;
	int time ;
} ;
// functions declarations

//idea
/*
<= 10% == gold
> 10% && <= 30% == silver
> 30% && <= 60% == copper
else iron
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	vector <infor> arr ( n ) ;
	for ( auto &a : arr ) cin >> a.pass >> a.time ;
	int target_pass = arr[0].pass , target_time = arr[0].time ;
	sort ( arr.begin() , arr.end() , []( infor a , infor b ) {
		return a.pass == b.pass ? a.time < b.time : a.pass > b.pass ;
	}) ;
	// for ( auto &a : arr ) {
	// 	cout << a.pass << ' ' << a.time << endl ;
	// }
	int grade = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( arr[i].pass == target_pass && arr[i].time == target_time ) {
			grade = i + 1 ;
			break ;
		}
	}
	//cout << grade << endl ;
	// cout << n / 10 << ' ' << n / 10 * 3 << ' ' << n / 10 * 6 ;
	if ( grade <= n / 10 ) cout << "gold" << endl ;
	else if ( grade > n / 10 && grade <= n / 10 * 3 ) cout << "silver" << endl ;
	else if ( grade > n / 10 * 3 && grade <= n / 10 * 6 ) cout << "bronze" << endl ;
	else cout << "iron" << endl ;
	return 0 ;
}
//questions ：
/*

*/