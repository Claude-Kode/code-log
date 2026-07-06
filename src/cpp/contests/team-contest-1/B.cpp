// #ifdef __GNUC__
//   #pragma GCC optimize("fast-math")
//   #pragma GCC optimize("Ofast, unroll-loops = full")
//   #pragma GCC optimize("avx, avx2")
// #endif

#include <bits/stdc++.h>
using namespace std;

#define int long long 

string bit(int x) {
  return bitset<10>(x).to_string().substr(10 - __lg(x) - 1);
}

void solve() {
  int n, k; cin >> n >> k;
  vector<int> vec(n + 1);

  int mx = 0;
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
    mx = max(mx, __lg(vec[i]));
    cout << vec[i] << ": " << bit(vec[i]) << "\n";
  }
  
  mx = min(mx, __lg(k));
  auto check = [n](const vector<int>& vec) -> bool {
    for (int i = 1; i <= n; i ++) {
      if (vec[i] < vec[i - 1]) return false;      
    }
    return true;
  };

  vector<int> ans;
  // for (int i = 0; i <= mx; i ++) {
  //   int ch = (1 << i);
  //   auto temp = vec;
  //   for (int i = 1; i <= n; i ++) {
  //     temp[i] ^= ch;
  //   }
  //   cout << "ch: " << ch << "\n";
  //   for (int i = 1; i <= n; i ++) {
  //     cout << temp[i] << " \n"[i == n];
  //   }
  //   if (check(temp)) {
  //     ans.push_back(ch);
  //   }
  // }

  for (int i = 0; i <= k; i ++) {
    int ch = i;
    auto temp = vec;
    for (int i = 1; i <= n; i ++) {
      temp[i] ^= ch;
    }
    if (check(temp)) {
      cout << ch << ": " << bit(ch) << "\n";
    }
  }

}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  cin >> tt;
  while (tt --) {
    solve();
  }
}