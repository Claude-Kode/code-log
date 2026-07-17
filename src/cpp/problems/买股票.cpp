 //头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
int arr[1000001];
//函数声明

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
		}
		for(int i=0;i<n-1;i++){
			if(arr[i]<arr[i+1]){
				result+=arr[i+1]-arr[i];
			}
		}
		cout<<result<<endl;
	}
    return 0;
}
//开long long  long long  long long  long long  long long  long long  long long  
//long long  long long  long long  long long  long long  long long  long long  
//long long  long long  long long  long long  long long  long long  long long  
//long long  long long  long long  long long  long long  long long  long long  
