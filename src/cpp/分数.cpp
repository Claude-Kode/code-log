//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <cmath> 
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明
int multiply ( int b ) {
	int a = 1 ;
	for ( int i = 0 ; i < b ; i ++ ) {
		a *= 10 ;
	}
	return a ;
}

int gcd( int a , int b ) {
	return b == 0 ? a : gcd(b, a % b);
}

//idea
/*
对于最大公约数的求解
a 和 b 的最大公约数也是 a%b的最大公约数，翻过过来，（a%b)%a的最大公约数也一样
你品
先输入字符串，然后取小数点的位置，
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t ;
	cin >> t ;
	while ( t -- ) {
		string number ;
		cin >> number ;
		int len = number.size() ;
		int dot_pos = number.find ( '.' ) ;
		number[dot_pos] = 'A' ;
		string temp[ len - 1 ] ;
		for ( const auto &a : number ) {
			int sub = 0 ;
			if ( a != 'A' ) {
				number[sub] = a ;
				sub ++ ;
			}
		}
		int int_number = stoi(temp) ;
		int denominator = multiply ( len - dot_pos ) ;
		int result = gcd ( int_number , denominator ) ;
		cout << int_number / result << '/' << denominator / result << endl ;
	}	
	return 0;
}
