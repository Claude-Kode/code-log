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
  vector<array<int, 3>> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
  }

  sort(vec.begin() + 1, vec.end(), [&](const auto &a, const auto &b){
    if (a[0] != b[0]) return a[0] < b[0];
    else if (a[1] != b[1]) return a[2] > b[2];
    else return a[2] > b[2];
  });

  for(int i = 1; i <= n; i ++) {
    if (vec[i][0] <= k && k <= vec[i][1] && k < vec[i][2]) k = vec[i][2];
  }

  cout << k << endl;
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