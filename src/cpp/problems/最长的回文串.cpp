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
int char_fre[128] ;
//函数声明


//idea
/*
1.如果所有元素都是偶数，直接输出即可
2.单反有奇数的，回文串长度减到剩下一个奇数为止
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t ;
	cin >> t ;
	while ( t -- ) {
		string str ;
		cin >> str ;
		int len = str.size() ;
		for ( const auto a : str ) {
			char_fre[(int)a] ++ ;
		}
		int count_odd = 0 ;
		for ( int i = 0 ; i < 128 ; i ++ ) {
			if ( (char_fre[i] & 1) == 1 ) count_odd ++ ;
		}
		count_odd ? cout << len - ( count_odd -1 ) << endl : cout << len << endl ;
		for ( int i = 0 ; i < 128 ; i ++ ) {
			char_fre[i] = 0 ;
		}
	}
	return 0;
}
