//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <stack>
#include <map>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

//idea
/*

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char c ;
	stack <char> str ; 
	while ( cin.get(c) && c != '\n' ) {
		if ( c == '('|| c == '[' ) {
			str.push( c ) ;
		} else if ( c == ')' ) {
			if ( str.empty() ) {
				cout << "NO" << endl ;
				return 0 ;
			}
			if ( str.top() == '(' ) {
				str.pop() ;
			} else {
				cout << "NO" << endl ;
				return 0 ;
			}
		} else if ( c == ']' ) {
			if ( str.empty() ) {
				cout << "NO" << endl ;
				return 0 ;
			}
			if ( str.top() == '[' ) {
				str.pop() ;
			} else {
				cout << "NO" << endl ;
				return 0 ;
			}
		}
	}
	str.empty() ? cout << "YES" << endl : cout << "NO" << endl ;
	return 0;
}
//questions ：
/*
while ( cin >> c && c != '\n' )不会写

*/
