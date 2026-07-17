// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations
// void slove() {
// 	int n ; cin >> n ; 
// 	vector<int> arr ( n ) ;
// 	for ( auto &a : arr ) cin >> a ;
// 	int cnt = 0 ; 
// 	for ( int i = 0 ; i < n - 1; i ++ ) {
// 		for ( int j = i + 1 ; j < n ; j ++ ) {
// 			if ( arr[i] < arr[j] ) cnt ++ ; 
// 			if ( cnt >= n - 1 ) { cout << "Yes" << endl ; return ; }
// 		}
// 	} 
// 	cout << "No" << endl ; 
// }
void slove () {
	int n ; cin >> n ;
	vector<int> arr ( n ) , pre ( n ) , suf ( n ) ;
	int mn = INT_MAX , mx = INT_MIN ;
	for ( int i = 0 ; i < n ; i ++ ) cin >> arr[i] ;
	for ( int i = 0 ; i < n ; i ++ ) { mn = min ( mn , arr[i] ) ; pre[i] = mn ; }
	for ( int i = n - 1 ; i >= 0 ; i -- ) { mx = max ( mx , arr[i] ) ; suf[i] = mx ; }
	for ( int i = 1 ; i < n ; i ++ ) 
		if ( pre[i - 1] > suf[i] ) 
			{ cout << "No" << endl ; return ; }
	cout << "Yes" << endl ; return ;
}
//idea
/*
从后向前遍历 一个数字必须要和前面的有配对关系至少一次
或者也可以说 从前向后遍历每个数字必须要能和他后面的数字匹配至少一次
所以这个数字要小于他后面所有数字的最大值
但是其实不是 ， 是配对的要练成一串
假如当前数字不是最小值 ， 那么当前数字肯定能和前面的最小值配对
如果当前数字是最小值 ， 他都配对不了的后面都配对不了
每个数字都要至少配对一次
如果当前值是最小值 ， 他肯定不能和前面的配对 ， 如果后面的最大值也小于当前值
那么当前值在后面也不能配对

总的来说就是
每个数字至少有一次配对 配对要符合下标递增值递增
配对有两个方向 ， 前面和后面
贪心的想， 为了尽可能配对成功 
要和小标小于他且值尽可能小的配对 ， 即在他之前的最小值配对
要和下标大于他且值尽可能大的配对 ， 即在他之后的最大值配对
如果前面没有能配对的最小值 ， 换句话说 ， 当前数字小于前面的所有数字
那么他只能和他后面的配对
如果后面的所有数字也小于他 ， 那么他就不能和别人配对
即这个点是孤立的 ， 不能形成一颗树
*/
// codes
signed main () {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int tt ; cin >> tt ;
	while ( tt -- ) slove () ; 
	return 0 ;
}
//questions ：
/*

*/