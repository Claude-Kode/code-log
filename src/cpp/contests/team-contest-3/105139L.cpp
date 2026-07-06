#include <bits/stdc++.h>
using namespace std;

#define int long long 

#define dbug(x) (std::cout << #x << ": " << x << "\n")

const int N = 1e7 + 1;
vector<int> pr;
vector<int> vis(N + 1, 0); 

void prime(int n) {
  vis[1] = 1;
  for (int i = 2; i <= n; i ++) {
    if (!vis[i]) pr.push_back(i);
    for (const auto &j : pr) {
      if (i * j > n) break;
      vis[i * j] = 1;
      if (i % j == 0) break;
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;

  // 为什么要最小素数
  auto cal = [&](int x) -> int {
    if (!vis[x]) {
      return x;
    }    
    for (const auto &a : pr) {
      if (x % a == 0) return a;
    }
  };

  int ga = cal(a),
      gb = cal(b);

  int ans = min(lcm(a, b), a + a + b + b);
  if (gcd(a, b) > 1) {
    ans = min(ans, a + b); 
  } else {
    vector<int> v = {ga, gb};
    if (ga != 2 and gb != 2) {
      v.push_back(2);
      ans = min(ans, a + b + 2 * (ga + gb));
    }

    for (int& x : v) {
      ans = min(ans, lcm(a, x) + lcm(x, b));
    }

    for (int& x1 : v) {
      for (int& x2 : v) {
        if (x1 == x2) continue;
        ans = min(ans, lcm(a, x1) + lcm(x1, x2) + lcm(x2, b));
      }
    }
  }

  cout << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  prime(N);

  int tt = 1;
  cin >> tt;
  while(tt --) {
    solve();
  }

  return 0;
}