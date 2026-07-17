// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int lcm(int a , int b) { 
  return a / gcd(a , b) * b ; 
} 

void solve(){

  int n; cin >> n;
  vector<int>a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i ++) cin>>a[i];
  for(int i = 1; i <= n; i ++) cin>>b[i];
  vector<int>c(n + 1);
  for(int i = 1; i<= n - 1; i ++){
    c[i] = __gcd(a[i] , a[i+1]);
  }

  int cnt = 0;
  for(int i = 1 ; i <= n; i ++){
    int g = (c[i - 1] / (__gcd(c[i - 1], c[i]))) * c[i];
    if(i == 1) g = c[1];
    if(i == n) g = c[i-1];
    if(a[i] > g){
      cnt ++;
    }
  }

  cout<< cnt << endl;

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
