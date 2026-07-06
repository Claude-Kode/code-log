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

class FenwickTree {
private : 
  int n; 
  vector<int> tree;

public : 

  FenwickTree(int _n = 1) : n(_n) {tree.assign(n + 1, INT_MAX);}
  // i ? i & -i : 1;
  static int lowbit(int i) {return i & -i;} 

  void update(int p, int v, bool f) { // 不能 update(0, ?) 会死循环
    for(int i = p; i <= n; i += lowbit(i)) if (f) {
      if(tree[i] == v - 1 ) tree[i] = v; 
      else break;
    } else break;
    for(int i = p; i <= n; i += lowbit(i)) tree[i] = min(tree[i], v);
  }

  int query (int p) {
    int res = INT_MAX;
    for(int i = p; i > 0; i -= lowbit(i)) res = min(res, tree[i]);
    return res;
  }
};

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  map<int, int> mp;
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
    mp[vec[i]] = i;
  } 

  FenwickTree pre(n + 1), suf(n + 1);
  for(int i = 1; i <= n; i ++) {
    pre.update(i, vec[i], 0);
    suf.update(i, vec[n - i + 1], 0);
  }

  int k; cin >> k;
  while(k --) {
    int l, r; cin >> l >> r;
    int mn1 = pre.query(l - 1), mn2 = suf.query(n - r);

    int x = min(mn1, mn2);
    if (x >= n) {cout << "peace" << '\n'; continue;}
    else cout << x << endl;
    int &p1 = mp[x], &p2 = mp[x + 1];
    pre.update(mp[x], x + 1, 1);
    pre.update(mp[x + 1], x, 0);
    suf.update(n - mp[x] + 1, x + 1, 1);
    suf.update(n - mp[x + 1] + 1, x, 0);
    swap(p1, p2);
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