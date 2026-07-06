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
  int n, h; cin >> n >> h;
  vector<int> vec(n + 2, h); 
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  stack<int> st; st.push(0); vector<int> l(n + 2, 0);
  for(int i = 1; i <= n; i ++) {
    while(st.size() > 1 && vec[st.top()] <= vec[i]) st.pop();
    l[i] = l[st.top()] + (h - vec[i]) * (i - st.top());
    st.push(i);
  }
  
  while(!st.empty()) st.pop();
  st.push(n + 1); vector<int> r(n + 2, 0);
  for(int i = n; i > 0; i --) {
    while(st.size() > 1 && vec[st.top()] <= vec[i]) st.pop();
    r[i] = r[st.top()] + (h - vec[i]) * (st.top() - i);
    st.push(i);
  }

  vector<int> sum(n + 1);
  for(int i = 1; i <= n; i ++) {
    sum[i] = l[i] + r[i] - (h - vec[i]);
  }

  int ans = 0 ;
  for(int i = 1; i <= n; i ++) {
    int mid = i;
    for(int j = i; j <= n ;j ++) {
      ans = max(ans, sum[i] + sum[j] - sum[mid]);
      if (vec[j] > vec[mid]) mid = j;
    }
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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}