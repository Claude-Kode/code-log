// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;

string bit(int x) {
  return bitset<6>(x).to_string() ;
  // str.substr(64 - __lg(n) - 1);
}

void solve() { 
  int n; cin >> n; 
  vector<int> vec;
  for(int i = 0; i < (1 << n); i ++) {
    vec.push_back(i);
  }

  auto calc = [&](int a) -> int{
    int len = __lg(a), cnt = 0;
    for(int i = 0; i <= len; i ++) if (a >> i & 1) cnt ++; else break;
    return cnt;
  };

  sort(vec.begin(), vec.end(), [&](int a, int b){
    int ca = calc(a), cb = calc(b);
    if (ca != cb) return ca > cb;
    else return a < b;
  });

  for(const auto &a : vec) cout << a << ' ';
  cout << endl; 
  
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
