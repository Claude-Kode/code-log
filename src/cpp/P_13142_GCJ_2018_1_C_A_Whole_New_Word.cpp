// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n, l, cnt_node;
vector<vector<int>> t;

void insert(string s) {
  int len = s.size(), p = 0;
  for(int i = 0; i < len; i ++) {
    int c = s[i] - 'A';
    if (!t[p][c]) t[p][c] = ++cnt_node;
    p = t[p][c]; 
  }
}

void solve() { 
  cin >> n >> l; cnt_node = 0;
  t.assign(n * 26 + 1, vector<int>(26, 0));

  vector<string> vec(n + 1);
  vector<unordered_set<int>> st(l + 10);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i];
    insert(vec[i]);
    for(int j = 0; j < l; j ++) {
      st[j].insert(vec[i][j] - 'A');
    }
  }

  // st[i] 的含义 : 第 i + 1个字符可以用啥的集合

  string ans = ""; bool find = false;
  auto dfs = [&](this auto&& dfs, int u, int d, string s) -> void {
    // dbug(d);dbug(s);
    if (d == l || find) return;
    for(int i = 0; i < 26; i ++) {
      if (t[u][i] == 0 && st[d].count(i)) {
        ans = s + (char)(i + 'A');
        find = true;
        // cerr << 1 << endl;
        return; 
      } else if (t[u][i]) {
        dfs(t[u][i], d + 1, s + (char)(i + 'A'));
      }
    }
  };

  dfs(0, 0, "");
  if (ans != "") {
    for(int i = ans.size() + 1; i <= l; i ++) {
      ans += (*st[i - 1].begin() + 'A');
    }
    cout << ans << endl;
  } else {
    cout << "-" << endl;
  }
}

/*
暴力搜索的话在外面记录一下变量是更好的选择哦 别忘了
他妈的之前写的跟吃了屎一样真他妈 难写
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // for(int i = 'A'; i <= 'Z'; i ++) {
  //   s.insert(i);
  // }

  // for(const auto &x : s) cout << x << ' ';
  // dbug(s);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    cout << "Case #" << CNT  << ": ",
    solve();
  
  
  return 0;
}