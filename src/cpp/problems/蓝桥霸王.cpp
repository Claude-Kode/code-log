// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;
const long double C = 9.8 * 2;

void solve() { 
  long double v, mu;
  int n; cin >> v >> mu >> n;
  vector<array<int, 2>> vec(n + 1);
  for(int i = 0; i <= n; i ++) {
    cin >> vec[i][0] >> vec[i][1];
    // cout << vec[i][0] << ' ' << vec[i][1] << '\n';
  }

  // dbug(vec);

  v *= v;
  for(int i = 1; i <= n; i ++) {
    // cout << v << endl;
    int dx = vec[i][0] - vec[i - 1][0];
    int dy = vec[i][1] - vec[i - 1][1];
    // cout << dx << ' ' << dy << endl;
    v = v - C * dy - C * mu * dx;
    
    if (v <= 0) {cout << 0.00 << endl; return; }
  }

  cout << sqrt(v) << '\n';
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  cout << fixed << setprecision(2);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}