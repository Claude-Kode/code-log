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
  int n, m; cin >> n >> m;
  int up_lim = (1 + n) * n / 2;
  int down_lim = n;

  if (n == 1) {
    if (m == 1) {
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
    return;
  }

  if (m < down_lim || m > up_lim) {cout << "-1" << endl; return;}

  vector<vector<int>> adj(n + 1);
  int diff = up_lim - m;
  int base = (n - 1);
  vector<int> vec;
  while(diff) {
    if (diff >= base) diff -= base, vec.push_back(base--);
    else vec.push_back(diff), diff = 0;
  } 

  // dbug(vec);

  int p = n; unordered_map<int, int> ump;
  for(const auto &x : vec) {
    adj[p - x].push_back(p);
    // cout << p - x << ' ' << p << endl; 
    ump[p --] = 1;
  }

  vector<int> ans;
  for(int i = n; i > 0; i --) {
    if (adj[i].empty() && ump[i] == 0) {
      ans.push_back(i);
    } else if (!adj[i].empty()) {
      ans.push_back(i);
      for(const auto &v : adj[i]) ans.push_back(v);
    }
  }
  
  cout << ans.front() << endl;
  for(int i = 1; i < n; i ++) {
    cout << ans[i - 1] << ' ' << ans[i] << endl; 
  }
}

/*

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