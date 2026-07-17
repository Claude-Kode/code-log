//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明
long long fast_power(long long a, long long b) {
	long long result = 1;
	while (b > 0) {
		if ( b & 1 ) result *= a;
		a *= a;
		b >>= 1 ;
	}
	return result;
}
//idea
/*

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a , b ;
	cin >> a >> b ;
	long long result = fast_power ( a , b ) ;
	cout << result << ' ' ;
	return 0;
}
//questions ：
/*

*/

