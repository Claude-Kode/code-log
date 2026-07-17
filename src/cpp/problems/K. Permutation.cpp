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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rn(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

void solve() {
  int n; cin >> n;
  if (n == 1) {
    cout << 1 << ' ' << 1 << "\n";
    return;
  }

  vector<int> ans(n + 1);

  auto ask = [&](int mid, int x, int y) -> int {
    cout << 0 << " "; 
    for (int i = 1; i <= mid; i ++) cout << x << ' ';
    for (int i = mid + 1; i <= n; i ++) cout << y << ' ';
    cout.flush();
    int res; cin >> res;
    return res;
  };

  auto dfs = [&](auto && sef, int l, int r, vector<int>& v) -> void {
    if (l == r) {
      assert(v.size());
      ans[l] = v[0];
      return;
    }

    vector<int> v1, v2;
    int i = 0, mid = (l + r) / 2, lst = 0;
    shuffle(v.begin(), v.end(), rng);
    while (i < (int)v.size() - 1) {
      int res = ask(mid, v[i], v[i + 1]);
      if (res == 1) {
        i ++;
      } else {
        if (res == 2) {
          for (int j = lst; j <= i; j ++) {
            v1.push_back(v[j]);
          }
          v2.push_back(v[i + 1]);
        } else {
          for (int j = lst; j <= i; j ++) {
            v2.push_back(v[j]);
          }
          v1.push_back(v[i + 1]);
        }
        i += 2; lst = i;
      }
    }

    if (lst != (int)v.size()) {
      if ((int)v1.size() == mid - l + 1) {
        for (int j = lst; j < (int)v.size(); j ++) {
          v2.push_back(v[j]);
        }
      } else {
        for (int j = lst; j < (int)v.size(); j ++) {
          v1.push_back(v[j]);
        }
      }
    }

    sef(sef, l, mid, v1);
    sef(sef, mid + 1, r, v2);
  };

  vector<int> vec(n);
  iota(vec.begin(), vec.end(), 1LL);
  dfs(dfs, 1, n, vec);  

  cout << 1 << " ";
  for (int i = 1; i <= n; i ++) {
    cout << ans[i] << " \n"[i == n];  
  }
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
