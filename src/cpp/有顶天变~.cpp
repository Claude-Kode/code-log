//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明


//idea
/*
找最大值左右两侧的最小值，把他们和这个最大值的差相加即可
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t ;
	cin >> t ;
	while ( t -- ) {
		int n ;
		cin >> n ;
		if ( n == 1 ) { 
			cout << 0 << endl ; 
			continue ;
		}
		int arr[n] = { 0 } ;
		int max_num = 0 , max_sub = 0 , lmin = 3000000000 , rmin = 3000000000 ;
		for ( int i = 0 ; i < n ; i ++ ) {
			cin >> arr[i] ;
			if ( arr[i] > max_num ) {
				max_num = arr[i] ;
				max_sub = i ;
			}
		}
		if ( max_sub == 0 ) {
			sort ( arr + 1 , arr + n ) ;
			lmin = max_num ;
			rmin = arr[1] ;
		} else if ( max_sub == n - 1 ) {
			sort ( arr , arr + n - 1 ) ;
			lmin = arr[0] ;
			rmin = max_num ;
		} else {
			sort ( arr , arr + max_sub ) ;
			lmin = arr[0] ;
			sort ( arr + max_sub + 2 , arr + n ) ;
			rmin = arr[ max_sub + 1 ] ;
		}
		cout << max_num - lmin + max_num - rmin << endl ;
	}
	return 0;
}
