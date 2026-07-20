#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rn(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

void solve() {
  int n; cin >> n;
  int k, x; cin >> k >> x;
  deque<int> a(n);
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
  }

  auto m = n;
  while (m --) {
    shuffle(a.begin(), a.end(), rng);
    int S = 0;
    for (int i = 0; i < n; i ++) {
      S += (i + i + 1 - n) * a[i];
    }
    cout << S << "\n";
    // a.push_back(a.front());
    // a.pop_front();
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