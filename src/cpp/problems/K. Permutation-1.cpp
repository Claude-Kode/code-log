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
int rn(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    return;
  }

  int mx_idx = __lg(n) + ((1 << __lg(n)) < n);
  vector<vector<pair<int, int>>> qs(mx_idx + 1);
  auto dfs = [&](auto&& self, int l, int r, int cnt) -> void {
    qs[cnt].push_back({l, r});
    if (l == r) return;
    int mid = (l + r) / 2;
    self(self, l, mid, cnt + 1);
    self(self, mid + 1, r, cnt + 1);
  };
  dfs(dfs, 1, n, 0);

  map<pair<int, int>, vector<int>> mp;
  for (int i = 1; i <= n; i++) mp[{1, n}].push_back(i);

  vector<int> bg(n + 1);
  for (int i = 1; i <= n; i++) bg[i] = mp[{1, n}][0];

  for (int d = 0; d <= mx_idx; d++) {
    int tot = (int)qs[d].size();

    for (auto [l, r] : qs[d]) {
      if (l == r) continue;
      int mid = (l + r) / 2;
      auto& vec = mp[{l, r}];

      vector<int> knownL, knownR, deferred;

      auto ask = [&](const vector<int>& qry) -> int {
        cout << 0 << " ";
        for (int i = 1; i <= n; i++) {
          if (l <= i && i <= r)
            cout << qry[i] << " ";
          else
            cout << bg[i] << " ";
        }
        cout << endl;
        int res;
        cin >> res;
        return res - (tot - 1);
      };

      while (vec.size() >= 2) {
        int i1 = rn(0, (int)vec.size() - 1), v1 = vec[i1];
        vec.erase(vec.begin() + i1);
        int i2 = rn(0, (int)vec.size() - 1), v2 = vec[i2];
        vec.erase(vec.begin() + i2);

        vector<int> qry(n + 1);
        for (int i = l; i <= mid; i++) qry[i] = v1;
        for (int i = mid + 1; i <= r; i++) qry[i] = v2;

        int match = ask(qry);

        if (match == 2) {
          knownL.push_back(v1);
          knownR.push_back(v2);
        } else if (match == 0) {
          knownL.push_back(v2);
          knownR.push_back(v1);
        } else {
          bool resolved = false;
          if (!knownR.empty()) {
            int ref = knownR[0];
            for (int i = l; i <= mid; i++) qry[i] = v1;
            for (int i = mid + 1; i <= r; i++) qry[i] = ref;
            int m = ask(qry) - 1;
            (m ? knownL : knownR).push_back(v1);
            (m ? knownL : knownR).push_back(v2);
            resolved = true;
          } else if (!knownL.empty()) {
            int ref = knownL[0];
            for (int i = l; i <= mid; i++) qry[i] = ref;
            for (int i = mid + 1; i <= r; i++) qry[i] = v2;
            int m = ask(qry) - 1;
            (m ? knownR : knownL).push_back(v1);
            (m ? knownR : knownL).push_back(v2);
            resolved = true;
          } else if (d > 0) {
            int ref_bg = -1;
            for (auto [l2, r2] : qs[d]) {
              if (l2 == l && r2 == r) continue;
              ref_bg = bg[l2];
              break;
            }
            for (int i = l; i <= mid; i++) qry[i] = v1;
            for (int i = mid + 1; i <= r; i++) qry[i] = ref_bg;
            int m = ask(qry);
            (m ? knownL : knownR).push_back(v1);
            (m ? knownL : knownR).push_back(v2);
            resolved = true;
          }
          if (!resolved) {
            deferred.push_back(v1);
            deferred.push_back(v2);
          }
        }
      }

      if (vec.size() == 1) {
        int v = vec[0];
        vec.clear();
        bool resolved = false;
        if (!knownR.empty()) {
          int ref = knownR[0];
          vector<int> qry(n + 1);
          for (int i = l; i <= mid; i++) qry[i] = v;
          for (int i = mid + 1; i <= r; i++) qry[i] = ref;
          int m = ask(qry) - 1;
          (m ? knownL : knownR).push_back(v);
          resolved = true;
        } else if (!knownL.empty()) {
          int ref = knownL[0];
          vector<int> qry(n + 1);
          for (int i = l; i <= mid; i++) qry[i] = ref;
          for (int i = mid + 1; i <= r; i++) qry[i] = v;
          int m = ask(qry) - 1;
          (m ? knownR : knownL).push_back(v);
          resolved = true;
        } else if (d > 0) {
          int ref_bg = -1;
          for (auto [l2, r2] : qs[d]) {
            if (l2 == l && r2 == r) continue;
            ref_bg = bg[l2];
            break;
          }
          vector<int> qry(n + 1);
          for (int i = l; i <= mid; i++) qry[i] = v;
          for (int i = mid + 1; i <= r; i++) qry[i] = ref_bg;
          int m = ask(qry);
          (m ? knownL : knownR).push_back(v);
          resolved = true;
        }
        if (!resolved) deferred.push_back(v);
      }

      int stuck = 0;
      while (!deferred.empty()) {
        if (++stuck > 5000) {
          for (int v : deferred) vec.push_back(v);
          deferred.clear();
          break;
        }
        if (!knownR.empty() || !knownL.empty()) {
          int v = deferred.back();
          deferred.pop_back();
          if (!knownR.empty()) {
            int ref = knownR[0];
            vector<int> qry(n + 1);
            for (int i = l; i <= mid; i++) qry[i] = v;
            for (int i = mid + 1; i <= r; i++) qry[i] = ref;
            int m = ask(qry) - 1;
            (m ? knownL : knownR).push_back(v);
          } else {
            int ref = knownL[0];
            vector<int> qry(n + 1);
            for (int i = l; i <= mid; i++) qry[i] = ref;
            for (int i = mid + 1; i <= r; i++) qry[i] = v;
            int m = ask(qry) - 1;
            (m ? knownR : knownL).push_back(v);
          }
        } else if (deferred.size() >= 2) {
          int a = deferred.back();
          deferred.pop_back();
          int b = deferred.back();
          deferred.pop_back();
          vector<int> qry(n + 1);
          for (int i = l; i <= mid; i++) qry[i] = a;
          for (int i = mid + 1; i <= r; i++) qry[i] = b;
          int match = ask(qry);
          if (match == 2) {
            knownL.push_back(a);
            knownR.push_back(b);
          } else if (match == 0) {
            knownL.push_back(b);
            knownR.push_back(a);
          } else {
            vec.push_back(a);
            vec.push_back(b);
            break;
          }
        } else {
          int v = deferred.back();
          deferred.pop_back();
          knownL.push_back(v);
        }
        if (vec.size() >= 2) break;
      }

      for (int v : knownL) mp[{l, mid}].push_back(v);
      for (int v : knownR) mp[{mid + 1, r}].push_back(v);
    }

    if (d < mx_idx) {
      for (auto [cl, cr] : qs[d + 1]) {
        if (!mp[{cl, cr}].empty()) {
          int v = mp[{cl, cr}][0];
          for (int i = cl; i <= cr; i++) bg[i] = v;
        }
      }
    }
  }

  cout << 1 << " ";
  for (int i = 1; i <= n; i++) {
    cout << mp[{i, i}][0] << " \n"[i == n];
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
