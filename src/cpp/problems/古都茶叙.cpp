// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 

  int n; cin >> n ;
  vector<int> vec(2 * n + 1);
  for(int i = 1 ; i <= n ; i ++ ) {
    cin >> vec[i]; 
  }

  // auto temp = vec;
  // for(int i = 1; i <= n; i ++) {
  //   vec[i + n] = temp[i];
  // }

  for(int i =n+1 ; i <= 2 * n ; i ++ ) vec[i] += vec[i -n];

  auto cmp = [&](int a, int b) -> bool { return vec[a] > vec[b] ; } ;
  
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); 
  for(int i = 1 ; i <= n - 1; i ++) pq.push(i); 

  for(int i = n ; i <= 2 * n - 1 ; i ++ ) {
    int l = i - n; pq.push(i);
    while(pq.top() <= l) pq.pop();
    if (vec[pq.top()] >= vec[i - n]) {
      cout << i - n + 1 << endl;
      return;
    }
  }

}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}
