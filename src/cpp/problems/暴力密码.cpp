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

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	string answer="abcdefghijklmnopqrstuvwxyz";
	while(t--){
		string abc ,backup ;
		cin>>abc;
		char temp;
		for(int k=0;k<26;k++){
			//先偏移
			for(int i=0;i<26;i++){
				abc[i] = ( abc[i] - ('a' - 1) + 26 - k ) % 26 + ( 'a' - 1 );
			}
			backup = abc;
			for(int r=1;r<=26;r++){
				for(int l=1;l<=r;l++){
					
					//翻转
					for( int i = 0 ; i < ( r - l + 1) / 2 ; i++){
						temp = abc[l - 1 + i];
						abc[l - 1 + i]=abc[r - 1 - i];
						abc[r - 1 - i]=temp;
					}
					if( abc == answer ){ cout << l  << ' ' << r << ' ' << k << endl ; goto end;}
				}
			}
			abc = backup ;
		}
		end:;
	}
	return 0;
}
