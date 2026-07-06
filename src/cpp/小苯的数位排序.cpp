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
  vector<string> vec(n + 1);
  for(int i = 1 ; i <= n; i ++) {
    cin >> vec[i];
  }

  vector<int> num(n + 1); int cnt = 0; num[n] = stoll(vec[n]);
  for(int i = n - 1; i > 0; i --) {
    num[i] = stoll(vec[i]);
    while(vec[i].size() > 1 && num[i] > num[i + 1]) {
      // cout << vec[i] << ' ';
      int temp = 0;
      for(const auto &c : vec[i]) temp += c - '0';
      num[i] = temp; vec[i] = to_string(temp);
      // cout << vec[i] << ' ';
      // cout << endl; 
      cnt ++;
    }
    if (vec[i].size() == 1 && num[i] > num[i + 1]) {
      cout << -1 << endl; 
      return ;
    }
  }

  cout << cnt << endl; 
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