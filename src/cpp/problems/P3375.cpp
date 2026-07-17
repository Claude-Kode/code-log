// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  string s, p;
  cin >> s >> p;
  int n = s.size(), m = p.size();

  // 本质上 nxt 就是一个前缀函数, 但是要求的是真前缀和真后缀, 不能等于字符串本身
  // 等于本身了就相当于往后面跳了, 这是不合法的
  // 应该是往已经匹配过的范围里面跳跃 
  vector<int> nxt(m, 0);
  {
    int j = 0;
    for (int i = 1; i < m; i ++) {
      // 如果 j == 0, 则停止前跳
      // 否则一直跳到前一个字符为结尾的 前后缀最大相等长度
      // 现在的情况是: 前面已经匹配了 j 个字符，即 p[0..j-1] == p[i - j, .., i - 1]
      // 注意 这里的 j 一直都是上一个的 j 好吧
      // 能一直跳的原因为
      /*
        对于 p[1 - (i - 1)] 来说
        有长度为 j 的 pre[i - 1] 等于 suf[i - 1]
        此时 由于 0-based 的原因, p[j] 是 pre[i - 1] 的后一个字符
        那么如果这个字符不匹配, pre[i] 无法从 pre[i - 1] 直接加一个字符得到
        比如 ababc, abab的前后缀是 ab, 当扩展到 abc 的时候, 就没有前缀 abc了
        此时我们要找一个前缀, 这个前缀的后一个字符要和 此时的第 i 个字符相等
        同时这个前缀好要和, suf[i - 1] 的后缀相等
        这里存在一个连等关系
        有 pre[i - 1] = suf[i - 1]
        那么  suf[i - 1] 的后缀 也就等于 pre[i - 1] 的后缀
        pre[i - 1] 的后缀等于什么呢, 就是 pre[i - 1] 里面的 真前缀 等于 真后缀

        所以下一步直接在 pre[i - 1] 跳到他的前缀等于后缀, 然后看这个跳过去的前缀的后一个字母
        是否和 p[i] 相等即可

        然后依次递推, 当 j = 0 的时候, 此时就只剩下一个字符了, 也不能往前面跳了, 如果还找不到
        证明这个 p[i] 根本就没有 前缀和后缀相等

        还记得么, 我们的 nxt 本质意义上其实是位置, 但是由于 0-based 的原因, nxt[i] 的值 + 1
        就是那个前缀的长度
      */
      while (j and p[i] != p[j]) {
        j = nxt[j - 1];
      }
      // 此时的 j 和
      // 如果 j 没增加, 他一定是 0 了, 就是前缀没有任何一个字符和他是相等的
      j += (p[i] == p[j]);
      nxt[i] = j;
    }
  }


  // nxt[i]: 模式串[1, i] 最大前后缀相等长度

  vector<int> res;
  {
    int j = 0; // j 表示当前已经匹配的字符的数量
    for (int i = 0; i < n; i ++) {
      // 如果 j == 0, 则停止前跳
      // 这个 j 是在模式串上进行跳跃
      while (j and s[i] != p[j]) {
        j = nxt[j - 1];
      }
      j += (s[i] == p[j]);
      if (j == m) {
        res.push_back(i - m + 1);
        // 相当于这一位匹配完了, 也算不匹配成功了
        // 每次都是跳到上一个的 最长前后追长度位置即可
        j = nxt[j - 1];
      }
    }
  }

  for (auto &x : res) {
    cout << x + 1 << "\n";
  }

  for (int i = 0 ; i < m; i ++) {
    cout << nxt[i] << " \n"[i == m - 1];
  }
} 

/*如果两个指针都是单向前进的, 那么复杂度一定是线性的*/

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int tt = 1, _ = 0;
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}
