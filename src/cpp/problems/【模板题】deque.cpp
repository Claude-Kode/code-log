//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
	deque<long long> arr ;
	int operation ;
	while ( cin >> operation ) {
		switch ( operation ) {
			case 1 : {
			long long temp ;
			cin >> temp ;
			arr.push_front( temp ) ;
			break;
			}
			case 2 : {
				long long temp ;
				cin >> temp ;
				arr.push_back( temp ) ;
				break ;
			}
			case 3 : {
				cout << arr.front() << endl ;
				break ;
			}
			case 4 : {
				cout << arr.back() << endl ;
				break ;
			}
			case 5 : {
				int len = arr.size() ;
				cout << len << endl ;
				break ;
			}
			case 6 : {
				arr.empty() ? cout << 1 << endl : cout << 0 << endl ;
				break ;
			}
			case 7 : {
				arr.pop_front() ;
				break ;
			}
			case 8 : {
				arr.pop_back() ;
				break ;
			}
		}
	}
	return 0;
}
//questions ：
/*

*/
