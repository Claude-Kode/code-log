// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'
#define ls node >> 1
#define rs node >> 1 | 1


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

string bit(int x) {
  return bitset<32>(x).to_string() ;
  // str.substr(64 - __lg(n) - 1);
}

vector<int> tree, tag, vec;

void apply(int node, int l, int r) {

}

void push_up(int node, int l, int r) {
  tree[node] = tree[ls] + tree[rs];
}

void down(int node, int l, int r) {

}

void build(int node, int l, int r){

}

void update(int node, int l, int r, int ql, int qr, int val) {

}

void query(int node, int l, int r, int ql, int qr) {
  int res = 0;
}

void solve() { 

  int n, q, m; cin >> n >> q >> m;
  vec.assign(n + 1, 0), tag.assign(4 * n + 1, 0), tree.assign(4 * n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  build(1, 1, n);

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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0 ;
}
