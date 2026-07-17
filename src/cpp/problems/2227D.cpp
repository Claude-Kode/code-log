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
  vector<int> vec(2 * n + 1);
  int p01 = 0, p02 = 0; 
  for(int i = 1; i <= 2 * n; i ++) {
    cin >> vec[i];
  }

  for(int i = 1; i <= 2 * n; i ++) if (vec[i] == 0) {p01 = i; break;}
  for(int i = 2 * n; i >= 1; i --) if (vec[i] == 0) {p02 = i; break;}

  
  auto calc = [&](const vector<int>& mp) -> int {
    for(int i = 0; i <= n; i ++) {
      if (mp[i] > 0) return i;
    }
  };

  vector<int> buckle(n + 1, 1), temp(n + 1, 1);
  int l = p01 - 1, r = p01 + 1, ans = 0;
  temp[vec[p01]] --;
  while(l >= 1 && r <= 2 * n && vec[l] == vec[r]) {
    temp[vec[l]] --, temp[vec[r]] --;
    l --, r ++;
  }
  ans = max(ans, calc(temp));
  
  temp = buckle;
  l = p02 - 1, r = p02 + 1;
  temp[vec[p02]] --;
  while(l >= 1 && r <= 2 * n && vec[l] == vec[r]) {
    temp[vec[l]] --, temp[vec[r]] --;
    l --, r ++;
  }
  ans = max(ans, calc(temp));

  temp = buckle;
  vector<int> t(vec.begin() + p01, vec.begin() + p02 + 1);
  auto tt = t; reverse(tt.begin(), tt.end());
  if (tt == t) {
    for(int i = p01; i <= p02; i ++) temp[vec[i]] --;
    l = p01 - 1, r = p02 + 1;
    while(l >= 1 && r <= 2 * n && vec[l] == vec[r]) {
      temp[vec[l]] --, temp[vec[r]] --;
      l --, r ++;
    }
    ans = max(ans, calc(temp));
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