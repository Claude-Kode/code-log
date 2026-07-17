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

string bit(int x) { return bitset<10>(x).to_string().substr(10 - __lg(x) - 1); }

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  int odd = 0, even = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = __builtin_popcount(vec[i]);
    if (cnt & 1) {
      odd += vec[i];
    } else {
      even += vec[i];
    }
  }

  cout << max(odd, even) << "\n";
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