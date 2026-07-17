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

//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector < int > arr ( 10 ,1) ;
	auto it = find( arr.begin() , arr.end() , 1 ) ;
	cout << *it << endl ;
	return 0;
}
