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
  vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i ++) cin >> a[i];
  for(int i = 1; i <= n; i ++) cin >> b[i];

  if (a[n] == b[n]) {cout << n << endl; return;}

  unordered_map<int, int> ump1, ump2;
  ump1[a[n]] ++; ump2[b[n]] ++; 
  for(int i = n - 1; i > 0; i --) {
    int cnt = (n - i);
    if (cnt & 1) {
      if (a[i] == b[i] || ump1[b[i]]) {cout << i << endl; return;}
      if (a[i] == b[i] || ump2[a[i]]) {cout << i << endl; return;}
      ump1[a[i]] ++, ump2[b[i]] ++;
    } else {
      if (a[i] == b[i] || ump2[b[i]]) {cout << i << endl; return;}
      if (a[i] == b[i] || ump1[a[i]]) {cout << i << endl; return;}
      ump1[b[i]] ++, ump2[a[i]] ++;
    }
  }

  cout << "ump1" << endl;
  for(const auto& [k, v] : ump1) {
    cout << k << ' ' << v << endl;
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