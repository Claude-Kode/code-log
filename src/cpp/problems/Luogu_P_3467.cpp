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
如果上一张海报的高度小于这一张 ， 证明上一张海报的可以共用
如果这张海报的高度高于上一张 ， 是可以连用但是还要单开一张
如果这张海报的高度小于上一张 ， 这张海报就不能是上一张的连续 ，只能是新开的一张海报
这道题的关键点就在于 ， 只有当前面往后面延伸的海报在后面能完整的覆盖一个墙
才能省下来一张海报
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , ans = 0 ;
	cin >> n ;
	stack<int> st ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int temp ; cin >> temp ;
		int height ; cin >> height ;
		// 要维护的是单调递增栈 ， 当前元素大于栈顶入栈 ， 小于等于则弹栈
		while ( !st.empty() && height < st.top() ) 
			st.pop() ;
		if ( st.empty() || st.top() < height ) 
			ans ++ ;
		st.push( height ) ;
	}
	cout << ans ;
	return 0 ;
}
//questions ：
/*

*/