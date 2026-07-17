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

int n, m, cnt_node; 
int t[N][64], cnt[N];

int to(char c) {
  if (c <= '9') return c - '0';
  if (c <= 'Z') return c - 'A';
  if (c <= 'z') return c - 'a';
}

void insert(string s) {
  int len = s.size(), p = 0; 
  for(int i = 0; i < len; i ++) {
    int c = to(s[i]);
    if (!t[p][c]) t[p][c] = ++cnt_node;
    p = t[p][c];
  }
  cnt[p] ++;
}

int query(string s) {
  int len = s.size(), p = 0, res = 0;
  for(int i = 0; i < len; i ++) {
    int c = to(s[i]);
    if (!t[p][c]) return res;
    p = t[p][c]; res += cnt[p];
  }
  return res;
}

void solve() { 
  cin >> n >> m;
  for(int i = 1; i <= n; i ++) {
    string str; cin >> str;
    insert(str);
  }

  for(int i = 1; i <= m; i ++) {
    string s; cin >> s;
    cout << query(s) << endl;
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