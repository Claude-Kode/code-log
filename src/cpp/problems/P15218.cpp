// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 

  int n, m; cin >> n >> m;
  vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i ++) cin >> a[i];
  for(int i = 1; i <= m; i ++) cin >> b[i];

  map<int, int> mp;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j ++) {
      if (b[j] >= a[i]) mp[b[j] - a[i]] ++;
    }
  }

  int mx = -1, ans = 0;
  for(auto [k, v] : mp) {
    if (mx < v) mx = v, ans = k;
  }
  cout << ans << endl; 
}

/*
本身我是想滑动窗口来写的 这样可以做到 11 配对
可是我们来看一下
对于 a 和 b 来说 本身他们两个都是 递增的
对于任何一个进入的时间来说 只要确定了差值 就一定能确定唯一的出去的时间

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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}