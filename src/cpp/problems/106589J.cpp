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
  int n; cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> pre(n + 1, 1), suf(n + 1, 1);
  for (int i = 2; i <= n; i ++) {
    if (vec[i] > vec[i - 1]) {
      pre[i] = pre[i - 1] + 1;
    }
  }

  for (int i = n - 1; i > 0; i --) {
    if (vec[i] < vec[i + 1]) {
      suf[i] = suf[i + 1] + 1;
    }
  }

  map<int, int> mp1, mp2;
  for (int i = 1; i <= n; i ++) {
    if (vec[i] == vec[i - 1]) {
      mp1[i] = mp1[i - 1];
    } else {
      mp1[i] = i - 1;
    }
  }

  for (int i = n; i > 0; i --) {
    if (vec[i] == vec[i + 1]) {
      mp2[i] = mp2[i + 1];
    } else {
      mp2[i] = i + 1;
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; i ++) {
    
  }
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}