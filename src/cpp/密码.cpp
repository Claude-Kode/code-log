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
	int a;
	cin>>a;
	while(a--){
		string abc = "abcdefghijklmnopqrstuvwxyz";
		string sample,recover;
		cin>>sample;
		recover = sample;
		char  temp = '\0';
		for(int k=0;k<26;k++){//偏移量
			for(int l=0;l<26;l++){//首交换(结果要加1)
				for(int r=0;r<26;r++){//末交换（结果要加1）
					if(l > r ){break;}
					for(int i=0;i<26;i++){//先偏移
						sample[i] = ( sample[i] - 'a' +26 - k ) % 26 + 'a' ;
						//cout<< sample[i]<<' '
					}
					//在交换
					for( int j = 0; j <= ( r - l + 1 ) / 2; j++){
						if( ( l+j ) >= ( r-j ) ){ break; }
						temp = sample[ l + j ];
						sample[ l + j ] = sample[ r - j ];
						sample[ r - j ] = temp;	
					}
					//cout<<endl;
					if( sample == abc ){ 
						cout<< l+1 << ' ' << r+1 << ' ' << k <<endl; 
						return 0;
					}else{
						sample = recover ;
					}
				}
			}
		}
	}
	return 0;
}
