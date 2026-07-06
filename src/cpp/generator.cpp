#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(time(0));
int rn(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

void p(int l, int r, vector<int>& vec) {
  iota(vec.begin() + 1, vec.end(), l);
  shuffle(vec.begin() + 1, vec.end(), rng);
}

void solve() {
  int n = 1000, q = (1, 2e5);
  cout << n << ' ' << q << "\n";
  for (int i = 1; i <= n; i ++) {
    cout << rn(-1e9, 1e9) << " \n"[i == n];
  }
  for (int i = 1; i <= q; i ++) {
    int l = rn(1, n - 1), r = rn(l + 1, n), k = rn(1, r - l + 1);
    cout << l << ' ' << r << ' ' << k << "\n";
  }
}

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 250;
  cout << tt << endl; 
  while(tt --) 
    solve();
  
  return 0;
}
