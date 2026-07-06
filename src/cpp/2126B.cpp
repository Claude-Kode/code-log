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
  int n, k; cin >> n >> k;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  int ans = 0, cnt = 0;
  for(int i = 1; i <= n; i ++) {
    if (vec[i]) cnt = 0;
    else if (vec[i] == 0 && cnt  == 0) cnt = 1;
    else if (vec[i] == 0) cnt ++;
    if (cnt == k) ans ++, i ++, cnt = 0;
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