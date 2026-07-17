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

using u64 = unsigned long long;

u64 BASE = 131;
u64 MOD1 = 1E9 + 7;
u64 MOD2 = 1E9 + 9;

struct StrHash {
  int n;
  vector<u64> h1, h2, p1, p2;
  StrHash() = default;
  StrHash(const string& s): n(s.size()) {
    h1.assign(n + 1, 0); h2.assign(n + 1, 0);
    p1.assign(n + 1, 0); p2.assign(n + 1, 0);
    for (int i = 0; i < n; i ++) {
      h1[i + 1] = (h1[i] * BASE + s[i]) % MOD1;
      h2[i + 1] = (h2[i] * BASE + s[i]) % MOD2;
      p1[i + 1] = (p1[i] * BASE) % MOD1;
      p2[i + 1] = (p2[i] * BASE) % MOD2;
    }
  }

  pair<u64, u64> get(int l, int r) {
    int v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
    int v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return {v1, v2};
  }
};

void solve() {
  int n;
  cin >> n;
  vector<string> ss(n + 1);
  vector<StrHash> hashs(n + 1);
  unordered_map<string, int> ex;
  for (int i = 1; i <= n; i ++) {
    cin >> ss[i];
    hashs[i] = StrHash(ss[i]);
    ex[ss[i]] = 1;
  }

  int m;
  cin >> m;
  for (int i = 1; i <= m; i ++) {
    string s;
    cin >> s;
    if (ex.count(s) and ex[s] < 2) {
      cout << "OK" << "\n";
      ex[s] ++;
    } else if (ex.count(s)) {
      cout << "REPEAT" << "\n";
    } else {
      cout << "WRONG" << "\n";
    }
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