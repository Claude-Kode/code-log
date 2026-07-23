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
  vector<u64> h1, h2, p1, p2;
  StrHash() = default;
  StrHash(const string& s) {
    int n = s.size();
    h1.assign(n + 1, 1);
    h2.assign(n + 1, 1);
    p1.assign(n + 1, 1);
    p2.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
      h1[i + 1] = (h1[i] * BASE + s[i]) % MOD1;
      h2[i + 1] = (h2[i] * BASE + s[i]) % MOD2;
      p1[i + 1] = (p1[i] * BASE) % MOD1;
      p2[i + 1] = (p2[i] * BASE) % MOD2;
    }
  }

  // [l, r], 1 <= l <= r <= n
  pair<u64, u64> get(int l, int r) {
    if (r < l) return pair(0ULL, 0ULL);
    u64 v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
    u64 v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return pair(v1, v2);
  }
};

struct AC_auto {
  vector<array<int, 26>> trie;
  vector<int> fail, cnt, pass;
  vector<int> q;
  int tot;

  AC_auto(int n = 1) : tot(0) {
    trie.assign(n + 1, {});
    fail.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    pass.assign(n + 1, 0);
    q.assign(n + 1, 0);
  }

  void insert(const string& s) {
    int u = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (!trie[u][c]) {
        trie[u][c] = ++tot;
        if (tot >= (int)trie.size()) {
          trie.resize(tot * 2);
          fail.resize(tot * 2);
          cnt.resize(tot * 2);
          pass.resize(tot * 2);
          q.resize(tot * 2);
        }
      }
      u = trie[u][c];
    }
    cnt[u]++;
  }

  void build() {
    int p1 = 0, p2 = -1;
    for (int c = 0; c < 26; c++) {
      int v = trie[0][c];
      if (v) {
        fail[v] = 0;
        q[++p2] = v;
      }
    }
    while (p1 <= p2) {
      int u = q[p1++];
      for (int c = 0; c < 26; c++) {
        int& v = trie[u][c];
        if (v) {
          fail[v] = trie[fail[u]][c];
          q[++p2] = v;
        } else {
          v = trie[fail[u]][c];
        }
      }
    }
  }

  int ask(const string& t) {
    int u = 0, res = 0;

    for (char ch : t) {
      u = trie[u][ch - 'a'];
      pass[u]++;
    }
    for (int i = tot - 1; i >= 0; i--) {
      int u = q[i];
      pass[fail[u]] += pass[u];
    }
    for (int i = 1; i <= tot; i++) {
      if (cnt[i] and pass[i]) res++;
    }
    return res;
  }

  vector<int> traverse(const string& t) {
    int u = 0;
    vector<int> node(t.size());
    for (int i = 0; i < (int)t.size(); i++) {
      u = trie[u][t[i] - 'a'];
      node[i] = u;
    }
    return node;
  }

  void clear() {
    memset(trie[0].data(), 0, 26 * sizeof(int));
    for (int i = 1; i <= tot; i++) {
      fail[i] = cnt[i] = pass[i] = 0;
      memset(trie[i].data(), 0, 26 * sizeof(int));
    }
    tot = 0;
  }
};

struct PairHash {
  size_t operator()(const pair<u64, u64>& p) const {
    return p.first ^ (p.second << 17) ^ (p.second >> 47);
  }
};

static const int N = 1e6 + 10;

AC_auto acma(N);

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  vector<StrHash> hash(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    hash[i] = StrHash(a[i]);
  }

  int ans = 0;

  // sz(t) < sz(s1) and sz(t) < sz(s2)
  int mx_len = 0;
  unordered_map<int, unordered_map<pair<u64, u64>, int, PairHash>> pre;
  for (int i = 0; i < n; i++) {
    int e = a[i].size();
    for (int len = 1; len <= e; len++) {
      auto h = hash[i].get(e - len + 1, e);
      ans += pre[len][h]; 
    }
    for (int len = 1; len <= e; len++) {
      pre[len][hash[i].get(1, len)]++;
    }
  }

  // sz(t) > sz(s1) and sz(t) < sz(s2)
  for (int i = 0; i < n; i ++) {
    acma.insert(a[i]);
  }

  acma.build();

  // build 之后，q[0..tot-1] 是 fail 树的拓扑序(浅的在前)
  vector<int> chain_cnt(acma.tot + 1, 0);
  for (int i = 0; i < acma.tot; i++) {
    int u = acma.q[i];
    chain_cnt[u] = chain_cnt[acma.fail[u]] + acma.cnt[u];
  }

  vector<vector<int>> ns;
  for (int j = 0; j < n; j++) {
    auto& s = a[j];
    int m = s.size();
    vector<int> nxt(m);
    for (int i = 1, k = 0; i < m; i++) {
      while (k > 0 and s[k] != s[i]) {
        k = nxt[k - 1];
      }
      k += s[k] == s[i];
      nxt[i] = k;
    }

    ns.push_back(nxt);
    vector<int> node(m + 1, 0);
    int u = 0;
    for (int i = 0; i < m; i++) {
      u = acma.trie[u][s[i] - 'a'];
      node[i + 1] = u;
    }

    for (int B = nxt[m - 1]; B; B = nxt[B - 1]) {
      ans += chain_cnt[node[m - B]];
    }
  }

  // sz(t) > sz(s1) and sz(t) > sz(s2)
  vector<vector<int>> B(n);
  for (int i = 0; i < n; i ++) {
    int len = a[i].size();
    int k = ns[i][len - 1];
    while (k > 0) {
      B[i].push_back(k);
      k = ns[i][k - 1];  
    }
  } 

  unordered_map<int, unordered_map<pair<u64, u64>, int, PairHash>> suf;
  for (int i = 0; i < n; i ++) {
    int len = (int)a[i].size();
    for (auto& b : B[i]) {
      int X = (int)a[i].size() - b;
      auto h = hash[i].get(1, X);
      ans += suf[X][h];
    }

    for (auto& b : B[i]) {
      int X = (int)a[i].size() - b;
      suf[X][hash[i].get(b + 1, len)]++;
    } 
  }

  cout << ans + n * (n - 1) / 2 << "\n";
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