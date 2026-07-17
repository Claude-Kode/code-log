#include <bits/stdc++.h>
using namespace std;

#define int long  long 
#define ll long long 

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  // len: (x,  x + len), wid: (y, y + wid)
  map<int, int> len, wid;
  len[0] = n; wid[0] = m;
  len[n] = 0; wid[m] = 0;

  map<int, int, greater<int>> mx_len, mx_wid;

  mx_len[n] ++;
  mx_wid[m] ++;

  for (int i = 1; i <= q; i ++) {
    int op, k;
    cin >> op >> k;
    if (op == 1) {
      // x == k
      auto it = len.upper_bound(k);
      int x2 = it -> first;
      int x1 = (--it) -> first;
      len[x1] = k - x1;
      len[k] = x2 - k;
      mx_len[k - x1] ++;
      mx_len[x2 - k] ++;
      mx_len[x2 - x1] --;
      // cout << x2 - x1 << "???\n";
      if (mx_len[x2 - x1] == 0) {
        mx_len.erase(x2 - x1);
      }
    } else {
      // y == k
      auto it = wid.upper_bound(k);
      int y2 = it -> first;
      int y1 = (--it) -> first;
      wid[y1] = k - y1;
      wid[k] = y2 - k;
      mx_wid[k - y1] ++;
      mx_wid[y2 - k] ++;
      mx_wid[y2 - y1] --;
      // cout << y2 - y1 << "???\n";
      if (mx_wid[y2 - y1] == 0) {
        mx_wid.erase(y2 - y1);
      }
    }

    // cout << "len: \n";
    // for (auto &[_, __] : mx_len) {
    //   cout << _ << ' ' << __ << "\n";
    // }

    // cout << "wid: \n";
    // for (auto &[_, __] : mx_wid) {
    //   cout << _ << ' ' << __ << "\n";
    // }

    cout << mx_len.begin() -> first * mx_wid.begin() -> first << "\n";
  }
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