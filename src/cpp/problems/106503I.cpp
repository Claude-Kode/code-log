// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define arr array<int, 2>
#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      char c; cin >> c;
      g[i][j] = (c == '*');
    }
  }

  vector<vector<int>> pre(n + 1, vector<int>(m + 1)), suf(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      pre[i][j] = pre[i][j - 1];
      if (!g[i][j]) pre[i][j] = j;
    }

    suf[i][m] = (g[i][m] == 0 ? m : m + 1);
    for (int j = m - 1; j > 0; j --) {
      suf[i][j] = suf[i][j + 1];
      if (!g[i][j]) suf[i][j] = j;
    }
  }

  // dbug(g);
  // dbug(pre);
  // dbug(suf);

  vector<vector<arr>> infor;
  auto work = [&](int j, int s, int t) -> void {
    vector<arr> v;
    for (int i = s; i <= t; i ++) {
      int l = j - pre[i][j] - 1,
          r = suf[i][j] - j - 1;
      int len = 2 * min(l, r) + 1;
      if (len < 3) continue;
      // cout << "infor: " << i << ' ' << j << ' ' << len << " ";
      // cout << "INFOR: " << l << ' ' << r << "\n";
      v.push_back(arr{i - s, len});
    }
    if (v.size()) infor.push_back(v);
  };

  for (int j = 1; j <= m; j ++) {
    for (int i = 1; i <= n; i ++) {
      if (!g[i][j]) continue;
      int s = i, t = i;
      while (t + 1 <= n && g[t + 1][j]) t ++;
      if (t - s > 1) work(j, s, t);
      i = t;
    }
  }

  auto f = [&](int x) -> int {
    return (x - 3) / 2 + 1;
  };

  int ans = 0;
  for (const auto &v : infor) {
    std::map<int, int> mp;
    for (int i = 0; i < v.size(); i ++) {
      mp[f(v[i][1])] ++;
    } 

    auto t = vector<pair<int, int>>(mp.begin(), mp.end());
    for (int i = 0; i < t.size(); i ++) {
      int x = t[i].second;
      ans += t[i].first * (x * (x - 1) / 2);
      for (int j = i + 1; j < t.size(); j ++) {
        ans += t[i].first * (t[i].second * t[j].second);
      }
    }

    for (int i = 1; i < v.size(); i ++) {
      int diff = v[i][0] - v[i - 1][0];
      assert(diff > 0);
      if (diff > 1) continue;
      ans -= f(min(v[i][1], v[i - 1][1]));
    }
  }

  // for (const auto &v : infor) {
  //   for (const auto &[k, v] : v) {
  //     cout << k << ' ' << v << "\n";
  //   }
  // }

  cout << ans << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0; 
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif

// void solve() {
//   int n, m;
//   cin >> n >> m;
//   vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {
//       char c; cin >> c;
//       g[i][j] = (c == '*');
//     }
//   }

//   vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0)),
//                       suf(n + 1, vector<int>(m + 2, m + 1));

//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {
//       pre[i][j] = pre[i][j - 1];
//       if (!g[i][j]) pre[i][j] = j;
//     }

//     for (int j = m; j >= 1; j--) {
//       suf[i][j] = suf[i][j + 1];
//       if (!g[i][j]) suf[i][j] = j;
//     }
//   }

//   vector<vector<array<int, 2>>> infor;
//   auto work = [&](int j, int s, int t) -> void {
//     vector<array<int, 2>> v;
//     for (int i = s; i <= t; i++) {
//       int p1 = pre[i][j], p2 = suf[i][j];
//       int len = min(p2 - j, j - p1) * 2 - 1;
//       if (len >= 3) v.push_back({i - s, len});
//     }
//     if (v.size()) infor.push_back(v);
//   };

//   for (int j = 1; j <= m; j++) {
//     for (int i = 1; i <= n; i++) {
//       if (!g[i][j]) continue;
//       int s = i, t = i;
//       while (t <= n && g[t][j]) t++;
//       t--;
//       if (t - s + 1 < 3) continue;
//       work(j, s, t);
//       i = t; 
//     }
//   }

//   int ans = 0;
//   for (const auto& v : infor) {
//     map<int, int> mp;
//     int sz = v.size();
//     for (int i = 0; i < sz; i++) {
//       mp[(v[i][1] - 3) / 2 + 1]++;
//     }

//     vector<array<int, 2>> tmp;
//     for (auto [k, cnt] : mp) {
//       tmp.push_back({k, cnt});
//     }
//     for (int i = 0; i < tmp.size(); i++) {
//       int k1 = tmp[i][0], v1 = tmp[i][1];
//       ans += k1 * (v1 * (v1 - 1) / 2);
//       for (int j = i + 1; j < tmp.size(); j++) {
//         int k2 = tmp[j][0], v2 = tmp[j][1];
//         ans += v1 * v2 * k1;
//       }
//     }

//     for (int i = 1; i < sz; i++) {
//       if (v[i][0] - v[i - 1][0] > 1) continue;
//       ans -= (min(v[i][1], v[i - 1][1]) - 3) / 2 + 1;
//     }
//   }

//   cout << ans << "\n";
// }

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   int tt = 1, C = 0;
//   std::cin >> tt;
//   while (tt-- && ++C)
//     // std::cout << "TEST CASE : " << C << endl,
//     solve();

//   return 0;
// }

