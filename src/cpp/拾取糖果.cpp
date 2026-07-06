//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <cmath>
//宏定义
#define endl '\n'
#define mod 99824353ll
#define min_N 1e-9
//命名空间声明
using namespace std;
//全局变量&数组
struct k_fre {
	double k ;
	int fre = 0 ;
};
//函数声明
bool operator==(const k_fre& a, const double b) {
	return abs ( a.k - b ) < min_N ;
}
bool cmp_fre ( const k_fre &a , const k_fre &b) {
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
	vector < struct k_fre > arr ;
	int special = 0 ; 
	for ( int i = 0 ; i < n ; i ++ ) {
		double x , y ;
		cin >> x >> y ;
		if ( x == 0 ) {
			special ++ ;
		} else {
			double k = y / x ;
			auto it = find( arr.begin() , arr.end() , k ) ;
			if ( it != arr.end() ) {
				it -> fre ++ ;
			} else {
				arr.push_back ( {k , 1} ) ;
			}
		}
	}
	sort ( arr.begin() , arr.end() , cmp_fre ) ; 
	int result = max ( arr[0].fre , special ) ;
	cout << result << endl ;
	return 0;
} 
