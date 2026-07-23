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
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i]; 
    a[i] = (a[i] % 2 + 2) % 2;
  }

  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  vector<int> pre(n + 2), suf(n + 2); a[0] = -1; a[n + 1] = -1;
  for (int i = 1; i <= n; i ++) {
    if (a[i] != a[i - 1]) {
      pre[i] = 1;
    } else {
      break;
    }
  }

  for (int i = n; i > 0; i --) {
    if (a[i] != a[i + 1]) {
      suf[i] = 1;
    } else {
      break;
    }
  }

  int ans = 0; pre[0] = 1; suf[n + 1] = 1;
  for (int i = 1; i <= n; i ++) {
    if (a[i - 1] != a[i + 1] and pre[i - 1] and suf[i + 1]) {
      ans ++;
    }
  }

  dbug(a, pre, suf);

  cout << ans << "\n";
} 
    
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
} 