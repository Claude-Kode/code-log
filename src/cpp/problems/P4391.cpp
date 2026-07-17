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

void solve() {
  int m; cin >> m;
  string s; cin >> s;
  int n = s.size();
  vector<int> nxt(n, 0);
  int j = 0;
  for (int i = 1; i < n; i ++) {
    while(j and s[i] != s[j]) {
      j = nxt[j - 1];
    }
    j += (s[i] == s[j]);
    nxt[i] = j;
  }

  cout << m - nxt[n - 1]<< "\n";
} 
/*
  相当于寻找一个循环子串满足
  ans
  有 s = suf(ans) + ans + ... + pre(ans)
  找到一个长度最短的满足条件的 ans 即可

  我们假设 s 可以写成这样的形式
  (x 为 s 中出现的循环字子串, suf 为 x 的后缀, pre 为 x 的前缀)
  于是有
  s = suf + ...(k * x) + pre 
  = {suf + (k - 2) * x + pre} + {(x - pre) + pre} 
  = {suf + (x - suf)} + {suf + (k - 2) * x + pre}

  len(suf + (x - suf)) = len((x - pre) + pre) = x
  而 发现式子有一个 真前缀等于真后缀
  所以答案即为 n - nxt.back()
*/
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