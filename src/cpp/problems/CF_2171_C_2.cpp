// header file
#include <iostream>
#include <algorithm>
#include <vector>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays 

// functions declarations

//idea
/*
异或要让每个数位的1的数量之和尽量都是奇数次
同时要让高位尽可能高
或者说就是比谁的 高位数量是奇数次谁就赢了
如果两边高位数量都一样 就算一遍然后分类讨论
答案还是从平局入手的
而且找到了一个不变量
无论怎么换 ， 这2n个数字的异或一直是一个定值
也就是说无论怎么换 ， 两个人的结果之间的异或还是不变的
如果这个异或是0那么证明两个人的结果之间的异或是0证明两个人的结果一定是相同的
也就是平局了
如果不相等要判断谁更大
我已经拿到了结果的数字 ， 结果的最高位就是第一个不同的数字 
我只要判断结果的最高位 对应的两数对应的数位谁是1谁就赢了
那么问题来了怎么判断呢
和你之前的思想一样 ， 这个数是1是0只有两种情况 ， 所以一次转换就可以定胜负
所以还是看谁能拿到最后的转换机会
bit位指的是res的尽可能高位的第一个是1的位置
最后一个 a[i]和b[i]的第bit位不相同 ， 这一次是谁操作谁就赢了

总结一下 无论如何交换 res_a ^ res_b = res 这个res是永远不变的
所以res从高位向低位第一个 1 ，把这个数位记作bit
res_a 和 res_b 的第bit位是互不相同的 ， 也就是说这一位谁是 1 谁就赢
接下来彼比的就是谁能在过程中通过交换把这一位变成 1
首先注意变成1的是res_a 这个res_a并不是由一个元素决定的 
我们可以想在bit这一位上 从异或的开始到结尾只有两种状态 0 和 1
所以对于a 和 b来说 ， 不管之前是0 还是 1 只要最后一次是1就可以了
由于可以选择跳过或者换 ， 也就是说对于他们的最后一次操作 ， 只要条件允许就可以保证bit位一定是 1
那么这个条件是什么呢？ 这个条件能导致的结果是能把 0 变成 1
那么就要求两个数的bit位数字是不相同的
也就是某个i a[i]的bit位和b[i]的bit位是不同的ss
同时前面也说过 ， 我们要求的是最后一次转换 ， 也就是i要尽可能接近n
总得来说 ， 表面上看起来是两个数的交换 ， 其实是结果上特定bit位的操作
也就是原来是 0 -> n 上每个 a[i] ^ b[i] 的问题转化成了两个数之间的特定bit转换操作 
*/
// codes
signed main() {
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ; cin >> t ;
	while ( t -- ) {
		int n ; cin >> n ;
		vector<int> A ( n ) , B ( n ) ;
		int res = 0 ; 
		for ( auto &a : A ) { cin >> a ; res ^= a ; } 
		for ( auto &a : B ) { cin >> a ; res ^= a ; }
		if ( !res ) { cout << "Tie" << endl ; continue ; }
		int f_bit = 0 , index = 0 ;
		for ( int i = 0 ; i < 32 ; i ++ ) if ( res >> i & 1 ) f_bit = i ;
		// 找到最后一个可以改变 f_bit 位的索引是谁 谁能改变谁就赢了
		for ( int i = 0 ; i < n ; i ++ ) 
			if ( ( A[i] ^ B[i] ) & 1 << f_bit ) 
				{ index = i ; }
		( index & 1 ) == 1 ? cout << "Mai" << endl : cout << "Ajisai" << endl ;
 	}
	return 0 ;
}
//questions ：
/*

*/