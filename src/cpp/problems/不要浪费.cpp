//头文件
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
//宏定义
#define endl '\n'
#define int long long
//命名空间声明
using namespace std;
//全局变量&数组
int arr[100001] , answer[100001];
//函数声明
bool check ( int test , int n , int k ) {
	long long cnt = 0 ; 
	for ( int i = 1 ; i <= n ; i ++ ) {
		cnt += ( arr[i] / test ) ;
		answer[i] =  ( arr[i] / test ) ;
		if ( cnt == k ) return true ;
	}
	if ( cnt > k ) return true ; //多了说明test太小了 ， l增大
	else return false ; //少了说明test大了 ， r缩小
}
//idea
/*

*/
//代码
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , k ;
	cin >> n >> k ;
	int max_len = 0 ;
	long long total_len = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> arr[i] ;
		total_len += arr[i] ;
		if ( arr[i] > max_len ) max_len = arr[i] ;
	}
	if ( total_len < k ) {
		cout << total_len << endl ;
		return 0 ;
	}
	int l = 1 , r = max_len ;
	int answer ;
	while ( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if ( check ( mid , n , k ) ) {
			l = mid + 1 ;
			answer = mid ;
		} else { 
			r = mid - 1 ;
		}
	}
	cout << total_len - k * answer ;
	return 0;
}
//questions ：
/*

*/
