//每个数据都对三取一遍模
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
long long arr[1001];
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long result=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			result+=arr[i]%3;
			result%=
		}
		result%3==0 ? cout<<"yes"<<endl : cout<<"no"<<endl;
	}
	
	return 0;
}
