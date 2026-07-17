#include <bits/stdc++.h>
using namespace std;

#define int long  long 
#define ll long long 

#define gcd __gcd

int mex(int a, int b) {
  int t = 0;
  while (t == a || t == b) t ++;
  return t;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  vector<int> c(m + 1), x(m + 1);
  for (int i = 1; i <= m; i ++) {
    cin >> c[i] >> x[i];
  }

  for (int i = 1; i < m; i ++) {
    if (c[i] != 1 and c[i + 1] != 2) {
      cout << "YES" << "\n";
      return;
    }
  }

  auto chk = [&]() -> bool {
    
  };

  for (int i = 1; i <= m; i ++) {
    if (c[i] == 1) {

    } else if (c[i] == 2) {

    } else {
      
    }
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