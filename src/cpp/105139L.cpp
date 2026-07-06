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

const int N = 1e7 + 1;
vector<int> pr;
vector<int> vis(N , 0);

void prime(int n) {
  vis[1] = 1;
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
}

void solve() {
  int a, b; cin >> a >> b;

  auto cal = [&](int x) -> int {
    if (!vis[x]) return x;
    for (int &a : pr) {
      if (x % a == 0) return a;
    }
  };

  int ga = cal(a), gb = cal(b);
  int ans = INT_MAX;
  ans = min(ans, lcm(a, b));
  if (gcd(a, b) > 1) {
    ans = min(ans, a + b);
  }

  ans = min(ans, a + lcm(ga, 2) + lcm(ga, b));
  ans = min(ans, a + lcm(ga, gb) + b);
  ans = min(ans, lcm(a, 2) + lcm(2, gb) + b);

  ans = min(ans, a + lcm(ga, 2) + lcm(2, gb) + lcm(gb, 2));

  cout << ans << "\n";
} 

int32_t main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  prime(N);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}