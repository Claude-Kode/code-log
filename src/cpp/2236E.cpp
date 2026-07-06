#ifdef __GNUC__
// #pragma GCC optimize("fast-math")
#pragma GCC optimize("Ofast, unroll-loops = full")
#pragma GCCtarget("avx, avx2")
#endif

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

using arr = array<int, 6001>;

// arr operator+(const arr& a, const arr& b) {
//   arr res;
//   for (int i = 0; i < 6001; i++) {
//     res[i] = a[i] + b[i];
//   }
//   return res;
// }

// arr& operator+=(arr& a, const arr& b) {
//   for (int i = 0; i < 6001; i++) {
//     a[i] += b[i];
//   }
//   return a;
// }

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  for (int len = n / 2; len >= 0; len --) {
    if (!len) {
      cout << 0 << "\n";
      return; 
    }
    
    unordered_map<int, int> mxs, mns;  
    arr buc = {};
    int cnt = 0;

    auto cmp1 = [](const pair<int, int>& p1, const pair<int, int>& p2) {
      return p1.first > p2.first;  
    };
    
    auto cmp2 = [](const pair<int, int>& p1, const pair<int, int>& p2) {
      return p1.first < p2.first;  
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)>
        pq1(cmp1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp2)>
        pq2(cmp2);

    auto add = [&](int i) {
      if (buc[vec[i]] ++ == 0) cnt ++;
      pq1.push({vec[i], i});
      pq2.push({vec[i], i});
    };

    auto remo = [&](int i) {
      int v = vec[i];
      if (-- buc[v] == 0) cnt --;
    };

    for (int i = 1; i <= len; i ++) {
      add(i);
    }

    for (int i = 1; i + len - 1 <= n; i ++) {
      int l = i, r = l + len - 1;
      if (cnt == len) {
        while (!pq1.empty() and pq1.top().second < l) pq1.pop();
        while (!pq2.empty() and pq2.top().second < l) pq2.pop();

        int mn = pq1.top().first;
        int mx = pq2.top().first;

        if (mx - mn + 1 == len) {

          if (mxs.count(mn - 1) and mxs[mn - 1] <= i - len) {
            cout << len << "\n";
            return;
          }

          if (mns.count(mx + 1) and mns[mx + 1] <= i - len) {
            cout << len << "\n";
            return;
          }

          if (!mxs.count(mx)) mxs[mx] = i;
          if (!mns.count(mn)) mns[mn] = i;
        }
      }

      if (r + 1 <= n) {
        remo(l);
        add(r + 1);
      }
    }
  }

  cout << 0 << "\n";
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

// dbug(vec);

// vector<Info> seg(n << 2 | 1);
// auto pull = [&](int p) -> void {
//   seg[p] = seg[p << 1] + seg[p << 1 | 1];
// };

// auto build = [&](auto&& sef, int p, int l, int r) -> void {
//   if (l == r) {
//     seg[p].buc[vec[l]]++;
//   } else {
//     int m = (l + r) / 2;
//     sef(sef, p << 1, l, m);
//     sef(sef, p << 1 | 1, m + 1, r);
//     pull(p);
//   }
// };

// auto ask = [&](auto&& sef, int p, int l, int r, int L, int R) -> arr {
//   if (L <= l and r <= R) {
//     return seg[p];
//   } else {
//     int m = (l + r) / 2;
//     arr res = {};
//     if (L <= m) res += sef(sef, p << 1, l, m, L, R);
//     if (m < R)  res += sef(sef, p << 1 | 1, m + 1, r, L, R);
//     return res;
//   }
// };

// build(build, 1, 1, n);
