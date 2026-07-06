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

void solve() {
  int n, x, y; cin >> n >> x >> y;
  vector<int> a(1), b;
  
  for (int i = 1; i <= n; i ++) {
    int j; cin >> j;
    if (i <= x || i > y) a.push_back(j);  
    else b.push_back(j);                  
  }

  if (!b.empty()) rotate(b.begin(), min_element(b.begin(), b.end()), b.end());
  int m = b.empty() ? -1 : b[0];
  auto it = a.begin() + 1;
  while (it != a.end() && *it < m) it ++;
  a.insert(it, b.begin(), b.end());
  for (int i = 1; i <= n; i ++) {
    cout << a[i] << " \n"[i == n];
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