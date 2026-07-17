// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, m; cin >> n >> m;
  vector<unordered_map<int, int>> adj(n + 1);
  vector<int> in(n + 1);
  for(int i = 1; i <= m; i ++) {
    int u,v; cin >> u >> v;
    adj[u][v] ++;
    in[v] ++;
  }

  int node = 0, cnt = 0;
  for(int i = 1; i <= n; i ++) {
    if (!in[i]) cnt ++, node = i;
  }

  if (cnt != 1) {cout << 0 << endl; return;}
  queue<int> q; q.push(node); 
  vector<int> seq;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    seq.push_back(u);
    for(const auto &[v, cnt] : adj[u]) {
      in[v] -= cnt;
      if (!in[v]) {
        q.push(v);
      }

    }
  }

  // for(const auto &a : seq) {
  //   cout << a << ' ' ;
  // } cout << '\n';

  int mm = seq.size(), ans = 1;
  for(int i = 1; i < mm; i ++) {
    (ans *= adj[seq[i - 1]][seq[i]]) %= mod;
  }
  cout << ans % mod << endl;
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}