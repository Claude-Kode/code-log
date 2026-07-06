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
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i];
  set<int> s;
  for(int i = 1; i <= n; i ++) s.insert(i);
  for(int i = 1; i <= n; i ++) if (s.count(vec[i])) s.erase(vec[i]);

  auto ans = vec;
  for(int i = 1; i <= n; i ++) if (vec[i] == vec[i - 1]) ans[i] = 0;

  // for(int i = 1; i <= n; i ++) cout  << ans[i] << " \n"[i == n];

  auto temp = ans; auto ss = s;
  for(int i = 1; i <= n; i ++) if (!ans[i]) {
    ans[i] = *s.begin(); s.erase(s.begin());
  }
  for(int i = 1; i <= n; i ++) cout << ans[i] << " \n"[i == n];

  ans = temp; s = ss;
  for(int i = 1; i <= n; i ++) if (!ans[i]) {
    // cout << vec[i] << " \n"[i == n];
    auto it = s.lower_bound(vec[i]); it --;
    ans[i] = *it; s.erase(it);
  }
  for(int i = 1; i <= n; i ++) cout << ans[i] << " \n"[i == n];
}

/*
查找第一个
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


