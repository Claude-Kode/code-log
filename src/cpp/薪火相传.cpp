//本题就是求最长的连续为0的子串的长度
//头文件
#include <iostream>
#include <string>
#include <algorithm>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组
int arr[100001];
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n=0;
		string s;
		cin>>n>>s; 
		int len=s.length();
		int len_tou=0,len_wei=0;
		if(s[0]=='0'){
			for(int i=0;i<n;i++){
				if(s[i]=='0'){len_tou++;}
				else{ break;}
			}
		}
		if(s[len-1]=='0'){
			for(int i=len-1;i>=0;i--){
				if(s[i]=='0'){len_wei++;}
				else{ break;}
			}
		}
		int max1=0,temp=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				temp++;
				if(max1<temp){
					max1=temp;
				}
			}else{ 
				temp=0;
			}
		}
		int result=max( (max1+1)/2 , max(len_tou,len_wei));
		cout<<result<<endl;
	}
	return 0;
}
