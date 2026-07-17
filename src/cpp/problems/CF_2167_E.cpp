// header file
#include <iostream>
#include <algorithm>
#include <vector>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays

// functions declarations

//idea
/*
第一想法就是 每个传送阵难道都要满足最优解吗 ， 肯定不是
不是让每个的距离都尽可能大 ，而是设置一个最小距离然后验证
这不二分吗？？？
先找有意义的特殊情况
好像没有 ， 如果每个位置都有人直接随便放
只有一个位置没有人就放那个位置
如果最小距离是x那么两个朋友之间的最小间隔如果大于2 * x那么是不能放的
max(0, (a[i] - m) - (a[i - 1] + m) + 1);
我的问题在于check的思路不是贪心的
我的是这样排列的 
| *** & *** & *** |
其实贪心应该是这样的
| *****&&**** |
全堆在中间的
*/
// codes
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int t ; cin >> t ;
	int i  = 0 ;
	while ( t -- ) {
		int n , k , x ; cin >> n >> k >> x ;
		vector<int> pos ( n ) ;
		for ( auto &a : pos ) cin >> a ;
		
		cout << endl ;
	}	
	return 0 ;
}
//questions ：
/*

*/

// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, k, x;
//         cin >> n >> k >> x;
//         vector<int> a(n);
//         for (int &i : a) cin >> i;
//         a.push_back(-1e9);
//         a.push_back(1e9);
//         n += 2;
//         sort(a.begin(), a.end());
//         int l = 0, r = x + 1;
//         while (l + 1 < r) {
//             int m = (l + r) >> 1, f = 0;
//             a[0] = - m, a[n - 1] = x + m;
//             for (int i = 1; i < n; ++i) f += max(0, (a[i] - m) - (a[i - 1] + m) + 1);
//             if (f >= k) l = m;
//             else r = m;
//         }
//         a[0] = - l, a[n - 1] = x + l;
//         int j = 0;
//         for (int i = 1; i < n; i++)
//     		for (j = max(j, a[i - 1] + l); j <= min((a[i] - l), x) && k; j++)
//     			cout << j << ' ', k--;
//     	cout << '\n';
//     }
//     return 0;
// }