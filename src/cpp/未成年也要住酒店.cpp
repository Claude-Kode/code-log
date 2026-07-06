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
int room_contain[200001];
//函数声明
int cmp ( int a , int b ) {
	return a > b ;
}
//代码
int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m ; 
	cin >> n >> m ;
	int age = 0 ; 
	int count_adult = 0 , count_youth = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> age ;
		age >= 18 ? count_adult ++ : count_youth ++ ; 
	}
	if ( count_adult + count_youth >= m && count_adult < m ) { // 成年人不够一个房间一个
		cout << "NO" << endl ;
		return 0 ;
	}
	int total_contain = 0 ;
	for ( int i = 0 ; i < m ; i ++ ) {
		cin >> room_contain[i] ;
		total_contain += room_contain[i] ;
	}
	sort ( room_contain , room_contain + m , cmp ) ;
	if ( total_contain < count_adult + count_youth ) { // 房间人数根本就不够
		cout << "NO" << endl ;
		return 0 ;
	}
	for ( int i = 0 ; i < m ; i ++ ) {
		if ( count_youth > 0 ){
			
			count_adult -- ;
			room_contain[i] -- ;
			if ( count_youth > room_contain[i] ) {
				count_youth -= room_contain[i] ;
			} else { //该房间能容纳剩余所有未成年
				room_contain[i] -= count_youth ;
				count_youth = 0 ;
				count_adult -= room_contain[i] ;
			}	
			
		} else { //没有未成年了 直接全部分配给成年人
			count_adult -= room_contain[i] ;
		}
	}
	if ( count_adult <= 0 && count_youth <= 0 ) { cout << "YES" << endl ; }
	else { cout << "NO" << endl ; }
	return 0;
}
//输出no的情况
//成年人分配不了，所有房间根本装不下
//分配后多出未成年
