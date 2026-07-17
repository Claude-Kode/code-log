// // @Author : GoryK
// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")
// #include <bits/stdc++.h>
// using namespace std;

// #define int int_fast64_t
// #define endl '\n'

// const int mod = 1e9 + 7; 
// const int N = 2e5 + 10;

// vector<int> prime(int n) {
//   vector<int> vis(N , 0) , pr ; 
//   for ( int i = 2 ; i <= n ; i ++ ) {
//     if( !vis[i] ) pr.push_back( i ) ;  
//     for ( const auto &j : pr ) {
//       if (i * j > n) break ; 
//       vis[i * j] = 1 ; 
//       if (i % j == 0) break ; 
//     }
//   }
//   return pr ; 
// }
 
// vector<int> pr;

// void solve() { 

//   int n; cin >> n;
  

// }

// /*

// */

// signed main() {
  
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
  
//   #ifdef GK
//     freopen("INPUT.txt", "r", stdin);
//     freopen("OUTPUT.txt", "w", stdout);
//   #endif 

//   // cout << fixed << setprecision(6);

//   pr = prime(100);
//   // for(const auto &a : pr) cout << a << ' ';


//   int tt , CNT = 0; cin >> tt;
//   while(tt -- && ++CNT) 
//     // cout << "TEST CASE : " << CNT << endl,
//     solve();
  
//   return 0;
// }

