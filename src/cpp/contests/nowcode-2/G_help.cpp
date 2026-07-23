// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

const int N = 1e7;
vector<int> pr;
vector<int> vis(N + 1, 0);

void prime(int n) {
  vis[1] = 1;
  for (int i = 2; i <= n; i ++) {
    if(!vis[i]) pr.push_back(i) ;  
    for (const auto& j : pr) {
      if (i * j > n) break; 
      vis[i * j] = 1; 
      if (i % j == 0) break; 
    }
  }
}

map<int, int> cal_fac(int n) {
  map<int, int> res;
  for (int& p : pr) {
    if (p * p > n) break;
    while (n % p == 0) {
      res[p]++; 
      n /= p;
    }
  }
  if (n > 1) res[n] ++;
  return res;
}

void solve() {  
  auto ans = vector<int>();
  for (int i = 1; i <= 1e7; i ++) {
    if ((int)cal_fac(i).size() == 8) {
      ans.push_back(i);
    }
  }

  dbug(ans);
} 
    
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  prime(N);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 