// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;
  if (n == 1 || n == 2 || n == 4) cout << -1 << endl; 
  else {
    if (n % 3 == 0 || n % 3 == 2) cout << n / 3 << endl; 
    else {
      cout << 1 + (n - 7) / 3 << endl; 
    }
  }
}

/*

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


// #include <iostream>
// using namespace std;

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         long long n;
//         cin >> n;
//         if (n == 1 || n == 2 || n == 4) {
//             cout << -1 << endl;
//             continue;
//         }
//         long long k = n / 3;
//         if (n % 2 == 1) { // n 奇数
//             if (k % 2 == 0) k--;
//         } else { // n 偶数
//             if (k % 2 == 1) k--;
//         }
//         cout << k << endl;
//     }
//     return 0;
// }