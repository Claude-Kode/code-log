// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

class Trie {
private :
  int n, cnt_node;
  vector<int> cnt;
  vector<array<int, 64>> trie;

public :
  Trie (int _n = 0) : n(_n), cnt_node(0LL) {cnt.assign(n + 1, 0); trie.assign(n + 1, {});}

  static int to(char c) {
    if (c <= '9') return c - '0';
    if (c <= 'Z') return c - 'A' + 10;
    if (c <= 'z') return c - 'a' + 36;
  }

  void insert(string s) {
    int len = s.size(), p = 0;
    for(int i = 0; i < len; i ++) {
      int c = to(s[i]);
      if (!trie[p][c]) trie[p][c] = ++ cnt_node; 
      p = trie[p][c];
    }
    cnt[p] ++;
  }

  int query(string s) {
    int len = s.size(), p = 0, res = 0;
    for(int i = 0; i < len; i ++) {
      int c = to(s[i]);
      if (!trie[p][c]) break;
      p = trie[p][c]; res += cnt[p];
    }
    return res;
  }
};

Trie t(N);

void solve() { 
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i ++) {
    string s; cin >> s;
    t.insert(s);  
  }

  for(int i = 1; i <= m; i ++) {
    string q; cin >> q;
    cout << t.query(q) << endl; 
  }
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}
