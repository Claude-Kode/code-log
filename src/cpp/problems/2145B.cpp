// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, m; cin >> n >> m;
  string ans(n + 1, '+');
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  string op; cin >> op;
  for(const auto &c : op) {
    if (c == '0') cnt0 ++;
    if (c == '1') cnt1 ++;
    if (c == '2') cnt2 ++;
  }

  // dbug(n);
  // dbug(m);
  // dbug(cnt0);
  // dbug(cnt1);
  // dbug(cnt2);

  int rem = n - cnt0 - cnt1;
  int p1 = 1, p2 = n;
  while(cnt0 --) ans[p1 ++] = '-';
  while(cnt1 --) ans[p2 --] = '-';
  // dbug(rem);
  if (cnt2 >= rem) {
    for(int i = p1; i <= p2; i ++) ans[i] = '-';
  } else {
    while(cnt2 --) {
      ans[p1 ++] = '?', ans[p2 --] = '?';
    }
  }

  for(int i = 1; i <= n; i ++) cout << ans[i];
  cout << endl; 
}

/*
不是 又是注意到这个什么 操作和顺序无关
bledest 你妈死了 傻逼
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}