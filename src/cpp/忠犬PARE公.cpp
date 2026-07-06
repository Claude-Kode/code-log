// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCCtarget("avx,avx2")
// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

const int mod = 100000007;
const int N = 5000010;

std::vector<int> pr;

int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

void prime(int n) {
  vector<int> vis(N, 0);
  for (int i = 2; i <= n; i ++) {
    if(!vis[i]) pr.push_back( i ) ;  
    for (const auto &j : pr) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
}

map<int, int> prime_factor(int a, const vector<int>& pr) {
  map<int, int> factors;
  for (const auto &x : pr) if(a % x == 0) {
    while (a % x == 0) factors[x] ++, a /= x;
    if ( a < x ) { if (a > 1) factors[a]++; break; }
  } 
  return factors;
}

void solve() {    
  int n, m, suma = 0, sumb = 0; 
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i ++) {
    std::cin >> a[i];
    suma += a[i];
    suma %= mod;
  }

  for (int i = 1; i <= m; i ++) {
    std::cin >> b[i];
    sumb += b[i];
    sumb %= mod;
  }

  int pw = (suma % mod * sumb % mod) % mod;

  std::map<int, std::vector<int>> mpa, mp_pre;
  for(int i = 1; i <= n; i ++) {
    std::map<int, int> tmp = prime_factor(a[i], pr);
    for (const auto &[k, v] : tmp) {
      mpa[k].push_back(v);
    } 
  }

  for (auto &[k, v] : mpa) {
    std::sort(v.begin(), v.end());
    std::vector<int> pre(v.size() + 1, 0);
    for (int i = 0; i < v.size(); i ++) {
      pre[i + 1] = pre[i] + v[i];
    }
  }

  dbug(mpa);

  int g = 1;
  for (int i = 1; i <= m; i ++) {
    auto mpb = prime_factor(b[i], pr);
    for (const auto &[k, v] : mpb) {
      if (!mpa.count(k)) continue;
      auto it = std::lower_bound(mpa[k].begin(), mpa[k].end(), v);
      int cnt_pre = it - mpa[k].begin(),
          cnt_suf = mpa[k].size() - cnt_pre;

      dbug(v);
      dbug(mpa[k]);
      dbug(cnt_pre);
      dbug(cnt_suf);
      // cout << 
      g = (((g % mod) + fp(k, mp_pre[k][cnt_pre], mod)) % mod * fp(k, cnt_suf * v, mod)) % mod;
    }
  }

  cout << pw << ' ' << g << "\n";

  // g = fp(g, 2, mod);
  // int ans = (pw % mod * fp(g, mod - 2, mod) % mod) % mod;
  // std::cout << ans << "\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  prime(N - 1);

  int tt = 1, _ = 0; 
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();
  return 0;
}