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

  int n, k; cin >> n >> k;
  vector<int> vec(n + 1);

  for(int i = 1 ; i <= n ; i ++ ) {
    cin >> vec[i]; vec[i] %= k;
    if (vec[i] == 0) vec[i] = INT_MAX;
  }

  vector<int> ans (n + 1);
  iota(ans.begin() + 1, ans.end(), 1LL);
  sort(ans.begin() + 1, ans.end(), [&](int i, int j){
    if (vec[i] != vec[j])return vec[i] > vec[j];
    else return i < j;
  });

  for(int i = 1 ; i <= n ; i ++ ) {
    cout << ans[i] << ' ' ;
  }

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