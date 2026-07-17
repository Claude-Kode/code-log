#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Infor {
  // seg[p].sum 的真实含义就是
  // 以 p 为根的子树代表的最大啊区间[l, r] 的 sum 和
  // 如果要往下面递归 要带上每一层的 add_tag, 
  // sum就相当于是负责每个以当前节点为根的子树的和
  int sum = 0; 
  // tag 的含义一直都没有变, 就是以 p 为根的子树 每个子树的每个单位元素都要更新 tag 出来
  // 不包括 p 点哦
  int tag = 0; 
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<Infor> seg(n << 2 | 1);

  auto apply = [&](int p, int l, int r, int v) -> void {
    seg[p].sum += v * (r - l + 1);
    seg[p].tag += v;
  };

  auto pull = [&](int p, int l, int r) -> void {
    seg[p].sum =  seg[p << 1].sum + seg[p << 1 | 1].sum + seg[p].tag * (r - l + 1);
  };

  auto build = [&](auto&& sef, int p, int l, int r) -> void {
    if (l == r) {
      seg[p].sum = a[l];
    } else {
      int m = (l + r) / 2;
      sef(sef, p << 1, l, m);
      sef(sef, p << 1 | 1, m + 1, r);
      pull(p, l, r);  
    }
  };


  auto add = [&](auto&& sef, int p, int l, int r, int L, int R, int v) -> void {
    if (L <= l && r <= R) {
      apply(p, l, r, v);
      return;
    } else {
      int m = (l + r) / 2;
      if (L <= m) sef(sef, p << 1, l, m, L, R, v);
      if (R > m) sef(sef, p << 1 | 1, m + 1, r, L, R, v);
      pull(p, l, r); 
    }

  };

  auto query = [&](auto&& sef, int p, int l, int r, int L, int R, int pre_tag = 0) -> int {
    if (L <= l && r <= R) {
      return seg[p].sum + pre_tag * (r - l + 1);
    } else {
      int m = (l + r) / 2, res = 0;
      if (L <= m) res += sef(sef, p << 1, l, m, L, R, pre_tag + seg[p].tag);
      if (R > m)  res += sef(sef, p << 1 | 1, m + 1, r, L, R, pre_tag + seg[p].tag);
      return res;
    }
  };

  build(build, 1, 1, n);
  while (m --) {
    int op, l, r, v;
    cin >> op;
    if (op == 1) { 
      cin >> l >> r >> v;
      add(add, 1, 1, n, l, r, v);
    } 
    if (op == 2) {  
      cin >> l >> r;
      cout << query(query, 1, 1, n, l, r) << '\n';
    }
  }
}


int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  while (tt--) solve();
  return 0;
}