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
int judge_parity ( int a , int b ) {
	return ( a & 1 ) == ( b & 1 ) ;
}

//idea
/*
1.任意相邻两数加合是质数
2.任意数是质数
3.奇数可以都化为3 ，偶数都化成2
4.所以只要相邻数的奇偶性相同就不行
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
		for ( auto &a : arr ) {
			cin >> a ;
		}
		bool sign = true ;
		for ( auto i = arr.begin() ; i < arr.end() - 1 ; i ++ ) {
			if ( judge_parity ( *i , *( i + 1 ) ) ) {
				cout << "NO" << endl ;
				sign = false ;
				break ;
			}
		}
		if ( sign ) cout << "YES" << endl ;
	}
	return 0;
}
