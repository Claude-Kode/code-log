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
  vector<int> vec(n + 10), b2;
  for(int i = 1; i <= n ; i++) {
    cin >> vec[i];
    if (vec[i] == 2) b2.push_back(i);
  }

  auto BFS = [&](int i) -> void {
    queue<int> q; q.push(i);
    while (!q.empty()) {
      auto t = q.front(); q.pop();
      vec[t] = 2;
      if (vec[t - 1] == 1) q.push(vec[t - 1]);
      if (vec[t + 1] == 1) q.push(vec[t + 1]);
    }
  };

  for(const auto &a : b2) BFS(a);

  for(int i = 1; i <= n; i ++) {
    if (vec[i] == 2) {
      vec[i - 1] = 2;
      vec[i + 1] = 2;
    }
  }

  for(int i = 1; i <= n ; i++ ) {
    if (vec[i] == 1) {
      if (vec[i - 1] == 0) vec[i - 1] = 1;
      else if(vec[i + 1] == 0) vec[i - 1] = 1;
    }
  }

  // for(int i = 1 ; i <= n ; i ++) cout << vec[i] << ' ' ;
  // cout << endl; 

  int ans = 0; vec[0] = -1;
  for(int i = 0; i < n ; i++) {
    if (vec[i] != vec[i + 1]) ans ++ ;
  }

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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}


