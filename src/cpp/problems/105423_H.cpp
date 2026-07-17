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

int mod = 998244353;

void solve() {
  int n, K;
  cin >> n >> K;
  string s;
  cin >> s;
  
  int m = s.size();
  vector<int> nxt(m);
  {
    int j = 0;
    for (int i = 1; i < m; i ++) {
      while (j and s[i] != s[j]) {
        j = nxt[j - 1];
      }
      j += (s[j] == s[i]);
      nxt[i] = j;
    }
  }

  vector<vector<vector<int>>> dp(n + 1,
  vector<vector<int>> (K + 1,
  vector<int>(m + 1, 0)));

  map<int, map<int, map<int, int>>> mp;
  for (int i = 1; i <= n; i ++) {
    // 当前在匹配第几个
    // for (int j = 1; j <= K; j ++) {
      // 当前在匹配第 j 个的第 k 个字母
      for (int k = 0; k < m; k ++) {
        for (int p = 0; p < 26; p ++) {
          char c = 'a' + p;
          if (c == s[k]) {

          } 
        }
      }
    // }
  }

} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}