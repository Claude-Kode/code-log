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

// string bit(int x) {
//   return bitset<10>(x).to_string().substr(10 - __lg(x) - 1);
// }

void solve() {
  int n, k; 
  cin >> n >> k;
  vector<int> vec(n + 1), suf(n + 1);

  int sum = 0;
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
    sum += (i & 1 ? 1 : -1) * vec[i];
  }

  int pre = 0;
  map<int, int> ump1, ump2;
  for (int i = 1; i <= n; i ++) {
    suf[i] = sum - pre;
    pre += (i & 1 ? 1 : -1) * vec[i];
    if (i & 1) ump1[suf[i]] ++;
    else ump2[suf[i]] ++;
  }

  // dbug(suf);

  // ump1[0] ++;
  // ump2[0] ++;

  int ans = 0;
  for (int i = 1; i <= n; i ++) {
    ans += !(k - sum + suf[i]);
    if (i & 1) {
      ump1[suf[i]] --;
      {
        int ned = (k - sum + suf[i]);
        ans += ump1[ned];
      }
      {
        int ned = -(k - sum + suf[i]);
        ans += ump2[ned];
      }
    } else {  
      ump2[suf[i]] --;
      {
        int ned = (k - sum + suf[i]);
        ans += ump2[ned];
      }
      {
        int ned = -(k - sum + suf[i]);
        ans += ump1[ned];
      }
    }
  }

  cout << ans << "\n";
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