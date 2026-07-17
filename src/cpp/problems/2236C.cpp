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
  int a, b, x;
  cin >> a >> b >> x;

  auto aa = a, bb = b;
  vector<int> a1(1, 0), b1(1, 0);
  do {
    a1.push_back(aa);
    aa /= x;
  } while (aa);
  do {
    b1.push_back(bb);
    bb /= x;
  } while (bb);

  if (a1.back()) a1.push_back(0);
  if (b1.back()) b1.push_back(0);

  int cnt = INT_MAX;
  for (int i = 1; i <= a1.size() - 1; i ++) {
    for (int j = 1; j <= b1.size() - 1; j ++) {
      // dbug(a1[i], b1[i], abs(a1[i] - b1[j]));
      cnt = min(cnt, (i + j - 2) + abs(a1[i] - b1[j]));
    }
  }

  cout << cnt << '\n';
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