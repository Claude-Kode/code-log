// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

 
  int p = 0;
  vector<int> ans; 
  for (int i = 1; i <= n; i ++) {
    if (vec[i - 1] * vec[i] < 0) {
      if (vec[i - 1] > 0) {
        ans.push_back(i - 1);
     if(p) {  ans.push_back(p);}
      } 
    }
    if (vec[i] < 0) {
      p = i;
    }
  }
  
  if (vec[n] > 0) {
    ans.push_back(n);
    if (p) {
      ans.push_back(p);
    }
  }

  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i ++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
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