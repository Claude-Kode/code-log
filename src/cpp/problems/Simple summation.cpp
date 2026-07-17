//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n==0){
        cout<<'1';
    }else{
        cout<<'5';
    	for(int i=0;i<n-1;i++){
    		cout<<'0';
		}
		cout<<'5';
    	for(int i=0;i<n-1;i++){
    		cout<<'0';
		}
    }
    return 0;
}
