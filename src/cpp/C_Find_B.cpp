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
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i];
  vector<int> buckle(n + 1), pre(n + 1);
  for(int i = 1 ; i <= n ; i ++) 
    (buckle[i] += buckle[i - 1]) += vec[i] == 1, 
    pre[i] += pre[i - 1] + vec[i];

  while (q--) {
    int l, r; cin >> l >> r;
    int len = r - l + 1, cnt1 = buckle[r] - buckle[l - 1], sum = pre[r] - pre[l - 1];
    // cout << sum << endl; 
    if (sum - len < cnt1 || len < 2) cout << "NO" << endl; 
    else cout << "YES" << endl; 
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