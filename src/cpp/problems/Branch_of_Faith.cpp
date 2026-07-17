// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int get_dep(int i, int k) {
  return ceil(log(i * (k - 1) + 1) / log(k));
}

int get_sum(int k, int h, int mod) {
    if (k == 1) return h % mod;  // 特殊情况：k=1
    int numerator = (fp(k, h, mod) - 1 + mod) % mod;
    int denominator = (k - 1) % mod;
    int inv_denom = fp(denominator, mod - 2, mod);
    return numerator * inv_denom % mod;
}

int get_num(int n, int i, int k) {
  int dep_i = get_dep(i, k), dep_n = get_dep(n, k);
  if (dep_i < dep_n) {
    return fp(k, dep_i - 1, mod);
  } else {
    if (dep_n == 1) return n % mod;  // 只有一层
    int pre = get_sum(k, dep_n - 1, mod);    
    return (n - pre + mod) % mod;
  }
}

void solve() {

    int n , q ; cin >> n >> q ; 

    while ( q -- ) {
        int qq; cin >> qq;
        cout << get_num(n, qq, 2) << endl; ;
    }

}

/*

*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
    
*/
