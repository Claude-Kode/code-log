// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 1e6 + 10;

// vis[i] == 0 就是苏苏
vector<int> vis(N , 0);

void prime() {
  vector<int> pr ; 
  for ( int i = 2 ; i <= N ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > N) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
}

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  auto check = [&](int t) -> bool {
    vector<int> vis(t + 1), cand;
    for(int i = 1; i <= n; i ++) {
      if (vec[i] >= t || vis[vec[i]]) cand.push_back(vec[i]);
      else vis[vec[i]] = 1;
    }

    sort(cand.begin(), cand.end());

    vector<int> miss;
    for(int i = 0; i < t; i ++) if (!vis[i]) miss.push_back(i);

    int p = cand.size() - 1;
    for(int i = miss.size() - 1; i >= 0; i --) {
      int lim = (cand[p] - 1) / 2;
      if (p >= 0 && miss[i] <= lim) p --;
      else return false;
    }

    return true;
  };

  int l = 0, r = n, ans = l;
  while(l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
 
  cout << ans << endl; 
}

/*
我一开始的那个贪心是错的
错在哪 不能贪心呢 就是 每个数字不是按照大小顺序贡献的

我想的是 数字越大 越能产生更大范围的贡献

事实上 为了让贡献最大 我们要尽可能的 让每个人都有贡献
所以应该是直接让暂时没产生贡献的区贡献 这样就对了
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  prime();

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}
