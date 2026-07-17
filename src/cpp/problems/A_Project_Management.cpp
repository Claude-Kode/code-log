// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;


    
void solve() { 

  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1), ord(n + 1);
  for(int i = 1; i <= n; i ++) cin >> a[i] >> b[i];

  iota(ord.begin() + 1, ord.end(), 1LL);
  sort(ord.begin() + 1, ord.end(), [&](int i, int j) {
    if (a[i] != a[j]) return a[i] < a[j];
    else return b[i] > b[j];
  });

  auto check = [&](int x) -> bool {

    int s = 0;        // 之前职级已选人数
    int cur_rank = -1;
    int cnt = 0;      // 当前职级已处理人数
    
    for (int i = 1; i <= n; ) {
      int rank = a[ord[i]];
      if (rank != cur_rank) {
        s += cnt;
        cnt = 0;
        cur_rank = rank;
      }
      
      // 收集当前职级所有员工
      vector<int> b_vals;
      while (i <= n && a[ord[i]] == cur_rank) {
        b_vals.push_back(b[ord[i]]);
        i++;
      }
      
      // 当前职级最多能选的人数
      int max_take = min((int)b_vals.size(), x - s);
      int take = 0;
      
      // 从多到少尝试
      for (int t = max_take; t >= 1; t--) {
        // 如果选t个人，高职级人数 = x - s - t
        // 第t个人的b值（b_vals[t-1]）需要 >= 高职级人数
        if (b_vals[t-1] >= x - s - t) {
          take = t;
          break;
        }
      }
      
      cnt = take;  // 当前职级选take个人
    }
    
    s += cnt;  // 加上最后一组
    return s >= x;

    // int s = 0;           // 之前职级已选人数
    // int cur = -1;   // 当前职级
    // int t = 0;           // 当前职级已选人数
    
    // for(int i = 1; i <= n; i++) {
    //   int id = ord[i];
      
    //   // 如果职级变化
    //   if(a[id] != cur) {
    //     s += t;      // 将当前职级已选人数加入s
    //     t = 0;       // 重置当前职级计数
    //     cur = a[id];
    //   }
      
    //   // 贪心选择：如果当前员工满足条件，就选择
    //   // 条件：b[i] >= 最终集合中比他职级高的人数
    //   // 最终集合中比他职级高的人数最多是：x - s - t - 1
    //   if(s + t >= x) return true;
    //   int lim = x - s - t - 1;
    //   assert(lim >= -1);
    //   if(b[id] >= lim) {
    //     t++;
    //   }
      
    //   // 如果已选总数达到x，提前返回
    //   if(s + t >= x) return true;
    // }
    
    // s += t;  // 加上最后一组
    // return s >= x;
  };

  int l = 0, r = n, ans = l;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }

  cout << ans << endl; 
  vector<int> res;
  int s = 0, cur = -1, t = 0;
  for(int i = 1; i <= n && (int)res.size() < ans; i++) {
    int id = ord[i];
    
    if(a[id] != cur) {
      s += t;
      t = 0;
      cur = a[id];
    }
    
    if(b[id] >= ans - s - t - 1) {
      res.push_back(id);
      t++;
    }
  }
  
  for(int i = 0; i < ans; i++) {
    cout << res[i] << " \n"[i == ans - 1];
  }
}

/*
如果每次只选择一个 a[i]
我们是一定能选完所有的 a[i] 的值
这个题的难点就在于 每个 a[i] 只会对更大的 a[i] 产生影响 相同的a[i]就算再多也不会产生影响

我们可以思考两种极端的情况
所有的 a[i] 都是相同的应该怎么选

所有的 a[i] 都不同应该怎么选

对于第一种情况来说 很显然直接全选就可以了 理由已经说过了 相同的 a[i] 并不会干扰选择

对于第二种情况来说 我们是应该从大到小进行选择还是从小到大呢
先考虑从大到小 如果这样的话 每次应该从符合条件的小的里面挑最大的那个进行选择

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

/*
首先 一个员工有两种属性 一种是能力值 一种是忍耐度
所以这个属于偏序类的问题

首先我固定一个维度 能力值 对于相同的能力值来说 我们肯定是先选忍耐度更高的
因为先选高的低的还能选 , 先选低的高的真不一定能选了

再让我们来看能力值 我们是优先选低的还是高的呢 这个时候我们考虑固定另一个维度来看
如果每个维度的
忍耐度都是相同的呢



*/