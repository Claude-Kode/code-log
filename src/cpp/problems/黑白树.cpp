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
vector<int> fa;

void init(){
  fa.assign(n + 1, 0);
  iota(fa.begin() + 1, fa.end(), 1LL);
}

int find(int i) {
  return i == fa[i] ? i : fa[i] = find(fa[i]);
}

void merge(int i, int j) {
  int fi = find(i), fj = find(j);
  if (fi == fj) return; 
  else fa[fi] = fj;
}

void solve() { 
  cin >> n >> m;
  vector<array<int, 3>> edges;
  for(int i = 1; i <= m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  int cnt = 0, mn = 0, mx = 0;

  init();
  sort(edges.begin(), edges.end(), [&](const array<int, 3>& a, const array<int, 3>& b) {
    return a[2] < b[2];
  });
   
  int comp = n;
  for(const auto&[u, v, w] : edges) {
    int fu = find(u), fv = find(v);
    if(fu != fv) {
      merge(u, v);
      cnt ++;
      mx += (w == 0);
      comp --;
    } 
    if (cnt == n - 1) break; 
  }

  if (cnt < n - 1) {cout << 0 << endl; return; }

  init(); cnt = 0;
  sort(edges.begin(), edges.end(), [&](const array<int, 3>& a, const array<int, 3>& b) {
    return a[2] > b[2];
  });

  for(const auto&[u, v, w] : edges) {
    int fu = find(u), fv = find(v);
    if(fu != fv) {
      merge(u, v);
      cnt ++;
      mn += (w == 0);
    } 
    if (cnt == n - 1) break;
  }

  cout << mx - mn + 1 << endl; 
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
