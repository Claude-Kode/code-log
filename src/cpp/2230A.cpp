// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;  

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n, a, b;
  cin >> n >> a >> b;
  int k = n / 3, rem = n % 3;
  cout << min(k * b, a * (n - rem)) + min(b, rem * a) << "\n";
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