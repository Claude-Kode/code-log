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
  vector<int> vec(n + 1);
  for (int i = 1 ; i <= n; i ++) {
    cin >> vec[i];
  }

  int sum = 0;
  for (int i = 1; i <= n; i ++) {
    for (int j = i + 1; j <= n; j ++) {
      if (vec[j] > vec[i]) {
        vec[j] = vec[i];
      }
    }
    sum += vec[i];
  }

  cout << sum << "\n";
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