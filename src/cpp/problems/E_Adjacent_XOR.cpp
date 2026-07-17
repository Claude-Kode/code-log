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

class LinearBasis {
private: 
  int lb[64];
public: 
  void insert(int x) {
    for(int i = 60; i >= 0; i--) if(x>>i&1) 
      if(lb[i]) x ^= lb[i]; else {lb[i] = x; return;}
  }

  bool check(int x) {
    for(int i = 60; i >= 0; i --) if(x >> i & 1) 
      if(lb[i]) x ^= lb[i]; 
      else return false;
    return true;
  }
};


void solve() { 
  int n; cin >> n;
  vector<int> a(n + 1),  b(n + 1);
  for(int i = 1; i <= n; i ++) cin >> a[i];
  for(int i = 1; i <= n; i ++) cin >> b[i];

  if (a[n] != b[n]) {cout << "NO" << '\n'; return;}
  for(int i = n - 1; i > 0; i --) {
    if (a[i] == b[i] || (a[i] ^ a[i + 1]) == b[i] || (a[i] ^ b[i + 1]) == b[i]) {

    } else {
      // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
      // for(int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];
      cout << "NO" << endl; return;
    }
  }


  cout << "YES" << endl;
}

/*
左边很显然可以获取右边任意多个数的 xor 
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