#include <bits/stdc++.h>
#define int long long 

int32_t main() {
  int tt; 
  std::cin >> tt;
  while (tt --) {
    int n, k; 
    std::cin >> n >> k;
    std::vector<int> vec(n + 1);
    for (int i = 1; i <= n; i ++) {
      std::cin >> vec[i];
    }

    auto cmp = [&](const auto &a, const auto &b) -> bool {
      return vec[a] < vec[b];
    };

    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
    std::map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
      pq.push(i);
      if (i < k) continue;
      while (mp[pq.top()]) pq.pop();
      std::cout << vec[pq.top()] << " \n"[i == n];
      mp[i - k + 1] = 1;
    }
  }

  return 0;
}