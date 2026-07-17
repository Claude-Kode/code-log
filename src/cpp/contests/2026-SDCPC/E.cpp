#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long 

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1, vector<int>(m + 1));

  if (n * m <= 4) {
    cout << "No" << "\n";
    return;
  }

  if (n == 2 and m == 3) {
    cout << "Yes" << "\n";
    cout << "5 3 1\n";
    cout << "2 0 4\n";
    return;
  }

  int num = 0;
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      if (!((i + j) & 1)) {
        g[i][j] = num ++;
      }
    }
  }

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      if ((i + j) & 1) {
        g[i][j] = num ++;
      }
    }
  }

  cout << "Yes" << "\n";
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      cout << g[i][j] << " \n"[j == m];
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1; 
  cin >> tt;
  while (tt --) {
    solve();
  }

  return 0;
}