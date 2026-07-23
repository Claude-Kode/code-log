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

const int mod = 998'244'353;

vector<int> fact(100, 1);

void solve() {
  int n; cin >> n;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> p[i];
  }

  // p 相当于入边, 每个 i 放 A 的那个, q 相当于出边, 每个 A_i 出去哪里
  auto q = p;
  for (int i = 1; i <= n; i ++) {
    q[p[i]] = i;
  }

  bool INV = false;
  vector<int> pred(n + 1, 0);
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j < i; j ++) {
      if (q[i] < q[j]) {
        INV = true;
        pred[i] ^= (1 << (j - 1));
      }
    }
  }

  if (!INV) {
    cout << fact[n] << "\n";
    return;
  }

  int FULL = (1 << n);
  auto dp = vector<int>(FULL, 0);
  dp[0] = 1;
  for (int mask = 0; mask < FULL; mask ++) {
    for (int i = 1; i <= n; i ++) {
      int b = i - 1;
      if (mask >> b & 1) {
        int pre_mask = mask ^ (1 << b);
        if ((pred[i] & pre_mask) == pred[i]) {
          dp[mask] = (dp[mask] + dp[pre_mask]) % mod;
        }
      }
    }
  }

  cout << dp[FULL - 1] * 2 % mod << "\n";
} 
 
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  for (int i = 2; i <= 22; i ++) {
    fact[i] = fact[i - 1] * i % mod; 
  }

  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 