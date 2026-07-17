//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明
long long intersect_judge(long long x1,long long y1,long long r1,long long x2,long long y2,long long r2){
	long long dis = (y2-y1) * (y2-y1) + (x2-x1) * (x2-x1);
	long long sum = (r1+r2) * (r1+r2);
	long long dif = (r1-r2) * (r1-r2);
	if( dis > sum || dis < dif){ return 0; }
	else if( dis == sum || dis == dif ){ return 1; }
	else{ return 2; }
}
//(y2-y1) * (y2-y1) + (x2-x1) * (x2-x1) < (r1-r2) * (r1-r2)
//
//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long x1,y1,r1,x2,y2,r2;
	while(true){
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		if( cin.eof() ){ break; }
		int result = intersect_judge (x1,y1,r1,x2,y2,r2);
		if( result == 2 ){ cout << 2 << endl; }
		else if ( result == 1 ){ cout << 1 << endl; }
		else { cout << 0 << endl; }
	}
	return 0;
}
