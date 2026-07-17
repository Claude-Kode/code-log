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
int arr1[1001],arr2[1001];
//函数声明
int cmp(int a,int b){
	return a>b;
}
//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>arr1[i];
			arr2[i]=arr1[i];
		}
		sort(arr2,arr2+n,cmp);
		int del=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				if(arr2[i]==arr1[j]){
					arr2[i]=0;
					arr1[j]=0;
					del++;
					break;
				}
			}
		}
		cout<<m-del<<endl;
		fill_n(arr1,n,0);
		fill_n(arr2,n,0);
	}
	return 0;
}

