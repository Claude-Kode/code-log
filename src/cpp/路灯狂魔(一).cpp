//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
#define mod 1000000009
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

//idea
/*
等于2或者4，或者+2%3 == 0 或者+4%3 == 0
或者直接%3 == 0
或者等于1
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
		vector <int> arr ( n , 0 ) ; 
		cout << "YES" << endl ;	
		if ( n % 3 == 0 ) {
			for ( int i = 0 ;  i < n ; i ++ ) {
				if ( ( i + 2 ) % 3 == 0 ){
					arr[i] = 1 ;
				}
				cout << arr[i] << ' ' ;
			}
			cout << endl ;
			
		} else if ( n % 3 == 1 ) {
			arr[0] = 1 ; 
			arr[n-1] = 1 ;
			for ( int i = 0 ; i < n ; i ++ ) {
				if ( i % 3 == 0 ) {
					arr[i] = 1 ;
				}
				cout << arr[i] << ' ' ;
			}
			cout << endl ;
			
		} else if ( n % 3 == 2 ) {
			arr[0] = 1 ;
			for ( int i = 0 ; i < n ; i ++ ) {
				if ( i % 3 == 0 ) {
					arr[i] = 1 ;
				}
				cout << arr[i] << ' ' ;
			}
			cout << endl ;
		}
	}
	return 0;
}
