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
long long calculate_zero(int n){
	long long result=0;
	while(n!=0){
		result+=n/2;
		n/=2;
	}
	return result;
}
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long  n;
	cin>>n;
	cout<<calculate_zero(n)<<endl;
	return 0;
}
