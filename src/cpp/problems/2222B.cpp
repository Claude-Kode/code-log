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
  // cout << "infor: " << n << ' ' << m << endl; 
  vector<int> odd, even;
  int sum = 0; bool fo = true, fe = true;
  for(int i = 1; i <= n; i ++) {
    int temp; cin >> temp;
    if (i & 1) odd.push_back(temp);
    else even.push_back(temp);
    sum += temp;
    if ((i & 1) && temp > 0) fo = false;
    if (!(i & 1) && temp > 0) fe = false;
  }

  sort(odd.begin(), odd.end(), greater<int>());
  sort(even.begin(), even.end(), greater<int>());

  int cnt1 = 0, cnt2 = 0;
  for(int i = 1; i <= m; i ++) {
    int op; cin >> op;
    if (op & 1) {
      cnt1 ++;
    } else {
      cnt2 ++;
    }
  }

//   cout << "cnt: " << cnt1 << ' ' << cnt2 << endl;

//   cout << "infor: \n";
//   for(const auto &a : odd) cout << a << ' ';
//   cout << endl;
//   for(const auto &a : even) cout << a << ' ';
// cout << endl;

  for(int i = 0; i < min((int)odd.size(), cnt1); i ++) {
    if (odd[i] >= 0) sum -= odd[i], fo = false;
    else if (fo) sum -= odd[i], fo = false;
    else break;
  }

  for(int i = 0; i < min((int)even.size(), cnt2); i ++) {
    if (even[i] >= 0) sum -= even[i], fe = false;
    else if (fe) sum -= even[i], fe = false;
    else break;
  }

  cout << sum << endl; 
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