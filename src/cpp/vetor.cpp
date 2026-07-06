//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
	int n , m ;
	cin >> n >> m ;
	vector < vector <int> > vc ( n , vector <int> ( m, 0 ) ) ;
	for ( auto &row : vc ) {
		for ( auto &element : row ) {
			cin >> element ;
		}
	}
	int x , y ;
	cin >> x >> y ;
	cout << vc.at(x-1).at(y-1) << endl ;
	return 0;
} 
