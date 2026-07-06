#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
    sum += vec[i];
  }

  cout << (sum + n - 1) / n << "\n";
  // vector<int> num(30, 0);
  // int cnt = 0;
  // for (int i = 1; i <= n; i ++) {
  //   for (int j = 0; j <= __lg(vec[i]); j ++) {
  //     if (!(vec[i] >> j & 1)) continue;
  //     num[j] ++;
  //     cnt = max(cnt, j);
  //   }
  // }

  // // for (int i = 0; i <= cnt; i ++) {
  // //   cout << num[i] << " \n"[i == cnt];
  // // }

  // // cout << cnt << "\n";
  // for (int i = cnt; i >= 0; i --) {
  //   if (i > 0) {
  //     int rem = (n - num[i - 1]) / 2;
  //     num[i - 1] = min(n, 2 * num[i] + num[i - 1]);
  //     num[i] = max(num[i] - rem, 0LL);
  //   }

  //   if (!num[i]) continue;

  //   if (i < cnt and num[i + 1]) {
  //     int rem = 2 * (n - num[i + 1]);
  //     num[i] = max(num[i] - rem, 0LL);
  //   }
  // }

  // // for (int i = 0; i <= cnt; i ++) {
  // //   cout << num[i] << " \n"[i == cnt];
  // // }

  // int res = 0;
  // for (int i = 0; i <= cnt; i ++) {
  //   if (num[i]) {
  //     res += (1 << i);
  //   }
  // }

  // cout << res << "\n";
}

int32_t main() {
  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }
  return 0;
}

