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

map<int, vector<string>> mp;

void insert(const string& s, int i) {
  int u = 0, m = s.size();
  for (int i = 0; i < m; i++) {
    int c = s[i] - 'a';
    if (trie[u][c] == 0) trie[u][c] = ++tot;
    u = trie[u][c];
  }
  cnt[u]++;
  mp[u].push_back(s);
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

pair<int, vector<int>> ask(const string& t) {
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

  int mx = 0;
  vector<int> res;
  for (int i = 1; i <= tot; i ++) {
    if (cnt[i] and mx < pass[i]) {
      mx = max(mx, pass[i]);
    }
  }

  for (int i = 1; i <= tot; i++) {
    if (pass[i] == mx) {
      res.push_back(i);
    }
  }

  return pair(mx, res);
}

void solve(int n) {

  for (int i = 0; i <= tot; i ++) {
    cnt[i] = fail[i] = pass[i] = q[i] = 0;
    for (int j = 0; j < 26; j++) {
      trie[i][j] = 0;
    }
  }

  tot = 0; mp.clear();

  for (int i = 1; i <= n; i ++) {
    string s; cin >> s;
    insert(s, i);
  }

  build();
  string t; cin >> t;
  auto [mx, idx]= ask(t);
  cout << mx << "\n";
  // dbug(mx, idx, mp);
  for (auto& i : idx) {
    for (auto& x : mp[i]) {
      cout << x << "\n";
    }
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  int n; 
  while (cin >> n and n > 0) {
    // dbug(n);
    // std::cout << "TEST CASE : " << _ << endl,
    solve(n);
  }

  return 0;
} 