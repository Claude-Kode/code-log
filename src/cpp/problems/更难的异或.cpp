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
这道题里我的第一思路就是用前缀和统计1出现的次数即可
不对不是用前缀和
可以直接用下标桶来进行存储即可
第一问题就是字符串的转化
但是有n个01字符串啊
要注意下标的转化
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	int buckle[m] ;
	char temp ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			cin >> temp ;
			buckle[j] += temp - '0' ;
		}
	}
	int q = 0 ; 
	cin >> q ;
	while ( q -- ) {
		int l , r ;
		cin >> l >> r ;
		bool sign = true ;
		for ( int i = l ; i <= r ; i ++ ) {
			if ( ( buckle[i] & 1 ) == 1 ) {
				cout << "NO" << endl ;
				sign = false ;
				break ;
			}
		}
		if ( sign ) cout << "YES" << endl ;
	}
	return 0;
}
//questions ：
/*
第一问题就是字符串的转化
数组初始化！！！！！！！！
*/
