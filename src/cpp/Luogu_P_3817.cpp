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

// functions declarations

//idea
/*
根据贪心思维，我要让尽可能多的所有长度是 2 的子序列的和尽可能接近 x
这道题答案关注的是丢掉了多少糖
我的计算方式是根据策略组合出一个新的序列然后挨个统计
其实就是计算最多能留几颗糖
这道题的关键是糖是无法传递 , 只能丢掉	
发现贪心有通过排序得到最优解的 , 有的是纯纯决策
这道题我忽略了一个很重要的东西，就是从哪里减去多的糖果
我一直在想这个每个序列应该怎么组合
教训是好好列样例动动手算
你就发现跟顺序其实没关系
因为糖果不能增大只能减小啊 wtf
*/
// 你溜号了！！！！！！
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n , x ;
	cin >> n >> x ;
	vector<int> sweet ( n ) ;
	for ( auto &a : sweet ) cin >> a ;  
	// sj
	if ( n == 1 && sweet[0] > x ) { cout <<  sweet[0] - x << endl ; return 0 ; }

	int ans = 0 ;
	for ( int i = 1 ; i < n ; i ++ ) {

		int temp_sum = sweet[i - 1] + sweet[i] ;

		if ( temp_sum > x ) { 
			ans += temp_sum - x ; 

			if ( sweet[i] > temp_sum - x ) sweet[i] -= temp_sum - x ; 
			else sweet[i] = 0 ;

		}
s
	}

	cout << ans << endl ;
	return 0 ;
}
//questions ：
/*

*/