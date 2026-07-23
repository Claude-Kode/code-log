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

struct LB {
  array<int, 64> b = {};
  LB() = default;

  bool ins(int x) {
    for (int i = 62; i >= 0; i--) if (x >> i & 1)
      if (!b[i]) { b[i] = x; return true; }
      else x ^= b[i];
    return false;
  }

  bool chk(int x) {
    for (int i = 62; i >= 0; i--)
      if (x >> i & 1) x ^= b[i];
    return x == 0;
  }

  int get_max() {
    int res = 0;
    for (int i = 62; i >= 0; i--)
      res = max(res, res ^ b[i]);
    return res;
  }

  int get_min() {
    for (int i = 0; i <= 62; i++)
      if (b[i]) return b[i];
    return -1;
  }

  int kth_min(int k) {
    auto t = vector<int>();
    for (int i = 0; i < 63; i++) if (b[i]) t.push_back(b[i]);
    for (int i = 0; i < (int)t.size(); i++)
      for (int j = 0; j < i; j++)
        t[i] = min(t[i], t[i] ^ t[j]);
    int res = 0; k--;
    for (int i = 0; i < (int)t.size(); i++)
      if (k >> i & 1) res ^= t[i];
    return res;
  }

  int kth_max(int k) {
    auto t = vector<int>();
    for (int i = 62; i >= 0; i--) if (b[i]) t.push_back(b[i]);
    return kth_min((1LL << (int)t.size()) - k + 1);
  }

  void merge(const LB& o) {
    for (int i = 62; i >= 0; i--) {
      if (o.b[i]) ins(o.b[i]);
    }
  }
};

void solve() {
  int n; cin >> n;
  auto a = vector<int>(n + 1, 0);

  int S = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; S ^= a[i];
  }

  LB lb;
  for (int i = 1; i <= n; i++) {
    lb.ins(a[i] & ~S);
  }

  cout << S + 2 * lb.get_max() << "\n";
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