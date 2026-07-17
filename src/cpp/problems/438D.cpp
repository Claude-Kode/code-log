// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct SGT {
  SGT *ls, *rs;
  int sum, mx, l, r, mid;
  SGT (int L, int R, const vector<int>& vec) {
    l = L, r = R, mid = (l + r) / 2;
    if (l == r) {
      mx = sum = vec[l];
    } else {
      ls = new SGT(l, mid, vec);
      rs = new SGT(mid + 1, r, vec);
      pull();
    }
  }

  void pull() {
    sum = ls -> sum + rs -> sum;
    mx = std::max(ls -> mx, rs -> mx);
  }

  void mod(int L, int R, int M) {
    if (l > R || r < L || mx < M) {
      return; 
    } else if (l == r) {
      mx = (sum %= M);
    } else {
      ls -> mod(L, R, M);
      rs -> mod(L, R, M);
      pull();
    }
  }

  void set(int L, int R, int V) {
    if (l > R || r < L) {
      return;
    } else if (l == r) {
      mx = sum = V;
    } else {
      ls -> set(L, R, V);
      rs -> set(L, R, V);
      pull();
    }
  }

  int ask(int L, int R) {
    if (l > R || r < L) {
      return 0;
    } else if (L <= l && r <= R) {
      return sum;
    } else {
      return ls -> ask(L, R) + rs -> ask(L, R);
    }
  }
};

void solve() {
  int n, m; 
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  SGT seg(1, n, vec);

  for (int i = 1; i <= m; i ++) {
    int op; cin >> op;
    if (op == 1) {
      int l, r; cin >> l >> r;
      cout <<  seg.ask(l, r) << "\n";
    }

    if (op == 2) {
      int l, r, m; 
      cin >> l >> r >> m;
      seg.mod(l, r, m);
    }

    if (op == 3) {
      int p, x; cin >> p >> x;
      seg.set(p, p, x);
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