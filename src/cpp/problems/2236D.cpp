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
  int n, k;
  cin >> n >> k;
  vector<int> vec(n + 1);
  map<int, int, greater<int>> mp;
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
    mp[vec[i]] ++;
  }

  bool ans = false;
  // map<int, int> fail;
  // g(v) , e 选择 v 的时候, 那个谁一定输掉
  // 
  set<int> fail;
  for (auto &[v, cnt] : mp) {
    bool f1 = false;
    auto it = fail.upper_bound(v);
    if (it != fail.end() and *it <= v + k) {
      f1 = true;
    }

    if (!(cnt & 1) | f1) {
      ans = true; 
      break;
    } else {
      fail.insert(v);
    }
  }

  cout << (ans ? "YES" : "NO") << "\n";
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