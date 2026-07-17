// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void dedup(vector<pair<int, int>>& vec ) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}
    
void solve() { 

  int n, m; cin >> n >> m;
  string s = " ", temp; cin >> temp; s += temp;
  vector<int> l0(n + 1), r1(n + 1);
  l0[1] = 0;
  for(int i = 2; i <= n ; i ++ ) {
    l0[i] = l0[i - 1]; if (s[i] == '0') l0[i] = i;
  }

  r1[n] = n + 1;
  for(int i = n - 1; i > 0; i --) {
    r1[i] = r1[i + 1]; 
    if (s[i] == '1') r1[i] = i;
  }

  set<pair<int, int>> st; 
  for(int i = 1; i <= m; i ++) {
    int l, r; cin >> l >> r;
    int ll = r1[l], rr = l0[r];
    if (ll > rr) st.insert({0, 0});
    else st.insert({ll, rr});
  }

  cout << st.size() << endl; 
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}