// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT();

class BIT {
public: 
  int n; 
  std::vector<int> tree;
public: 
  BIT(int _n = 1) : n(_n) {tree.assign(n + 1, 0);}
  static int lowbit(int i) {return i & -i;} 

  void update(int p, int v) { // 不能 update(0, ?) 会死循环
    if (p <= 0) return;
    for(int i = p; i <= n; i += lowbit(i)) {
      tree[i] = max(tree[i], v);
    }
  }

  int query (int p) {
    if (p <= 0) return 0;
    int res = 0;
    for(int i = p; i > 0; i -= lowbit(i)) {
      res = max(res, tree[i]);
    }
    return res;
  }
};

void solve() {
  int n, k; cin >> n >> k;
  vector<array<int, 2>> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i][0] >> vec[i][1];
  }

  sort(vec.begin() + 1, vec.end(), [&](const auto &a, const auto & b){
    return (a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]);
  });

  auto get = [&](int x, const auto &a) -> int {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
  };

  auto check = [&](int v) -> bool {
    vector<int> val(n + 1); val[0] = LLONG_MIN;
    for (int i = 1; i <= n; i ++) {
      val[i] = vec[i][1] * v - vec[i][0];
    }

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    unordered_map<int, int> ump;
    BIT bit(n + 1);

    vector<int> dp(n + 1); 
    for (int i = 1; i <= n; i ++) {
      int cur = vec[i][1] * v - vec[i][0];
      ump[cur] = i;
      int mx = bit.query(get(cur, val));
      dp[i] = mx + 1;
      if (dp[i] >= k) return true;
      bit.update(get(cur, val), dp[i]);
    }

    return false;
  };

  int l = 1, r = 1e8, ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (check(m)) r = m - 1, ans = m;
    else l = m + 1;
  }

  cout << ans << "\n";
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