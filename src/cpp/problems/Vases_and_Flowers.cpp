// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Infor {
  int sum = 0;
  int tag = -1;
};

void solve() {
  int n,m ;
  cin >> n >> m;

  vector<Infor> seg(n << 2 | 1);

  auto apply = [&](int p, int l, int r, int v) -> void {
    seg[p].sum = (r - l + 1) * v;
    seg[p].tag = v;
  };

  auto push = [&](int p, int l, int r) -> void {
    if (seg[p].tag == -1) return;
    int m = (l + r) / 2;
    apply(p << 1, l, m, seg[p].tag);
    apply(p << 1 | 1, m + 1, r, seg[p].tag);
    seg[p].tag = -1;
  };

  auto pull = [&](int p) -> void {
    seg[p].sum = seg[p << 1].sum + seg[p << 1 | 1].sum;
  };

  auto set = [&](auto && sef, int p, int l, int r, int L, int R, int v) -> void {
    if (L <= l && r <= R) {
      apply(p, l, r, v);
    } else {
      push(p, l, r);
      int m = (l + r) / 2;
      if (L <= m) 
        sef(sef, p << 1, l, m, L, R, v);
      if (m < R)
        sef(sef, p << 1 | 1, m + 1, r, L, R, v);
      pull(p);
    }
  };

  auto sum = [&](auto && sef, int p, int l, int r, int L, int R) -> int {
    if (L <= l and r <= R) {
      return seg[p].sum;
    } else {
      push(p, l, r);
      int m = (l + r) / 2, res = 0;
      if (L <= m) 
        res += sef(sef, p << 1, l, m, L, R);
      if (m < R)
        res += sef(sef, p << 1 | 1, m + 1, r, L, R);
      return res;
    }
  };

  auto find = [&](auto && sef, int p, int l, int r, int L, int R, int k) -> int {
    if (l == r) return l;
    push(p, l, r);
    int m = (l + r) >> 1;
    // 左儿子与 [L,R] 的交集是 [max(l, L), min(m, R)]
    int leftL = max(l, L), leftR = min(m, R);
    int left0 = 0;
    if (leftL <= leftR) {
      int ones = sum(sum, p << 1, l, m, leftL, leftR); // 重叠部分的 1 个数
      left0 = (leftR - leftL + 1) - ones;              // 重叠部分的 0 个数
    }
    if (k <= left0) {
      return sef(sef, p << 1, l, m, L, R, k);
    } else {
      return sef(sef, p << 1 | 1, m + 1, r, L, R, k - left0);
    }
  };

  for (int i = 1; i <= m; i ++) {
    int op;
    cin >> op;
    if (op == 1) {
      int s, cnt;
      cin >> s >> cnt;
      s ++;
      int rem = sum(sum, 1, 1, n, s, n);
      if (rem == n - s + 1) {
        cout << "Can not put any one.\n";
        continue;
      }

      int cnt0 = (n - s + 1) - rem;
      int ans1 = find(find, 1, 1, n, s, n, 1),
          ans2 = find(find, 1, 1, n, s, n, min(cnt0, cnt));
      set(set, 1, 1, n, ans1, ans2, 1);
      cout << ans1 - 1 << ' ' << ans2 - 1 << "\n";
    }

    if (op == 2) {
      int l, r;
      cin >> l >> r;
      l ++, r ++;
      cout << sum(sum, 1, 1, n, l, r) << "\n";
      set(set, 1, 1, n, l, r, 0);
    }
  }

  cout << "\n";
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