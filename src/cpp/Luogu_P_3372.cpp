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

// 为什么 tag 数组的下标是跟 tree 一样的
int n;
vector<int> tree, vec, tag;

int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }

void init(){tree.assign(4 * n + 1, 0); vec.assign(n + 1, 0); tag.assign(4 * n + 1, 0);}

// 这个函数就是为了方便 懒标记下传存在的
void apply(int node, int l, int r, int val) {
  tag[node] += val;
  tree[node] += (r - l + 1) * val; 
}

void down(int node, int l, int r) {
  int mid = (l + r) >> 1;
  apply(ls(node), l, mid, tag[node]);
  apply(rs(node), mid + 1, r, tag[node]);
  tag[node] = 0;  
}

void build(int node, int l, int r) {
  if (l == r) { tree[node] += vec[l]; return; } 
  int mid = (l + r) / 2;
  build(ls(node), l, mid);
  build(rs(node), mid + 1, r);
  tree[node] = tree[ls(node)] + tree[rs(node)]; 
}

void update(int node, int l, int r, int ql, int qr, int val) {
  if (ql <= l && qr >= r) {tag[node] += val; tree[node] += (r - l + 1) * val; return;} 
  // this function is apply the lz tag to the next layer , notice , only the next 
  down(node, l, r) ; 
  int mid = (l + r) / 2 ;  
  if (ql <= mid) update(ls(node), l, mid, ql, qr, val ) ; 
  if (qr > mid) update(rs(node), mid + 1, r, ql, qr, val ) ;
  // if not push down , the get sum here is wrong  
  tree[node] = tree[ls(node)] + tree[rs(node)] ;
}

int query(int node, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return tree[node];
  down(node, l, r);
  int mid = (l + r) / 2, res = 0;
  if (ql <= mid) res += query(ls(node), l, mid, ql, qr) ; 
  if (qr > mid) res += query(rs(node), mid + 1, r, ql, qr) ; 
  return res; 
}

void solve() { 

  int n , m ; cin >> n >> m ; 
  tree.assign(4 * n + 1, 0); vec.assign(n + 1, 0); tag.assign(4 * n + 1, 0);
  for ( int i = 1 ; i <= n ; i ++ ) {
    cin >> vec[i] ;
  }
  
  build(1 , 1 , n);
  for (int i = 1 ; i <= m; i ++) {
    int op ; cin >> op ;
    if ( op == 1 ) {
      int l , r , val ; cin >> l >> r >> val ; 
      update(1 , 1 , n , l , r , val);
    } else {
      int l , r ; cin >> l >> r ; 
      cout << query(1 , 1 , n , l , r) << endl ; 
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

  solve() ;
  
  return 0 ;
}