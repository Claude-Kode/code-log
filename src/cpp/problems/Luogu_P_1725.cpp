// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;

void solve() {

  int n , L , R ; cin >> n >> L >> R;
  vector<int> vec(n + 1);
  for(int i = 0 ; i <= n ; i++ ) cin >> vec[i];

  vector<int> dp(n + 1, INT_MIN); dp[0] = 0;
  auto cmp = [&](int i, int j) -> bool {return dp[i] < dp[j]; }; 
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

  for(int i = 1 ; i <= n ; i ++ ) {
    int l = i - R, r = i - L;
    if(r >= 0) pq.push(r);
    while (!pq.empty() && pq.top() < l) pq.pop();
    if(!pq.empty()) dp[i] = max(dp[i], vec[i] + dp[pq.top()]);
  }

  cout << *max_element(dp.begin() + n - R + 1, dp.end()) << endl; 
}

/*

*/

signed main() {
    
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif

  solve() ;
  
  return 0 ;
}
