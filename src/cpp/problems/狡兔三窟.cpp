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
int buckle[46];
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	int max=0;
	for(int i=1;i<=t;i++){
		int result=0,j=i;
		while(j!=0){
			result+=j%10;
			j=int (j/10);
		}
		buckle[result]++;
		if(max<buckle[result]){max=buckle[result];}
	}
	cout<<max<<endl;
	return 0;
}
