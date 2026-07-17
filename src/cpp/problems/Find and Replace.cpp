//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

//idea
/*
读取一个字母，奇数次读取设为0，偶数次设为1
加入到map中
如果出现同一个键对应的值不一样直接return false
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
		map <char , int> mymap ;
		bool sign = true ;
		string test ;
		cin >> test ;
		for ( int i = 0 ; i < n ; i ++ ) {
			int value = i % 2 ;
			if ( mymap.find( test[i] ) != mymap.end() ) { 
				auto it = mymap.find( test[i] ) ;
				if ( it -> second != value  ) {
					cout << "NO" << endl ;
					sign = false ;
					break ;
				}
			} else {
				mymap.insert( { test[i] , value } ) ;
			}
		}
		if ( sign ) cout << "YES" << endl ;
	}
	return 0;
}
//questions ：
/*
map的insert函数要在括号里面加花括号
map内置了find函数
*/
