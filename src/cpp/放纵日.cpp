// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 3e7;

vector<int> pr;

vector<int> prime(int n) {
  vector<int> vis(N , 0) , pr ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  return pr ; 
}

void solve() { 
  string a, b, c; cin >> a >> b >> c;
  if (a.size() <= 4) a = string(4 - a.size(), '0') + a;
  if (b.size() == 1) b = "0" + b;
  if (c.size() == 1) b = "0" + c;
  string num = a + b + c;
  int p = 0;
  while(num[p] == '0') p ++;
  int n = stoll(string(num.begin() + p, num.end()));
  cout << string(p, '0') << *upper_bound(pr.begin(), pr.end(), n) << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  pr = prime(N - 1);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}
