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
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> odd, even;
  for(int i = 1; i <= n; i ++) {
    if (vec[i] & 1) odd.push_back(vec[i]);
    else even.push_back(vec[i]);
  }

  int min_odd = INT_MAX;
  int max_odd = INT_MIN;
  int min_eve = INT_MAX;
  int max_eve = INT_MIN;

  if (!odd.empty()) {
    min_odd = *min_element(odd.begin(), odd.end());
    max_odd = *max_element(odd.begin(), odd.end());    
  }

  if (!even.empty()) {
    min_eve = *min_element(even.begin(), even.end());
    max_eve = *max_element(even.begin(), even.end());    
  }

  if (odd.size() > 1) {
    int pre_mx = odd[0];
    for(int i = 1; i < odd.size(); i ++) {
      if (odd[i] < pre_mx && max_eve < pre_mx && min_eve > odd[i]) {
        cout << "NO" << endl; return; 
      }
      pre_mx = max(pre_mx, odd[i]);
    }
  }


  if (even.size() > 1) {
    int pre_mx = even[0];
    for(int i = 1; i < even.size(); i ++) {
      if (even[i] < pre_mx && max_odd < pre_mx && min_odd > even[i]) {
        cout << "NO" << endl; return; 
      }
      pre_mx = max(pre_mx, even[i]);
    }
  }

  cout << "YES" << endl;
}

/*
每个数字有一个他最后该有的位置 p
如果 p 和他中间那一段可以换过去就无敌了

其实这个思路确实是对的 关键就是在于怎么换过去
然后这个过程中是可以一个变成一个很简单的检验 傻逼 cf 最爱搞个什么傻逼东西出来
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}
