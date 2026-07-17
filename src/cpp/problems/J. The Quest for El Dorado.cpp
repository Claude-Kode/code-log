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

const int INF = LLONG_MAX;

struct ST {
  int n;
  vector<vector<int>> f;

  ST() : n(0){}                  
  ST(const vector<int>& a) {
    n = (int)a.size();
    if (n == 0) return;         
    int K = __lg(n) + 1;
    f.assign(K, vector<int>(n));
    f[0] = a;
    for (int k = 1; k < K; k ++) {
      for (int i = 0; i + (1 << k) <= n; i ++) {
        f[k][i] = max(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
      }
    }

  }

  int ask(int l, int r) {
    int k = __lg(r - l + 1);
    return max(f[k][l], f[k][r - (1 << k) + 1]);
  }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<tuple<int, int, int>>> g(n + 1);
  for (int i = 1; i <= m; i ++) {
    int u, v, c, w;
    cin >> u >> v >> c >> w;
    g[u].emplace_back(v, c, w);
    g[v].emplace_back(u, c, w);
  }

  vector<vector<int>> color_ids(m + 2);      
  vector<vector<int>> color_w(m + 2);        
  vector<ST> color_st(m + 2);                
  vector<pair<int, int>> tick(k + 1);   
  for (int i = 1; i <= k; i ++) {
    cin >> tick[i].first >> tick[i].second;  
    int c = tick[i].first, w = tick[i].second;
    color_ids[c].push_back(i);
    color_w[c].push_back(w);
  }

  for (int c = 1; c <= m + 1; c ++) {
    if (!color_w[c].empty()) {
      color_st[c] = ST(color_w[c]);
    }
  }

  auto next_tick = [&](int c, int idx, int need) -> int {
    auto& ids = color_ids[c];
    auto& st = color_st[c];
    // 这里有可能是空的, 要判断一下哦
    if (ids.empty()) return -1;
    int L = upper_bound(ids.begin(), ids.end(), idx) - ids.begin();
    if (L >= st.n || st.ask(L, st.n - 1) < need) {
      return -1;
    }
    int l = L, r = st.n - 1, ans = l;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (st.ask(L, mid) >= need) r = mid - 1, ans = mid;
      else l = mid + 1;
    }
    return ids[ans];
  };

  vector<pair<int, int>> dis(n + 1, {INF, INF});
  using TUP = tuple<int, int, int>;  
  priority_queue<TUP, vector<TUP>, greater<TUP>> pq;
  pq.emplace(1, 0, 1);                
  dis[1] = {1, 0};

  while (!pq.empty()) {
    auto [idx, used, u] = pq.top();
    pq.pop();
    if (pair(idx, used) != dis[u]) continue;  
    if (idx > k) continue;

    for (auto& [v, c, w] : g[u]) {
      if (tick[idx].first == c and used + w <= tick[idx].second) {
        pair nd(idx, used + w);
        if (nd < dis[v]) {
          dis[v] = nd;
          pq.emplace(idx, used + w, v);
        }
      }

      int nr = next_tick(c, idx, w);
      if (nr != -1) {
        pair nd(nr, w);
        if (nd < dis[v]) {
          dis[v] = nd;
          pq.emplace(nr, w, v);
        }
      }
    }
  }

  for (int i = 1; i <= n; i ++)
    cout << (dis[i].first != INF);
  cout << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}