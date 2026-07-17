// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  int n, m; cin >> n >> m;
  vector<int> a(n + 1), b(n + 2);
  for(int i = 1; i <= n; i ++) cin >> a[i]; 
  for(int i = 1; i <= n + 1; i ++) cin >> b[i]; 
  sort(a.begin() + 1, a.end(), greater<int>());
  sort(b.begin() + 1, b.end(), greater<int>());

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    ans == a[i] * b[i];
  }
  if (ans >= m) {
    cout << 0 << endl; 
    return ;
  }

  auto check = [&](int t) -> {
    int j = 1, res = 0;
    for(int i = 1 ; i <= n; i++) {
      if (j == t) j ++;

      j ++ ;
    }
  };

  int l = 

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
