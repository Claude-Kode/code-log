// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, k; cin >> n >> k;
  if (k == n * n - 1) {
    cout << "NO" << endl;
    return; 
  }

  cout << "YES" << '\n';

  vector<vector<char>> vec(n + 1, vector<char>(n + 1, 'D')); 

  if (k == n * n) {
    for(int i = 1; i <= n ;i ++) {
      for(int j = 1; j <= n; j ++) {
        cout << vec[i][j];
      } cout << '\n';
    }
    return; 
  }

  int rem = 0;
  if (k > (n - 2) * n) rem = k - (n - 2) * n, k = (n - 2) * n;

  for(int i = n - 1; i <= n; i ++) {
    for(int j = 1; j < n; j ++) {
      vec[i][j] = 'R';
    }
  }

  vec[n][n] = 'U';

  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      if (k == 0) break; 
      vec[i][j] = 'U'; k --;
    } if (k == 0) break; 
  }

  for(int i = n - 1; i <= n; i ++) {
    for(int j = 1; j < n; j ++) {
      if (rem == 0) break;
      vec[i][j] = 'U'; rem --;
    } if (rem == 0) break;
  }

  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      cout << vec[i][j];
    } cout << '\n';
  } 
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}