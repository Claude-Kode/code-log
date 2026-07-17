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
// 对每个前缀 S[1..i],统计其不重叠的公共前后缀的个数 num[i],最后求 ∏(num[i]+1)mod(1e9 + 7)。
void solve() {
  string s; 
  cin >> s;
  int n = s.size();
  
  vector<int> nxt(n, 0);
  int j = 0;
  for (int i = 1; i < n; i ++) {
    while (j and s[i] != s[j]) {
      j = nxt[j - 1];
    }

    j += (s[i] == s[j]);
    nxt[i] = j;
  }

  // std::hash<int>
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}