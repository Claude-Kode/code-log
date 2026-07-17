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
  int n, k; 
  cin >> n >> k;
  string s; 
  cin >> s;
  s = " " + s;

  int cnt = 0, mx = 0;
  for(int i = 1; i <= n; i ++) {
    if (s[i] == '0') cnt = 0;
    else if (s[i] == '1' && cnt == 0) cnt = 1;
    else if (s[i] == s[i - 1]) cnt ++;
    mx = max(mx, cnt);
  }

  // dbug(s);
  // dbug(mx);
  if (mx >= k) {cout << "NO" << endl; return;}
  cout << "YES" << endl;
  vector<int> vec(n + 1);
  
  int num = 0;
  for(int i = 1; i <= n; i ++) {
    if (s[i] == '1') vec[i] = ++ num;
  }
    for(int i = 1; i <= n; i ++) {
    if (s[i] == '0') vec[i] = ++ num;
  }
  for(int i = 1; i <= n; i ++) {
    cout << vec[i] << " \n"[i == n];
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