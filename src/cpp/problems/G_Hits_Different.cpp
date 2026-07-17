// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int m = 1500;
const int N = 1e7;

vector<vector<int>> pre(m + 1, vector<int>(m + 1, 0));
vector<int> ans(N + 1);

void solve() { 
  int n; cin >> n;
  cout << ans[n] << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // 如果不用前缀和的话也是一个容斥
  int num = 1;
  for(int s = 2; s <= m; s ++) {
    for(int x = s - 1; x > 0; x --) {
      int y = s - x;
      pre[x][y] = pre[x - 1][y] + pre[x][y - 1] - pre[x - 1][y - 1] + num * num;
      ans[num] = pre[x][y];
      num ++;
    }
  }
  // cout << "curr: " << curr << endl; 

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}