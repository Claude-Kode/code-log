// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n; 
vector<int> tree;

void init() {tree.assign(n + 1, 0);}
int lowbit(int i) {return i & -i;} 

void update(int p, int v) {
  for(int i = p; i <= n; i += lowbit(i)) tree[i] += v;
}

int query (int p) {
  int res = 0;
  for(int i = p; i > 0; i -= lowbit(i)) res += tree[i];
  return res;
}


void solve() { 
  int m; cin >> n >> m; init();
  for(int i = 1; i <= n; i ++) {
    int temp; cin >> temp;
    update(i, temp);
  }

  for(int i = 1; i <= m; i ++) {
    int op; cin >> op;
    if (op == 1) {
      int x, k; cin >> x >> k;
      update(x, k);
    } else {
      int x, y; cin >> x >> y;
      cout << query(y) - query(x - 1) << endl; 
    } 
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}