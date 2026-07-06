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
  int n, k, m, q;
  cin >> n >> k >> m >> q;
  // dbug(n, k, m, q);
  map<int, int> f;

  auto fp = [n](int x, int exp) -> int {
    int res = 1, base = x;
    while (exp) {
      if (exp & 1) {
        res = res * base % n;
      }
      base = base * base % n;
      exp >>= 1;
    }
    return res;
  };

  auto cal = [&](int x) -> vector<int> {
    vector<int> res;
    for (int i = 1; i <= k; i ++) {
      res.push_back(fp(x, i));
    }
    return res;
  };

  for (int i = 1; i <= m; i ++) {
    int tmp; cin >> tmp;
    // dbug(tmp);
    auto v = cal(tmp);
    // dbug(i, tmp, v);
    for (auto& x : v) {
      f[x] = 1;
    }
  }

  for (int i = 1; i <= q; i ++) {
    int tmp; cin >> tmp;
    auto v = cal(tmp);
    // dbug(i, tmp, v);
    bool s = 1;
    for (auto& x : v) {
      s &= f[x];
    }
    cout << s << " \n"[i == q]; 
  }
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}