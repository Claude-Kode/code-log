

// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;



void solve() { 

  int n, q; cin >> n >> q;
  vector<int> a(n + 1), b(n + 1), c(n + 1);
  for(int i = 1; i <= n; i ++) cin >> a[i];
  for(int i = 1; i <= n; i ++) cin >> b[i];
  for(int i = 1; i <= n; i ++) cin >> c[i];
  
  map<int, int> mp; 
  int ans = 0;
  
  for(int i = 1; i <= n; i ++) {
    if (a[i] < b[i]) {
      mp[b[i]] = max(mp[b[i]], c[i]);
    } else {
      ans += c[i];
    }
  }
  
  int mx = 0;
  for(auto &[k, v] : mp) {
    v = max(v, mx);
    mx = max(mx, v);
  }

  while (q --) {
    int x; cin >> x;
    if (mp.empty()) {
      cout << ans << endl;
    } else {
      auto it = mp.upper_bound(x);
      if ( it == mp.begin() ) {
        cout << ans << endl;
      } else {
        it --;
        cout << it -> second + ans << endl;
      }
    }
  }

}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}
