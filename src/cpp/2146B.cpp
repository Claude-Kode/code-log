// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, m; cin >> n >> m;
  vector<map<int, int>> vec(n + 1);
  unordered_map<int, int> ump;
  for(int i = 1; i <= n; i ++) {
    int a; cin >> a;
    for(int j = 1; j <= a; j ++) {
      int num; cin >> num;
      vec[i][num] ++; ump[num] ++;
    }
  }

  int cnt = 0; 
  for(int i = 1; i <= n; i ++) {
    bool f = true;
    for(const auto &[k, v] : vec[i]) {
      f &= (ump[k] > v);
    }
    cnt += f;
  }

  cout << (cnt >= 2 && ump.size() == m? "YES" : "NO") << '\n';
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