/*
//第一步先查出两年都是快乐时光的段数
//每一段统计出长度（几天）
//每一段的加合输出
#include <iostream>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int arr[1000000];

int sigma(int a){
	if(a==1){return 1;}
	return a+sigma(a-1);}
	
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    	int len=0;//字符串长度 
    	string a,b;//22，23年快乐/不快乐 
    	cin>>len>>a>>b;
    	int days=0;//快乐时光的段数 
    	for(int i=0;i<len-1;i++){
			if(a[i]=='1'&&a[i+1]=='1'&&b[i]=='1'&&b[i+1]=='1'){
				arr[days]++;
				if((a[i]=='1'&&a[i+1]=='0')||(b[i]=='1'&&b[i+1]=='0')){
					days++;
				}
			}	
		}
		int result=0;
		for(int i=0;i<days;i++){result+=sigma(arr[i]+1);} 
		cout<<result<<endl;
		fill_n(arr,arr+days,0);
    }
    return 0;
} 
*/
//第一步先查出两年都是快乐时光的段数
//每一段统计出长度（几天）
//每一段的加合输出
//第一步先查出两年都是快乐时光的段数
//每一段统计出长度（几天）
//每一段的加合输出
#include <iostream>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int arr[1000000];

int sigma(int a){
	if(a==1){return 1;}
	return a+sigma(a-1);}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int len=0;//字符串长度 
		string a,b;//22，23年快乐/不快乐 
		cin>>len>>a>>b;
		int days=0;//快乐时光的段数 
		for(int i=0;i<len-1;i++){
			int sign=0;
			if(a[i]=='1'&&a[i+1]=='1'&&b[i]=='1'&&b[i+1]=='1'){
				arr[days]++;
				sign=1;
			}
			if(((a[i]=='1'&&a[i+1]=='0')||(b[i]=='1'&&b[i+1]=='0'))&&sign==1){
				days++;
			}	
		}
		int result=0;
		for(int i=0;i<days;i++){result+=sigma(arr[i]+1);} 
		cout<<result<<endl;
		fill_n(arr,days,0);
	}
	return 0;
} 
