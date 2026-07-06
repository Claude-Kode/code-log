// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, m, l; cin >> n >> m >> l;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> a[i]; 
  }

  int ans = 0;
  multiset<int> mst; int p = 1;
  for(int i = 1; i <= min(n + 1, m); i ++) mst.insert(0);
  for(int i = 1; i <= l; i ++) {
    int x = *mst.begin() + 1;
    mst.erase(mst.begin());
    mst.insert(x);

    if (p <= n && i == a[p]) {
      mst.erase(--mst.end());
      if (mst.size() < min((n - p) + 1, m)) mst.insert(0);
      p ++;
    }
  }
  
  cout << *--mst.end() << endl; 
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