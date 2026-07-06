// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 998244353; 
const int N = 2e5 + 10;

vector<vector<int>> C;
vector<int> fact(N);

void generate_c(int n) {
  vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));
  for (int i = 1 ; i <= n ; i ++) { 
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j ++ ) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

int cmb(int n, int k, vector<vector<int>>& C) {
  if (k < 0 || k > n) return 0;
  return C[n][k];
}

int MOD(vector<int> vec) {
  int res = 1;
  for(const auto &a : vec) res = (res % mod * a % mod) % mod;
  return res % mod;
}

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 0; i <= n; i ++) cin >> vec[i];

  int sum = accumulate(vec.begin(), vec.end(), 0LL);
  int cnt = 0, k = sum / n, rem = sum % n;
  for(int i = 1; i <= n; i ++) {
    if (vec[i] > k + 1) {cout << 0 << endl; return; }
    else if (vec[i] == k + 1) cnt ++;
    else vec[0] -= -(vec[i] - k);
  }

  if (vec[0] < 0) {cout << 0 << endl; return; }

  // int ans = ans = (((cmb(n - cnt, rem - cnt, C) % mod * fact[rem] % mod) % mod) * fact[n - rem]% mod) % mod;
  cout << MOD(vector<int>{cmb(n - cnt, rem - cnt, C), fact[rem], fact[n - rem]}) << endl;
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

  generate_c(60);

  fact[0] = fact[1] = 1;
  for(int i = 2; i <= N - 1; i ++) fact[i] = (fact[i - 1] * i) % mod;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}