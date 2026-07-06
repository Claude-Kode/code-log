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
int arr[1000005] , check[1000005] ;
//函数声明
// int cmp ( const check &answer1 , const check &answer2 ) {
// 	if ( answer1.count_graph != 0 && answer2.count_graph != 0 ){
// 		return answer1.number < answer2.number ;
// 	}
// }
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	int l , r ;
	int temp = m ;
	while ( temp -- ) {
		cin >> l >> r ;
		arr[l] ++ ;
		arr[r+1] -- ;//构造差分数组，下标就是店铺的编号
		//cout << l << ' ' << r ;
	}
	//cout << endl ;
//	for ( int i = 1 ; i <=n + 1 ; i ++ ){
//		cout << arr[i] << ' ' ;
//	}
//	cout << endl ;
//	int true_message = -1 ;//
	for ( int i = 1 ; i <= n + 1 ; i ++ ){//arr[i+1]是组合数组，下标从1到n
		arr[i] += arr[i-1] ;
		//这两部把差分数组进行加合，非零的累加起来
//		cout << arr[i] << ' ' ;
//		if ( true_message > arr[i+1] ) true_message = arr[i+1] ;
		
	}
//    bool sign = true ;
	for ( int i = 1 ; i <= n ; i ++ ){//结构体的下标代表储存的是 消息正确个数 的相关数据（
		check[arr[i]] ++  ;
//        if ( arr[i] != arr[i-1] ) answer[arr[i-1]].count ++ ;
	}
//	for ( int i = 0 ; i <= m ; i ++ ){
//		cout << answer[i].number << ' ' << answer[i].count << endl ;
//	}
	for ( int i = 0 ; i <= m ; i ++ ){
		if (  check[i] != 0 ) cout << m - i << ' ' << check[i] << endl ;
		break ;
	}
// 	 	sort ( answer , answer + m , cmp ) ;
// 	cout << answer[0].number << ' ' << answer[0].count_graph << endl ;
	return 0;
}
//有点像时间那道题/、，消息的左区间设置为 1 ，有区间+1设置为 0 
//下标代表餐厅的编号

//捋一下思路
//初始化为零，大小是 n+1 的数组

