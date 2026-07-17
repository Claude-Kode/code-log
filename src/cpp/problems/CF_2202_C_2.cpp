// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

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

void solve() { 

  int n , ans = 0 ; cin >> n ; 
  vector<int> vec(n + 1) , len ; 
  for ( int i = 1 ; i <= n ; i ++ ) cin >> vec[i] ; 
  for ( int i = 1 ; i <= n ; i ++ ) {
    // cout << "i f " << i << endl ; 
    int mn = vec[i] , mx = vec[i] , ii = 0 ;
    while ( i < n && vec[i + 1] <= vec[i] + 1 && vec[i + 1] > mn ) {
      ii ++ ; i ++ ; 
    } 
    int l = i - ii , r = i , len = ii + 1 ;
    int a = l - 1 , b = n - r ; 
    ans += n * ( n + 1 ) / 2 - a * ( a + 1 ) / 2 - b * ( b + 1 ) / 2 ;

    cout << a << ' ' << len << ' ' << b << endl ; 

    cout << len << endl ; 

  }

  cout << ans << endl ; 
  
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  system("pause") ;

  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  int tt ; cin >> tt ;
  while(tt --) solve() ;
  
  return 0 ;
}

// #include <bits/stdc++.h>
// using namespace std ; 
// #define int long long 
// #define endl '\n'

// void solve(){

//   int n ; cin >> n ; 
//   vector<int> vec(n + 1) ; 
//   for (int i = 1 ; i <=n ; i ++) cin >> vec[i];

//   sort(vec.begin() + 1 , vec.end()) ; 
//   for (const auto &a : vec) cout << a << ' ' ; 
//   cout << endl ; 

// }

// signed main() {

//   ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0 ) ; 

//   int tt ; cin >> tt; 
//   while (tt --) solve() ; 

//   return 0 ; 
// }