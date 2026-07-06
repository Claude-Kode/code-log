// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int long long

void solve() { 
  int n;
  cin >> n;
  
  auto ask = [&](int i, int j) -> int {
    cout << i << ' ' << j << endl; 
    int ans = 0; cin >> ans;
    return ans;
  };

  for(int len = 1; len <= n; len ++) {
    for(int i = 1; i + len <= n; i ++) {
      int j = i + len;
      if (ask(i, j)) {
        return;
      }
    }
  }   
}

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);  
  std::cout.tie(nullptr);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}