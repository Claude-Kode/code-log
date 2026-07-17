// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1), positive, negative;
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
    if (vec[i] > 0) positive.push_back(i);
    else negative.push_back(i);
  }

  sort(positive.begin(), positive.end(), [&](int i, int j) {
    return vec[i] > vec[j];
  });
  sort(negative.begin(), negative.end(), [&](int i, int j) {
    return vec[i] < vec[j];
  });

  dbug(positive);

  // for(const auto& x : positive) cout << x << " ";
  // for(const auto& x : negative) cout << x << " ";
  cout << "\n";
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