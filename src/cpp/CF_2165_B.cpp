// header file
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map> 
// macro definition
#define endl '\n'
#define int long long
#define mod 998244353 
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
// 暴力的方法就是每局每一种子集的分布 ，然后计算每一种的 数量之后累加
// 但是这个题是分割不存在去重的问题啊
// 好像也是基本的爬楼梯问题 
// 首先这是一个判断组合数量的问题 
// 再来思考答案的的组成 ， 答案的长度小于等于分割出来的子集数量
// 由于多个子集的众数可能相同所以答案里面会存在多个相同的数量
// 111122
// 如果一个数在全局是众数 ， 无论你怎么分割 ， 他在局部子集至少会做为众数出现一次 ， 最多是
// 而如果不是全局众数 ， 最少可以出现0次  最多可以出现他本身的频率次
// 还是从答案的视角来看 ， 我们把所有出现的元素常出现的次数组合起来
//  
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int tt ; cin >> tt ; 
	while ( tt-- ) {
		int n ; cin >> n ;
		vector<int> arr ( n ) ;
		unordered_map<int , int> mp ;
		int max_cnt = 0 ; 
		for ( auto &a : arr ) { cin >> a ; mp[a] ++ ; max_cnt = max ( max_cnt , mp[a] ) ; }
		vector<int> dp ( mp.size() + 1 , 0 ) ; dp[0] = 1 ;
		for ( int i = 0 ; i < n ; i ++ ) if ( !mp[i] ) 
		for ( int j = n ; j >= max_cnt ; j -- ) {
			dp[j] = ( dp[j] + mp[i] * dp[j - mp[i]] ) % mod ; 
		}
		int res = 0 ; 
		for ( int i = max_cnt ; i <= n ; i ++ ) {
			res += dp[i] ;
		}
		cout << res << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/