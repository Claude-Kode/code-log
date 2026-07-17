//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
int arr1[8001],arr2[8001];
string name1[8001],name2[8001];
//函数声明

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int t1;
	cin>>t1;
	for(int i=0;i<t1;i++){
		cin>>arr1[i]>>name1[i];	
	}
	
	int t2;
	cin>>t2;
	for(int i=0;i<t2;i++){
        cin>>name2[i]>>arr2[i];	
	}
	
	int t3;
	cin>>t3;
	int number;
	for(int i=0;i<t3;i++){
		cin>>number;
		bool sign=false;
		
		for(int j=0;j<t1;j++){
			if(number==arr1[j]){
				sign=true;
			}
		}

		for(int j=0;j<t2;j++){
			if(number==arr2[j]){
				for(int k=0;k<t1;k++){
					if(name2[j]==name1[k]){
						sign=true;
					}
				}
			}
		}
		
		if(sign){
			cout<<"no"<<endl;
		}else{
			cout<<"yes"<<endl;
		}
		
	}
	return 0;
}
