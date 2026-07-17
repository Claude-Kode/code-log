// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i ++) {
    char c; cin >> c;
    a[i] = (c == '(' ? 1 : -1);
  }

  for(int i = 1; i <= n; i ++) {
    char c; cin >> c;
    b[i] = (c == '(' ? 1 : -1);
  }

  if (count(a.begin(), a.end(), 1) + count(b.begin(), b.end(), 1) != n || a[1] < 0 || b[1] < 0) {
    std::cout << "NO" << endl;
    return;
  } 

  int p = 0,  m = 0;
  for(int i = 1; i <= n; i ++) {
    if (a[i] == -1 && b[i] == 1) p += 2;
    if (b[i] == -1 && a[i] == 1) m += 2;
    a[i] += a[i - 1]; 
    b[i] += b[i - 1];
    while(a[i] > 0 && b[i] < 0 && m >= 2) {
      a[i] -= 2, b[i] += 2; m -= 2;
    }
    while(a[i] < 0 && b[i] > 0 && p >= 2) {
      a[i] += 2, b[i] -= 2; p -= 2;
    }

    if (a[i] < 0 || b[i] < 0) {cout << "NO" << endl; return;}
  }

  cout << "YES" << endl;
}

/*
就是交换了之后我们是有后效性的
显然 当两个括号相同的时候没必要交换
如果上面是 1 下面是 -1, 交换了之后上面 -= 2, 下面 += 2
如果上面是 -1 下面是 1, 交换了之后上面 += 2, 下面 -= 2
然后我们要 保证时时刻刻 a[i] 的前缀和 >= 0, 而且 b[i] 也是

对 然后是这样的 就是相当于我们有一个幅度 我们记录一下
可以把 a 上调的幅度, 把 b 下调的幅度 差不多感觉是这样 ??
不对啊卧槽 是不是他妈的
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}

