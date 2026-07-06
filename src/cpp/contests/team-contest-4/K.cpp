#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n; cin >> n;
  vector<int> r(n + 1), c(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> r[i];
  }

  for (int i = 1; i <= n; i ++) {
    cin >> c[i];
  }

  vector<vector<int>> vec(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i ++) {
    for (int j = i; j <= n; j ++) {
      // cout << i << ' ' << j << "\n";
      // cout << j << ' ' << i << "\n";
      vec[i][j] = i - 1;
      vec[j][i] = i - 1;
    }
  }

  // for (int i = 1; i <= n; i ++) {
  //   for (int j = 1; j <= n; j ++) {
  //     // cout << "[i, j]: " << i << ' ' << j << " \n"[j == n];
  //     cout << vec[i][j] << " \n"[j == n];
  //   }
  // }

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j ++) {
      cout << vec[r[i]][c[j]] << " \n"[j == n];
    } 
  }
  // auto ans = vec;
  // sort(vec.begin() + 1, vec.end(), [&](auto &a))
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  cin >> tt;  
  while(tt --) {
    solve();
  }

  return 0;
}