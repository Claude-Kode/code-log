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
	long long  x,y;
	cin>>x>>y;
	if((x&1)==1&&(y&1)==1){
		cout<<(x+1)*(y-1)/4+(x-1)*(y+1)/4<<endl;
	}else{
		cout<<x*y/2<<endl;
	}
	return 0;
}
