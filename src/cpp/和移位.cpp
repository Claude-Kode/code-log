// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map> 
#include <utility>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
这个题我主要是思维维度上面的问题
我想的总是模拟出一个 k 位移的数组，再一次遍历
没有想到可以直接单个元素进行操作和统计即可
真的是太sb了
只要堆每个下标一次向后方枚举非本身的下标，轮番计算k即可
比你的模拟思维强一万倍，
主要原因就是竖着横着填答案都行，横着填你就是sb

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , q ;
	cin >> n >> q ;
	vector <int> arr ( n ) ;
	unordered_map <int , unordered_map<int , int>> mp ;
    int min_x = 1145141919810 ;
    int max_x = -1145141919810 ;
	for ( auto &a : arr ) {
        cin >> a ;
        min_x = min ( min_x , a ) ;
        max_x = max ( max_x , a ) ;
    }
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < n ; j ++ ) {
			// cout << i << ' ' << ( i + j ) % n << ' ' ;
			mp[j][ arr[ ( i + j ) % n ] + arr[i] ] ++ ;
		}
		// cout << endl ;
	}
    unordered_map <int , int> res ;
    for ( int i = 2 * min_x ; i <= 2 * max_x ; i ++ ) {
        int x = i ;
        vector <int> ans ;
		int max_value = 0 ; 
		for ( int i = 0 ; i < n ; i ++ ) {
			ans.push_back( mp[i][x] ) ;
			max_value = max ( max_value , mp[i][x] ) ;
		}
		for ( int i = 0 ; i < n ; i ++ ) {
			if ( ans[i] == max_value ) {
				res[x] = i ;
				break ;
			}
		}
    }
	while ( q -- ) {
        int x ;
        cin >> x ;
		if ( res.count( x ) ) cout << res[x] << endl ;
        else cout << 0 << endl ;
	}
	return 0 ; 
}
//questions ：
/*

*/

