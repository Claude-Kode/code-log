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
/*bool cmp(string a,string b){
if(a.size()>b.size())return 1;
if(a.size()<b.size())return 0;
if(a.size()==b.size())return a>b;

}
sort(a+1,a+n+1,cmp);
sort(b+1,b+m+1,cmp);*/

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
		
		string max_A,max_B;
		
		for(int i=0;i<n-1;i++){
			if( cmp1 ( A[i] , A[i+1] ) ==1 ){//A[i]位数>A[i+1]
				max_A=A[i];
			}else if( cmp1 ( A[i] , A[i+1] ) ==0 ){//A[i]位数==A[i+1]
				if( cmp2 ( A[i] , A[i+1] ) ){
					max_A=A[i];
				}else{
					max_A=A[i+1];
				}
			}else{//A[i]位数<A[i+1]
				max_A=A[i+1];
			}
		}
		
		for(int i=0;i<m-1;i++){
			if( cmp1 ( B[i] , B[i+1] ) ==1 ){//B[i]位数>B[i+1]
				max_B=B[i];
			}else if( cmp1 ( B[i] , B[i+1] ) ==0 ){//B[i]位数==B[i+1]
				
				if( cmp2 ( B[i] , B[i+1] ) ){
					max_B=B[i];
				}else{
					max_B=B[i+1];
				}
				
			}else{//B[i]位数<B[i+1]
				max_B=B[i+1];
			}
		}
		cout<<max_A<<max_B<<endl;
	}
	return 0;
}
/*bool cmp(string a,string b){
if(a.size()>b.size())return 1;
if(a.size()<b.size())return 0;
if(a.size()==b.size())return a>b;

}
sort(a+1,a+n+1,cmp);
sort(b+1,b+m+1,cmp);*/
