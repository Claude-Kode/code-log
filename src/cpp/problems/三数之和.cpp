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
int arr[3001];
//函数声明

//代码
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int result  = 0;
	sort ( arr , arr + n );
	for ( int i = 0 ; i < n - 2 ; i++ ){
		if ( i > 0 && arr[i] == arr[i-1] ) continue ;//首先固定i，同时三元和为零的问题化解为找另外两个数，他们的合是i的相反数
													 //所以如果i和上一项相等，上一项已经算过的你要是再算就重复了，得跳过
		int j = i + 1;
		int k = n - 1;
		while( j < k ){
			int sum = arr[i] + arr[j] + arr[k] ;
			if ( sum == 0) {
				result++ ;	//找出一个符合结果的情况
				while ( j < k && arr[j] == arr[j+1]){//对j去重，也就是左指针
					j++;
				}
				while ( j < k && arr[k] == arr[k-1]){//对k去重，也就是右指针
					k--;
				}
				k--;//都没有重，让右指针左移，测下一组
			} else if ( sum < 0 ){//记得我的排序吗，和小于0证明数小了，右指针再左移肯定全小于0，直接右移左指针
				j++ ;
			} else {//sum > 0 同理
				k--;
			}
		}
	}
	cout<<result<<endl;
	return 0;
}
