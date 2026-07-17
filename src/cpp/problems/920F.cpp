// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#include "__DEBUG_TOOL.h"
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 1e6;

int n, q;


vector<int> vec, tree, fa, res(N + 1);

void init(){ 
  tree.assign(n + 1, 0); 
  fa.assign(n + 10, 0);
  vec.assign(n + 1, 0);
  iota(fa.begin() + 1, fa.end(), 1LL);
  // for(int i = 1; i <= n; i ++) cout << fa[i] << " \n"[i == n];
}

int lowbit(int i) {return i & -i;}

void upd(int p, int v) {
  for(int i = p; i <= n; i += lowbit(i)) tree[i] += v;
}

int query(int p) { 
  int res = 0;
  for(int i = p; i > 0; i -= lowbit(i)) res += tree[i];
  return res; 
}

int find(int i) {
  return i == fa[i] ? i : fa[i] = find(fa[i]);
}

void change(int l, int r) {
  for(int i = find(l); i <= r; i = find(i + 1)) {
    upd(i, res[vec[i]] - vec[i]);
    vec[i] = res[vec[i]];
    if (vec[i] <= 2) fa[i] = find(i + 1);
  }
}

void solve() { 
  cin >> n >> q; init();
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
    upd(i, vec[i]);
  }

  // for(int i = 1; i <= n; i ++) cout << query(i) << " \n"[i == n];
 
  while (q --) {
    int op, l, r; cin >> op >> l >> r;
    if (op == 1) change(l, r);
    else cout << query(r) - query(l - 1) << endl; 
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

  for(int i = 1; i <= N; i ++) {
    for(int j = i; j <= N; j += i) {
      res[j] ++;
    }
  }

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}