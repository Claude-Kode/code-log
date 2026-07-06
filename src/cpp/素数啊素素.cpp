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
bool st[1000001] ;// false质数 true合数
int prime[1000001];
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	int count = 0 ;
	st[0] = true ; st[1] = true ;
	for ( int i = 2 ; i <= m ; i ++ ) {
		if( !st[i] ) prime[count++] = i ;
		for ( int p : prime ) {
			if ( ( i * p ) > m ) break ;
			st[i*p] = true ;
			if ( i % p == 0 ) break ;
		}
	}
	int l , r ;
	while ( n-- ) {
		cin >> l >> r ;
		int result = 0 ;
		for ( int i = l ; i <= r ; i ++ ) {
			if ( !st[i] ) result ++ ;
		}
		cout << result << endl ;
	}
	return 0;
}
