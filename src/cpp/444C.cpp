// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;  

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Infor {
  // col == 0, 当前区间颜色不统一, 不为 0 代表区间的颜色是 col
  int col = 0;
  int sum = 0;
  int add_tag = 0;
  int col_tag = 0;
};

int ls(int i) {return i << 1;}
int rs(int i) {return i << 1 | 1;}

void solve() {    
  int n, m;
  cin >> n >> m;
  std::vector<Infor> seg(n << 2 | 1);

  // for (int i = 1; i <= 5; i ++) {
  //   cerr << "seg: " << seg[i].col << "\n";
  // }

  auto pull = [&](int p) -> void {  
    seg[p].sum = seg[ls(p)].sum + seg[rs(p)].sum;
    if (seg[ls(p)].col == seg[rs(p)].col && seg[ls(p)].col != 0) {
      seg[p].col = seg[ls(p)].col;
    } else {
      seg[p].col = 0;
    }
  };

  auto apply = [&](int p, int l, int r, int color, int v) -> void {
    // 目前这个函数都是假设区间的颜色是统一的

    // apply 里面需要维护 区间的 和吗
    // 应该是不需要的 我们只需要维护区间的 color-tag即可 

    // 这里没有处理 add_tag
    seg[p].sum += v * (r - l + 1);
    seg[p].col = color;
    seg[p].add_tag += v;
    seg[p].col_tag = color;
  };

  auto push = [&](int p, int l, int r) -> void {
    if (!seg[p].col_tag) return; 
    int m = (l + r) / 2;
    // 好像是没有优先级的 但是一次都要更新完才行
    // 我们的 col_tag 只能代表的是最终颜色
    apply(ls(p), l, m, seg[p].col_tag, seg[p].add_tag);
    apply(rs(p), m + 1, r, seg[p].col_tag, seg[p].add_tag);
    seg[p].add_tag = 0, seg[p].col_tag = 0;
  };

  auto build = [&](auto && sef, int p, int l, int r) -> void {
    if (l == r) {
      seg[p].col = l;
      seg[p].sum = 0;
      // cout << "leaf: " << p << "\n";
    } else {
      int m = (l + r) / 2;
      sef(sef, ls(p), l, m);
      sef(sef, rs(p), m + 1, r); 
      pull(p);
    }
  };

  auto set = [&](auto && sef, int p, int l, int r, int L, int R, int color) -> void {
    // cerr << "infor: " << p << ' ' << l << ' ' << r << ' ' << L << ' ' << R << "\n";
    // cerr << "color: " << seg[p].col << ' ' << color  << "\n";
    if (L <= l && r <= R && seg[p].col != 0)  {
      // cerr << p << "\n";
      apply(p, l, r, color, abs(color - seg[p].col));
    } else {
      // cerr << p << "\n";
      push(p, l, r);
      int m = (l + r) / 2;
      if (L <= m) sef(sef, ls(p), l, m, L, R, color);
      if (m < R)  sef(sef, rs(p), m + 1, r, L, R, color);
      pull(p);
    }
  };

  auto ask = [&](auto && sef, int p, int l, int r, int L, int R) -> int {
    if (L <= l && r <= R)  {
      return seg[p].sum;
    } else {
      push(p, l, r);
      int m = (l + r) / 2, res = 0;
      if (L <= m) res += sef(sef, ls(p), l, m, L, R);
      if (m < R)  res += sef(sef, rs(p), m + 1, r, L, R);
      return res;
    }
  };

  build(build, 1, 1, n);
  // for (int i = 1; i <= 5; i ++) {
  //   cerr << "seg: " << seg[i].col << "\n";
  // }
  // cout << "sum: " << ask(ask, 1, 1, n, 1, n) << "\n";

  auto q = [&]() -> void {
    for (int i = 1; i <= n; i ++) {
      cout << "::" << i << ' ' << ask(ask, 1, 1, n, i, i) << "\n";
    }
  };

  for (int i = 1; i <= m; i ++) {
    int op; 
    cin >> op;
    if (op == 1) {
      int l, r, color; 
      cin >> l >> r >> color;
      // cout << "set: \n";
      set(set, 1, 1, n, l, r, color);
      // q();
    }

    if (op == 2) {
      int l, r; 
      cin >> l >> r;
      cout << ask(ask, 1, 1, n, l, r) << "\n";
    }
  }
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