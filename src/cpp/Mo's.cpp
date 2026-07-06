// @Author : GoryK
#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

#define int long long

template <typename T>
using Ost =
    tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  vector<array<int, 3>> query(m + 1);
  for (int i = 1; i <= m; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    query[i] = {l, r, k};
  }

  int block = sqrt(n);
  auto to = [&](int i) -> int { return (i - 1) / block + 1; };

  vector<int> idx(m + 1);
  iota(idx.begin() + 1, idx.end(), 1);

  sort(idx.begin() + 1, idx.end(), [&](const int& i, const int& j) {
    int blk_a = to(query[i][0]), blk_b = to(query[j][0]);
    if (blk_a != blk_b)
      return blk_a < blk_b;
    else
      return (blk_a & 1 ? query[i][1] < query[j][1] 
                        : query[i][1] > query[j][1]);
  });

  Ost<pair<int, int>> ost;

  auto add = [&](int i) -> void { 
    ost.insert({vec[i], i}); 
  };

  auto remo = [&](int i) -> void { 
    ost.erase({vec[i], i}); 
  };

  vector<int> ans(m + 1);
  int cur_l = 1, cur_r = 0;

  for (int q = 1; q <= m; q++) {
    int i = idx[q];
    int l = query[i][0], r = query[i][1], k = query[i][2];

    while (cur_r < r) add(++cur_r);
    while (cur_l > l) add(--cur_l);
    while (cur_l < l) remo(cur_l++);
    while (cur_r > r) remo(cur_r--);

    auto it = ost.find_by_order(k - 1);
    ans[i] = it->first;
  }

  for (int i = 1; i <= m; i++) {
    cout << ans[i] << " \n"[i == m];
  }
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