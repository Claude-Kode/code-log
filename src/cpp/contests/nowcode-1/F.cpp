#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long

void solve() {
  int n; cin >> n;
  int k, x; cin >> k >> x;
  deque<int> a(n);
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
  }

  while (a[k] != x) {
    a.push_back(a.front());
    a.pop_front();
  }

  for (int i = 0; i < n; i ++) {
    cout << a[i] << " \n"[i == n - 1];
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