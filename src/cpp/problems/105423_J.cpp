#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 3, base = 131;
vector<int> p(N), val(N);
class SegTree {
 public:
  vector<int> tree, cnt;
  void setting(int n) {
    tree.assign(4 * n + 1, 0);
    cnt.assign(4 * n + 1, 0);
  }
  void up(int i) {
    cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
     tree[i] = tree[i << 1]  + tree[i << 1 | 1] * p[cnt[i << 1]];
  }
  void add(int pos, int jobv, int i, int l, int r) {
    if (l == r) {
      cnt[i] = (jobv != 0);
      tree[i] = jobv;
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
      add(pos, jobv, i << 1, l, mid);
    else
      add(pos, jobv, i << 1 | 1, mid + 1, r);
    up(i);
  }
};
void solve() {
  int n;
  cin >> n;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * base;
    val[i] = rng();
  }
  vector<int> idxa(n + 1), idxb(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    idxa[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    idxb[x] = i;
  }
  SegTree tree1, tree2;
  tree1.setting(n);
  tree2.setting(n);
  int l = 1, ans = 0;
  for (int r = 1; r <= n; r++) {
    tree1.add(idxa[r], val[r], 1, 1, n);
    tree2.add(idxb[r], val[r], 1, 1, n);
    while (tree1.tree[1] != tree2.tree[1]) {
      tree1.add(idxa[l], 0, 1, 1, n);
      tree2.add(idxb[l], 0, 1, 1, n);
      l++;
    }

    // dbug(l, r, "\n");

    ans += (r - l + 1);
  }
  cout << ans << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) {
    solve();
  }
  return 0;
}