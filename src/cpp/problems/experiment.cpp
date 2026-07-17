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
int day[88888];
//函数声明
int timeread(){
	int a,b,c;
	char d,e;
	cin>>a>>d>>b>>e>>c;
	return  a*3600+b*60+c; 
}
//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a=timeread();
		int b=timeread();
		//cout<<a<<' '<<b<<endl;
		day[a]++;//进去的那一秒+1
		day[b+1]--;//出去的那一秒的下一秒-1，因为出去的那一秒也算在店里
		
	}
	int max_guest = 0 , guest = 0;
	for(int i=0;i<88888;i++){
		guest+=day[i];
		if(max_guest<guest){
			max_guest=guest;
		}
	}
	cout<<max_guest<<endl;
	return 0;
}
