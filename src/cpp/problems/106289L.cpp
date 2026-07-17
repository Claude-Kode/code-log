// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() { 
  int n, p; cin >> n >> p;
  if (n >= 3 * p || n == 5 && p == 2) {cout << -1 << endl; return;}
  vector<int> ans(n + 1);
  iota(ans.begin(), ans.end(), 0);

  int l = (n >= p), r = (n >= 2 * p);

  if (l) swap(ans[p], ans[1]);
  if (r) swap(ans[2 * p], ans[n]);

  auto check = [&](const vector<int>& a) -> bool {
    for(int i = 2; i < n; i ++) {
      if ((a[i - 1] * a[i]) % p == (a[i] * a[i + 1]) % p) return false;
    }
    return true;
  };

  while(!check(ans)) shuffle(ans.begin() + 1 + l, ans.end() - r, rng);
  for(int i = 1; i <= n; i ++) cout << ans[i] << " \n"[i == n];
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}