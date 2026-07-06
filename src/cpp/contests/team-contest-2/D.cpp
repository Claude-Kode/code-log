#include <bits/stdc++.h>
using namespace std;

#define int long long 

int cnt_node = 0;
int N = 1e7 + 1;
vector<int> cnt(N);
vector<array<int, 2>> trie(N, {0, 0});

string bit(int x) {
  return bitset<30>(x).to_string();
}

void insert(int num) {
  int p = 0;
  for (int i = 30; i >= 0; i --) {
    int c = (num >> i) & 1;
    if (!trie[p][c]) {
      trie[p][c] = ++cnt_node;
    }
    p = trie[p][c];
    cnt[p] ++;
  }
}

void del(int num) {
  int p = 0;
  vector<int> v;
  int lp = 0;
  for (int i = 30; i >= 0; i --) {
    int c = (num >> i) & 1;
    lp = p;
    p = trie[p][c];
    // v.push_back(p);
    if (!--cnt[p]) {
      trie[lp][c] = 0;
    }
  }

}

int ask (int num) {
  int p = 0; string s;
  for (int i = 30; i >= 0; i --) {
    int c = (num >> i) & 1;
    if (trie[p][c ^ 1]) {
      p = trie[p][c ^ 1];
      s += (c ^ 1) + '0';
    } else {
      p = trie[p][c];
      s += c + '0';
    }
  }
  
  // cout << s << "\n";
  int res = 0;
  for (int i = s.size() - 1; i >= 0; i --) {
    if (s[i] - '0') {
      // cout << i << "\n";
      res += (1LL << (30 - i));
    }
  }
  return res;
}

void solve() {
  int q; cin >> q;
  for (int i = 1; i <= q; i ++) {
    char op; 
    cin >> op;
    int x; cin >> x;
    if (op == '+') {
      insert(x);
    } else if (op == '-') {
      del(x);
    } else {
      int y = ask(x);
      // cout << x << ' ' << y << "\n";
      cout << max((x ^ y), x) << "\n";
    }
  }
}

int32_t main() {
  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }
  return 0;
}