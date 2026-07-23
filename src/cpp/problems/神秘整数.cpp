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

  ranges::sort(a);

  int G = a[2] - a[1];
  for (int i = 2; i <= n; i ++) {
    G = __gcd(G, abs(a[i] - a[1]));
  }

  // cout << G << "\n";

  set<int> ans;
  for (int i = 1; i * i <= G; i ++) {
    if (G % i == 0) {
      if (i != 1)  ans.insert(i);
      if (G / i)   ans.insert(G / i);
    }
  }

  if (ans.empty() or G == 1) {
    cout << -1 << "\n";
    return;
  }

  for (auto& x : ans) {
    if (x == 1) continue;
    cout << x << ' ' ;
  }

  cout << "\n";
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