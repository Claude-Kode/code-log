#include <bits/stdc++.h>
using namespace std;

#define int long  long 
#define ll long long 

void solve() {
  int n; cin >> n;
  int S, D, HP;
  cin >> S >> D >> HP;
  
  vector<int> a(n + 1), k(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i] >> k[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i ++) {
    int lim_s = min(a[i], 3LL) * S;
    int lim_d = min((5 - a[i]), 3LL) * D;

    if (lim_s >= HP) {
      HP = 0;
      ans = i;
      break;
    }

    if (lim_d < k[i]) {
      cout << "No" << "\n";
      return;
    }
    
    int cnt_d = 0;
    while(cnt_d < 3 and cnt_d * D < k[i]) {
      cnt_d ++;
    }

    HP -= min(a[i], (3 - cnt_d)) * S;

    // cout << HP << ' ' << (3 - cnt_d) * S << "\n";
    if (HP <= 0) {
      ans = i;
      break;
    }
  } 

  if (HP > 0) {
    cout << "No" << "\n";
    return;
  }

  cout << "Yes" << "\n";
  cout << ans << "\n";
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