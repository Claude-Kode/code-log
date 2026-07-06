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
long long arr[1000001] , pre[1000001];
//函数声明
void generate_prefix( long long arr[] , long long pre[] , int n ){
	pre[0] = 0 ; 
	for ( int i = 1 ; i <= n ; i ++ ){
		pre[i] = pre[i-1] + arr[i] ;	
	}
}
//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ ){
		cin >> arr[i] ;
	}
	generate_prefix ( arr , pre , n ) ;
	int q ;
	cin >> q ;
	int l = 0 , r = 0 ;
	while ( q-- ){
		cin >> l >> r ;
		cout << pre[r] - pre[l - 1] << endl ;
	} 
	return 0;
}
