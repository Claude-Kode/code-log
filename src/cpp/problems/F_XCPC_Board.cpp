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
  int n, p, m; cin >> n >> p >> m;

  auto check = [&](string s) -> bool {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s == "ac" || s == "accepted"; 
  };

  vector<vector<vector<array<int, 2>>>> vec(n + 1, 
  vector<vector<array<int, 2>>> (p + 1));
  for(int i = 1; i <= m; i ++) {
    int tim, id, qid; string res; 
    cin >> tim >> id >> qid >> res;
    vec[id][qid].push_back(array<int, 2>{tim, check(res)});
  }

  unordered_map<int, int> tim, solved;
  for(int i = 1; i <= n; i ++) { // 当前人
    for(int q = 1; q <= p; q ++) { // 当前问题
      sort(vec[i][q].begin(), vec[i][q].end(), [&](const auto& a, const auto& b) {
        return a[0] < b[0];
      });

      bool ac = 0; int cur_tim = 0;
      for(const auto& [tim, res] : vec[i][q]) {
        if (!res) cur_tim += 20;
        else {cur_tim += tim, ac = true; break;}
      }

      if (ac) tim[i] += cur_tim, solved[i] ++;

    }
  }

  vector<int> ans(n + 1);
  iota(ans.begin(), ans.end(), 0LL);
  sort(ans.begin() + 1, ans.end(), [&](const int& a, const int& b) {
    if (solved[a] != solved[b]) return solved[a] > solved[b];
    else if (tim[a] != tim[b]) return tim[a] < tim[b];
    else return a < b;
  });

  for(int i = 1; i <= n; i ++) {
    cout << ans[i] << ' ' << solved[ans[i]] << ' ' << tim[ans[i]] << endl;
  }

}

/*
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