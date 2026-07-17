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
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> dp(n + 1);
  stack<int> st;
  for(int i = 1; i <= n; i ++) {
    while(!st.empty() && vec[st.top()] < vec[i]) st.pop();
    int s = (st.empty() ? 0 : st.top());
    dp[i] = dp[s] + s + (i - s);
    st.push(i);
  }

  cout << accumulate(dp.begin(), dp. end(), 0LL) << '\n';
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