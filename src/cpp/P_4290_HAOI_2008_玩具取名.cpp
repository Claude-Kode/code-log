// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;



void solve() { 

  int a, b, c, d; cin >> a >> b >> c >> d;
  auto to = [&](char c) -> int {
    if (c == 'W') return 1;
    if (c == 'I') return 2;
    if (c == 'N') return 3;
    if (c == 'G') return 4;
  }; 

  auto from = [&](int c) -> char {
    if (c == 1) return 'W';
    if (c == 2) return 'I';
    if (c == 3) return 'N';
    if (c == 4) return 'G';
  };

  vector<vector<vector<int>>> f(4 + 1, 
  vector<vector<int>> (4 + 1, 
  vector<int>(5, 0)));

  auto work = [&](int n, char c) {
    for(int i = 1 ;i <= n; i ++) {
      string s; cin >> s;
      f[to(c)][to(s[0])][to(s[1])] = 1;
    }
  };

  work(a, 'W');
  work(b, 'I');
  work(c, 'N');
  work(d, 'G');

  // for(int i = 1; i <= 4; i ++) {
  //   for(int j = 1; j <= 4; j ++) {
  //     for(int k = 1; k <= 4; k ++) if (f[i][j][k]){
  //       cout << i << ' '<< j << ' ' << k << endl; 
  //     }
  //   }
  // }

  string s; cin >> s; int n = s.size(); s = " " + s;

  vector<vector<vector<int>>> dp(n + 1, 
  vector<vector<int>> (n + 1, 
  vector<int>(5, 0)));

  for(int i = 1; i <= n ; i++ ) dp[i][i][to(s[i])] = 1;

  for(int len = 2; len <= n; len ++) {
    for(int l = 1; l <= n - len + 1; l ++) { int r = l + len - 1; 
      for(int k = l; k < r; k ++) {
        for(int lc = 1; lc <= 4; lc ++) { // l - r 能变成什么字符
          for(int kc = 1; kc <= 4; kc ++) { // l - k 能变成什么字符
            for(int rc = 1; rc <= 4; rc ++) { // k  + 1 - r 能变成什么字符
              if (f[lc][kc][rc] && dp[l][k][kc] && dp[k + 1][r][rc]) {
                dp[l][r][lc] = 1;
              }
            }
          }
        }
      }
    }
  }

  string ans; 
  for(int i = 1; i <= 4; i++) if (dp[1][n][i]) {
    ans.push_back(from(i)); 
  }

  if (ans.empty()) cout << "The name is wrong!" << endl; 
  else cout << ans << endl;
}

/*  
给定一定的转换规则 从所给的字符串逆推得到能否推出制定的字符串

规则只规定了转换的源头和对象 并没有规定特定的位置 
所以只要存在可以转换的对象即可发生转换 , 所以发生转换的位置甚至可以说是随机的
所以这里不能使用线性 dp 可以使用区间 dp 
很显然的 我们是可以缩小问题的规模的
逆推转换的时候其实相当于折叠字符串

也就是 if f(j,k) : (i, h) = (i, j) + (j, k)(折叠后的答案) + (k, h);

很显然这个地推方向是根据长度规定的 所以我们对外层的虚幻应该是搞一个区间长度

或者这样想 最后答案是一个字母
这个字母肯定是从某两个字母合并来的
我们看那两个字母 分别从这个 (1, n) 的两个相邻的区间合并来的
也就是说已经成功分解了子问题 问题的边界是 最后如果 siz 等于  2 的时候 返回它可以被合并的那个字符

我懂了 其实一开始的题目读错了 就是两两相邻合并能不能合并出一个字符 就是这么回事
区间合并很显然就是一个 区间 dp 了

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}
 