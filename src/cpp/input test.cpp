//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
vector < string > myvector ;
//函数声明
void input_turn ( string a ) {
	while ( cin.peek() != '\n' ) {
		string temp ;
		getline ( cin , temp , '_' ) ;
		myvector.push_back ( temp ) ;
	}
}
//idea
/*

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a ;
	cin >> a ;
	input_turn ( a ) ;
	for ( const auto &a : myvector ) {
		cout << a << endl ;
	}
	return 0;
}
//questions ：
/*

*/
