//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <cmath>
#include <numeric>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组
struct k_fre {
	int x ;
	int y ;
	int fre = 0 ;
};
//函数声明
bool cmp ( const k_fre &a , const k_fre &b ) {
	return a.fre > b.fre ;
}
//idea
/*

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n ;
	cin >> n ;
	vector <k_fre> arr ;
	int count_1 = 0 , count_2 = 0 , count_3 = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int x , y ;
		cin >> x >> y ;
		if ( x == 0 && y == 0 ) {
			count_1 ++ ;
		} else if ( x == 0 ) {
			count_2 ++ ;
		} else if ( y == 0 ) {
			count_3 ++ ;
		}else {
			int temp = gcd ( abs(x) , abs(y) ) ;
			x /= temp ;
			y /= temp ;
			if ( x < 0 && y < 0 ) {
				x = -x ; 
				y = -y ;
			} else if ( x < 0 && y > 0 ) {
				x = -x ;
				y = -y ;
			}
			auto search_result = find_if(arr.begin(), arr.end(), [x , y] (const k_fre& a) { return a.x == x && a.y == y ; } ) ;
			if ( search_result != arr.end() ) {
				search_result -> fre ++ ;
			} else {
				arr.push_back( { x , y , 1 } ) ;
			}
		}
	}
	sort ( arr.begin() , arr.end() , cmp ) ;
	if ( arr.empty() ) {
		cout << max ( count_1 + count_3 , count_2 + count_1 ) << endl ;
	} else {
		cout << max ( arr[0].fre + count_1 , max ( count_1 + count_3 , count_2 + count_1 ) ) << endl ;
	}
	return 0;
}
//questions ：
/*

*/
