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

const int N = 1e6 + 10;

int fail[N], cnt[N], pass[N], q[N];
int trie[N][26];

// 目前 trie 里面的节点总数量(节点编号 1-based)
int tot = 0;

map<int, int> node;

void insert(const string& s, int i) {
  int u = 0, m = s.size();
  for (int i = 0; i < m; i++) {
    int c = s[i] - 'a';
    if (trie[u][c] == 0) trie[u][c] = ++tot;
    u = trie[u][c];
  }
  cnt[u]++; 
  node[i] = u;
}

void build() {
  int p1 = 0, p2 = -1;
  for (int c = 0; c < 26; c++) { 
    int& v = trie[0][c];
    if (v) {
      q[++p2] = v;
    } 
  }

  while(p1 <= p2) {
    int u = q[p1++];
    for (int c = 0; c < 26; c++) {
      int& v = trie[u][c];
      if (v) {
        q[++p2] = v;
        fail[v] = trie[fail[u]][c];
      } else {
        v = trie[fail[u]][c];
      }
    }
  }
}

unordered_map<int, int> ask(const string& t) {
  int u = 0;
  for (char ch : t) {
    int c = ch - 'a';
    u = trie[u][c];
    pass[u]++;
  }

  for (int i = tot - 1; i >= 0; i --) {
    int u = q[i];
    pass[fail[u]] += pass[u];
  }

  unordered_map<int, int> res;
  for (int i = 1; i <= tot; i ++) {
    if (cnt[i]) {
      res[i] = pass[i];
    }
  }

  return res;
}

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

  void insert(const string &s) {
    int u = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (!trie[u][c]) {
        trie[u][c] = ++ tot;
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
    cnt[u] ++;
  }

  void build() {
    int p1 = 0, p2 = -1;
    for (int c = 0; c < 26; c ++) {
      int v = trie[0][c];
      if (v) {
        fail[v] = 0;
        q[++ p2] = v;
      }
    }
    while (p1 <= p2) {
      int u = q[p1 ++];
      for (int c = 0; c < 26; c ++) {
        int &v = trie[u][c];
        if (v) {
          fail[v] = trie[fail[u]][c];
          q[++ p2] = v;
        } else {
          v = trie[fail[u]][c];
        }
      }
    }
  }

  int ask(const string &t) {
    int u = 0, res = 0;

    for (char ch : t) {
      u = trie[u][ch - 'a'];
      pass[u] ++;
    }
    for (int i = tot - 1; i >= 0; i --) {
      int u = q[i];
      pass[fail[u]] += pass[u];
    }
    for (int i = 1; i <= tot; i ++) {
      if (cnt[i] and pass[i]) res ++;
    }
    return res;
  }

  void clear() {
    memset(trie[0].data(), 0, 26 * sizeof(int));
    for (int i = 1; i <= tot; i ++) {
      fail[i] = cnt[i] = pass[i] = 0;
      memset(trie[i].data(), 0, 26 * sizeof(int));
    }
    tot = 0;
  }
};

void solve () {
  int n; cin >> n;
  for (int i = 0; i <= tot; i ++) {
    cnt[i] = fail[i] = pass[i] = q[i] = 0;
    for (int j = 0; j < 26; j++) {
      trie[i][j] = 0;
    }
  }

  tot = 0; node.clear();

  for (int i = 1; i <= n; i ++) {
    string s; cin >> s;
    insert(s, i);
  }

  build();
  string t; cin >> t;
  auto ans = ask(t);

  for (int i = 1; i <= n; i++) {
    cout << ans[node[i]] << "\n";
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_) {
    // dbug(n);
    // std::cout << "TEST CASE : " << _ << endl,
    solve();
  }

  return 0;
} 