#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  string a, b;
  cin >> a >> b;
  a.pop_back();
  b.pop_back();

  int aa = stoll(a);
  int bb = stoll(b);

  cout << (aa <= bb) << "\n";
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