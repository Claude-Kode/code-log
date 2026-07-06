//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组
int arr[100005] , backup_arr[100005] ;
//函数声明
void recover ( int arr[], int backup_arr[] , int n ) {
	for ( int i = 1 ; i <= n ; i ++ ) {
		arr[i] = backup_arr[i] ;
	}
}
//void generate_suffix( int arr[] , int suf[] , int n ){
//	suf[n+1] = 0 ;
//	for ( int i = n ; i >= 1 ; i -- ) {
//		suf[i] = suf[i+1] + arr[i] ;
//	}
//}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n ; 
	cin >> n ; 
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> arr[i] >> backup_arr[i];
	}
	int test = 0 , max = arr[n]  , min = 0 ;
	//二分查答案
	while ( min < max ) {
		bool sign = true ;
		recover ( arr , backup_arr , n ) ;
		test = ( min + max + 1 ) / 2 ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			arr[i] += arr[i+1] - test ;
			if ( arr[i] < test ) {
				max = test - 1 ; 
				sign = false ;
			}//test本身不可行所以max更新为 test - 1 
		}
		if ( sign ) min = test ;//test本身可行 min更新为 test即可
	}
	cout << test << endl ;
	return 0;
}
//二分的逻辑
//取最最右边的值为max , min 设置为 0
//取test = ( 0 + max ) / 2 
//用test对数组进行遍历，如果出现操作过后 arr[i] < test
//说明test取大了 把max设置为test + 1 ， test = （ min + max ) / 2 ，再次进行遍历
//只要出现 arr[i] < test 就说明test大了 
//如果一遍下来通过了，把min设置为test，
//接下来可行就把min设置为test，不可行就把max设置为test
//当max == min的时候就是正确答案了

//1. 用向下取整（test = (min + max) / 2）
//计算得 test = (a + (a+1)) / 2 = a（整数除法自动舍掉小数，向下取整）。
//假设 test = a 是可行的（符合 “找最大可行解” 的逻辑，我们需要尝试更大的值）：
//按规则更新 min = test = a（因为可行，要保留并尝试更大值）。
//更新后区间仍为 [a, a+1]，和之前完全一样。
//下一轮循环会重复计算出 test = a，陷入死循环（永远无法让 min == max）。
//2. 用向上取整（test = min + (max - min + 1) / 2）
//计算得 test = a + ((a+1) - a + 1)/2 = a + 1（向上取整到较大的那个值）。
//假设 test = a+1 是可行的：
//按规则更新 min = test = a+1，此时 min == max，循环正常终止。
//假设 test = a+1 是不可行的：
//按规则更新 max = test - 1 = a，此时 min == max，循环也能正常终止。
