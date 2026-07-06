#include <bits/stdc++.h>
using namespace std;

#define int long long 

int N = 1e6;
// set<int> fail; 
map<int, int> ump;

void solve() {
  int n; cin >> n;
  // cout << (fail.count(n) ? "Pinkie Pie" : "Fluttershy") << "\n";
  if (ump[n]) {
    cout << "Pinkie Pie" << "\n";
    return;
  }
  
  if (ump[n - 1]) {
    cout << "Fluttershy" << "\n";
    return;
  }

  cout << ((n & 1) ? "Fluttershy" : "Pinkie Pie") << "\n";
}

int32_t main() {
  int tt = 1;
  cin >> tt;

  // fail.insert(2);
  // fail.insert(3);
  int pre = 0;

  for (int i = 1; i <= N; i ++) {
    pre ^= i;
    
    if (!pre) ump[i] = 1;
    //   fail.insert(i);
    // } else {
    //   if (i > 1 and !fail.count(i - 1)) {
    //     fail.insert(i);
    //   }
    // }
  }

  // for (const auto &a : fail) {
  //   cout << a <<  "\n";
  // }

  while (tt --) {
    solve();
  }
  return 0;
}