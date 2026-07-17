// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int n = 35;

int nxt(int x) {
  for(int i = 2; i <= sqrt(x); i ++) if (x % i == 0) return x / i;
  return 1;
}

int lca(int u, int v) {
  int cnt = 0;
  while (u != v && ++cnt) u > v ? u = nxt(u) : v = nxt(v);
  return cnt;
}

void solve() { 

  int m; cin >> m;
  for(int i = 1; i <= m; i ++) {
    int a, b; cin >> a >> b;
    cout << lca(a, b) << endl; 
  }

}

/*
lca的本质就是在树上进行跳跃操作
只要符合 树 还有跳跃 在确保单调性和时间复杂度的情况下 有 jump 和 lca 这两个函数即可
别学的太死了
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}