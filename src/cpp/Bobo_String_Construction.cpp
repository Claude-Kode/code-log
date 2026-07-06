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

int kmpCount(const std::string& text, const std::string& pattern) {
  if (pattern.empty()) {
    return 0;  // 空模式串按需求返回 0，也可改为 text.size() + 1
  }

  int n = text.size();
  int m = pattern.size();

  // 1. 构建 pattern 的 next 数组（部分匹配表）
  //    next[i] = pattern[0..i] 的最长相等真前后缀长度
  std::vector<int> next(m, 0);
  int j = 0;  // 前缀指针
  for (int i = 1; i < m; ++i) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = next[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      ++j;
    }
    next[i] = j;
  }

  // 2. 在 text 中搜索 pattern
  int count = 0;
  j = 0;  // 模式串当前匹配位置
  for (int i = 0; i < n; ++i) {
    // 当前字符不匹配，回退 j
    while (j > 0 && text[i] != pattern[j]) {
      j = next[j - 1];
    }
    if (text[i] == pattern[j]) {
      ++j;
    }
    // 找到一个完整匹配
    if (j == m) {
      ++count;
      // 允许重叠匹配：回退到 next[j-1] 继续搜索
      // 若不允许重叠，改为 j = 0 即可
      j = next[j - 1];
    }
  }
  return count;
}

void solve() { 
  int n; cin >> n;
  string t; cin >> t;
  string s1(n, '1'), s2(n, '0');
  if (kmpCount(t + s1 + t, t) == 2) {cout << s1 << endl; return;}
  if (kmpCount(t + s2 + t, t) == 2) {cout << s2 << endl; return;}
  cout << -1 << endl; 
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}