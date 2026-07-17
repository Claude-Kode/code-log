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
struct room_condition {
	int capacity ;
	bool have_adult = false ;
};

//idea
/*
循环填充成年人到剩余数为0为止
填充过了成年人的房间标记为true
标记为true的房间可以存储teenager
如果成年人是0直接cout no ， then ，return 0；
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	// input age
	vector < int > age ( n ) ; 
	int count_adult = 0 , count_teenager = 0 ;
	
	for ( auto &a : age ) {
		cin >> a ;
		a >= 18 ? count_adult ++ : count_teenager ++ ;
	}
	// input room_condition
	vector < room_condition > hotelroom ( m ) ;
	int total_capacity = 0 ;
	for ( auto &a : hotelroom ) {
		cin >> a.capacity ;
		total_capacity += a.capacity ;
	}
	// judge
	if ( count_adult == 0 ) { //special
		cout << "NO" << endl ;
		return 0;
	}
	if ( count_adult + count_teenager > total_capacity ) { //special
		cout << "NO" << endl ;
		return 0;
	}
	
	for ( auto &a : hotelroom ) {
		a.capacity -- ;
		count_adult -- ;
		a.have_adult = true ;
	}
	
	count_teenager += count_adult ; //每个房间先分配一个，剩下的直接当未成年处理就行
	
	for ( auto &a : hotelroom ) {
		if ( count_teenager == 0 ) break ;
		if ( a.have_adult ) {
			count_teenager -= a.capacity ;
		}
	}
	
	// output result
	count_teenager ? cout << "YES" << endl : cout << "NO" << endl ;
	return 0;
}
