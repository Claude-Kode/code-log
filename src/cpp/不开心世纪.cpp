// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, m; cin >> n >> m;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i++) cin >> vec[i];

  unordered_map<int, int> f, e;
  for(int i = 1; i <= n; i ++) {
    if (!f[vec[i]] && vec[i] <= m) f[vec[i]] = i;
  }

  for(int i = n; i > 0; i --) {
    if (!e[vec[i]] && vec[i] <= m) e[vec[i]] = i;
  }

  cout << "f: " << endl;
  for (const auto&[k, v] : f) {
    cout << k << ' ' << v << endl; 
  }
  cout << endl;
  
  cout << "e: " << endl;
  for (const auto&[k, v] : e) {
    cout << k << ' ' << v << endl; 
  }
  cout << endl;


  set<int> s; vector<int> val(n + 1);
  for(int i = 1; i <= n; i ++) {
    if (f[vec[i]] == i) s.insert(vec[i]);
    if (vec[i] <= m) val[i] = s.size();
    if (e[vec[i]] == i) s.erase(vec[i]);
  }

  cout << "VAL: \n";
  for(int i = 1; i <= n; i ++) {
    cout << val[i] << " \n"[i == n];
  }

  if (ranges::max(val) < m) {cout << -1 << endl; return; }  
  vector<int> a, b;
  for(int i = 1; i <= n; i ++) {
    if (val[i] == m) a.push_back(i);
    if (val[i] == 1) b.push_back(i);
  }

  ranges::sort(a);
  ranges::sort(b);

  int ans = INT_MAX;
  for(const auto &x : a) {
    auto it1 = lower_bound(b.begin(), b.end(), x);
    auto it2 = upper_bound(b.begin(), b.end(), x);
    if (it1 != b.end()) ans = min(ans, abs(x - *it1 + 1) - m);
    if (it2 != b.end()) ans = min(ans, abs(*it2 - x + 1) - m);

    cout << "infor: \n";
    if (it1 != b.end()) cout << x << ' ' << *it1 << ' '; 
    // if (it2 != b.end()) cout << *it2 << endl; 
  }

  // cout << ans << endl; 
}
/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}