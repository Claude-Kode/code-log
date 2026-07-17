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
  vector<string> ss;
  {
    string s;
    while (cin >> s) {
      if (s == ".") break;
      ss.push_back(s);
    }
  }

  string s;
  {
    string tmp; 
    while (cin >> tmp) {
      s += tmp;
    }
  }

  auto build_nxt = [&](const string& p) -> vector<int> {
    int n = p.size();
    int j = 0;
    vector<int> nxt(n, 0);
    for (int i = 1; i < n; i ++) {
      while (j and p[i] != p[j]) {
        j = nxt[j - 1];
      }
      j += (p[i] == p[j]);
      nxt[i] = j;
    }
    return nxt;
  };

  auto kmp = [&](const string& s, const string& p) -> vector<int> {
    int n = s.size(), m = p.size();
    vector<int> res; auto nxt = build_nxt(p);
    int j = 0;
    for (int i = 0; i < n; i ++) {
      while (j and s[i] != p[j]) {
        j = nxt[j - 1];
      }  
      j += (s[i] == p[j]);
      if (j == m) {
        res.push_back(i - m + 2);
        j = nxt[j - 1];
      }
    }
    return res;
  };

  int n = s.size();
  vector<vector<int>> vec(n + 1);
  for (const auto& p : ss) {
    auto v = kmp(s, p);
    for (int& l : v) {
      int r = l + p.size() - 1;
      vec[r].push_back(l);
    }
  }

  vector<int> dp(n + 1); dp[0] = 1;
  for (int i = 1; i <= n; i ++) {
    for (const auto& l : vec[i]) {
      dbug(l - 1, i, dp[l - 1], "\n");
      dp[i] = max(dp[i], dp[l - 1]);
    }
  }

  dbug(vec);
  dbug(dp);

  for (int i = n; i > 0; i --) {
    if (dp[i]) {
      cout << i << "\n";
      return; 
    } 
  }

  cout << 0 << "\n";
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