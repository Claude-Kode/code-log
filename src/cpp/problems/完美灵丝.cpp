// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename F>
struct ST {
  vector<vector<int>> st;
  F combine;

  ST(const vector<int>& a, F f) : combine(f) {
    int n = (int)a.size() - 1, k = __lg(n);
    st.assign(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int j = 1; j <= k; j++)
      for (int i = 1; i + (1 << j) - 1 <= n; i++)
        st[j][i] = combine(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }

  int query(int l, int r) {
    int j = __lg(r - l + 1);
    return combine(st[j][l], st[j][r - (1 << j) + 1]);
  }
};

void solve() {
  int n, k, d;
  cin >> n >> k >> d;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  // 稀疏表
  int lg = __lg(n);
  vector st_max(lg + 1, vector<int>(n + 1));
  vector st_min(lg + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) st_max[0][i] = st_min[0][i] = a[i];
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st_max[j][i] = max(st_max[j - 1][i], st_max[j - 1][i + (1 << (j - 1))]);
      st_min[j][i] = min(st_min[j - 1][i], st_min[j - 1][i + (1 << (j - 1))]);
    }
  }

  auto ask_max = [&](int l, int r) { int j = __lg(r - l + 1); return max(st_max[j][l], st_max[j][r - (1 << j) + 1]); };
  auto ask_min = [&](int l, int r) { int j = __lg(r - l + 1); return min(st_min[j][l], st_min[j][r - (1 << j) + 1]); };

  unordered_map<int, int> lst;
  ordered_set<int> pos;
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    if (lst.count(a[i])) {
      pos.erase(pos.find(lst[a[i]]));
    }
    lst[a[i]] = i;
    pos.insert(i);

    int cnt = lst.size();
    if (cnt < k) continue;

    int L = (cnt == k ? 1 : *pos.find_by_order(cnt - k - 1) + 1);
    int R = (k == 0 ? i : *pos.find_by_order(cnt - k));

    // 二分找满足极差约束的最左左端点
    int l = 1, r = i, range_L = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ask_max(mid, i) - ask_min(mid, i) <= d) r = mid - 1, range_L = mid;
      else l = mid + 1;
    }

    L = max(L, range_L);
    if (L <= R) ans += R - L + 1;
  }

  cout << ans << "\n";
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

