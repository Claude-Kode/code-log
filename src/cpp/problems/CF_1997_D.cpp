// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 

  int n; cin >> n;
  vector<int> vec(n + 1);
  vector<vector<int>> son(n + 1);
  for(int i = 1 ; i <= n; i ++) cin >> vec[i];
  for(int i = 2 ; i <= n; i ++) {
    int temp; cin >> temp; 
    son[temp].push_back(i);
  }

  // map<int, int> mp;
  std::function<bool(int, int)> check = [&](int u, int ned) -> bool {
    if (ned >= INT_MAX) return false; 
    if (son[u].empty()) return vec[u] >= ned;
    if (u != 1) ned += max(0LL, ned - vec[u]);
    for(const auto &v : son[u]) {
      if (!check(v, ned)) return false;
    }
    return true;
  };
  
  int l = 0, r = 1e9, ans = l;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(1, mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  } 

  cout << vec[1] + ans << endl; 

}

/*
用一个最小堆弹出当前的最小节点 如果 他的字子节点的最小值 
即 memo[v] + 2 <= memo[u] 就可以变 
然后一直变到不能变为止
*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}