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

class FenwickTree {
private : 
  int n; 
  vector<int> tree;

public : 

  FenwickTree(int _n = 1) : n(_n) {tree.assign(n + 1, 0);}
  // i ? i & -i : 1;
  static int lowbit(int i) {return i & -i;} 

  void update(int p, int v) { // 不能 update(0, ?) 会死循环
    for(int i = p; i <= n; i += lowbit(i)) tree[i] += v;
  }

  int query (int p) {
    int res = 0;
    for(int i = p; i > 0; i -= lowbit(i)) res += tree[i];
    return res;
  }
};


void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    int l = 0; for(int j = 1; j < i; j ++) l += (vec[j] > vec[i]);
    int r = 0; for(int j = i + 1; j <= n; j ++) r += (vec[j] > vec[i]);
    ans += min(l, r);
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

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}