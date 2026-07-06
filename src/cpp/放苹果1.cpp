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
int m , n ;
int pre_sum = 0 ;
vector <int> arr ;
set < vector <int> > answer ;
bool canbeUsed[11] ;
// functions declarations

void bool_set ( int pos ) {
	for ( int i = 0 ; i < 11 ; i ++ ) {
		if ( i <= pos ) canbeUsed[i] = true ;
		else canbeUsed[i] = false ;
	}
}

void DFS ( int step ) {
	// end
	if ( step == n + 1 ) {
		sort( arr.begin() , arr.end() ) ;
		answer.insert ( arr ) ;
		return ;
	}
	// DFS answer
	else {
		for ( int i = 0 ; i <= m ; i ++ ) {
			if ( canbeUsed[i] ) {
				arr[step] = i ;
				pre_sum += i ;
				bool_set ( m - pre_sum ) ;
				DFS ( step + 1 ) ;
				pre_sum -= i ;
				bool_set ( m - pre_sum ) ;
			}
		}
		return ;
	}
 }
//idea
/*
sum of apples is M , the number of plates is N 
allow empty plate
so DFS from 0
the numebr of apples in the m-th plate is 0 to n - sum of the pre m-1 -th
the last must be n - the sum of pre n-1-th
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ;
	cin >> t ;
	while ( t -- ) {
		cin >> m >> n ;
		answer.clear() ; // !!!
		arr.resize ( n + 1 , 0 ) ; //!!!
		bool_set ( 11 ) ; // !!!
		pre_sum = 0 ;
		DFS ( 1 ) ;
		cout << answer.size() << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/
