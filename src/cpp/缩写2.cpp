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
string str[1001][101];
//函数声明
//全大写判断
bool cap(const string& a){
	for(char c : a){
		if(c>'Z'||c<'A'){return false;}
	}
	return true; 
}
//首字母大写判断
bool cap_1(const string& a){
	if(a[0]<='Z'&&a[0]>='A'){return true;}
	return false;
}

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int j=0;
		do{
			cin>>str[i][j];
			if(  cap ( str[i][j] ) ){
				cout<<str[i][j];
			}else if( cap_1 ( str[i][j] ) ){
				cout<<str[i][j][0];
			}
			j++;
		}while( cin.peek()!='\n');//peek只读不取
		cout<<endl;
	}
	return 0;
}
