#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n; cin >> n;
  vector<array<int, 2>> vec(n + 1, {0, 0});
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i][0] >> vec[i][1];
  }

  double ans = INT_MAX;
  for (int i = 1; i <= n; i ++) {
    for (int j = i + 1; j <= n; j ++) {
      for (int k = j + 1; k <= n; k ++) {
        int a = vec[j][0] - vec[i][0];
        int b = vec[j][1] - vec[i][1];
        int c = vec[k][0] - vec[i][0];
        int d = vec[k][1] - vec[i][1];
        int s = abs(a * d - b * c);
        if (!s) continue;
        ans = min(ans, 0.5 * s);
      }
    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << setprecision(8);

  int tt = 1;
  cin >> tt;
  while(tt --) {
    solve();
  }

  return 0;
}