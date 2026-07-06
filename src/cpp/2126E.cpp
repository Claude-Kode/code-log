// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"
#define DONO (cout << "NO" << '\n'; eturn;)
#define DOYES (cout << "YES" << '\n'; return;)

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int gcd(int a, int b) {
  return __gcd(a, b);
}

int lcm(int a , int b) { 
  return a / __gcd(a , b) * b ; 
} 

void solve() { 
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i ++) cin >> a[i];
  for(int i = 1; i <= n; i ++) cin >> b[i];

  if (a[n] != b[1]) {
    cout << "NO" << endl;
    return; 
  }

  vector<int> ans(n + 1);
  for(int i = 1; i <= n; i ++) {
    ans[i] = lcm(a[i], b[i]);
  }

  for(int i = 2; i <= n; i ++) {
    if (gcd(ans[i], a[i - 1]) != a[i]) {
      cout << "NO" << endl;
      return;
    }
  }

  for(int i = n - 1; i > 0; i --) {
    if (gcd(ans[i], b[i + 1]) != b[i]) {
      cout << "NO" << endl;
      return;  
    }
  }

  cout << "YES" << endl;
}

/*
从简单的判断入手 首先 前缀和后缀 gcd 肯定要是一直相等的
其次欠货追 gcd 一定是非递增的

下一个想的就是, 通过 a 数组的第一个确定第一个数 那么可以不可以这样
我们通过第一个数来构造出整个序列, 如果最后一个是不能等于 b[n] 那么的话就构造失败了
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