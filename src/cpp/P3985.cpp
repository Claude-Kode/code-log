// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

struct Info {
  int p, mn, mx;
};

// REGISTER_REFLECT(Info, p, mn, mx)

void solve() {
  int N, W; cin >> N >> W;
  vector<int> V(N + 1, 0), P(N + 1);
  for (int i = 1; i <= N; i ++) {
    cin >> V[i] >> P[i];
  }
  
  map<int, Info, greater<int>> dp; // {2, {v, mn, mx}}
  dp[0] = {0, INT_MAX, INT_MIN};
  for (int i = 1 ; i <= N; i ++) {
    for (const auto& [w, info] : dp) {
      auto [p, mn, mx] = info;
      if (w > W - V[i]) continue;
      if (max(mx, V[i]) - min(mn, V[i]) > 3) continue;
      if (dp[w + V[i]].p > p + P[i]) continue;
      dp[w + V[i]] = {p + P[i], min(mn, V[i]), max(mx, V[i])};
    }
  }   
  
  int ans = 0;
  for (const auto& [w, info] : dp) {
    dbug(w, info);
    ans = max(ans, info.p);
  }

  cout << ans << "\n";
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}