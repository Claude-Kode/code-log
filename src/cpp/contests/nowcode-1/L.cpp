#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long

const int mod = 998244353;

using u64 = uint64_t;

u64 BASE = 131;
u64 MOD1 = 1E9 + 7;
u64 MOD2 = 1E9 + 9;

u64 BASE = 131;
u64 MOD1 = 1E9 + 7;
u64 MOD2 = 1E9 + 9;

struct StrHash {
  vector<u64> h1, h2, p1, p2;
  StrHash() = default;   
  StrHash(const string& s) { 
    int n = s.size(); 
    h1.assign(n + 1, 0); h2.assign(n + 1, 0);
    p1.assign(n + 1, 0); p2.assign(n + 1, 0);
    for (int i = 0; i < n; i ++) {
      h1[i + 1] = (h1[i] * BASE + s[i]) % MOD1;
      h2[i + 1] = (h2[i] * BASE + s[i]) % MOD2;
      p1[i + 1] = (p1[i] * BASE) % MOD1;
      p2[i + 1] = (p2[i] * BASE) % MOD2;
    }
  }

  pair<u64, u64> get(int l, int r) {
    u64 v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
    u64 v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return {v1, v2};
  }
};

void solve() {
  int n; cin >> n;
  string s; cin >> s; 
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }


}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }

  return 0;
}