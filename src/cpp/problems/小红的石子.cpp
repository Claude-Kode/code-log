// @Author : GoryK
#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

vector<int> unprime(1e4 + 1);


// Functions : 

int fp( int x , int p , int mod) {
  int res = 1 , base = x ; 
  while ( p ) {
    if ( p & 1 ) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int lcm(int a , int b) { 
  return a / gcd(a , b) * b ; 
} 

int inv (int x , int mod) { 
  return fp(x , mod - 2 , mod) ; 
}

vector<int> prime(int n) {
  vector<int> vis(maxn , 0) , pr ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  return pr ; 
}

void dedup(vector<int>& vec ) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

string bit(int x) {
  return bitset<32>(x).to_string() ;
}

void solve() { 

  int N = 1e9;vector<int> win(N + 1);
  for (int i = 1; i <= 8; i++) win[i] = 0;win[8] = 1;

  auto check = [&](int x) -> bool {
    if (x < 4) return false;
    int lim = sqrt(x);
    for (int i = 2 ; i <= lim; i++) if (x % i == 0) return true; 
    return false;
  };

  for ( int i = 9 ; i <= N ; i ++ ) {
    for(int j = 4; j <= i; i ++) {
      int x = j, y = i - j;
      if (check(x) && check(y) && win[y] == 0) {
        win[i] = 1;
        break;
      }
    }
  }

  for (int i = 1 ; i <= N; i++) {
    // cout << "i : " << i << ' ' ; 
    // if (win[i]) cout << "KOU" << endl;
    // else cout << "YUKARI" << endl; 

    if (!check(i - 4) && win[1]) cout << i << ' ' << "66666666666666666666666666" << endl ;

  }


  // int n ; cin >> n ; 
  // if (check(n - 4) || check(n - 13)) {
  //   cout << "kou" << endl ; 
  // } else cout << "yukari" << endl ;

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

  // auto num = prime(1e4) ;
  // vector<int> vis(1e4 + 1);
  // for (const auot &a : num) vis[a] = 1;
  // for( int i = 1 ; i <= 1e4 ; i++) if (!vis[i]) {
  //   unprime.push_back(i);
  // }

  // unordered_set<int> uset(unprime);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) {
    // cout << "TEST CASE : " << CNT << endl;
    solve();
  }
  
  return 0 ;
}
