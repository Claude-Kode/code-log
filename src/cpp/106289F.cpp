// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, q; cin >> n >> q;
  vector<int> vec(n + 1);
  map<int, int> mp;
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
    mp[vec[i]] = i;
  }

  int m = mp.size();
  vector<int> a(1);
  for(const auto &[k, v] : mp) {
    a.push_back(k);
  }

  sort(vec.begin() + 1, vec.end());
  vector<int> dp(n + 1);
  unordered_map<int, int> qs;
  for(int i = n - 1; i > 0; i --) {
    dp[i] = dp[i + 1] + (vec[i + 1] - vec[i]) * (n - i);
    qs[vec[i]] = dp[i];
  }

  auto check = [&](int t, int x) -> bool {
    // int cost = 0;
    // for(int i = 1; i <= n; i ++) {
    //   if (vec[i] > a[t]) cost += vec[i] - a[t];
    // }
    // return cost <= x;
    return qs[a[t]] <= x;
  };

  // dbug(mp);
  // dbug(a);

  vector<int> b(m + 1); b[m] = mp[a[m]];
  for(int i = m - 1; i > 0; i --) {
    b[i] = max(b[i + 1], mp[a[i]]);
  }

  while(q --) {
    int x; cin >> x;
    int l = 1, r = m, ans = l;
    while(l <= r) {
      int mid = (l + r) / 2;
      if (check(mid, x)) r = mid - 1, ans = mid;
      else l = mid + 1;
    }

    cout << b[ans] << '\n';
  }
} 

/*
对于每个频率 我们只存最大的那个索引作为答案即可
二分查最低频率, 高于当前频率的最大值
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