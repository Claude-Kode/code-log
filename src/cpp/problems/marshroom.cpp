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
int arr[100001];
//函数声明
int cmp( int a , int b ){
	if ( a < 0 && b < 0 ) return a > b ;
	else if ( a > 0 && b > 0 ) return a < b ;
	else if ( a > 0 && b < 0 ) return a > b;
	else return a < b ;
}
//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int number = 0 ;
	//bool continueinput = true ;
	int sub = 0 ;
	for ( int i = 0 ; i < n ; i++ ) {
		int j = 0 ;
		int temp = 1 ;
		cin >> temp ;  
		if ( temp == 0 ) number++ ;
		else arr[sub] = temp ; sub++;
	}
	sort ( arr , arr + sub + 1 ; cmp );
	int i = 0 ; 
	int j  = sub - 1 ;
	while ( j > i ){
		if ( arr[i] == 0 || arr[j] == 0 ) break ;
		if  ( arr[i] + arr[j] <= 0 ){
			number+=2;
			i++;
			j--;
		} else {
			break;
		}
	}	
	while (true){
		if( arr[i] < 0 ) {
			number++;
			i++;
		}else break;
	}
	cout << number << endl ;
	return 0;
}
