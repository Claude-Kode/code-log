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
long long arr[1000001], pre[1000001];
//函数声明

//代码
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + arr[i - 1];
	}
	for (int i = 0; i < n; i++) {
		arr[i + 1] += arr[i] % x;
	}
	cout << arr[n - 1] % x;
	return 0;
}
