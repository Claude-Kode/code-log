// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

// REGISTER_REFLECT()

void solve() {
  int n, x, t;
  cin >> n >> t >> x;
  string s;
  cin >> s;
  int cnt_a = 0;
  // A 的作用是 帮助当前需要非空桌子的 A 来满足条件
  // 这个可能就够了
  // 我们的 A 单单这样用就可以了
  int ans = 0;
  int emp = t;
  int cand = 0;
  for (int i = 0; i < n; i ++) {
    if (s[i] == 'A') {
      if (cand > 0) {
        cand --; 
        cnt_a ++;
        ans ++;
        //  当前是第一个 A, 他只能新开, 会不会有更优解
      } else if (emp){
        emp --;
        cand += (x - 1);
        ans ++;
      }
    } else if (s[i] == 'I') {
      if (emp > 0) {
        emp --;
        cand += x - 1;
        ans ++;
      }
    } else if (s[i] == 'E' and x > 1) {
      if (cand) {
        cand --;
        ans ++;
      } else if (emp > 0 and cnt_a > 0) {
        emp --;
        cnt_a --;
        cand += x - 1;
        ans ++;
      }
    }

    // cout << "I: " << i + 1 << "\n";
    // dbug(cand);
    // dbug(emp);
    // dbug(cnt_a);
  }

  cout << ans << "\n";
  // cout << n - emp * x - cand << "\n";
}

/*
我的思路是这样的,
对于这种题目一眼看上去类似于寻找最优策略达到最优效果类型的题目, 贪心的来想,
很容想到 I 每次都要独自占用一张桌子, E每次都要尽可能的在
已经有人的桌子里面坐, 问题的关键是 A, A的关键就是,
他可以充当当所有桌子都满了的时候作为 E 的前驱新开, 也可以作为填充物,
但是问题的关键是, A 的放置可能是有后效性的, 类似于可能会存在, 我要是把 A 当做
E填充的话是不对的, 好的就是这样, 我觉得贪心是错的 然后这个时候我就会想到 dp ,
然后我的中心问题就是, 我不能很自然的想到 dp,
因为这种最优解问题除了贪心基本就是 dp 了, 所以我想请你来细细的分析一下,
好好的来证明一下这个题目

这个策略的问题在于: A 在空位尚存时总是选择“填充,
可能让我们失去提前开新桌,而桌子一旦没被开启,就永远空在那里,容量白白浪费
*/

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}