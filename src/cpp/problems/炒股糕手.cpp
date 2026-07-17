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
  int n; cin >> n;
  unordered_map<string, int> val;
  unordered_map<string, vector<array<int, 3>>> infor;
  for(int i = 1; i <= n; i ++) {
    string temp; cin >> temp;
    int s, t, w; cin >> s >> t >> w;
    val[temp] += (t - s + 1) * w;
    infor[temp].push_back({s, t, w});
  }

  int mx = INT_MIN; string str = "ZZZZZZZZZ";
  for(const auto &[s, v] : val) {
    if (mx < v) mx = v, str = s;
    else if (mx == v) str = min(str, s);
  }

  int m = 0;
  for(const auto &[s, t, w] : infor[str]) m = max(m, t);
  vector<int> diff(m + 1); int pre = 0;
  for(const auto &[s, t, w] : infor[str]) {
    diff[s] += w; diff[t + 1] -= w;
  }

  cout << str << endl;
  for(int i = 1; i <= m; i ++) {
    diff[i] += diff[i - 1];
    cout << diff[i] << " ";
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