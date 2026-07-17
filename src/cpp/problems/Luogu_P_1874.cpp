// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int INF = 1e9;
int len, n;
string s;
vector<vector<int>> memo;

int dfs(int pos, int sum) {
  if (sum < 0) return INF;
  if (pos == len) return (sum == 0) ? 0 : INF;
  
  if (memo[pos][sum] != -1) return memo[pos][sum];
  
  int ans = INF, val = 0;
  
  // 主要的想法就是在这里啊 我的那个是子集型枚举写起来会很麻烦 
  // 这个直接通过 for 循环枚举下一个断点 优雅的很
  for (int i = pos; i < len; i++) {
    val = val * 10 + s[i] - '0';
    if (val > sum) break;
    int next = dfs(i + 1, sum - val);
    if (next != INF) {
      ans = min(ans, next + (pos != 0));
    }
  }
  
  return memo[pos][sum] = ans;
}

void solve() {
  cin >> s >> n;
  len = s.size();
  memo.assign(len + 1, vector<int>(n + 1, -1));
  
  int res = dfs(0, n);
  cout << (res >= INF ? -1 : res) << endl;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    
  solve();
  
  return 0;
}