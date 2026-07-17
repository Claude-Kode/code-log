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
string A[101],B[101];
//函数声明
int  cmp1(const string& a,const string& b){
	int len1=a.length();
	int len2=b.length();
	if( len1 > len2 )  {return 1;}
	else if( len1 == len2 )  {return 0;}//位数相等cmp2
	else  {return -1;}//后比前大，max需要更新
}

bool cmp2(const string& a,const string& b){
	int len=a.length();
	for(int i=0;i<len;i++){
		if ( a[i] < b[i] )  {return true;}//max需要更新
	}
	return false;
}

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		for(int i=0;i<m;i++){
			cin>>B[i];
		}
		
		string max_A="\0",max_B="\0";
		
		for(int i=0;i<n;i++){
			if( cmp1( max_A , A[i] )==-1 ){
				max_A=A[i];
			}else if( cmp1( max_A , A[i] )==0 ){
				if( cmp2( max_A , A[i] ) ){
					max_A=A[i];
				}
			}
		}
		
		for(int i=0;i<n;i++){
			if( cmp1( max_B , B[i] )==-1 ){
				max_B=B[i];
			}else if( cmp1( max_B , B[i] )==0 ){
				if( cmp2( max_B , B[i] ) ){
					max_B=B[i];
				}
			}
		}
		cout<<max_A<<max_B<<endl;
	}
	return 0;
}
