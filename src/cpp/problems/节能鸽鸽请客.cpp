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
#define min_number -1e12
#define max_number 1e12
//命名空间声明
using namespace std ;
//全局变量&数组
int delicious[100001] , expectation[100001] ;
//函数声明

//idea
/*
这道题的本质就是集合在集合a中搜索集合b中每一个与其相差最小的元素
*/
//代码
signed main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ;
	cout.tie(0) ;
	int m , n ;
	cin >> m >> n ;
	for ( int i = 1 ; i <= m ; i ++ ) {
		cin >> delicious[i] ;
	}
	sort ( delicious , delicious + m + 1 ) ;
	delicious[0] = min_number ; delicious[m+1] = max_number ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> expectation[i] ;
	}
	sort ( expectation , expectation + n + 1 ) ; 
	
	int result = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		int answer = 0 ;
		int l = 1 , r = m ;
		while ( l <= r ) {
			int mid = ( l + r ) / 2 ;
			answer = mid ;
			if ( delicious[mid] > expectation[i] ) {
				r = mid - 1 ;
			}else if ( delicious[mid] < expectation[i] ) {
				l = mid + 1 ;
			} else {
				break ;
			}
		}
		
//        cout << delicious[answer] << ' ' ;
		result += min ( { abs ( expectation[i] - delicious[answer+1] ) , abs ( expectation[i] - delicious[answer] ) , abs ( expectation[i] - delicious[answer-1] ) }) ;
	}
//    cout << endl ;
	cout << result << endl ;
	return 0 ;
}
//questions ：
/*

*/
