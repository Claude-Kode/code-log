//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <stack>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

//idea
/*

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<long long> arr ;
	int operation ;
	while ( cin >> operation ) {
		switch ( operation ) {
			case 1 : {
			long long temp ;
			cin >> temp ;
			arr.push( temp ) ;
			break;
			}
			case 2 : {
			arr.pop() ;
				break ;
			}
			case 3 : {
				cout << arr.top() << endl ;
				break ;
			}
			case 4 : {
				int len = arr.size() ;
				cout << len << endl ;
				break ;
			}
			case 5 : {
				arr.empty() ? cout << 1 << endl : cout << 0 << endl ;
				break ;
			}

		}
	}
	return 0;
}
//questions ：
/*

*/
