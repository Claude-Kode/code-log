// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
string digits = { "23" } ;
// functions declarations
vector <string> numbermap = { "" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" } ;
void backTracking ( int step , string digits , int len , string temp , vector <string> &answer ) {
	// step 代表当前计算的这种答案，内部有几个字母
	// 同时也代表从 digits 中读取第几个数字字符
	cout << step << ' ' << temp << endl ;
	if ( step == len + 1 ) {
		answer.push_back ( temp ) ;
		return ;
	} else {
		for ( auto &a : numbermap [ digits [ step - 1 ] - '0' ] ) {
			temp.push_back ( a ) ;
			backTracking ( step + 1 , digits , len , temp , answer ) ;
			temp.pop_back () ;
		}
	}
}
//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int len = digits.size() ;
	vector <string> answer ; 
	string temp ;
	backTracking ( 1 , digits , len , temp , answer ) ;
	for ( auto &a : answer ) cout << a << endl ;
	return 0 ;
}
//questions ：
/*

*/
