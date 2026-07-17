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
int posi[10001],disposi[10001] ;
//函数声明
//int cmp( int a , int b ){
//	if ( a < 0 && b < 0 ) return a > b;
//	if ( a > 0 && b > 0 ) return a < b;
//	if ( a > 0 && b < 0 ) return b ;
//	if ( a < 0 && b > 0 ) return a ;
//}
//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n ;
	cin >> n ;
	int sub1 = 0 , sub2 = 0;
	int temp = 1 ;
	int result = 0 ;
	while ( n-- ){
		cin >> temp ;	
		if ( temp <= 0 ) result++ ;//先统计能吃的，后面直接加上有毒的嫩吃的就好了
		if ( temp < 0 ) { disposi[sub1] = temp ; sub1++ ; }
		else if ( temp > 0 )  { posi[sub2] = temp ; sub2++ ;}
	}
	
	sort ( posi , posi + sub2 ) ;
	sort ( disposi , disposi + sub1 ) ;

	int i = 0 ;//无毒
	int j = sub2 ;//有毒
	while ( true ) {//解不了的有毒的接着往下跳
		
		if ( disposi[i] + posi[j] <= 0 ) {
			result++ ; 
			i++ ; 
			j-- ;
		}else j-- ;
		
		if ( j == -1 || i == sub1 + 1 ) break ;
	}
	cout << result << endl ;
	return 0;
}
