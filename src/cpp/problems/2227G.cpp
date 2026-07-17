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

void dedup(vector<int>& vec ) { 
  sort(vec.begin(), vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

int getId(int x, vector<int>& vec){
  return lower_bound(vec.begin(), vec.end() , x) - vec.begin() + 1;
}

void ranked(vector<int>& vec) {
  auto temp = vec; dedup(temp);
  for(auto &x : vec) x = getId(x, temp);
}

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
};

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> dp(n + 1, 0), sum1(n + 1, 0), sum2(n + 1, 0);

  for(int i = 1; i <= n; i ++) {
    sum1[i] = sum1[i - 1] + (i & 1 ? vec[i] : -vec[i]);
    sum2[i] = sum2[i - 1] + (i & 1 ? -vec[i] : vec[i]);
  }

  // dbug(sum1);
  // dbug(sum2);

  ranked(sum1), ranked(sum2); 

  // dbug(sum1);
  // dbug(sum2);
  // cout << sum1[0] << ' ' << sum2[0] << endl; 

  FenwickTree s1(n + 10), s2(n + 10); s1.update(sum1[0], 1);
  for(int i = 1; i <= n; i ++) {
    if (i & 1) {
      dp[i] = s1.query(sum1[i] - 1);
      s2.update(sum2[i], 1);
    } else {
      dp[i] = s2.query(sum2[i] - 1);
      s1.update(sum1[i], 1);
    } 
  }

  cout << accumulate(dp.begin() + 1, dp.end(), 0LL) << '\n';
}

/*
一般来说这种问题直接看那个  n 的大小 这个题是 On 的所以我们想一个 On 的算法即可

一般来说 On的都有什么 奇偶性检验, 差分, 前缀和 之类的东西

一定不要懒啊 一定要去手玩样例 然后去总结规律

也就是说所有的子数组都以一个通用的性质是可以检测的 而且还是 On 的
事实上 所有的子数组颤抖的都应该是 3 * n + 2 的

我们想着去运用一个 dp 然后看当前的数字能作为前面多少个数组的后缀即可 
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