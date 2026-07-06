// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998244353; 
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

int fact(int x, int mod) {
  int res = 1;
  for(int i = 1; i <= x; i++) (res *= i) %= mod;
  return res;
}

int cmb(int n, int m, int mod) {
  if (n < 0 || m < 0 || m > n) return 0;
  if (m > n - m) m = n - m;  
  int res = 1;
  for (int i = 1; i <= m; i++) {
    res = res * (n - i + 1) % mod;
    res = res * fp(i, mod - 2, mod) % mod;  
  }
  return res;
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

void dedup(vector<int>& vec) { 
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

int getId(int x, vector<int>& vec){
  return lower_bound(vec.begin() + 1, vec.end() , x) - vec.begin();
}

string bit(int x) {
  return bitset<32>(x).to_string() ;
  // str.substr(64 - __lg(n) - 1);
}

int n, k;
vector<int> tree;
int lowbit(int i) { return i & -i; }

void update(int p, int v) {
  for (int i = p; i <= n; i += lowbit(i)) tree[i] += v;
}

int query(int p) {
  int res = 0;
  for (int i = p; i > 0; i -= lowbit(i)) res += tree[i];
  return res; 
}

void solve() { 

  cin >> n >> k; 
  vector<int> l(n + 1), r(n + 1), temp;
  for(int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    temp.push_back(l[i]);
    temp.push_back(r[i]);
  }

  tree.assign(4 * n + 1, 0);
  for(auto &a : tree) a = 0;
  vector<int> vec(n + 1); iota(vec.begin() + 1, vec.end(), 1LL);
  sort(vec.begin() + 1, vec.end(), [&](int a, int b) {
    if (l[a] != l[b]) return l[a] < l[b];
    else return r[a] > r[b];
  }); 
  
  dedup(temp);
  for(int i = 1; i <= n; i++) {
    l[i] = getId(l[i] , temp);
    r[i] = getId(r[i] , temp);
  }

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    int cost = (k - (i - 1) + query(l[vec[i]] - 1)) ;
    if (cost <= 0) {
      cout << 0 << endl; return ;
    }
    (ans *= cost) %= mod;
    update(r[vec[i]], 1);

  }

  cout << ans << endl; 

}

/*
每次都算一下当前还有多少中颜色可以涂 然后乘一下 
可以放置的数量是他和别人直接接触的
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



// void man() {
    
//     int n,k; cin>>n>>k;
    
//     vector<node> ve(n+1);
//     fori (1,n) {
//         cin>>ve[i].l>>ve[i].r;
//     }
//     sort(all1(ve) , [] (node a , node b) -> bool {
//         if (a.l == b.l) {
//             return a.r > b.r;
//         }
//         return a.l < b.l;
//     });
//     vector<int> b;
//     fori (1,n) {
//         b.push_back(ve[i].l);
//         b.push_back(ve[i].r);
//     }
//     vector<int> temp = b;
//     sort(all(temp));
//     fori (1,n) {
//         ve[i].r = lower_bound(all(temp) , ve[i].r) - temp.begin() + 3;
//         ve[i].l = lower_bound(all(temp) , ve[i].l) - temp.begin() + 3;
//     }
//     int ans = 1;
//     Tree tr(5*n);
//     fori (1,n) {
//         int s = tr.qury(ve[i].l-1);
//         tr.update(ve[i].r,1);
//         int ll = (k-(i-1-s)+mod)%mod;
//         ans*=ll;
//         ans%=mod;
// //        cout<<ll<<' '<<s<<endl;
//     }
//     cout<<ans%mod<<endl;
    
    
// }