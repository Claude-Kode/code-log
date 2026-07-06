// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 
  int n; cin >> n;
  string s; cin >> s;
  int l = 0, r = 0;
  for(int i = 0; i < n; i++) {
    if (s[i] == '_') {
      if (l) {
        s[i] = ')';
        l--; 
      } else {
        s[i] = '(';
        l++; 
      }
    } else if (s[i] == '(') {
      l++;
    } else {  // ')'
      if (l) l--;
      else r++;
    }
  }
  
  int ans = 0; 
  stack<int> L;
  for(int i = 0; i < n; i++) {
    if (s[i] == '(') L.push(i);
    else {
      ans += i - L.top();
      L.pop();
    }
  }
  cout << ans << endl;
}

/*
RBS 问题中 一定要记住 佐罗好的数量始终大于等于 右括号的数量
*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}
