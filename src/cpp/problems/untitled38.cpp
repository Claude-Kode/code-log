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

//函数声明

//idea
/*

*/
//代码
signed main(){
	ios_base::sync_with_stdio ( false ) ; cin.tie ( 0 ) ;cout.tie ( 0 ) ;
	int t ;
	cin >> t ;
	while( t -- ) {
		int n ;
		cin >> n ;
		vector <int> arr ( n ) ;
		unordered_map <int , int> mymap ;
		// input
		cin >> arr[0] ;
		int win = 0 , lose = 0 ;
		for ( int i = 1 ; i < n ; i ++ ) {
			
			cin >> arr[i] ; 
			mymap [ arr[i] ] ++ ;
			
			if ( arr[i] < arr[0] ) win ++ ;
			else if ( arr[i] > arr[0] ) lose ++ ;
			
		} 
		
		// calculate
		unordered_map <int , int> winNum ; winNum [arr[0]] = win ;
		unordered_map <int , int> loseNum ; loseNum [arr[0]] = lose ;
		sort ( arr.begin() , arr.end() ) ;
		for ( int i = 1 ; i < n ; i ++ ) {
			
			if ( arr[i] > arr[i-1] ) {
				win  += mymap [ arr[i-1] ] ; 
				lose -= mymap [ arr[i] ]   ; 
				
			} else if ( arr[i] < arr[i-1] ) {
				win  -= mymap [ arr[i] ] ; 
				lose += mymap [ arr[i-1] ]   ; 
			}
			
			winNum [ arr[i] ] = win ;
			loseNum [ arr[i] ] = lose ;
			
		}
		// print
		for ( auto &a : arr ) cout << winNum [a] << ' ' ;
		cout << endl ;
		for ( auto &a : arr ) cout << loseNum [a] << ' ' ;
		cout << endl ;
	}
	return 0 ;
}
//questions ：
/*

*/
