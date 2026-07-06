// @Author : GoryK
#include <bits/stdc++.h>
#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    std::cin >> vec[i];
  }

  vector<int> lmx(n + 1), lmn(n + 1), rmx(n + 1), rmn(n + 1);
  stack<int> st;
  for(int i = 1; i <= n; i ++) {
    while(!st.empty() && vec[st.top()] < vec[i]) st.pop();
    lmx[i] = (st.empty() ? 0 : st.top());
    st.push(i);
  }

  st = std::stack<int>();
  for (int i = 1; i <= n; i ++) {
    while(!st.empty() && vec[st.top()] > vec[i]) st.pop();
    lmn[i] = (st.empty() ? 0 : st.top());
    st.push(i);
  }

  st = std::stack<int>();
  for (int i = n; i > 0; i --) {
    while(!st.empty() && vec[st.top()] < vec[i]) st.pop();
    rmx[i] = (st.empty() ? n + 1 : st.top());
    st.push(i);
  }

  st = std::stack<int>();
  for(int i = n; i > 0; i --) {
    while(!st.empty() && vec[st.top()] > vec[i]) st.pop();
    rmn[i] = (st.empty() ? n + 1 : st.top());
    st.push(i);
  }

  int ans = 0;
  for(int i =1; i <= n; i ++) {
    ans += (i - lmx[i]) * (rmx[i] - i) * vec[i];
    ans += (i - lmn[i]) * (rmn[i] - i) * vec[i];
  }

  std::cout << ans << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, C = 0; 
  cin >> tt;
  while (tt-- && ++C)
    // cout << "TEST CASE : " << C << endl,
    solve();

  return 0;
}