//头文件
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
//宏定义
#define endl '\n'
#define int long long
//命名空间声明
using namespace std ;
//全局变量&数组
struct number_infor {
	int value ;
	bool is_used = true ;
};
//函数声明
bool cmp ( number_infor a , number_infor b ) {
	return a.value > b.value ;
}
bool check ( vector <int> backup , int x , int m ) {
	//逻辑是先固定 x 的奇偶位，然后差m - 1个大于等于他的数字
	//如果有等于它的数字，且可以固定在不同奇偶位的地方，x就是答案
	//如果没有相等的，必须在异奇偶位插入一个小于x的元素
	return  ; // zhee shi shen me b ti a zhen tm fu le 
}
//idea
/*
二分思维
取某个值，能从他的后面选出 m个比他大的，就在他后面找一个比他的大的接着是
如果不能，往前面找
关于奇数位最凶啊和偶数位最小请举出反例
可能是奇数位照一次偶数位再找一次？但是两次查找为一对，且一对不出现下标重复的元素
选一个数字作为
直接固定一个数，往前找一个小于等于他的，往后找 m - 2 个大于等于他的就可以，同时储存第一个小于等于他的数和第一个大于等于他的数
但是也不行，有可能是严格递减数列就没招了
用作下一次的查找
贪心的最优解就是以最大值为起点，向两边搜索，第m个小于他的数就是答案
那么这样的话是可以排序的啊，子序列虽然被改变了顺序但是题里没固定这个解的位置
关键是排序之后可能就改变了对应值的下标的奇偶性了
*/
//代码
signed main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	vector <int> arr ( n ) ;
	vector <int> backup ( n ) ; 
	int max_value = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( max_value < arr[i] ) max_value = arr[i] ;
		cin >> arr[i] ;
		arr[i] = backup[i] ;
	}
	sort ( backup.begin() , backup.end() , cmp ) ;	
	
	if ( m == 1 ) {
		cout << max_value << endl ;
	} else {
		
		
		
		
		
		
		
		
		
	}
	return 0 ;
}
//questions ： 
/*

*/
