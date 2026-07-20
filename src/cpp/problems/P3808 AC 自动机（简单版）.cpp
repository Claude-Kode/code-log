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

void insert(const string& s) {
  int u = 0, m = s.size();
  for (int i = 0; i < m; i++) {
    int c = s[i] - 'a';
    if (trie[u][c] == 0) trie[u][c] = ++tot;
    u = trie[u][c];
  }
  cnt[u]++;
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

int ask(const string& t) {
  int u = 0, res = 0;
  for (char ch : t) {
    int c = ch - 'a';
    u = trie[u][c];
    pass[u]++;
  }

  for (int i = tot - 1; i >= 0; i --) {
    int u = q[i];
    pass[fail[u]] += pass[u];
  }

  for (int i = 1; i <= tot; i ++) {
    if (cnt[i]) res += cnt[i] * (pass[i] > 0);
  }

  return res;
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i ++) {
    string s; cin >> s;
    insert(s);
  }

  build();
  string t; cin >> t;
  cout << ask(t) << "\n";
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