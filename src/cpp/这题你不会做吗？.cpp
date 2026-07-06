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

//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int count_0=0,count_1=0;
	int temp=0;
	for (int i=0;i<n;i++){ 
		cin>>temp;
		if(temp>=m){ count_1++;}
		else{ count_0++;}
	}
	if( count_1 + 1 >= count_0 ){ cout<<count_1 - count_0 <<endl;}
	else{ cout<<-1<<endl;}
	return 0;
}
