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

//函数声明
long long group(long long N,int k){
	//cout << "-1:" << N << "\n" ;
	
	if(N<=k){return 1;}
	if( ( (N-k) &1 ) !=0){return 1;}
	if( ( (N-k) &1 ) ==0){return group((N-k)/2,k)+group((N-k)/2+k,k);}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	long long N;
	int k;
	cin>>N>>k;
	cout<<group(N,k)<<endl;

	
	return 0;
}
