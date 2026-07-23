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

int N = 1e7;

void solve() {  
  int l = rn(1, N), r = rn(1, N), n = rn(max(l, r) + 1, N);
  if (l > r) swap(l, r);
  cout << l << ' ' << r << ' ' << n << "\n";
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