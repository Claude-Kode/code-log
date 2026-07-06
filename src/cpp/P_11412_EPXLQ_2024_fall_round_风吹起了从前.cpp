// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#include <cmath> 

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e6 + 10;

int n, m, cnt_node; 
int t[N][64];
vector<map<int, int>> infor(N + 1);

int to(char c) {
  if (c <= '9') return c - '0';
  if (c <= 'Z') return c - 'A';
  if (c <= 'z') return c - 'a';
}

void insert(string s, int d, int v) {
  int len = s.size(), p = 0;
  for(int i = 0; i < len; i ++) {
    int c = to(s[i]);
    if (!t[p][c]) t[p][c] = ++cnt_node;
    p = t[p][c];
    infor[p][d] += v;
  }
}


int query(string s, int d) {
  int len = s.size(), p = 0;
  for(int i = 0; i < len; i ++) {
    int c = to(s[i]);
    if (!t[p][c]) t[p][c] = ++cnt_node;
    p = t[p][c];
  }

  auto it = infor[p].upper_bound(d); 
  return (it == infor[p].begin() ? 0 : prev(it) -> second);
}

void solve() { 
  cin >> n >> m;
  for (int i = 1; i <= n; i ++) {
    int r, v; string s; 
    cin >> r >> v >> s;
    insert(s, r, v);
  }

  for(int i = 1; i <= cnt_node; i ++) {
    auto &mp = infor[i];
    if (mp.size() <= 1) continue; 
    for(auto it = next(mp.begin()); it != mp.end(); it ++) {
      auto pre = prev(it);
      it -> second += pre -> second;
    }
  }

  for(int i = 1; i <= m; i ++) {
    string s; int d; 
    cin >> d >> s;
    cout << query(s, d) << endl;
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