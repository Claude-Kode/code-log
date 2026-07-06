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

  int n, k; cin >> n >> k;
  unordered_map<int, int>
  vector<int> t(n + 1), w(n + 1);
  for(int i = 1 ; i <= n ; i++ ) {
    cin >> w[i] >> t[i];
  }

   

  auto check = [&](int test) -> bool {
    int res = 0;
    for(int i = 1; i <= n; i ++) {
      res = max(res, )
    }
    return res <= k; 
  };
 
  int l = 0, r = 1e9, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }

  cout << ans << endl; 
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

