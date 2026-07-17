// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

class FenwickTree {
public: 
  int n; 
  std::vector<int> tree;
public: 
  FenwickTree(int _n = 1) : n(_n) {tree.assign(n + 1, 0);}
  static int lowbit(int i) {return i & -i;} 

  void update(int p, int v) { // 不能 update(0, ?) 会死循环
    if (p <= 0) return;
    for(int i = p; i <= n; i += lowbit(i)) {
      tree[i] += v;
    }
  }

  int query (int p) {
    if (p <= 0) return 0;
    int res = 0;
    for(int i = p; i > 0; i -= lowbit(i)) {
      res += tree[i];
    }
    return res;
  }
};

void solve() {    
  int n;
  std::cin >> n;
  std::vector<int> val(1, INT_MIN);
  std::vector<std::array<int, 2>> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    std::cin >> vec[i][0] >> vec[i][1];
    val.push_back(vec[i][0]);
    val.push_back(vec[i][1]);
  }

  std::sort(val.begin(), val.end());
  for (int i = 1; i <= n; i ++) {
    vec[i][0] = lower_bound(val.begin() + 1, val.end(), vec[i][0]) - val.begin();
    vec[i][1] = lower_bound(val.begin() + 1, val.end(), vec[i][1]) - val.begin();
  }

  std::sort(vec.begin() + 1, vec.end(), [&](const auto &a, const auto &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    else return a[1] < b[1];
  });

  FenwickTree t(2 * n);
  int ans = 0;
  for (int i = 1; i <= n; i ++) {
    int add = (i - 1) - t.query(vec[i][0] - 1);
    ans += add;
    // dbug(add);
    t.update(vec[i][1], 1);
  }

  std::cout << ans << "\n";
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