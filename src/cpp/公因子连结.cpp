#ifdef __GNUC__
  #pragma GCC optimize("fast-math")
  #pragma GCC optimize("Ofast, unroll-loops = full")
  #pragma GCCtarget("avx, avx2")
#endif

// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

// #define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else
  #define dbug(...)
#endif

// REGISTER_REFLECT()

/*
这个题可能是某种神秘的数据结构, 然后实现区间修改区间查询
难道是线段树套 map
*/

const int N = 1e7 + 1;
vector<int> pr;
vector<int> vis(N , 0);

void prime(int n) {
  vis[1] = 1;
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;
    for ( const auto &j : pr ) {
      if (i * j > n) break ;
      vis[i * j] = 1 ;
      if (i % j == 0) break ;
    }
  }
}

class BIT {
public:
  int n;
  std::vector<int> tree;
public:
  BIT(int _n = 1) : n(_n) {tree.assign(n + 1, 0);}
  static int lowbit(int i) {return i & -i;}

  void set(int p, int v) { // 不能 update(0, ?) 会死循环
    if (p <= 0) return;
    for(int i = p; i <= n; i += lowbit(i)) {
      tree[i] += v;
    }
  }

  int ask(int p) {
    if (p <= 0) return 0;
    int res = 0;
    for(int i = p; i > 0; i -= lowbit(i)) {
      res += tree[i];
    }
    return res;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vector<set<int>> vec(n + 1);

  auto div = [&](int i, int num) -> void {

    if (num == 1) {
      return;
    }

    if (!vis[num]) {
      vec[i].insert(num);
      return;
    }

    for (auto& a : pr) {
      if (a * a > num) break;
      if (num == 1) break;
      while (num % a == 0) {
        vec[i].insert(a);
        num /= a;
      }
    }
    // 为什么不加这一行会错啊
    if (num > 1) vec[i].insert(num);
  };

  for (int i = 1; i <= n; i ++) {
    int temp; cin >> temp;

    // assert(temp != 1);

    div(i, temp);
    // dbug(temp);
    // dbug(vec[i]);
  }

  map<int, vector<array<int, 2>>> qs;
  for (int i = 1; i <= q; i ++) {
    int l, r; cin >> l >> r;
    qs[r].push_back({l, i});
  }

  for (auto &[k, v] : qs) {
    sort(v.begin(), v.end(), [&](const auto &a, const auto &b){
      return a[0] < b[0];
    });
  }

  vector<int> ans(q + 1);
  BIT bit(n + 1);
  map<int, int> pre;
  for (int i = 1; i <= n; i ++) {
    for (const auto& fac : vec[i]) {
      if (pre[fac]) {
        bit.set(pre[fac], -1);
      }
      bit.set(i, 1);
      pre[fac] = i;
    }

    if (!qs.count(i)) continue;
    for (auto &[l, pos] : qs[i]) {
      ans[pos] = bit.ask(i) - bit.ask(l - 1);
    }
  }

  for (int i = 1; i <= q; i ++) {
    cout << ans[i] << "\n";
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  prime(N);

  // for (int i = 0; i < 10; i ++) {
  //   cout << pr[i] << " \n"[i == 9];
  // }

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using pa = pair<ll, ll>;
// const ll mod=1e9+7;
const ll mod = 998244353;
const ll MAX = 10000009;
ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll ksm(ll a, ll b) {
  ll res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll fac[MAX], fc[MAX];

void init_comb(ll n) {
  fac[0] = 1;
  for (ll i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  fc[n] = ksm(fac[n], mod - 2);
  for (ll i = n - 1; i >= 0; i--) fc[i] = fc[i + 1] * (i + 1) % mod;
}

ll C(ll n, ll m) {
  if (m < 0 || m > n) return 0;
  return fac[n] * fc[m] % mod * fc[n - m] % mod;
}
ll a[100009];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll tt = 1;
  cin >> tt;
  while (tt--) {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
      cin >> a[i];
    }

    for (ll i = 0; i < 31; i++) {
      for (ll j = 0; j < 31; j++) {
        ll s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for (ll k = 1; k <= n; k++) {
          if (a[k] & (1 << i)) {
            if (a[k] & (1 << j)) {
              s1++;
              ans += s4;
            } else {
              s2++;
              ans += s3;
            }
          } else {
            if (a[k] & (1 << j)) {
              s3++;
              ans += s2;
            } else {
              s4++;
              ans += s1; 
            }
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
/*

*/
