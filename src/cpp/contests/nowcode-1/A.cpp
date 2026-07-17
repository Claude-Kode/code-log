#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long

unordered_map<char, int> ump;

void solve() {
  ump['a'] = 1;
  ump['e'] = 1;
  ump['i'] = 1;
  ump['o'] = 1;
  ump['u'] = 1;
  string s; cin >> s;
  if (s.size() != 8 ){
    cout << "Well-Being" << "\n";
    return; 
  }
  
  s = " " + s;
  for (int i = 1; i <= 8; i ++) {
    if (i & 1) {
      if (ump[s[i]]) {
        cout << "Well-Being" << '\n';
        return;
      }
    } else {
      if (ump[s[i]] == 0) {
        cout << "Well-Being" << '\n';
        return;
      }
    }
  }

  cout << "Suspected Virus" << '\n';
  return;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1;
  cin >> tt;
  while (tt --) {
    solve();
  }

  return 0;
}