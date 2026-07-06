#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n, m;  
  cin >> n >> m;

  vector<vector<int>> vec(n + 1);

  while (m --) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, x;
      cin >> i >> x;
      vec[i].push_back(x);
    } else{
      int i1, j1, i2, j2;
      cin >> i1 >> j1 >> i2 >> j2;
      swap(vec[i1][j1 - 1], vec[i2][j2 - 1]);
    }
  }

  for (int i = 1; i <= n; i ++) {
    cout << vec[i].size() << " ";
    for (auto &x : vec[i]) {
      cout << x << " ";
    }
    cout << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  // cin >> tt;
  while(tt --) {
    solve();
  }

  return 0;
}