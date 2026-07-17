//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
long long arr1[300001],arr2[300001];
//函数声明

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	sort(arr1,arr1+n);
	for(int j=0;j<m;j++){
		cin>>arr2[j];		
	}
	sort(arr2,arr2+m);
	long long result=0;
	int sub=0;
	for(int i=0;i<m;i++){
		if(arr2[i]>=arr1[sub]){
			result+=arr2[i];
			if(sub==n-1){
				break;
			}
			sub++;
		}
	}
	cout<<result<<endl;
	return 0;
}
