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

const int N = 10;

vector<vector<int>> C;

void generate_c(int n) {
  C.assign(n + 1, vector<int>(n + 1, 0));
  for (int i = 1 ; i <= n ; i ++) { 
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j ++ ) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

int cmb(int n, int k) {
  if (k < 0 || k > n) return 0;
  return C[n][k];
}

int fp(int x, int p) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) res *= base;
    base *= base , p >>= 1 ;
  }
  return res ; 
}

void solve() {
  string L, R;
  cin >> L >> R;
  
  L = to_string(stoll(L) - 1);

  map<tuple<bool, int, int, string>, int> memo;
  auto dfs = [&](this auto&& dfs, bool f, int pos, int cnt, string& s) -> int {
    if (cnt == 0) return 1;
    if (pos == s.size()) return 1;

    auto key = make_tuple(f, pos, cnt, s);
    if (memo.count(key)) {
      return memo[key];
    }

    int res = 0;
    if (f) {
      for (int i = 0; i <= s[pos] - '0'; i ++) {
        res += dfs(f and i == s[pos] - '0', pos + 1, cnt - (i > 0), s);
      }
    } else {
      for (int i = 0; i <= cnt; i ++) {
        res += fp(9, i) * cmb(s.size() - pos, i);
      }
    }

    return memo[key] = res;
  };  

  cout << dfs(1, R.size() - 1, 3, R) - dfs(1, L.size() - 1, 3, L) << "\n";
} 


int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
   
  generate_c(100);

  // cout << fixed << setprecision(5);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}
