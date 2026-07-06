// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;

struct TUP {
  int a; int b; int c; int d; 
  bool operator==(const TUP& other) const { 
    return a == other.a && b == other.b && c == other.c && d == other.d;
  }
};

struct TUPHash {
  std::size_t operator()(const TUP& t) const {
    std::hash<int> hasher;
    std::size_t h1 = hasher(t.a);
    std::size_t h2 = hasher(t.b);
    std::size_t h3 = hasher(t.c);
    std::size_t h4 = hasher(t.d);
    
    std::size_t seed = h1;
    seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= h3 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= h4 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
  }
};

void solve() { 

  int n, m; cin >> n >> m;
  vector<int> vec(n + 1), card(4 + 1);
  for(int i = 1 ; i <= n ; i ++) cin >> vec[i];
  TUP infor{0, 0, 0, 0};
  for(int i = 1 ; i <= m; i ++) {
    int temp; cin >> temp;
    if (temp == 1) infor.a ++;
    if (temp == 2) infor.b ++;
    if (temp == 3) infor.c ++;
    if (temp == 4) infor.d ++;
  }

  vector<unordered_map<TUP, int, TUPHash>> dp(n + 1);
  std::function<int(int, TUP)> dfs = [&](int p, TUP card) -> int {
    if (p > n) return INT_MIN;
    if (dp[p].find(card) != dp[p].end()) return dp[p][card];
    int res = 0;
    if (card.a) card.a -- , res = max(res, dfs(p + 1, card)), card.a ++ ;
    if (card.b) card.b -- , res = max(res, dfs(p + 2, card)), card.b ++ ;
    if (card.c) card.c -- , res = max(res, dfs(p + 3, card)), card.c ++ ;
    if (card.d) card.d -- , res = max(res, dfs(p + 4, card)), card.d ++ ;

    return dp[p][card] = max(dp[p][card], vec[p] + res);
  };

  cout << dfs(1, infor) << endl; 

}

/*

*/

int_fast32_t main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}


