// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> coin(n + 1), pos(n + 1, 1), jail(n + 1), dead(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> coin[i];
  }

  vector<int> type(m + 1), pr(m + 1), tl(m + 1), own(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> type[i];
    if (type[i] == 1) {
      cin >> pr[i] >> tl[i];
    }
  }

  int k; cin >> k;
  vector<int> di(k);
  for (auto &x : di) {
    cin >> x;
  }
  
  int alive = n, die_idx = 0, p = 1;
  auto bk = [&](int i) {
    dead[i] = 1, coin[i] = 0, alive--;
    for (int g = 1; g <= m; g++) {
      if (own[g] == i) {
        own[g] = 0;
      }
    }
  };

  while (die_idx < k and alive > 1) {
    if (dead[p]) { 
      p = p % n + 1; 
      continue; 
    }

    if (jail[p]) {
      jail[p] = 0;
      p = p % n + 1;
      continue;
    }

    pos[p] = (pos[p] - 1 + di[die_idx++]) % m + 1;
    int g = pos[p];

    if (type[g] == 0) {
      coin[p] += 200;
    } else if (type[g] == 1) {
      if (own[g] == 0) {
        if (coin[p] >= pr[g]) {
          coin[p] -= pr[g], own[g] = p;
        }
      } else if (own[g] != p) {
        int o = own[g];
        if (coin[p] < tl[g]) {
          coin[o] += coin[p];
          bk(p);
        } else {
          coin[p] -= tl[g];
          coin[o] += tl[g];
        }
      }
    } else if (type[g] == 2) {
      coin[p] += 150;
    } else if (type[g] == 3) {
      if (coin[p] < 100) {
        coin[p] = 0;
        bk(p);
      } else {
        coin[p] -= 100;
      }
    } else if (type[g] == 4) {
      jail[p] = 1;
    }

    p = p % n + 1;
  }

  for (int i = 1; i <= n; i++) {
    if (dead[i]) {
      cout << "bankrupt 0\n";
    } else {
      int cnt = 0;
      for (int g = 1; g <= m; g++) {
        cnt += (own[g] == i);
      }
      cout << coin[i] << " " << cnt << "\n";
    }
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 

/*
coin	每位玩家当前金币数
pos	每位玩家当前所在格子编号(初始都为 1)
jail	玩家是否处于停牌状态(1=下回合不能动，0=正常)
dead	玩家是否已破产 
type	每格的类型：0 start / 1 fang zi / 2 luck / 3 pun / 4 jail
pr	地产格的购买价格 when type = 1
tl	地产格的过路费(仅 type=1 时有意义)
own	地产当前属于哪位玩家(0 = 无主)
di	骰子点数序列，按顺序消耗
alive 是存活玩家计数器，die_idx 是当前消耗到第几个骰子，p 是当前行动玩家编号。
*/