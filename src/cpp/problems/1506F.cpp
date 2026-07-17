// @Author : GoryK
#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n; cin >> n;
  vector<array<int, 2>> vec(n + 1);
  for(int i = 1; i <= n; i ++) cin >> vec[i][0]; 
  for(int i = 1; i <= n; i ++) cin >> vec[i][1]; 
  sort(vec.begin() + 1, vec.end(), [&](array<int, 2>& a, array<int, 2>& b){
    return a[0] < b[0]; 
  });

  int s = 1;
  if (vec[1][0] == 1 && vec[1][1] == 1) s ++;
  else vec[0][0] = 1, vec[0][1] = 1;
  // check is even
  auto check = [&](int i, int j) -> bool {
    return !((i + j) & 1);
  };

  auto cal = [&](int a, int b, int c, int d) -> int {

    if ((c - a) == (d - b)) return (check(a, b) ? (c - a) : 0);

    int l = c - a, r = d - b;
    int res = 0;
    if (check(a, b)) res += (l - r) / 2;
    else res += (l - r + 1) / 2;
    return res;
  };

  int ans = 0;
  for(int i = s; i <= n; i ++) {
    int a = vec[i - 1][0], b = vec[i - 1][1], c = vec[i][0], d = vec[i][1];
    ans += cal(a, b, c, d);
  } 

  cout << ans << endl; 
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