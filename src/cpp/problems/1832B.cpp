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
  vector<int> vec(n + 10, 0);
  for(int i = 1; i <= n; i++ ) cin >> vec[i];

  sort(vec.begin() + 1, vec.begin() + n + 1);

  auto pre = vec;auto suff = vec;
  for(int i = 1; i <= n; i ++) pre[i] += pre[i - 1];
  for(int i = n; i > 0; i --) suff[i] += suff[i + 1];

  // for(auto a : suff) cout << a << ' ' ;
  // cout << endl; 

  int ans = 0, sum = pre[n];
  int l = 0, r = n - k + 1;
  while (r <= n + 1) {
    // cout << r << ' ' ;
    ans = max(ans, sum - suff[r] - pre[l]);
    l += 2, r ++;
  }

  // cout << endl; 
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