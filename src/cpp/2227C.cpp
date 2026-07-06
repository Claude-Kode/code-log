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
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> a, b, c, d;
  for(int i = 1; i <= n; i ++) {
    if (vec[i] % 6 == 0) a.push_back(vec[i]);
    else if (vec[i] % 2 == 0) b.push_back(vec[i]);
    else if (vec[i] % 3 == 0) c.push_back(vec[i]);
    else d.push_back(vec[i]);
  }

  for(const auto &x : a) cout << x << ' ' ;
  for(const auto &x : b) cout << x << ' ' ;
  for(const auto &x : d) cout << x << ' ' ;
  for(const auto &x : c) cout << x << ' ' ;
  cout << endl;
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