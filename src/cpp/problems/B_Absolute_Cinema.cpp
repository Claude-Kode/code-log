// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i ++) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; i ++) {
    if (a[i] > b[i]){
      swap(a[i], b[i]);
    }
  }

  cout << accumulate(b.begin() + 1, b.end(), 0LL) + *max_element(a.begin() + 1, a.end()) << "\n";
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