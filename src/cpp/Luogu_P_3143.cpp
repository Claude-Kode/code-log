// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
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
低于每个元素ele搜索左边开始第一个
ele - k 出现的位置就是答案个数
但是问题来了能搜出最大的那个但是要求两个不重复我靠
那么策略问题来了 ， 我是让两个中的一个尽可能大还是让两个都取平均
直觉告诉我应该是是第一个
或者说直接把区间扩大到 2 * k ?
应该是不行的
或者说从左到右搜一遍 ，从右到左搜一遍
左起点 > 右起点
找加合最大的两对
但是这样退化了把 ， 复杂度变成n方了

*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	
	return 0 ;
}
//questions ：
/*

*/