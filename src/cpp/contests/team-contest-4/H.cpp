#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  int n; cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 2; i <= n; i ++) {
    pq.push(vec[i]);
  }

  int s = vec[1];
  while(pq.size()) {
    if (pq.top() < s) {
      pq.pop(); 
      continue;
    }
    int t = pq.top();
    pq.pop();
    int a = s + t;
    s = (s + t + 1) / 2;
  }

  cout << s << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  cin >> tt;
  while(tt --) {
    solve();
  }

  return 0;
}