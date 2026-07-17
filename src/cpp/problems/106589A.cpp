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

struct Info {
  int id;
  int token;
  int r;
};

void solve() {
  int q, w; cin >> q >> w;

  map<int, int> mp1, mp2;
  map<int, int> token, tim;

  auto cmp1 = [&](const auto& a, const auto& b) -> bool {
    return (a.r != b.r ? a.r > b.r : a.id > b.id);
  };

  auto cmp2 = [&](const auto& a, const auto& b) -> bool {
    return tim[a.id] > tim[b.id];
  };

  priority_queue<Info, vector<Info>, decltype(cmp1)> pq1(cmp1);
  priority_queue<Info, vector<Info>, decltype(cmp2)> pq2(cmp2);

  int cnt = 0;
  while (q --) {
    string op; 
    cin >> op;
    if (op == "ADD") {
      int id, t, r;
      cin >> id >> t >> r;
      mp1[id] = 1;
      token[id] = t;
      tim[id] = ++cnt;
      pq1.push({id, t, r});
    } else if (op == "ASK") {
      int id; cin >> id;
      
    } else {

    }
  }
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}