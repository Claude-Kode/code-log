

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
    cin >> vec[i];
  }

  int res = 0;
  vector<int> mn(n + 1, INT_MAX); mn[n] = vec[n];
  for(int i = n - 1; i > 0; i --) {
    res += (vec[i] > mn[i + 1] ? vec[i] - mn[i + 1] : 0);
    mn[i] = min(mn[i + 1], vec[i]);
  }

  int ans = res; map<int, int> mp;
  for(int i = 1; i <= n; i ++) {
    ans = max(ans, res + mp[mn[i]]);
    mp[mn[i]] ++;
  }

  cout << ans << endl; 
}

/*
每个点的公式是减等于他的后缀最小值
假如 vec[i] - 1 之后 后面的后缀最小值 谁变了谁就应该加上贡献

就是如果当前的 vec[i] - 1 之后 后面的后缀最小值会变化的区域会产生一个贡献

严格来说就是这样的
对于当前的柱子 
他的大于后缀最小值的部分会移动
所以我们的答案可以是这样算出来的 就是所有的柱子之和减去所有的后缀最小值之和
如果 vec[i] -= 1, 那么前面后缀最小值等于 vec[i] 的所有的柱子会各自有一个正方体移动


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