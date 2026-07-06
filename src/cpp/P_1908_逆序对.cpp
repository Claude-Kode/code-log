// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 1e7 + 10;

int n, cnt_node, ans, t[N][2], cnt[N];

int insert(int num) {
  int p = 0;
  for(int i = 29; i >= 0; i --) {
    int c = (num >> i & 1);
    if (c == 0 && t[p][1]) ans += cnt[t[p][1]];
    if (!t[p][c]) t[p][c] = ++cnt_node;
    p = t[p][c]; cnt[p] ++;
  }
  return ans;
}

void solve() { 
  int n; cin >> n;
  for(int i = 1; i <= n; i ++) {
    int temp; cin >> temp;
    insert(temp);
  } 
  cout << ans << endl;
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