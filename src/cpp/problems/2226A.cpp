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
  int ans = 0; int p = 0;
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
    if (vec[i] == 1) p = i;
  }

  for(int i = 1; i <= p; i ++) if (vec[i] == 1) vec[i] = 0;
  if (p == n) vec[p] = 1;
  cout << accumulate(vec.begin() + 1, vec.end(), 0LL) << endl;
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