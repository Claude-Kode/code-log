// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;


int n, m; 
vector<int> lb(64);

void add(int x) {
  for(int i = 62; i >= 0; i --) if (x >> i & 1) {
    if (lb[i]) x ^= lb[i];
    else {lb[i] = x; return;}
  }    
}

void solve() { 
  lb.assign(64, 0);
  cin >> n >> m;
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    add(u ^ v ^ w);
  }

  int ans = n ^ 1;
  for(int i = 62; i >= 0; i --) { if ((ans >> i & 1) && lb[i]) ans ^= lb[i]; }

  // assert(ans);
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