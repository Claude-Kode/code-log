// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  vector<vector<int>> g(4, vector<int>(4, 0));
  for(int i = 1; i <= 3; i ++) {
    for(int j = 1; j <= 3; j ++) {
      cin >> g[i][j];
    }
  }

  vector<string> temp(4, "....");
  auto ans1 = temp, ans2 = temp;

  // for(int i = 1; i <= 3; i ++) {
  //   for(int j = 1; j <= 3; j ++) {
  //     cout << ans1[i][j];
  //   } 
  //   cout << "\n";
  // }

  // for(int i = 1; i <= 3; i ++) {
  //   for(int j = 1; j <= 3; j ++) {
  //     cout << ans2[i][j];
  //   } 
  //   cout << "\n";
  // }

  for(int j = 1; j <= 3; j ++) {
    int mx = 0;
    for(int i = 1; i <= 3; i ++) {
      mx = max(mx, g[i][j]);
    }
    // cout << mx << ' ' ;
    for(int i = 1; i <= mx; i ++) {
      ans1[3 - i + 1][j] = '*';
    }
  }

  // cout << '\n';

  for(int i = 1; i <= 3; i ++) {
    int mx = 0;
    for(int j = 1; j <= 3; j ++) {
      mx = max(mx, g[i][j]);
    }
    // cout << mx << ' ';
    for(int j = 1; j <= mx; j ++) {
      ans2[3 - j + 1][i] = '*';
    }
  }

  // cout << '\n';

  for(int i = 1; i <= 3; i ++) {
    for(int j = 1; j <= 3; j ++) {
      cout << ans1[i][j];
    } 
    cout << "\n";
  }

  for(int i = 1; i <= 3; i ++) {
    for(int j = 1; j <= 3; j ++) {
      cout << ans2[i][j];
    } 
    cout << "\n";
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, C = 0; 
  cin >> tt;
  while (tt-- && ++C)
    // cout << "TEST CASE : " << C << endl,
    solve();

  return 0;
}