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
  vector<int> a, b, c;
  for(int i = 1; i <= 6; i ++) {int temp; cin >> temp; a.push_back(temp);}
  for(int i = 1; i <= 6; i ++) {int temp; cin >> temp; b.push_back(temp);}
  for(int i = 1; i <= 6; i ++) {int temp; cin >> temp; c.push_back(temp);}

  vector<array<int, 3>> p;
  for(int i = 0; i < 6; i ++) {
    for(int j = 0; j < 6; j ++) {
      for(int k = 0; k < 6; k ++) {
        p.push_back({a[i], b[j], c[k]});
      }
    }
  }

  vector<int> vec = {4, 5 ,6};
  int ans = 0;
  for(const auto&[x, y, z] : p) {
    vector<int> temp = {x, y, z};
    // cout << temp << endl;
    sort(temp.begin(), temp.end());
    if (temp == vec) ans ++;
  }

  cout << 1.0 * ans / 216 << endl; 
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  cout << fixed << setprecision(10);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}