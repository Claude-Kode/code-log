//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
long long arr[100005];
//函数声明

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
        	cin>>arr[i];
            //cout<<arr[i]<<' ';
		}
        //cout<<endl;
		sort(arr,arr+n);
        //for(int i=0;i<n;i++){
            //cout<<arr[i]<<' ';
        //}
        //cout<<endl;
		long long result=0;
		for(int i=0;i<n;i++){
			if(m-arr[i]>=0){result++;}
		}
		//cout<<result<<endl;
        memset(arr,0,4*n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' ';
            cout<<endl;
        }
    }   
    return 0;
}
