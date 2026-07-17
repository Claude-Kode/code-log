// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  set<int> st;
  unordered_map<int, int> ump;
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i]; 
    ump[vec[i]] ++;
    st.insert(vec[i]);
  }

  int mx = ranges::max(vec);
  sort(vec.begin() + 1, vec.end());
  for(int i = 1; i <= n; i ++) {
    int base = vec[i], num = vec[i], p = 1;

    if (base == 1) {
      if (ump[1] > 2 || ump[1] == 2 && st.size() >= 2) {
        cout << "YES" << endl; 
      } else continue; 
    }

    ump[base] --;
    while(num <= mx) {
      if (ump[num] > 0) {
        ump[num] --;
        if (ump[p] > 0) {
          cout << base << ' ' << p << ' ' << num << endl;   
          cout << "YES" << endl; 
          return; 
        }
        ump[num] ++;
      }
      num *= base;
    }
    ump[base] ++;
    num *= base, p ++;
  }

  cout << "NO" << endl;
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