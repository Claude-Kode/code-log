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
策略就是每次增长的那一次都要最大的
换句话说如果调数组里最大的那个不能增长一次x
就要从最小的里面挑一个 ， 一直凑到
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ; cin >> t ;
	while ( t -- ) {
		int n , x ; cin >> n >> x ; 
		vector<int> arr ( n ) ; 
		for ( auto &a : arr ) cin >> a ;
		sort ( arr.begin() , arr.end() ) ; 
		int l = 0 , r = n - 1 ;
		int sum = 0 , res = 0 ;
		vector<int> ans ;
		while ( l <= r ) {
			if ( ( sum + arr[r] ) / x > sum / x ) { sum += arr[r] ; res += arr[r] ; ans.push_back(arr[r]) ; r -- ; }
			else 							  { sum += arr[l] ; ans.push_back(arr[l]) ; l ++ ; }
		}
		cout << res << endl ;
		for ( auto &a : ans ) cout << a << ' ' ;
		if ( !ans.empty() ) cout << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/