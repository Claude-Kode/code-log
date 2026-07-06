#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n, q;
  cin >> n >> q;
  vector<array<int, 3>> qs(q + 1);
  vector<int> val = {1, n + 1};  
  for (int i = 1; i <= q; i++) {
    int l, r, k;
    cin >> qs[i][0] >> qs[i][1] >> qs[i][2];
    val.push_back(qs[i][0]);
    val.push_back(qs[i][1] + 1);  
  }

  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());

  unordered_map<int, int> idx;
  for (int i = 0; i < (int)val.size(); i++) {
    idx[val[i]] = i;
  }
  
  int m = val.size() - 1;              
  vector<int> vec(m + 1), pre(m + 1); 
  for (int i = 1; i <= m; i++) {
    vec[i] = val[i] - val[i - 1];  
    pre[i] = pre[i - 1] + vec[i];
  }

  vector<int> seg(m << 2 | 1, 1), tag(m << 2 | 1, -1);

  auto apply = [&](int p, int l, int r, int x) -> void {
    seg[p] = (pre[r] - pre[l - 1]) * x;
    tag[p] = x;
  };

  auto push = [&](int p, int l, int r) -> void {
    if (tag[p] == -1) return;
    int mid = (l + r) / 2;
    apply(p << 1, l, mid, tag[p]);
    apply(p << 1 | 1, mid + 1, r, tag[p]);
    tag[p] = -1;
  };

  auto pull = [&](int p) -> void { 
    seg[p] = seg[p << 1] + seg[p << 1 | 1]; 
  };

  auto build = [&](auto&& sef, int p, int l, int r) -> void {
    if (l == r) {
      seg[p] = vec[l];
    } else {
      int mid = (l + r) / 2;
      sef(sef, p << 1, l, mid);
      sef(sef, p << 1 | 1, mid + 1, r);
      pull(p);
    }
  };

  auto set = [&](auto&& sef, int p, int l, int r, int L, int R, int x) -> void {
    if (L <= l && r <= R) {
      apply(p, l, r, x);
    } else {
      push(p, l, r);
      int mid = (l + r) / 2;
      if (L <= mid) sef(sef, p << 1, l, mid, L, R, x);
      if (mid < R)  sef(sef, p << 1 | 1, mid + 1, r, L, R, x);
      pull(p);
    }
  };

  build(build, 1, 1, m);

  for (int i = 1; i <= q; i++) {
    auto [l, r, k] = qs[i];
    int L = idx[l];
    int R = idx[r + 1];  
    set(set, 1, 1, m, L + 1, R, !(k & 1)); 
    cout << seg[1] << "\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }
  return 0;
}