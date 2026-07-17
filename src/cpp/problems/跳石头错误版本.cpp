//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
int arr[50005] , diff[50005] , copy_diff[50005] ;
//函数声明
void generate_diff ( int arr[] , int diff[] ,int copy_diff[] , int n ) {
	diff[0] = 0 ; copy_diff[0] = 0 ;
	for ( int i = 1 ; i <=n ; i ++ ) {
		diff[i] = arr[i] - arr[i-1] ; 
		copy_diff[i] = diff[i] ;
	}
}

int find_max ( int diff[] , int n ) {
	int max_value = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		if ( max_value < diff[i] ) max_value = diff[i] ;
	}
	return max_value ;
} 

void recover_copy_diff ( int diff[] , int copy_diff[] , int n ) {
	for ( int i = 1 ; i <= n ; i ++ ) {
		copy_diff[i] = diff[i] ;
	}
}
//idea
/*
二分搜索符合条件的x
距离小于x说明当前这个石头需要被移除，并且把这段距离加到它后面的石头上
记录移除的操作数量
如果正好等于M说明非常good！
大于M说明你这个x定的太高了
小于m说明x定得太低了
x的最小值是查分数组里面的最小值，但是这里直接写1应该就可以，
r是最大的数字，应该也是可以取的，如果差分是均匀的话，确实是可以等于的
这道题是一个闭区间
所有数组下下标均从1开始
arr数组的有效元素数量为 n + 1
diff同
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int s , n , m ;
	cin >> s >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> arr[i] ;
	}
	arr[n+1] = s ;
	generate_diff ( arr , diff , copy_diff ,  n + 1 ) ;
	int l = 1 , r = find_max ( diff , n + 1 ) ; 
	int result = 0 ;
	while ( l <= r ) {
		recover_copy_diff ( diff , copy_diff , n + 1 ) ;
		int mid = ( l + r ) >> 1 ;
		int count_remove = 0 ;
		for ( int i = 1 ; i <= n ; i ++ ) { //最后一块石头不能移除但是好像也得查一下，有可能就算移除了前面的石头，最后一块到倒数第二块也不满足
			if ( copy_diff[i] < mid ) {
				count_remove ++ ;
				copy_diff[i+1] += copy_diff[i] ;
			}
		}
		//等于了以后把mid往大了查
		if ( count_remove > m ) r = mid - 1 ;
		if ( count_remove <= m ) {
			l = mid + 1 ;
			result = mid ;
		}
	}
	cout << result << endl ;
	return 0 ;
 }
//questions ：
/*

*/
