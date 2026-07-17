#include <bits/stdc++.h>
using namespace std;

#define int long  long 
#define ll long long 

using TUP = tuple<int, int, int>;
struct info {
  int l, r, x;
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1), t(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> v[i];
  }

  for (int i = 1; i <= n; i ++) {
    cin >> t[i];
  }

  int pre = 0, sum = 0;
  vector<info> vec;
  for (int i = 1; i <= n; i ++) {
    int l = t[i], r = t[i] + v[i];
    int m = (v[i] + 1) * v[i] / 2;
    if (l >= pre) {
      vec.back().x += m;
      vec.back().r = r;
    } else {
      vec.push_back({l, r, m});
    }
    pre = max(pre, r);
  }

  int m = vec.size(), ans = 0;

  map<int, int> mp;
  for (int i = 0; i < m; i ++) {
    mp[vec[i].l] = i;
    sum += vec[i].x;
  }

  for (int i = 0; i < m; i ++) {
    int r = vec[i].r + v[i];
    int cur = vec[i].x;
    auto it = mp.lower_bound(r);
    int tar = it -> second;
    if (tar == i) {
      ans = max(ans, sum + (cur + 1 + cur + v[i]) * v[i] / 2);
    } else {
      
    }
  }

  cout << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }

  return 0;
}