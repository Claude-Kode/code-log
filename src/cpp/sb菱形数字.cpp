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
		memset(judge,0,10);
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
		memset(judge,0,10);
	}
	if(sign==0){
		cout<<"No";
	}else{
		cout<<"Yes";
	}
	return 0;
} 
