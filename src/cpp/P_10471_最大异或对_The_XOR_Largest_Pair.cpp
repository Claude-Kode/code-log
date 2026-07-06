// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

// #define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e6 + 10;

int n, cnt_node;
int t[N][2];

void insert(int num) {
  int p = 0;
  for(int i = 30; i >= 0; i --) {
    int dig = (num >> i & 1);
    if (!t[p][dig]) t[p][dig] = ++cnt_node;
    p = t[p][dig];
  }
}

int cal(int num) {
  int p = 0, res = 0;
  for(int i = 30; i >= 0; i --) {
    int dig = (num >> i & 1);
    if (t[p][dig ^ 1]) {
      res |= (1 << i); 
      p = t[p][dig ^ 1];
    } else {
      p = t[p][dig];
    }
  }
  return res;
}

void solve() { 
  cin >> n;
  vector<int> arr(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> arr[i]; insert(arr[i]);
  }

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    ans = max(ans, cal(arr[i]));
  }

  cout << ans << "\n";
} 

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // cout << bit(1) << '\n';
  // cout << bit(-1) << '\n';

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}

