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

class SGT {
  std::vector<int> seg;
  int off = 0;
  void pull(int i) { seg[i] = std::max(seg[i << 1], seg[i << 1 | 1]); }

 public:
  SGT() = delete;
  SGT(int n) {
    off = std::bit_ceil(unsigned(n + 2));
    seg.assign(off << 1, 0);
  }
  void upd(int i, int v) {
    if (v <= seg[i += off]) return;
    seg[i] = v;
    while (i >>= 1) pull(i);
  }
  int ask(int l, int r) {
    if (l > r) return 0;
    int res = 0; 
    for (l += off - 1, r += off + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) res = std::max(res, seg[l ^ 1]);
      if (r & 1) res = std::max(res, seg[r ^ 1]);
    }
    return res;
  }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  SGT seg(n + 1);
  vector<int> dp(n + 1, 0);
  vector<vector<array<int, 2>>> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    for (auto& [idx, val] : vec[i]) seg.upd(idx, val);
    int from = max(0LL, i - a[i] - 1);
    dp[i] = max(seg.ask(1LL, from) + a[i], a[i]);
    if (i + a[i] + 1 > n) continue;
    vec[i + a[i] + 1].push_back({i, dp[i]});
  }

  cout << ranges::max(dp) << "\n";
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}