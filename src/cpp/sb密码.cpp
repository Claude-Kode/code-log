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
int num[26];
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	//string answer="abcdefghijklmnopqrstuvwxyz";
	while(t--){
		string test;
		cin>>test;
		int l=27,r=-1,k=0;
		for(int i=0;i<26;i++){
			num[i] =  test[i] - 'a' + 1;//一定要+1啊
		}
		//先查偏移
		for(int i=0;i<25;i++){
			if( ( num[i+1] - num[i] + 26 ) % 26 == 1 ){ k = ( 26 - (i+1) + num[i]  ) % 26; break;}
		}
		//还原
		for(int i=0;i<26;i++){ 
			num[i] = ( num[i] + 26 - k ) % 26;
			if( num[i] == 0 ){ num [i] += 26 ;}
			cout<<num[i]<<' ';
		}
		cout<<endl;
		//再查反转,只要不一样就是反转的了
		int count = 0;
		for(int i=0;i<26;i++){
			if( num[i] != ( i + 1 )){ 
				count = i + 1;
				if( l > count ){ l = count; }
				if( r < count ){ r = count; }
			}
		}
		if( count == 0 ){ l = 1; r =1 ; }
		cout << l << ' ' << r << ' ' << k << endl;
	}
	return 0;
}
