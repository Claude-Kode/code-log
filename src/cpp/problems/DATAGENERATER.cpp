// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    
// int rand_int(int l, int r) {
//   return uniform_int_distribution<int>(l, r)(rng);
// }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  
long long rand_int(int l, int r) { 
  if (l > r) swap(l, r);  // 如果 l > r，交换
  return (unsigned long long)rng() % (r - l + 1) + l;
}

void solve() { 

  int n = rand_int(1, 100);
  cout << n << endl; 
  for (int i = 1; i <= n; i ++) {
    int num = rand_int(1, 500);
    cout << num << ' ';
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

  int tt , CNT = 0; cin >> tt;
  cout << tt << endl; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}

