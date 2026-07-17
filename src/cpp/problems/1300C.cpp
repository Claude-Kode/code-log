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
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i];

  int t = 0;
  for(int i = 30; i >= 0; i --) { 
    int cnt = 0;
    for(int j = 1; j <= n; j ++) if (vec[j] >> i & 1) {
      cnt ++, t = j;
    }
    if (cnt == 1) break;
  }

  if (t) cout << vec[t] << ' ';
  for(int i = 1; i <= n; i ++) if (i != t) cout << vec[i] << ' ';
  cout << endl; 
}

/*
把一个位置拆开 看他从头到尾会怎么变化
我推出了 a - a&b
其实也等价于 a & (~b)
a & b 是保留两个共同的 1 
a & (~b) 是去掉两个共同 的 1 
实际上就是选一个数 然后去掉别的树所有的 1 看最后的最大值
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}
