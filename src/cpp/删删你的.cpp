//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明
vector <string> process ( string a ) {
	vector <string> answer ;
	string temp ;
	char c ;
	bool sign = false ;
	int len = a.size() ;
	for ( int i = 0 ; i < len ; i ++ ) {
		c = a[i] ;
		if ( sign && c == '_') {
			continue ;
		} else if ( sign && c != '_') {
			sign = false ;
		}
		if ( c != '_' ) {
			temp.push_back( c ) ;
		} else {
			answer.push_back( temp ) ;
			temp.clear() ;
			sign = true ;
		}
		if ( i == len - 1 && !temp.empty() ) answer.push_back( temp ) ;
	}
	sort ( answer.begin() , answer.end() ) ;
	return answer ;
}
//idea
/*

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t ;
	cin >> t ;
	vector <string> result ;
	set < vector<string> > myset ;
	while ( t -- ) {
		string a ;
		cin >> a ;
		vector < string > myvector = process ( a ) ; 
		int len1 = myset.size() ;
		myset.insert( myvector ) ;
		int len2 = myset.size() ;
		if ( len1 != len2 ) {
			result.push_back( a ) ;
		}
	}
	cout << myset.size() << endl ;
	for ( const auto &a : result ) {
		cout << a << endl ;
	}
	return 0;
}
//questions ：
/*

*/
