// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

// #define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n, p, q; 
  cin >> n >> p >> q;
  int base = 0;
  vector<int> vec(p - 1);
  for(int i = 0; i <= n; i ++) {
    int tmp; cin >> tmp;
    if (!i) base = (tmp % p + p) % p;
    vec[i % (p - 1)] += (tmp % p + p) % p;
  }

  for (auto &x : vec) x %= p;

  auto f = [&](int t) -> int {
    int res = 0;
    for(int i = p - 2; i >= 0; i --) {
      res = (res * t + vec[i]) % p;
    }
    return res % p;
  };

  while(q --) {
    int x; cin >> x; 
    x = (x % p + p) % p;
    if (!x) {cout << base << "\n"; continue;}
    cout << f(x) << "\n";
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, C = 0;
  cin >> tt;
  while (tt-- && ++C)
    // cout << "TEST CASE : " << C << endl,
    solve();

  return 0;
}
