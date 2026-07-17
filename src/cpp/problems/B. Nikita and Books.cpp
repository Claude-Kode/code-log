#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] + sum < i + 1) {
      cout << "NO" << "\n";
      return;
    }
    sum += a[i] - (i + 1);
  } 
  cout << "YES" << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}