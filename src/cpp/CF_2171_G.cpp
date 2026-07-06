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
#define mod 1e6 + 3 
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations
void slove () {
	int n ; cin >> n ; 
	vector<int> a ( n ) , b ( n ) ;
	for ( auto &temp : a ) cin >> temp ;
	for ( auto &temp : b ) cin >> temp ;
	for ( int i = 0 ; i < n ; i ++ ) {

	} 
}
//idea
/*
这道题可以利用 * 2 快速逼近 b 数组
然后利用不断自增取得最后结果
记录除法的数量 取最小值然后 / 2 就是操作 x 的数量
然后还要统计同样用 x 次能变成b的序列
...wtf
让你统计数目的话肯定不能模拟计数
所以肯定有个什么公式之类的 加减乘除一下出来
所以转换也要有个定式 ， 就是固定的转换方式 ， 然后给他乘起来那种的
如果是定式转化的话一定是要先*2再加法吗 ， 答案肯定是不一定的
所以对于一个x可能要分离加法和乘法的数量进行讨论
在这里或许* 2可以看作二进制的左移
把 ai 和 bi 的二进制对齐 加一然后左移就可以还原固定的位
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int tt ; cin >> tt ;
	while ( tt -- ) slove () ; 
	return 0 ;
}
//questions ：
/*

*/