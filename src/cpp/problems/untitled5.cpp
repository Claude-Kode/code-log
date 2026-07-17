//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long n,m;
		cin>>n>>m;
		if( n!=1&&m!=1 ){
			cout<<(n*m-4)%99824353<<endl;
		}else if( (n==1&&m>2) || (n>2&&m==1) ){
			cout<<(n*m-2)%99824353<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	
	return 0;
}
