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
int arr[1001],buckle[1001];
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int max_sub=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			buckle[arr[i]]++;
			if(max_sub<arr[i]){max_sub=arr[i];}
		}
		if((n&1)==1){
			cout<<"NO"<<endl;
			fill_n(arr,n,0);
			fill_n(buckle,1001,0);
			continue;
		}
		
		bool sign=true;
		for(int i=1;i<=max_sub;i++){
			if(buckle[i]>2 ){
				sign=false;
				break;
			}
		}
		
		sign==true ? cout<<"YES"<<endl : cout<<"NO"<<endl;
		fill_n(arr,n,0);
		fill_n(buckle,1001,0);
	}
	
	return 0;
}
