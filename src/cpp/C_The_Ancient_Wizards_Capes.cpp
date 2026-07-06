// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 676767677; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  for(int i = 2; i <= n; i ++) if (abs(vec[i] - vec[i - 1]) > 1) {cout << 0 << endl; return; }

  auto check = [&](const vector<int>& a) -> bool {
    vector<int> pre(n + 1), suf(n + 2);
    for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + (a[i] == 0);
    for(int i = n; i >= 1; i --) suf[i] = suf[i + 1] + (a[i] == 1);
    for(int i = 1; i <= n; i ++) if (suf[i] + pre[i] != vec[i]) return false;
    return true;
  };

  vector<int> op1(n + 1), op2(n + 1); 
  op1[1] = 0, op2[1] = 1;
  for(int i = 2; i <= n ;i ++) {
    if (vec[i] == vec[i - 1])   
      op1[i] = op1[i - 1] ^ 1,
      op2[i] = op2[i - 1] ^ 1;
    else 
      op1[i] = op1[i - 1],
      op2[i] = op2[i - 1];
  }

  cout << check(op1) + check(op2) << endl; 
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