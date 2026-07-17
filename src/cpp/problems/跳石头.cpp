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
//命名空间声明
using namespace std;
//全局变量&数组
int arr[50005] , diff[50005] ;
//函数声明
void generate_diff ( int arr[] , int diff[] , int n ) {
	diff[0] = 0 ;
	for ( int i = 1 ; i <=n ; i ++ ) {
		diff[i] = arr[i] - arr[i-1] ; 
	} 
}

bool check ( int test , int n , int m ) {
    int dist = 0 ;
    int countRemoval = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        dist += diff[i] ;
        if ( dist < test ) countRemoval ++ ;
        else dist = 0 ;
    }
    if ( countRemoval <= m ) {
        return true ;
    } else {
        return false ;
    }
}
//idea
/*
如果间隔大于test，说明这个块石头不需要被移除 ，
如果间隔等于test了，要把test往金额可能大的方向找
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
    generate_diff ( arr , diff , n + 1 ) ; 
    int l = 1 , r = s ;
    while ( l <= r ) {
        int mid = ( l + r ) >> 1 ;
        if (check ( mid , n + 1 , m )) l = mid + 1 ;
        else r = mid - 1 ;
    }
    cout << ( l + r ) / 2 << endl ;
	return 0;
}
//questions ：
/*

*/