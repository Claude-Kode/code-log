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
  int n, k; cin >> n >> k;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  auto pre = vec;
  for(int i = 1; i <= n; i ++) {
    pre[i] += pre[i - 1];
  }

  vector<array<int, 2>> dp(n + 1); dp[1][1] = vec[1]; dp[1][0] = vec[1];
  auto cmp = [&](int i, int j) -> bool { return (dp[i][0] - pre[i] / 2) > (dp[j][0] - pre[j] / 2);};
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  for(int i = 1; i <= n; i ++) {
    while(!pq.empty() && pq.top() < i - k) pq.pop();
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + vec[i];
    dp[i][1] = dp[i][0];
    if (!pq.empty()) {
      dp[i][1] = dp[pq.top()][0] + (pre[i] - pre[pq.top()]) / 2;
    }
    pq.push(i);
  }

  cout << min(dp[n][0], dp[n][1]) << endl;
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