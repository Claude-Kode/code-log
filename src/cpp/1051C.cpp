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
  int n; cin >> n;
  vector<int> vec(n + 1);
  unordered_map<int, int> ump;
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
    ump[vec[i]] ++;
  }

  int cnt1 = 0, cnt2 = 0, cnt = 0;
  for(const auto&[k, v] : ump)
    if (v == 1) cnt1 ++;
    else if (v == 2) cnt2 ++;
    else cnt ++;

  if ((cnt1 & 1) && cnt  || !(cnt1 & 1)) {
    cout << "YES" << endl; 
    if (!(cnt1 & 1)) {
      // cout << "op" << endl; 
      int c = 0;
      for(int i = 1; i <= n; i ++) {
        if (ump[vec[i]] == 1) {
          cout << (c & 1 ? 'B' : 'A');
          c ++;
        } else cout << 'A';
      }
    } else {
      bool f = true; int c = 0;
      for(int i = 1; i <= n; i ++) {
        if (f && ump[vec[i]] > 2) {cout << 'B'; f = false; continue; }
        if (ump[vec[i]] == 1) {
          cout << (c & 1 ? 'B' : 'A'); 
          c ++;
        } else cout << 'A';
      }
    }
  } else {
    cout << "NO" << endl;
  }
  cout << endl; 
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}