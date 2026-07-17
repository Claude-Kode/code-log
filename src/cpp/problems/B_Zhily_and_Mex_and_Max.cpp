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
  int mx = INT_MIN, mn = INT_MAX;
  map<int, int> mp;
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i]; 
    mx = max(mx, vec[i]);
    mn = min(mn, vec[i]);
    mp[vec[i]] ++;
  }

  set<int> s; 
  for(int i = 0; i <= n; i ++) s.insert(i), vec[i] = INT_MAX;

  vec[1] = mx; mp[mx] --;
  int num = 0;
  for(int i = 2; i <= n; i ++) {
    if (mp[i - 2]) {
      vec[i] = i - 2;
      mp[i - 2] --;
    } else {
      break;
    }
  }

  int ans = mx * n;
  for(int i = 1; i <= n; i ++) {
    s.erase(vec[i]);
    ans += *s.begin();
  } 
  cout << ans << endl;
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