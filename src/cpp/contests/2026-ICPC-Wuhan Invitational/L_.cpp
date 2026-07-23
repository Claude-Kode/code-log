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

using u64 = uint64_t;
u64 BASE = 131;
u64 MOD1 = 1E9 + 7;
u64 MOD2 = 1E9 + 9;

struct StrHash {
  int n = 0;
  vector<u64> h1, h2, p1, p2;
  StrHash() = default;
  StrHash(const string& s): n(s.size()){
    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    p1.assign(n + 1, 1);
    p2.assign(n + 1, 1);
    for (int i = 0; i < n; i ++) {
      h1[i + 1] = (h1[i] * BASE + s[i]) % MOD1;
      h2[i + 1] = (h2[i] * BASE + s[i]) % MOD2;
      p1[i + 1] = p1[i] * BASE % MOD1;
      p2[i + 1] = p2[i] * BASE % MOD2;
    }
  }

  // 1 <= l <= r <= n
  pair<u64, u64> get(int l, int r) {
    if (r > n or l < 1 or r < l) return {-1, -1};
    u64 v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
    u64 v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return pair(v1, v2);
  }
};

struct AC_auto {
  int n = 0, tot = 0;
  vector<array<int, 26>> trie; 
  vector<int> cnt, fail, pass, q;

  AC_auto() = default;
  AC_auto(int _n): n(_n) {
    trie.assign(n + 1, {});
    fail.assign(n + 1, 0);
    pass.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    q.assign(n + 1, 0);
  }

  void resize_all(int sz) {
    trie.resize(sz);
    fail.resize(sz);
    pass.resize(sz);
    cnt.resize(sz);
    q.resize(sz);
  }

  void insert(string& s) {
    int u = 0;
    for (char& ch : s) {
      int c = ch - 'a';
      if (tot >= (int)trie.size()) resize_all(tot * 2);
      if (!trie[u][c]) trie[u][c] = ++tot;
      u = trie[u][c];
    }
    cnt[u]++;
  }

  void build() {
    int p1 = 0, p2 = -1;  
    for (int c = 0; c < 26; c++) {
      if (trie[0][c]) {
        q[++p2] = trie[0][c];
      }
    }

    while (p1 <= p2) {
      int u = q[p1++]; 
      for (int c = 0; c < 26; c++) {
        int& v = trie[u][c];
        if (v) {
          // 这里不管 trie[fail[u]][c] 是多少 直接继承就好
          // fail 只能给存在的具体的 trie 的节点, 其他的 trie 都是中继传送点
          fail[v] = trie[fail[u]][c];
          q[++p2] = v;
        } else {
          v = trie[fail[u]][c];
        }
      }
    }
  }

  vector<int> ask(string& s) {
    int u = 0, m = (int)s.size();
    vector<int> node(m + 1, 0);
    for (int i = 0; i < m; i++) {
      u = trie[u][s[i] - 'a'];
      node[i] = u;
    }

    return node;
  }
};

struct PairHash {
  std::size_t operator()(const pair<u64, u64>& p) const noexcept {
    return (std::hash<u64>{}(p.first) ^ std::hash<u64>{}(p.second));
  }
};

const int N = 1e6 + 10;

void solve() {  
  int n; cin >> n;
  vector<string> s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  vector<StrHash> hash(s.begin(), s.end());

  int ans = 0;

  // sz(t) < sz(s1) and sz(t) < sz(s2)
  unordered_map<int, unordered_map<pair<u64, u64>, int, PairHash>> pre;
  for (int i = 1; i <= n; i++) {
    int len = (int)s[i].size();
    for (int j = len; j > 0; j--) {
      auto h = hash[i].get(j, len);
      ans += pre[len - j + 1][h];
    }
    for (int j = 1; j <= len; j++) {
      auto h = hash[i].get(1, j);
      pre[j][h]++;
    }
  }

  // sz(t) > sz(s1) and sz(t) < sz(s2)
  AC_auto acma(N);
  for (int i = 0; i < n; i++) {
    acma.insert(s[i]);
  }

  acma.build();

  vector<vector<int>> ns(n + 1);
  for (int k = 1; k <= n; k++) {
    int j = 0, len = (int)s[k].size();
    auto& nxt = ns[k];
    for (int i = 0; i < len; i++) {
      while (j and s[k][j] != s[k][i]) {
        j = nxt[j - 1];
      }
      j += (s[k][j] == s[k][i]);
      nxt[i] = j;
    }
  }

  vector<vector<int>> B(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int b = ns[i][ns[i].back()]; b; b = ns[i][b - 1]) {
      B[i].push_back(b);
    }
  }

  int tot = acma.tot;
  vector<int> pre_cnt(tot + 1, 0);
  for (int i = 0; i < tot; i++) {
    int u = acma.q[i];
    pre_cnt[i] = pre_cnt[acma.fail[i]] + acma.cnt[i];
  }

  for (int i = 1; i <= n; i++) {
    int m = (int)s[i].size();
    auto node = acma.ask(s[i]);
    for (auto& b : B[i]) {
      ans += pre_cnt[node[m - b - 1]];
    } 
  }

  // sz(t) > sz(s1) and sz(t) > sz(s2)
  unordered_map<int, unordered_map<pair<u64, u64>, int, PairHash>> suf;
  for (int i = 1; i <= n; i ++) {
    int m = (int)s[i].size();
    for (int& b : B[i]) {
      int len = m - b;
      auto pre_h = hash[i].get(1, len);
      ans += suf[len][pre_h];
    }

    for (int& b : B[i]) {
      int len = m - b;
      auto suf_h = hash[i].get(m - len + 1, m);
      suf[len][suf_h]++;
    }
  }

  cout << ans << "\n";
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