// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {
  // shenme 78 shabi ti c
  int n, k; cin >> n >> k;
  vector<int> a(n + 1), b(n + 1);
  map<int, int> mp, cnt;
  
  for (int i = 1; i <= n; i ++) cin >> a[i], mp[a[i]] = i;
  for (int i = 1; i <= n; i ++) cin >> b[i], cnt[b[i]] ++;
  
  for (auto [x, y] : cnt) {
    if (x == -1) continue;
    if (y >= 2) { cout << "NO" << endl; return;}
  }
  
  // cout << "A: " << endl ;
  // for( const auto &[v, p] : mp1) if (v != -1) cout << v << ' ' << p << endl ;
  // cout << "B: " << endl ;
  // for( const auto &[v, p] : mp2) if (v != -1) cout << v << ' ' << p << endl ;

  for (int i = 1; i <= n; i ++) if (b[i] != -1) {
    int r = max(1LL, i - k + 1) + k - 1, l = min(i, n - k + 1);
    if (mp[b[i]] < l || mp[b[i]] > r) { cout << "NO" << endl; return; }
  }
  
  for (int i = 1; i <= n - k; i ++) if (b[i] != -1 && b[i] != a[i]) {
    cout << "NO" << endl;
    return;
  }
  
  for (int i = n; i >= k + 1; i --) if (b[i] != -1 && b[i] != a[i]) {
    cout << "NO" << endl;
    return;
  }
  
  cout << "YES" << endl;

}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}



