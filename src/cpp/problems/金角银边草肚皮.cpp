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
    long long n,m,q;
    cin>>n>>m>>q;
    int sign=0;
    if(n!=1&&m!=1){
    	if(q==1||q==m||q==1+(n-1)*m||q==n*m){
    		cout<<"Au"; 
		}else if( ( q > 1 && q < m) || ( q > 1+(n-1)*m &&q < n*m ) || q%m==0 || (q-1)%m==0 ) {
			cout<<"Ag";
		}else{
			cout<<"Fw";
		}
	}else{
		cout<<"Au";
	}
    return 0;
}
