//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t ;
	cin >> t ; 
	while ( t-- ) {
		long long test ;
		cin >> test ;
		if ( ( test & 1 ) == 1 ){//是奇数
			cout << "YES" << endl ;
			continue ;
		}else{//是偶数
			bool sign = true ;
			while( 1 ) {
				test >>= 1 ;
				if ( test == 1 ) break ;
				if ( test != 1 && ( test & 1 ) == 1 ) {
					cout << "YES" << endl ;
					sign = false ;
					break ;
				}
			} 
			if ( sign ) cout << "NO" << endl ;
		} 
	}
	return 0;
}
