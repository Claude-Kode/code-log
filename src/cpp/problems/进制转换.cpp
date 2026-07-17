//头文件
#include <iostream>
#include <algorithm>
#include <stack>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组
stack <int> base_2_number ;
stack <int> base_7_number ;
//函数声明
void generate_base_2_number ( int x ) {
	while ( x ) {
		int result = x % 2 ;
		base_2_number.push( result ) ;
		x >>= 1 ;
	}
	return ;
}

void generate_base_7_number ( int x ) {
	while ( x ) {
		int result = x % 7 ;
		base_7_number.push( result ) ;
		x /= 7 ;
	}
	return ;
}

void print_stack ( stack <int> a ) {
	while ( !a.empty() ) {
		cout<< a.top() ;
		a.pop() ;
	}
	cout << endl ;
}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x ;
	cin >> x ;
	if ( x ) {
		generate_base_2_number ( x ) ;
		generate_base_7_number ( x ) ;
		print_stack ( base_2_number ) ;
		print_stack ( base_7_number ) ;
	} else {
		cout << 0 << endl << 0 ;
	}
	
	return 0;
}
/*
你的二进制转换函数写的是while（x）
没有写关于0的处理哦
*/
