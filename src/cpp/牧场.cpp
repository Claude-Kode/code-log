// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 1e3 + 1;

string bit(int x) {
  return bitset<10>(x).to_string().substr(10 - __lg(x) - 1);
}

void solve() { 
  int n, q; cin >> n >> q;
  vector<array<int, 4>> infor(n + 1);
  vector<vector<vector<int>>> pre(8,
  vector<vector<int>>(N + 1, 
  vector<int> (N + 1, 0)));
  vector<vector<int>> diff(N + 1,
  vector<int>(N + 1));

  for(int i = 1; i <= n; i ++) {
    cin >> infor[i][0] >> infor[i][1] >> infor[i][2] >> infor[i][3];
    int x1 = infor[i][0], x2 = infor[i][1], y1 = infor[i][2], y2 = infor[i][3];
    diff[x1][y1] ++;
    diff[x1][y2 + 1] --;
    diff[x2 + 1][y1] --;
    diff[x2 + 1][y2 + 1] ++;
  }

  for(int i = 1; i <= N; i ++) {
    for(int j = 1; j <= N; j ++) {
      diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
    }
  }

  // for(int i = 1; i <= 10 ; i ++) {
  //   for(int j = 1; j <= 10; j ++) {
  //     cout << diff[i][j] << " \n"[j == 10];
  //   }
  // } 

  int tot = 0;
  for(int i = 1; i <= N; i ++) {
    for(int j = 1; j <= N; j ++) {
      tot += diff[i][j] > 0;
    }
  }

  for(int lim = 0; lim <= 7; lim ++) {
    for(int i = 1; i <= N; i ++) {
      for(int j = 1; j <= N; j ++)  {
        if (diff[i][j] <= lim) pre[lim][i][j] = 1;
        pre[lim][i][j] += pre[lim][i - 1][j] + pre[lim][i][j - 1] - pre[lim][i - 1][j - 1];
      }
    }
  }

  auto query = [&](int x1, int x2, int y1, int y2, int lim) -> int {
    return pre[lim][x2][y2] - pre[lim][x1 - 1][y2] - pre[lim][x2][y1 - 1] + pre[lim][x1 - 1][y1 - 1];
  };

  auto calc = [&](const vector<int>& s, int k) -> int {
    // cerr << "k: " << k << endl; 
    int mxs = (1 << k) - 1, ans = 0;
    for(int msk = 1; msk <= mxs; msk ++) {
      // cerr << "msk: " << msk << "::"<< bit(msk) << endl; 
      int m = __builtin_popcount(msk);
      int coef = (m & 1 ? 1 : -1);
      int x1 = 1, y1 = 1, x2 = N, y2 = N;
      for(int i = 0; i < k; i ++) if (msk >> i & 1) {
        int id = s[i];
        // cerr << id << ' ';
        x1 = max(x1, infor[id][0]);
        y1 = max(y1, infor[id][2]);
        x2 = min(x2, infor[id][1]);
        y2 = min(y2, infor[id][3]);
      }
      // cerr << endl; 
      if(x1 > x2 || y1 > y2) continue;
      // cerr << "corrdinate: "<< x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl; 
      ans += query(x1, x2, y1, y2, m);
    }

    return tot - ans;
  };

  int temp = q;
  while(q --) {
    int k; cin >> k;
    // cout << "k :" << k << endl; 
    vector<int> s(k);
    for(int i = 0; i < k; i ++) {
      cin >> s[i];
      // cout << s[i] << " \n"[i == k - 1];
    }
    // cerr << "Query: " << temp - q << endl; 
    cout << calc(s, k) << " \n"[q == 0];
  }
}

/*
如果是单纯的二维差分的话应该会爆炸
那能不能用线段树来维护呢 差分线段树 ?? 然后把 query 函数改成求前缀和
但是这个有点事 RMQ 问题的 因为本质上我们只关注有没有马
或者说

首先我们注意到 k 是很小的 所以对于一个非空的最大大小为 7 的子集来说
很显然 有 2 ^ 7 == 128 种

0 1 1 1 1 0 0 0 0 0
0 1 2 2 2 1 1 0 0 0
0 1 2 2 2 1 1 0 0 0
0 0 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

感觉这个 和 1009 都考了鸽巢定理

这个是 从 统计有多少个格子有马
变成 原先有马的格子 减去那些 只有禁用马列表上的马占据的格子的数量
所以很显然 这样的格子上的马的数量是一定 <= k 的

那个 1007 也是这样 对于一个不停加上数字取模的数来说
如果加上的数字不是 % k = 0 的话 那么就不会出现长度为 0 的环
换句话说 一个 % 的数不会一直循环

也就是说剩下的循环一定是 >= 1 && <= k的
所以这样来说 也是一个 有限的状态 然后可以装压然后用掩码来表示

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