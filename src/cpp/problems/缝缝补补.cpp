// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }
  
  bool f = true;
  for (int i = 2; i <= n; i ++) {
    if (a[i] - a[i - 1] != a[2] - a[1]) {
      f = false;
    }
  }

  if (f or n == 2) {
    cout << -1 << "\n";
    return;
  }

  vector<int> d(n + 1);
  for (int i = n; i > 1; i--) {
    d[i] = a[i] - a[i - 1];
  }

  // dbug(d);

  for (int i = n; i > 1; i--) {
    d[i] = abs(d[i] - d[i - 1]);
  }

  // dbug(d);

  int g = d[3];
  for (int i = 3; i <= n; i++) {
    // dbug(g);
    g = __gcd(g, d[i]);
  }

  cout << g << "\n";
} 
  
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 