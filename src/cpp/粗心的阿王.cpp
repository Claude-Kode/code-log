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
int mod_date(int a,int b,int c){
	//年份,从1到a-1年
	int sum_year=0;
	int year=a-1;
	int leap_year=year/4-year/100+year/400;//总闰月数量
	sum_year+=year*365+leap_year;
	//月份
	int sum_month=0;
	int pre[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
	sum_month+=pre[b-1];
	if( (a%4==0 && a%100!=0) || a%400==0 ){//如果a是闰年
		if(b>2){
			sum_month++;
		}
	}
	//日子      
	int sum_day=0;
	sum_day+=c;
	//
	return sum_day+sum_month+sum_year;
}

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int result= mod_date(a,b,c) %7;
		//只有周日和周一不打滑
		if( result==0 || result==6 ){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
