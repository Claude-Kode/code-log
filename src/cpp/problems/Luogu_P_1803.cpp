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
struct schedule {
	int start ;
	int end ;
} ;
// functions declarations

//idea
/*

这类题目是经常容易写错的，至少我现在看来是分情况制定测略
然后分优先级执行的题目
如果要保证一段时间内进行的比赛数量越多
要保证的那段比赛的时间越短越好
同时比赛要尽可能地连续

接下来是优先级尝试，如果比赛时间越短优先，连续不优先会不会出bug
返利的情况是连续应该先优先
但是我没有举出反例啊

如果连续型优先一定是错误的
那就是时间段优先
把时间的大小进行排序
连续型的优先是下一个最近的开始时间
可能考虑多了 就是时间短优先就可以了

再次尝试分析 , 全局最优是比赛最多 ， 
我选取一个比赛可以影响后面比赛的开始时间和后面比赛的选择少了当前这个比赛

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	vector<schedule> arr ( n ) ;
	for ( auto &a : arr ) cin >> a.start >> a.end ;
		
	sort ( arr.begin() , arr.end() , []( schedule a , schedule b ) {
		return a.end < b.end ;
	} ) ;
	// for ( auto &a : arr ) cout << a.start << ' ' << a.end << endl ;
	int ans = 1 , last_end = arr[0].end ;
	for ( int i = 1 ; i < n ; i ++ ) 
		if ( arr[i].start >= last_end ) {
			ans ++ ;	
			last_end = arr[i].end ;
		}
	
	cout << ans ;
	return 0 ;
}
//questions ：
/*

*/