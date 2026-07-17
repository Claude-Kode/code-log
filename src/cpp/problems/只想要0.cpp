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
char str[1001] ;
struct count_zero{
	int len ;
	int start_sub ;
	int end_sub ;
}a[1001];
//函数声明
int cmp ( const count_zero &a , const count_zero &b ) {
	return a.len > b.len ;
}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int len ;
	cin >> len ;
	for ( int i = 0 ; i < len ; i ++ ) {
		cin >> str[i] ;
	}
	int sub = 0 ; 
	for ( int i = 0 ; i < len ; i ++ ) {
		if ( str[i] == '0' ) {
			a[sub].len = 1 ;
			a[sub].start_sub = i ;
			a[sub].end_sub = i ;
			int j = i + 1 ;
			while ( str[j] == '0' ) {
				a[sub].len ++ ;
				a[sub].end_sub = j ;
				i = ++ j ;
			}
			sub ++ ;
		}
	}
	sort ( a , a + sub + 1 , cmp ) ;
	int result = a[0].start_sub + 1  +  len - a[0].end_sub + 1 ;
	cout << result << endl ;
	return 0;
}
//这道题就是检查最长的一串0
