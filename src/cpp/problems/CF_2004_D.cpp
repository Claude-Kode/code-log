// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std ;

// #define int long long
// #define endl '\n'

// const int mod = 1e9 + 7 ; 
// const int maxn = 2e5 + 10 ;

// void solve() {


    
// }

// /*

// */

// signed main() {
    
//     std::ios::sync_with_stdio(false) ;
//     std::cin.tie(nullptr) ;
//     std::cout.tie(nullptr) ;
    
//     #ifdef GK
//         freopen("INPUT.txt", "r", stdin) ;
//         freopen("OUTPUT.txt", "w", stdout) ;
//     #endif

//     // cout << fixed << setprecision(6) ;

//     int tt ; cin >> tt ;
//     while(tt --) solve() ;
    
//     return 0 ;
// }

// // Functions : 

// int fp( int x , int p , int mod) {
//     int res = 1 , base = x ; 
//     while ( p ) {
//         if ( p & 1 ) (res *= base) %= mod ; 
//         (base *= base) %= mod ; 
//         p >>= 1 ;
//     }
//     return res ; 
// }

// int lcm(int a , int b) { return a / gcd(a , b) * b  ; } 

// int inv (int x , int mod) { return fp(x , mod - 2 , mod ) ; }

// void dedup(vector<int>& vec ) { 
//   sort(vec.begin() + 1 , vec.end()) ;
//   vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
// }




#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9;
const string vars[] = {"BG", "BR", "BY", "GR", "GY", "RY"};
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      char s[5];
      cin >> s;
      a[i] = find(vars, vars + 6, s) - vars;
    }
    vector<vector<int>> lf(n), rg(n);
    // lf[i][j]: 在i左侧(包括i)最近的颜色为j的城市索引
    // rg[i][j]: 在i右侧(包括i)最近的颜色为j的城市索引
    // 每一个节点 i 都存了六种颜色的上一个节点
    for (int o = 0; o < 2; ++o) {
      vector<int> last(6 , -INF) ;
      for (int i = 0; i < n; ++i) {
        last[a[i]] = (o ? n - i - 1 : i) ; 
        (o ? rg[n - i - 1] : lf[i]) = last ;
      }
      reverse(a.begin(), a.end());
    }
    while (q--) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      int ans = INF;
      for (int j = 0; j < 6; ++j) { 
        // 这一步能判断 x 和 j 是否相邻的颜色，y 和 j 是否相邻的颜色
        if (a[x] + j != 5 && j + a[y] != 5) {
          ans = min(ans, abs(x - lf[x][j]) + abs(lf[x][j] - y));
          ans = min(ans, abs(x - rg[x][j]) + abs(rg[x][j] - y));
        }
      }
      if (ans > INF / 2) ans = -1;
      cout << ans << '\n';
    }
  }
}

#include <bits/stdc++.h>
using namespace std ; 

#define int long long 
#define endl '\n' 

signed mian() {
  int tt ; cin >> tt ; 
  while ( tt -- ) {
    
  }
  return 0 ; 
}

