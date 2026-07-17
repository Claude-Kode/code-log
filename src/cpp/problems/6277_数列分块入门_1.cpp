// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n; 
vector<int> vec, bel, tag;

void init() {
  int lim = sqrt(n);
  int cnt = (n + lim - 1) / lim;
  vec.assign(n + 1, 0);
  bel.assign(n + 1, 0);
  tag.assign(cnt + 1, 0);
  for(int i = 1; i <= n; i ++) {
    bel[i] = ((i - 1) / lim) + 1;
  }
}

void update(int l, int r, int val) {
  int block = sqrt(n);
  int bl = (l - 1) / block + 1, br = (r - 1) / block + 1;

  if (bl == br) {
    for(int i = l; i <= r; i ++) vec[i] += val;
    return;
  }
  for(int i = l; i <= bl * block; i ++) vec[i] += val;
  for(int i = bl + 1; i < br; i ++) tag[i] += val;
  for(int i = (br - 1) * block + 1; i <= r; i ++) vec[i] += val;   
}


int query(int p) {
  return vec[p] + tag[bel[p]];
}

void solve() { 

  cin >> n; init();
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  for(int i = 1; i <= n; i ++) {
    int op, l, r, val; cin >> op >> l >> r >> val;
    if (op == 0) {
      update(l, r, val);
    } else {
      cout << query(r) << endl;
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