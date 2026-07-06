// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e6 + 10;

int n, cnt_node;
int t[N][2], cnt[N];
vector<vector<array<int, 2>>> adj;

void insert(int num) {
  int p = 0;
  for(int i = 30; i >= 0; i --) {
    int dig = (num >> i & 1);
    if (!t[p][dig]) t[p][dig] = ++cnt_node;
    p = t[p][dig];
    cnt[p] ++;
  }
}

int query(int num) {
  int p = 0, res = 0;
  for(int i = 30; i >= 0; i --) {
    int dig  = (num >> i & 1);
    if (t[p][dig ^ 1]) {
      p = t[p][dig ^ 1];
      res |= (1 << i);
    } else {
      p = t[p][dig];
    }
  }
  return res;
}

namespace Gk {
  int query(int num) {
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i --) {
      int dig  = (num >> i & 1);
      if (t[p][dig ^ 1]) {
        p = t[p][dig ^ 1];
        res |= ((dig ^ 1) << i);
      } else {
        p = t[p][dig];
        res |= (dig << i);
      }
    }
    return res;
  }

  int findMaxXorNum(int num) {
    int p = 0, result = 0;
    
    for (int i = 30; i >= 0; i--) {
      int bit = (num >> i) & 1;      // 当前数字的这一位
      int want = bit ^ 1;            // 希望的数字b的这一位（相反）
      
      if (t[p][want]) {              // 可以走相反的位
        p = t[p][want];
        result |= (want << i);       // 在result中设置相反的位
      } else {                       // 只能走相同的位
        p = t[p][bit];
        result |= (bit << i);        // 在result中设置相同的位
      }
    }
    
    return result;  // 这就是与num异或最大的数字b
  }

  // int findMaxXorNum(int num) {
  //   int p = 0;  // 从根节点开始
  //   int target = 0;  // 要找的另一个数字
    
  //   for (int i = 30; i >= 0; i--) {
  //     int dig = (num >> i) & 1;  // 当前数字的第i位
  //     int want = dig ^ 1;  // 我们希望走的位（相反位）
      
  //     if (t[p][want]) {  // 如果存在相反的位
  //       p = t[p][want];
  //       target |= (want << i);  // 在目标数字中添加这个位
  //     } else {  // 只能走相同的位
  //       p = t[p][dig];
  //       target |= (dig << i);  // 在目标数字中添加这个位
  //     }
  //   }
    
  //   return target;  // 返回与num异或最大的那个数字
  // }

};

void solve() { 
  cin >> n;
  adj.assign(n + 1, {});
  for(int i = 1; i <= n; i ++) {
    int u, v, w; 
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> vec(n + 1);
  auto dfs = [&](this auto&& dfs, int u, int f) -> void {
    for(const auto &[v, w] : adj[u]) if (v != f) {
      vec[v] = vec[u] ^ w;
      dfs(v, u);
    }
  };

  dfs(1, 0);
  for(int i = 1; i <= n; i ++) {
    insert(vec[i]);
  }

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    ans = max(ans, Gk::query(vec[i]) ^ vec[i]);
  }

  cout << ans << endl; 
}

/*

运用 0 1 trie 来解决疑惑问题

第一点, 数字之间的大小比较遵循贪心原则, 两个数字从高到低位进行比较, 高位的更高低位的不用看了
第二点, 两个数字异或值最大本质上就是崽子电视上尽可能互斥即可

他实际上是这里有一个贪心, 就是在更高位如果能和要查询的数的数位不同, 那么就直接取这个数
然后由于前缀树的特点, 一般来说可能会有多个数在这一位有 1, 但是在前缀树上的目前搜索胡来的前缀, 他们会有一个共同的节点

其实他这个就是这样的, 由于插入的是数字, 每个数字都是 30 个节点, 也就是说,
根本不会出现就是你搜一般, 链子断掉的情况, 那么其实每个节点下面都有两种选择
选择 0 或者 1, 这两个肯定有一个是可行的至少, 我们优先选择和要查询的数不一样的即可 

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