// // @Author : GoryK
// #include <bits/stdc++.h>
// #define int long long

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif

// void solve() {
//   int n; std::cin >> n;
//   std::vector<int> p1(n + 1), p2(n + 1);
//   std::unordered_map<int, int> pos;
//   for (int i = 1; i <= n; i++) std::cin >> p1[i];
//   for (int i = 1; i <= n; i++) std::cin >> p2[i];
//   for (int i = 1; i <= n; i++) pos[p2[i]] = i;
//   // pos[i] 是 i 这个值在 p2 里面的位置是多少
//   // dbug(p1);
//   // dbug(p2);
//   std::vector<std::vector<int>> adj(n + 1);
//   auto build = [&](auto&& self, int l, int r) -> void {
//     if (l >= r) return;
//     int fa = l, s = l + 1;
//     while(s <= r) {
//       int t = s, mx = pos[p1[s]];
//       for(int j = s; j <= r; j ++) {
//         if (pos[p1[j]] < pos[p1[s]]) break;
//         mx = std::max(mx, pos[p1[j]]);
//         if (j - s == mx - pos[p1[s]]) {
//           t = std::max(t, j);
//         }
//       }

//       // cout << "fa: " << fa << " s: " << s << " t: " << t << '\n';
//       adj[p1[fa]].push_back(p1[s]);
//       self(self, s, t);
//       s = t + 1;
//     }
//   };

//   build(build, 1, n);

//   for (int i = 1; i <= n; i ++) if (!adj[i].empty()) {
//     for(const auto j : adj[i]) {
//       std::cout << i << ' ' << j << '\n';
//     }
//   }
// }

// // 本质上就是深度相等的连通块的顺序可以互换

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   int tt = 1, C = 0;
//   std::cin >> tt;
//   while (tt-- && ++C)
//     // std::cout << "TEST CASE : " << C << endl,
//     solve();

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using pa = pair<ll, ll>;
// const ll mod=1e9+7;
const ll mod = 998244353;
const ll MAX = 200009;

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll ksm(ll a, ll b, ll p) {
  ll res = 1;
  a %= p;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

ll fac[MAX], fc[MAX];

ll C(ll n, ll m) {
  if (m < 0 || m > n) return 0;
  return fac[n] * fc[m] % mod * fc[n - m] % mod;
}

ll a[500009];
ll b[500009], c[500009];
ll mp[500009];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll tt = 1;
  // cin>>tt;

  while (tt--) {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
      cin >> a[i];
      mp[a[i]] = i;
    }
    ll k1;
    cin >> k1;
    b[1] = mp[1];
    c[1] = mp[1];
    for (ll i = 2; i <= n; i++) {
      b[i] = min(b[i - 1], mp[i]);
      c[i] = max(c[i - 1], mp[i]);
    }
    while (k1--) {
      ll l, r;
      cin >> l >> r;
      if (b[1] >= l && c[1] <= r) {
      } else {
        cout << "1\n";
        b[1] = mp[2];
        c[1] = mp[2];
        swap(mp[1], mp[2]);
        continue;
      }
      ll l1 = 0, r1 = n + 1;
      ll k = 0;
      while (r1 - l1 > 1) {
        ll mid = (l1 + r1) / 2;
        if (b[mid] >= l && c[mid] <= r) {
          l1 = mid;
          k = mid + 1;
        } else {
          r1 = mid;
        }
      }
      if (k < n) {
        b[k] = min(b[k - 1], mp[k + 1]);
        c[k] = max(c[k - 1], mp[k + 1]);
        swap(mp[k], mp[k + 1]);
        cout << k << "\n";
      } else {
        cout << "peace\n";
      }
    }
  }
  return 0;
}

/*

 10
  10 9 4 3 2 1 6 5 8 7
  3
  1 10
  2 9
  3 9
 */
