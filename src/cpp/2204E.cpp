// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 9e5 + 10;

vector<array<int, 10>> buc(N);
vector<int> sum(N);
vector<vector<int>> sum_to_x(N);
vector<string> str(N);

void solve() { 
  string s; cin >> s;
  if (s.size() == 1) {cout << s << endl; return; }
  // cout << "STR: " << s << endl; 
  vector<int> arr(10, 0);
  int m = 0;
  for(const char &c : s) {
    arr[c - '0'] ++;
    m += c - '0';
  }

  // for(int i = 0; i < 10; i ++) cout << arr[i] << ' ';
  // cout << endl; 

  int cnt = 0;
  for(const auto &a : sum_to_x[m]) {
    cnt ++ ;
    if (cnt >= 100) {cout << "break" << endl; return; }
    bool f = true;
    for(int i = 0; i < 10; i ++) f &= (arr[i] >= buc[a][i]);
    if (!f) continue;
    for(int i = 9; i >= 0; i --) {
      int t = arr[i] - buc[a][i];
      while (t -- ) cout << i;
    } 
    cout << str[a] << endl;
    return; 
  }

}
/*
可以很简单的证明出来 转化次数是十分有限的
是 log{10}_{len(s)} 级别 只有 10 以内的转化
但是这个checker 好像有点难写
对于一个数字 x 变成 S(-1)(x) 的话 我们应该是不能把一个数表示成一个数字的
这样是一定会爆炸的
我觉得大概的策略是用一个桶来存数字之类的
但是 sum_digit == num 这个 num 可能会超级大 吗
是不是可以证明 我们需要用做计算的 num 在数字范围内是可以接受的
好像是可以的我去
然后写一个暴力的 DFS 感觉大概的思路就是这样的

这个暴力 dfs 写到一半出了问题了 就是对于当前的 num 来说  我可能有非常多的组合 难道是全都尝试一遍吗

这个题好像本质上就是一个预处理
对于任意的字符我们可以知道 他们对应的 sum_digit(str) 是唯一的

前面我已经退出来了
对于所有的 sum_digit(x) 他的大小是可以通过有限个次数枚举出来了的

str = x + s(x) + s(s(x)) ... 我们对那个 除了 x 的剩下部分好像都能算的出来呢 ?

我懂了 这个题可能是有一个可替代性, 就是即使是非常的大的数组生成的序列 S(x) 
也可以通过一个范围内的数来生成相同字符频次的序列

其实这个题真的特别简单 我都绷不住了 我真是个傻逼

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

  auto s = [&](int x) -> int {
    int res = 0;
    while(x) res += x % 10, x /= 10;
    return res;
  };

  for(int i = 1; i <= N; i ++) {
    int x = i;
    while(x > 9) { sum[i] += x; str[i] += to_string(x), x = s(x); }
    // 要加两次的原因是 最小的数的数字和就是它本身
    str[i] += to_string(x), sum[i] += x * 2;
    for(const char &c : str[i]) buc[i][c - '0'] ++;
    if(sum[i] <= N) sum_to_x[sum[i]].push_back(i);
  } 

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}
