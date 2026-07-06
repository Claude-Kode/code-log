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
	do{
		cin>>t;
		if(t!=1){
			if((t-1)%5==1){
				cout<<36<<endl;
			}else if((t-1)%5==1){
				cout<<36<<endl;
			}else if((t-1)%5==2){
				cout<<16<<endl;
			}else if((t-1)%5==3){
				cout<<96<<endl;
			}else if((t-1)%5==4){
				cout<<76<<endl;
			}else if((t-1)%5==0){
				cout<<56<<endl;
			}
		}else if(t==0){
			cout<<01<<endl;
		}else{
			cout<<06<<endl;
		}	
	}while(t!=-1);
	return 0;
}
