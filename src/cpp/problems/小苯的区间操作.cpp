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
  unordered_map<int, int> ump;
  for(int i = 1; i <= n ;i ++) {
    cin >> vec[i];
  }

  bool _l = true, _r = true;
  for(int i = 2; i <= n; i ++) {
    if (vec[i] <  vec[1]) _l = false;
    if (vec[i] == vec[1]) {
      if (!_l) {cout << "No" << endl; return;}
      break;
    }
  }

  for(int i = n - 1; i > 0; i --) {
    if (vec[i] <  vec[n]) _r = false;
    if (vec[i] == vec[n]) {
      if (!_r) {cout << "No" << endl; return;} 
      break;
    }
  }

  cout << "Yes" << endl;
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