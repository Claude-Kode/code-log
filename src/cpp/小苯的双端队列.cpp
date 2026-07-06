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
  deque<int> dq;
  for(int i = 1; i <= n; i ++) cin >> vec[i];

  for(int i = n; i > 0; i --) {
    if (dq.empty()) dq.push_back(vec[i]);
    else if (vec[i] == dq.front() - 1) dq.push_front(vec[i]);
    else if (vec[i] == dq.back() + 1) dq.push_back(vec[i]);
    else {cout << "NO" << endl; return;}
  }

  cout << "YES" << endl;
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