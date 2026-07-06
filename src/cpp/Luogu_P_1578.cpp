// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int l , w ;
	cin >> l >> w ;
	vector<vector<int>> arr ( l , vector<int> ( w , 1 ) ) ;
	int n ;
	cin >> n ;
	while ( n -- ) {
		int x , y ; cin >> x >> y ;
		arr[--x][--y] = 0 ;
	}
	for ( auto &row : arr ) {
		for ( auto &a : row ) {
			cout << a << ' ' ;
		}
		cout << endl ;
	}
	// 对于每一行进行单调站的维护选最大连续矩形面积
	vector<vector<int>> grid ( l , vector<int> ( w , 0 ) ) ;
	for ( int i = 0 ; i < l ; i ++ ) {
		for ( int j = 0 ; j < w ; j ++ ) {
			if ( i == 0 ) grid[i][j] = arr[i][j] ;
			else if ( arr[i][j] ) grid[i][j] = grid[i - 1][j] + arr[i][j] ;
			else if ( arr[i][j] == 0 ) grid[i][j] = grid[i - 1][j] ;
		}
	}
	cout << endl ;s
	for ( auto &row : grid ) {
		for ( auto &a : row ) {
			cout << a << ' ' ;
		}
		cout << endl ;
	}
	// 思考一下 为什么要用单调栈
	// 单调站的作用是寻找左边或者右边第一个大于小于的数
	// 对于每一行 , 记录了连续的矩形长度 , 可以抽象成一个个柱状图
	// 低于一段连续的高度不是0的柱状图来说  他的连续面积由这一段的最小高度决定
	// 但是这道题并非连续为优先
	// 本质上是遍历到一个柱状图的高度就算一下这个高度和前面能接上的连续的高度
	// 因为对于这一段柱状图来说 , 有连续的最大的举行的高度的大小一定是这一段柱状图中某个柱的高度
	// 所以每次经过一个柱子我们就算一下连续面积
	// 注意 , 我们这里实际上是在枚举高度 , 计算高度为当前的矩形能延伸到哪里
	// 单调栈的作用是为了找出能延伸的最大长度 , 也就是右边界和左边界
	// 所以单调栈是递减的 , 而且是严格递减的
	// 从左到右找一次 , 从右到左找一次
	int ans = 0 ;
	for ( int i = 0 ; i < l ; i ++ ) {
		// 维护一个单调递增栈 栈顶元素是第一个严格小于当前连续高度的第一个下标
		stack<int> st1 ;
		vector<int> left ( w , -1 ) ;
		for ( int j = 0 ; j < w ; j ++ ) {
			while ( !st1.empty() && grid[i][st1.top()] >= grid[i][j] ) 
				st1.pop() ;
			if ( !st1.empty() ) left[j] = st1.top() ;
			st1.push( j ) ;
		}
		stack<int> st2 ;
		// 为什么这里要直接赋值w呢 因为如果栈空 ， 说明这个数右边没有严格小于他的数
		// 所以就是数组的边界+1 是w
		vector<int> right ( w , w ) ;
		for ( int j = w - 1 ; j >= 0 ; j -- ) {
			while ( !st2.empty() && grid[i][st2.top()] >= grid[i][j] ) 
				st2.pop() ;
			if ( !st2.empty() ) right[j] = st2.top() ; 
			st2.push( j ) ; 
		}
		for ( int j = 0 ; j < w ; j ++ ) {
			ans = max ( ans , grid[i][j] * ( right[j] - left[j] - 1 ) ) ;
		}
	}
	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*

*/