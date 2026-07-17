// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 

  // auto split = [&](const string& s) -> vector<string> {
  //   vector<string> v;
  //   for(string t; getline(istringstream(s), t, '-'); v.push_back(t));
  //   return v;
  // };

  // auto f = [&](const auto& s, int i, int j) -> string {
  //   return string(s.begin() + i, s.begin() + j + 1);
  // };

  // auto cmp = [&](const string& s1, const string& s2) -> bool {

  // };
  
// , decltype(cmp)
  int n;; cin >> n;
  unordered_map<string, set<string>> ump;
  for(int i = 1; i <= n; i ++) {
    string num, p; cin >> num >> p;
    ump[p].insert(num);
  }

  int q; cin >> q;
  while(q --) {
    string name; cin >> name;
    if (!ump.count(name)) {cout << -1 << endl; continue;}
    for(const auto &s : ump[name]) {
      cout << s << endl;
    }
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