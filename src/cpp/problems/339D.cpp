// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;  

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n, m; 
  cin >> n >> m;
  int sz = (1 << n);
  vector<int> vec(sz + 1);
  for (int i = 1; i <= sz; i ++) {
    cin >> vec[i];
  }

  vector<int> seg(sz << 2 | 1, 0), 
              dep(sz << 2 | 1, 0);

  auto ls = [&](int i) {
    return i << 1;
  };

  auto rs = [&](int i) {
    return i << 1 | 1;
  };

  auto pull = [&](int p) -> void {
    int d = dep[p];
    if (d & 1) seg[p] = seg[ls(p)] | seg[rs(p)]; 
    else       seg[p] = seg[ls(p)] ^ seg[rs(p)]; 
  };

  auto build = [&](auto && self, int p, int l, int r) -> void {
    if (l == r) {
      seg[p] = vec[l];
    } else {
      int m = (l + r) / 2;
      self(self, ls(p), l, m);
      self(self, rs(p), m + 1, r);  
      dep[p] = dep[ls(p)] + 1;
      pull(p);
    }
  };

  auto set = [&](auto && self, int p, int l, int r, int pos, int V) -> void {
    if (l == r) {
      seg[p] = V;
    } else {
      int m = (l + r) / 2;
      if (pos <= m) self(self, ls(p), l, m, pos, V);
      else if (m < pos) self(self, rs(p), m + 1, r, pos, V);
      pull(p);
    } 
  };

  build(build, 1, 1, sz);

  for (int i = 1; i <= m; i ++) {
    int p, v; 
    cin >> p >> v;
    set(set, 1, 1, sz, p, v);
    cout << seg[1] << "\n";
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