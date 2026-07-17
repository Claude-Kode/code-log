

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

  static int lowbit(int i) {return i & -i;} 

  void update(int p, int v) {
    for(int i = p; i <= n; i += lowbit(i)) tree[i] += v;
  }

  int query (int p) {
    int res = 0;
    for(int i = p; i > 0; i -= lowbit(i)) res += tree[i];
    return res;
  }

  void assign() {tree.assign(n + 1, 0);}
};

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> temp(n + 1, 0);
  std::iota(temp.begin() + 1, temp.end(), 1LL);
  sort(temp.begin() + 1, temp.end(), [&](const int &a, const int &b) {return vec[a] < vec[b];});

  int res = 0;
  for(int i = 1; i <= n; i ++) {
    res += (i - temp[i]) * vec[temp[i]];
  }

  vector<int> pre(n + 1), suf(n + 1), mn(n + 1, vec[n]);
  for(int i = 1; i <= n; i ++) {
    mn[i] = min(mn[i + 1], vec[i]);
  }

  FenwickTree cnt(n + 1);
  for(int i = 1; i <= n; i ++) {
    pre[i] = (i - 1) - cnt.query(vec[i] - 1);
    cnt.update(vec[i], 1);
  }

  cnt.assign();
  for(int i = n; i > 0; i --) {
    cnt.update(vec[i], 1);
    suf[i] = cnt.query(vec[i] - 1);
  }

  int ans = res;
  for(int i = 1; i <= n; i ++) {
    ans = max(ans, res + pre[i] - suf[i]);
  }

  cout << ans << '\n';
}

/*
每个点的公式是减等于他的后缀最小值
这个算贡献的话本质上就是

我每次减掉去掉的那个方块的下落贡献
然后把后面的那些再加上即可

1 2 2 1

当 vec[i] -= 1 时
等于 初始的答案 + 他前面 >= vec[i] 的个数 - (vec[i]) 对答案的贡献
(vec[i]) 对答案的贡献 是 
(n - i + 1) - (后面 >= vec[i] 的个数 + 1)
n - i - 后面 >= vec[i] 的个数

(n - i + 1) - (n - i + 1 - query(vec[i] - 1));

5 4 4

对于初始的不进行操作的答案的计算我们来做一个简单的证明

每一个柱子会分成两部分 会动的部分和不会动的部分
首先 向右对齐的最终样子等价于把数组进行排序 这点是随便证明的
也就是

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