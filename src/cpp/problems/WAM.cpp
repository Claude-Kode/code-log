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

auto  main() ->int {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string str;
        int W=0,A=0,R=0,N=0,M=0,len=0;
        cin>>len>>str;
        auto a = [](){
        	
			};
			a()
        for(int i=0;i<len;i++){
        	if(str[i]=='W'){
        		W++;
			}else if(str[i]=='A'){
        		A++;
			}else if(str[i]=='R'){
        		R++;
			}else if(str[i]=='N'){
        		N++;
			}else if(str[i]=='M'){
        		M++;
			}
		}
		int good=min(W,min(A,M));
		int bad=min(R,min(N,M));
		good>=bad ? cout<<good-bad<<endl : cout<<0<<endl; 
	}
    return 0;
}
