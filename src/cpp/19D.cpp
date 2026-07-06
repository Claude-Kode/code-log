// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;  

#pragma comment(linker, "/STACK:16777216")
// #define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void dedup(vector<int>& vec) { 
  sort(vec.begin(), vec.end()) ;
  vec.erase(unique(vec.begin(), vec.end()), vec.end()) ; 
}

int getId(int x, vector<int>& vec) {
  return lower_bound(vec.begin(), vec.end() , x) - vec.begin();
}

void ranked(vector<int>& vec) {
  auto temp = vec; dedup(temp);
  for(auto &x : vec) x = getId(x, temp);
}

const int N = 4 * 4e6 + 10;
// std::vector<int> seg(N + 1, -1);

void solve() {    
  int n;
  std::cin >> n;
  std::vector<array<int, 3>> vec(n + 1);

  auto to = [&](const string &s) -> int {
    if (s == "add")    return 1;
    if (s == "remove") return 2;
    if (s == "find")   return 3;
  };

  std::vector<int> vals;
  for (int i = 1; i <= n; i ++) {
    string op; int x, y; 
    std::cin >> op >> x >> y;
    vec[i] = {to(op), x, y};
    vals.push_back(x);
    vals.push_back(y);
  }

  dedup(vals);
  int sz = vals.size();
  for (int i = 1; i <= n; i ++) {
    int &x = vec[i][1], &y = vec[i][2];
    x = getId(x, vals);
    y = getId(y, vals);
  } 

  std::unordered_map<int, std::set<int>> st;
  std::vector<int> seg(sz << 2 | 1, -1);

  // for (int i = 0; i < N; i ++) seg[i] = -1;

  auto pull = [&](int p) -> void {
    seg[p] = std::max(seg[p << 1], seg[p << 1 | 1]);
  };

  auto add = [&](auto &&sef, int p, int l, int r, int x, int y) -> void {
    if (l == r) {
      st[x].insert(y);
      seg[p] = *--st[x].end();
    } else  {
      int m = (l + r) / 2;
      if (x <= m) sef(sef, p << 1, l, m, x, y); 
      else if (m < x)  sef(sef, p << 1 | 1, m + 1, r, x, y);
      pull(p);
    }
  };

  auto remo = [&](auto &&sef, int p, int l, int r, int x, int y) -> void {
    if (l == r) {
      st[x].erase(y);
      seg[p] = (st[x].empty() ? -1  : *--st[x].end());
    } else {
      int m = (l + r) / 2;
      if (x <= m) sef(sef, p << 1, l, m, x, y);
      else if (m < x)  sef(sef, p << 1 | 1, m + 1, r, x, y);
      pull(p);
    }
  };
  
  auto find = [&](auto &&sef, int p, int l, int r, int L, int R, int y) -> int {
    // L <= l && r <= R && 
    if (seg[p] <= y) {
      return INT_MAX;
    } else if (l == r) {
      return l;
    } else {
      int m = (l + r) / 2, res = INT_MAX; 
      if (L <= m) res = std::min(res, sef(sef, p << 1, l, m, L, R, y));
      if (res != INT_MAX) return res;
      if (m < R)  res = std::min(res, sef(sef, p << 1 | 1, m + 1, r, L, R, y));
      return res;
    }
  };

  for (int i = 1; i <= n; i ++) {
    int op = vec[i][0], x = vec[i][1], y = vec[i][2];
    // cout << "infor: " << op << ' ' << x << ' ' << y << "\n";
    if (op == 1) {
      add(add, 1, 1, sz, x, y);
    }

    if (op == 2) {
      remo(remo, 1, 1, sz, x, y);
    }

    if (op == 3) {
      // cout << x << ' ' << y << "\n";
      // for (const auto &v : st[3]) {
      //   cout << v << ' ';
      // } 
      int res_x = find(find, 1, 1, sz, x + 1, sz, y);
      if (res_x == INT_MAX) {
        cout << -1 << "\n";
        continue;
      }
      // cout << "Y: ";
      // for (const auto &v : st[res_x]) {
      //   cout << v << ' ';
      // } 
      // cout << "\n";
      auto res_y = st[res_x].upper_bound(y);
      // cout << "orin: " << res_x << ' ' << *res_y << "\n";
      cout << vals[res_x] << ' ' << vals[*res_y] << "\n";
    }
  }

}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0; 
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}   