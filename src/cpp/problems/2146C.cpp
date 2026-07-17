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

void solve()  {
  int n; cin >> n;
  string s; cin >> s; s = "1" + s + "1";
  
  if (s.find("101") != string::npos) {cout << "NO" << endl; return;}
  cout << "YES" << endl;
  vector<int> ans(n + 1);
  iota(ans.begin(), ans.end(), 0);

  // cout << string(s.begin() + 1, s.end() - 1) << endl;
  int lst = 1;
  for(int i = 1; i <= n; i ++) {
    if (s[i] == '1') {
      sort(ans.begin() + lst, ans.begin() + i, greater<int>());
      lst = i + 1;
    }
  }
  
  sort(ans.begin() + lst, ans.end(), greater<int>());
  for(int i = 1; i <= n; i ++) {
    cout << ans[i] << " \n"[i == n];
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