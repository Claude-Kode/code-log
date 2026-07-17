// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;  

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  if (n <= 3) {
    cout << 1 << '\n';
    return;
  }
  if (a > b) swap(a, b);
  int dis = min(b - a, a + n - b);
  cout << dis + k << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0; 
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}