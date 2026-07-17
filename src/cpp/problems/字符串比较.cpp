//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
int buckle1[123],buckle2[123];
//函数声明

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        for(int i=0;i<n;i++){
        	buckle1[a[i]]++;  
			buckle2[b[i]]++;
		}
		bool sign=true;
		for(int i=0;i<123;i++){
			if(buckle1[i]!=buckle2[i]){
				sign=false;
				break;	
			}
		}
		sign?cout<<"YES"<<endl:cout<<"NO"<<endl;
		fill_n(buckle1,123,0); fill_n(buckle2,123,0);
	}
	return 0;
}
