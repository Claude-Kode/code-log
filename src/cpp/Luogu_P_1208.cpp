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
	int price ;
	int upLimit ;
} ;
// functions declarations

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , m ;
	cin >> n >> m ;
	vector<infor> arr ( m ) ;
	for ( auto &a : arr ) cin >> a.price >> a.upLimit ;
	sort ( arr.begin() , arr.end() , [] ( infor a , infor b ) {
		return a.price < b.price ;
	}) ;
	int index = 0 , ans = 0 ;
	while ( n ) {
		if ( arr[index].upLimit <= n ) {
			ans += arr[index].upLimit * arr[index].price ;
			n -= arr[index].upLimit ;
		} 
		else {
			ans += n * arr[index].price ;
			n = 0 ;
		}
		index ++ ;
	}
	cout << ans ;
	return 0 ;
}
//questions ：
/*

*/