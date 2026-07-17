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
//char t1[1000000],t2[1000000];
//函数声明

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int len=s.length();
    int l,r;
    cin>>l>>r;
    string t1,t2;
    for(int i=0;i<=l-1;i++){
    	//t1[i]=s[l-i-1];  
        t1.push_back(s[l-i-1]);
    }
    //cout<<t1<<endl;
    for(int i=0;i<=len-r;i++){
        //t2[i]=s[r+i-1]; 
    	t2.push_back(s[r+i-1]);
	}
    //cout<<t2<<endl;
    int result=t1.compare(t2);
    result<0?cout<<"luoluo"<<endl:cout<<"fanfan"<<endl;
    return 0;
}
