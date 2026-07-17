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
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    char c; cin >> c;
    vec[i] = (c == 'a' ? 1 : -1); 
  }

  auto pre = vec, suff = vec;
  for(int i = 1; i <= n; i ++) pre[i] += pre[i - 1];
  for(int i = n - 1; i > 0; i --) suff[i] += suff[i + 1];
  
  map<int, int> to;
  map<int, set<int>> mp;
  for(int i = n; i > 0; i --) mp[suff[i]].insert(i), to[i] = suff[i];
  mp[0].insert(n + 1); to[n + 1] = 0;
  int ans = n;
  for(int i = 0; i <= n; i ++) {
    // 对于每个 pre[i] 找 suff[j] = -1 * pre[i]
    if (i) mp[to[i]].erase(i);
    if (!mp[-pre[i]].empty()) {
      ans = min(ans, *mp[-pre[i]].begin() - i - 1);
    }
  }
  
  cout << (ans == n ? -1 : ans) << endl; 
}
/*
这题也是个傻福题 真不想写了操
就是一个前后缀加合等于 0 即可
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