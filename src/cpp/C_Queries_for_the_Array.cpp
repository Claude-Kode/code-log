// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;


    
void solve() { 

  string s; cin >> s;
  int mn = 0, mx = 0, sz = 0; 

  // sorted 维护的其实是一个最大的有序区间
  // unsorted 维护的是一个最小的无序区间
  int sorted = 0 , unsorted = INT_MAX;
  for(const auto &c : s) {
    if (c == '+') {
      sz ++;
    }
    if (c == '-') {
      sz --;
      sorted = min(sorted, sz);
      if (unsorted > sz) unsorted = INT_MAX;
    }
    if (c == '0') {
      if (sz <= 1) {cout << "NO" << endl; return;}
      if (sorted >= sz) {cout << "NO" << endl; return;}
      unsorted = min(unsorted, sz);
    }
    if (c == '1') {
      if (unsorted <= sz && unsorted) {cout << "NO" << endl; return;}
      sorted = sz; 
      if (unsorted != INT_MAX) unsorted = 0;
    }
  }

  cout << "YES" << endl;
}

/*
或者说我们维护一个变量 表示确定的一定是 sorted 的元素个数

这个样例 是考虑会不会有两个 1 的

三、如何想到维护 sorted和 unsorted

这类问题常涉及“前缀性质”的断言（如“数组有序”本质上是所有前缀有序的合取）。经验包括：

关注断言的范围：操作1断言的是整个数组有序，这意味着所有前缀都有序；操作0断言的是存在一个前缀无序。这种“全称”与“存在”的对立即是矛盾根源。

寻找最紧约束：

对于全称量词（∀），记录最强的正面结论：最长有序前缀

对于存在量词（∃），记录最弱的反面证据：最短无序前缀

利用单调性：

有序性质是“前缀遗传的”：如果长度为L的数组有序，则所有更短前缀也有序

无序性质是“后缀遗传的”：如果存在长度为L的无序前缀，则所有更长数组也包含该无序前缀

四、通用解题模式

识别断言类型：是全称断言（如“所有元素满足…”）还是存在断言（如“存在元素满足…”）

维护极值信息：

全称断言 → 维护最大的满足范围

存在断言 → 维护最小的反例范围

注意信息的部分持久性：删除操作可能使某些断言失效，需正确回退状态

推导充要条件：通过分析断言间的逻辑关系（蕴含、互斥）得到矛盾条件

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}