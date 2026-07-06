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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rn(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

const int N = 2e5;

void solve() {
  int n = rn(1, N);
  for (int i = 1; i <= n; i ++) {
    cout << rn(1, N) << " \n"[i == n];
  }
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  // std::cout << tt << "\n";
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

