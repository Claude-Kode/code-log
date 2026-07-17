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

  // int n, p; cin >> n >> p;
  // vector<int> vec(n + 1);
  // std::iota(vec.begin(), vec.end(), 0);
  // auto check  = [&](const vector<int>& a) -> bool {
  //   for(int i = 2; i < n; i ++) {
  //     int a = vec[i] * vec[i - 1];
  //     int b = vec[i] * vec[i + 1];
  //     if (a % p == b % p) return false;
  //   }
  //   return true;
  // };

  // do{
  //   if (check(vec)) dbug(vec);
  // } while(next_permutation(vec.begin() + 1, vec.end()));
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
    cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}