//头文件
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
//宏定义
#define endl '\n'
#define int long long
//命名空间声明
using namespace std ;
//全局变量&数组
int arr[100001] ;
//函数声明
bool check ( int test , int n , int m ) {
	int cnt = 0 ;
	for ( int i = 1 ; i <= m ; i ++ ) {
		if ( arr[i] % test == 0 ) cnt += arr[i] / test ;
		else cnt += arr[i] / test + 1 ;
	}
	cout << cnt << endl ;
	if ( cnt >= n ) return true ; //多了说明每个人分的太少了 ， 升高 l
	else return false ; //少了说明分的太多了 ， 降低 r
	//如果等于要让 test尽可能大，=和l升高的写在一起
}
//idea
/*

*/
//代码
signed main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m ; 
	cin >> n >> m ;
	int max_number = 0 ;
	for ( int i = 1 ; i <= m ; i ++ ) {
		cin >> arr[i] ;
		if ( max_number < arr[i] ) max_number = arr[i] ;
	}
	int l = 0 , r = max_number ;
	int answer ;
	while ( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if ( check ( mid , n , m ) ) {
			l = mid + 1 ;
		} else {
			r = mid - 1 ;
			answer = mid ;
		}
	}
	cout << answer << endl ;
	return 0 ;
}
//questions ：
/*

*/
