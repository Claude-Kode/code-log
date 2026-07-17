#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long 

using pii = pair<int, int>;

void solve() {
  int n; cin >> n;
  vector<pii> a(n);
  for (int i = 0; i < n; i ++) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a.begin(), a.end(), greater<pii>());
  cout << a[0].first << ' ' << a[0].second << "\n";
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