// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif

// void solve() {
  
// } 

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
  
//   int tt = 1, _ = 0;
//   std::cin >> tt;
//   while (tt-- && ++_)
//     // std::cout << "TEST CASE : " << _ << endl,
//     solve();

//   return 0;
// }



// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;  

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {    
  int a, m; 
  cin >> a >> m;
  map<int, int> mp;
  int mx = 0, mn = 9;
  bool f0 = false;
  for (int i = 1; i <= m; i ++) {
    int temp; cin >> temp;
    mp[temp] = 1;
    if (temp) {
      mx = max(mx, temp);
      mn = min(mn, temp);
    } else {
      f0 = true;
    }
  }
 
  string s = to_string(a);
  int n = s.size();
  // dbug(s);
  // dbug(n);

  if (m == 1 && mp.count(0)) {
    cout << a << "\n";
    return;
  }

  int ans = LLONG_MAX;
  string s1 = "", s2 = "", s3 = ""; 
  for (int i = 0; i < n; i ++) {
    // cout << "s[i] - '0' : " << s[i] - '0' << "\n";
    if (mp.count(s[i] - '0')) {
      s1 += s[i];
      // assert(s1 != "");
      // cout << "s1: " << s1 << "\n";
      ans = min(ans, abs(a - stoll(s1)));
      // dbug(s1);
    } else {
      int big = -1, small = -1;
      for (int d = s[i] - '0'; d <= 9; d ++) {
        if (mp.count(d)) {
          big = d; 
          break;
        }
      }

      for (int d = s[i] - '0'; d > 0; d --) {
        if (mp.count(d)) {
          small = d;
          break;
        }
      }

      // 这种情况下可以全都写 0 
      bool f = (!s1.empty() && f0);

      if (big != -1) {
        string t = s1;
        t += char(big + '0');
        while (t.size() < n) t += (f0 ? '0' : char(mn + '0'));
        // assert(t != "");
        ans = min(ans, abs(a - stoll(t)));
        // dbug(t);
      }

      if (small != -1) {
        string t = s1; 
        t += char(small + '0');
        while (t.size() < n) t += char(mx + '0');
        // assert(t != "");
        ans = min(ans, abs(a - stoll(t)));
        // dbug(t);
      }

      if (f) {
        string t = s1;
        while (t.size() < n) t += '0';
        ans = min(ans, abs(a - stoll(t)));
        // dbug(t);
      }

      break;
    }
  }

  if (n > 1) {
    for (int i = 1; i < n; i ++) {
      s2 += char(mx + '0');
    }
    ans = min(ans, abs(a - stoll(s2)));
  }


  s3 += char(mn + '0'); 
  if (f0) mn = 0;
  for (int i = 0; i < n; i ++) {
    s3 += char(mn + '0');
  }
  ans = min(ans, abs(a - stoll(s3)));

  // dbug(s1);
  // dbug(s2);
  // dbug(s3);

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