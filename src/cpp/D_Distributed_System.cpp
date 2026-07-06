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

  int n, q, base = 0; cin >> n >> q;
  vector<int> a(q + 1), b(q + 1), c(2 * n + 1);
  for(int i = 1; i <= q; i ++) {
    cin >> a[i] >> b[i];
    int rem = a[i] % n;
    c[b[i]] += 1; c[b[i] + rem] -= 1;
    base += a[i] / n;
  }

  for(int i = 1; i <= n - 1; i ++) c[i] += c[i - 1];
  for(int i = n; i <= 2 * n - 1; i ++) c[i] += c[i - 1];

  for(int i = 0; i < n ; i++ ) {
    cout << base + c[i] + c[i + n] << ' ' ;
  } cout << endl; 
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