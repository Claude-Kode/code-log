// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int unsigned long long
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
  // str.substr(64 - __lg(n) - 1);
}

// 安全加法，防止 long long 溢出
int safe_add(int a, int b) {
    if (a > 0 && b > 0 && a > LLONG_MAX - b) return LLONG_MAX;
    if (a < 0 && b < 0 && a < LLONG_MIN - b) return LLONG_MIN;
    return a + b;
}

// 安全乘法，防止 long long 溢出
int safe_mul(int a, int b) {
    if (a == 0 || b == 0) return 0;
    if (a > 0 && b > 0 && a > LLONG_MAX / b) return LLONG_MAX;
    if (a < 0 && b > 0 && a < LLONG_MIN / b) return LLONG_MIN;
    if (a > 0 && b < 0 && b < LLONG_MIN / a) return LLONG_MIN;
    if (a < 0 && b < 0 && a < LLONG_MAX / b) return LLONG_MAX;
    return a * b;
}

// 安全减法
int safe_sub(int a, int b) {
    if (a >= 0 && b < 0 && a > LLONG_MAX + b) return LLONG_MAX;
    if (a < 0 && b > 0 && a < LLONG_MIN + b) return LLONG_MIN;
    return a - b;
}

// 二分中安全的中点计算
int safe_mid(int L, int R) {
    if ((L ^ R) < 0) {  // 符号不同
        return (L + R) / 2;
    }
    return L + (R - L) / 2;  // 防止溢出
}

// void solve() { 

//   int n, k; cin >> n >> k ;
//   vector<int> t(n + 1), w(n + 1), l(n + 1);
//   for (int i = 1; i <= n; i++) {
//     cin >> t[i] >> l[i] >> w[i];
//   }

//   auto check = [&](int test) -> bool {
//     int res = 0;
//     for(int i = 1; i <= n; i++) {
//       // 安全计算 t[i] * l[i]
//       int prod = safe_mul(t[i], l[i]);
//       if (prod == LLONG_MAX) {
//         // 乘法溢出，说明每个周期可完成很多工作
//         res = safe_add(res, test / t[i]);
//         if (res >= k) return true;
//         continue;
//       }
      
//       // 安全计算周期长度
//       int cycle = safe_add(prod, w[i]);
//       if (cycle <= 0) {  // 不应该发生
//         continue;
//       }
      
//       int val = safe_mul(l[i], test / cycle);
//       res = safe_add(res, val);
//       if (res >= k) return true;
      
//       int rem = test % cycle;
//       int extra = 0;
//       if (rem >= prod) {
//         extra = l[i];
//       } else {
//         extra = rem / t[i];
//       }
//       res = safe_add(res, extra);
//       if (res >= k) return true;
//     }
//     return res >= k;
//   } ;

//   int L = 0, R = LLONG_MAX, ans = R;  // 使用安全上界
//   while(L <= R) {
//     int mid = safe_mid(L, R);  // 安全计算中点
//     if (check(mid)) {
//       ans = mid;
//       R = mid - 1;
//     } else {
//       L = mid + 1;
//     }
//   }

//   cout << ans << endl; 
// }

void solve() { 

  int n, k; cin >> n >> k ;
  vector<int> t(n + 1), w(n + 1), l(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> l[i] >> w[i];
  }

  auto check = [&](int test) -> bool {
    int res = 0, rem = 0;
    for(int i = 1; i <= n; i++) {
      int val = l[i] * (test / (t[i] * l[i] + w[i]));
      // assert(val >= 0);
      if (res < 0 || val < 0) return false; 
      // assert(res >= 0);
      res += val;
      rem = test %(t[i] * l[i] + w[i]);
      if ( rem >= t[i] * l[i]) res += l[i];
      else res += rem / t[i];
    }
    return res >= k;
  } ;

  int L = 0, R = 1e18, ans = 1e18;
  while(L <= R) {
    int mid = (L + R) / 2;
    if (check(mid)) R = mid - 1, ans = mid;
    else L = mid + 1;
  }

  cout << ans << endl; 

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
  while(tt -- && ++CNT) {
    // cout << "TEST CASE : " << CNT << endl;
    solve();
  }
  
  return 0 ;
}


