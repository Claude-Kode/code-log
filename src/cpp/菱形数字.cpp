//这道题我有很多种思路
//1  直接写入五个数字，通过除法分离出个位十位百位千位然后用不等号判断
//2  写入一个字符数组，转化成数字以后（ascii数值的加减）然后用桶，是否有大于一的
//3  最笨的，写入字符数组以后每个都挑出来挨个遍历
//感觉这道题码量下不来qwq 
//made 每一列也要看只能用二维字符数组了 
#include <iostream>
#include <string>
using namespace std;
string  str[5];
int main(){
	for(int i=0;i<5;i++){
		getline(cin,str[i]);
	}
	int sign=0;
	for(int i=0;i<5;i++){//行查一遍 
		for(int sub1=0;sub1<5;sub1++){
			for(int j=0;j<5;j++){
				if(str[i][sub1]==str[i][j]&&str[i][sub1]!=' '&&str[i][j]!=' '){
			 	sign++;
				}
			}
		}
	}
	for(int i=0;i<5;i++){//列查一遍 
		for(int sub2=0;sub2<5;sub2++){
			for(int j=0;j<5;j++){
				if(str[sub2][i]==str[j][i]&&str[sub2][i]!=' '&&str[j][i]!=' '){
			 		sign++;
				}
			}
		}
	}
	if(sign==13){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}
//下面我再用桶写一遍
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
string  str[5];
int judge[10];
int main(){
	int sign=0; 
	for(int i=0;i<5;i++){
		getline(cin,str[i]);
		//getchar();
	}
	for(int i=0;i<5;i++){//行查一遍 
		for(int j=0;j<5;j++){
			if(str[i][j]!=' '){
				judge[str[i][j]-'0']++;	
			}
		}
		for(int k=0;k<10;k++){
			if(judge[k]>1){
				sign=114514;
				break;
			}
		}
		memset(judge,0,40);
	}
	for(int i=0;i<5;i++){//列查一遍 
		for(int j=0;j<5;j++){
			if(str[j][i]!=' '){
				judge[str[j][i]-'0']++;	
			}
		}
		for(int k=0;k<10;k++){
			if(judge[k]>1){
				sign=114514;
				break;
			}
		}
		memset(judge,0,40);
	}
	if(sign==0){
		cout<<"No";
	}else{
		cout<<"Yes";
	}
	return 0;
}  
