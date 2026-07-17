// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
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

string bit(int x) {
  return bitset<32>(x).to_string() ;
}

void solve() { 

  int n; cin >> n; 
  vector<int> a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> c[i];

  queue<int> aa, bb, cc;
  for (int i = 1; i <= n; i++) aa.push(a[i]);
  for (int i = 1; i <= n; i++) bb.push(b[i]);
  for (int i = 1; i <= n; i++) cc.push(c[i]);

  // cout << aa.size() << endl; 

  int p = 0, q = 0;
  for (int i = 1; i <= n; i++) {
    bool fail = false;
    for (int j = 1; j <= n; j++) {
      int fa = aa.front(); aa.pop(); aa.push(fa);
      int fb = bb.front(); bb.pop(); bb.push(fb);
      if (fa >= fb) fail = true;
    }

    // queue<int> temp = aa;  // 复制队列
    // while (!temp.empty()) {
    //     cout << temp.front() << ' ';
    //     temp.pop();
    // }
    // cout << endl << endl;

    if (!fail) { p ++ ; }
    int fron = aa.front(); aa.pop();aa.push(fron);

  }

  for (int i = 1; i <= n; i++) {
    bool fail = false;
    for (int j = 1; j <= n; j++) {
      int fb = bb.front(); bb.pop(); bb.push(fb);
      int fc = cc.front(); cc.pop(); cc.push(fc);
      if (fb >= fc) fail = true;
    }
    if (!fail) { q ++ ; }
    int fron = bb.front(); bb.pop();bb.push(fron);
  }


  cout << p * q * n << endl; 

}

/*
本质上是通过固定 j[1] 来计算对齐方式
因为在一个对齐方式中 , 你从那个地方开始生产个循环结果都是一样的
所以在一个对齐方式中 有 n 个可以开始生产的地方 所以要乘以 n 就可以了
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
  while(tt -- && ++CNT) {
    // cout << "TEST CASE : " << CNT << endl;
    solve();
  }
  
  return 0 ;
}
