//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明
long long result(long long  a,long long  b,long long  n){
	return n * b - ( n - 1 ) * a;
	
}
void printer(long long a,long long n ){
	for ( int i=0 ; i<(n-1) ; i++ ) {  cout<<a<<' ';}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n,a,b;
	cin>>n>>a>>b;
	//
	if(b>a){ printer(a,n); cout<<result(a,b,n)<<endl;}
	
	else if(b==a) { printer(a,n+1); }
	
	else{ cout<<result(a,b,n)<<' '; printer(a,n); cout<<endl; }
	//
	return 0;
}
