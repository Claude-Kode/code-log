//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
int arr1[10]={-1},arr2[10]={-1};
char num[10];
//函数声明

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int sub1=1,sub2=1;
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(num[i]=='1'){
			arr1[sub1]=i;
			sub1++;
		}else{
			arr2[sub2]=i;
			sub2++;
		}
	}
	int q,k;//q是字符，k是次数
	for(int i=0;i<m;i++){
		cin>>q>>k;
		if(q==1&&arr1[k]!=-1||arr1[k]!=0){
			cout<<arr1[k]<<endl;
		}else if(q==0&&arr2[k]!=-1||arr2[k]!=0){
			cout<<arr2[k]<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
