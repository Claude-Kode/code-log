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
    int t;
    cin>>t;
    string a;
    int sum=0; 
    while(t--){
    	cin>>a;
    	int number=a[a.length()-1];
    	//
    	if( (number&1)==0 ){//如果是偶数 
    		sum-=number;
		}else{//如果是奇数 
			sum+=number;
		} 
		
	}
	if( (sum&1)==0 ){//如果是偶数
		cout<<"even"<<endl;
	}else{//如果是奇数 
		cout<<"odd"<<endl;
	}
    return 0;
}
