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

void solve(string s) {
  int n = s.size();
  int j = 0;
  vector<int> nxt(n, 0);
  for (int i = 1; i < n; i ++) {
    while (j and s[i] != s[j]) {
      j = nxt[j - 1];
    }
    j += (s[i] == s[j]);
    nxt[i] = j;
  }

  int diff = n - nxt[n - 1];
  // n - nxt[n - 1] 可以求出字符串的循环节的长度
  cout << (n % diff == 0 ? n / diff : 1) << "\n";
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  string s;
  while (tt and ++_) {
    cin >> s;
    if (s == ".") break;
    // std::cout << "TEST CASE : " << _ << endl,
    solve(s);
  }

  return 0;
}