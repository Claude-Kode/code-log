#include <bits/stdc++.h>
using namespace std ;
#define endl '\n'
#define int long long 
/*
对于这种构造题目真的就是撞大运的感觉
这题感觉真的没啥可讲的
根本就没有拆解模型这一步
就是猜一种组合方式验证一下
这种题可能真的没有什么难的 ，就是读题起来没有思路你就觉得很难
被题目的分数限制了
实际上你写不出来的要么是思路没有想到或者想歪了
你能力范围外的题目只有没学的算法和数据结构
剩下的无论多难都在能力范围内部
大胆猜 ，然后别溜号 , 努力验证
还有一个原因就是 构造题可能和样例没有关系
*/
void slove () {
	int n ; cin >> n ;
	vector<int> muls_2 , muls_3_odd , non ; 
	for ( int i = 1 ; i <= n ; i ++ ) 
		if ( i % 2 == 0 ) 
			muls_2.push_back( i ) ;
		else if ( i % 3 == 0 ) 
			muls_3_odd.push_back( i ) ;
		else 
			non.push_back( i ) ;
	while ( non.size() >= 1 && muls_2.size() >= 2 ) {
		cout << non.back() << ' ' ; non.pop_back() ;
		cout << muls_2.back() << ' ' ; muls_2.pop_back() ;
		cout << muls_2.back() << ' ' ; muls_2.pop_back() ;
	}
	while ( non.size() >= 1 && muls_3_odd.size() >= 2 ) {
		cout << non.back() << ' ' ; non.pop_back() ; 
		cout << muls_3_odd.back() << ' ' ; muls_3_odd.pop_back() ;
		cout << muls_3_odd.back() << ' ' ; muls_3_odd.pop_back() ;
	}
	while ( !non.empty() ) 
		{ cout << non.back() << ' ' ; non.pop_back() ; }
	while ( !muls_2.empty() ) 
		{ cout << muls_2.back() << ' ' ; muls_2.pop_back() ; }
	while ( !muls_3_odd.empty() ) 
		{ cout << muls_3_odd.back() << ' '; muls_3_odd.pop_back() ; }
	cout << endl ;
}

signed main () {
	int tt ; cin >> tt ;
	while ( tt -- ) slove() ;
	return 0 ; 
}