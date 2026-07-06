// #include <bits/stdc++.h>
// using namespace std;

// #define int long long 

// const int mod = 998244353;

// array<int, 10> operator-(array<int, 10> &a, array<int, 10> &b) {
//   array<int, 10> res;
//   for (int i = 1; i <= 9; i ++) {
//     res[i] = a[i] - b[i];
//   }
//   return res;
// }

// array<int, 10> operator+(array<int, 10> &a, array<int, 10> &b) {
//   array<int, 10> res;
//   for (int i = 1; i <= 9; i ++) {
//     res[i] = b[i] + a[i];
//   }
//   return res;
// }

// class BIT {
//  public: 
//   int n;
//   vector<array<int, 10>> tree;
//  public: 
//   BIT(int _n = 1): n(_n){
//     tree.assign(n + 1, {});
//   }

//   static int lowbit(int i) {
//     return i & -i;
//   }

//   void set(int p, int v) {
//     if (p <= 0) {
//       return;
//     }

//     for (int i = p; i <= n; i += lowbit(i)) {
//       tree[i][v] ++;
//     }
//   }

//   void print() {
//     for (auto &x : tree) {
//       for (auto &c : x) {
//         std::cout << c << ' ';
//       }
//       std::cout << "\n";
//     }
//   }

//   array<int, 10> ask(int p) {
//     if (p <= 0) {
//       return {};
//     }
//     array<int, 10> res = {};
//     for (int i = p; i > 0; i -= lowbit(i)) {
//       res = res + tree[i];
//     } 
//     return res;
//   }
// };  

// void solve() {
//   int n; cin >> n;
//   // cout << n << "\n";
//   vector<int> vec(n + 1), mx_dig(n + 1);
//   for (int i = 1; i <= n; i ++) {
//     string s; cin >> s;
//     // cout << s << "\n";
//     mx_dig[i] = ranges::max(s) - '0';
//     vec[i] = stoll(s);
//   }

//   int pre = 0, ans = 0;
//   BIT bit(n + 1);
//   map<int, int> mp;

//   auto minus = [&](const array<int, 10>& a, const array<int, 10>& b) -> array<int, 10> {
//     array<int, 10> res = {};
//     for (int i = 0; i < 10; i ++) {
//       res[i] = a[i] - b[i];
//     }
//     return res;
//   };

//   vector<int> st(10, 0); 
//   for (int i = 1; i <= n; i ++) {
//     pre += vec[i];
//     int mx = mx_dig[i];

//     bit.set(i, pre % 10);

//     for (int d = mx; d <= 9; d ++) {
//       int L = st[min(d + 1, 9LL)];
//       auto res = minus(bit.ask(i) - bit.ask(L - 1)); 
//     }

//     for (int d = 1; d <= mx; d ++) {
//       st[d] = i;
//     }
//   }
//   // for (int i = 1; i <= n; i ++) {
//   //   pre = pre + vec[i];
//   //   cout << "i: " << i << " pre: " << pre % 10 << "\n";
//   //   bit.set(i, pre % 10);

//   //   int d = mx_dig[i];
//   //   mp[d] = 1;

//   //   for (int j = d; j <= 9; j ++) {
//   //     if (!mp[j]) continue;

//   //     cout << "exist: " << j << "\n";

//   //     int L = st[min(j + 1, 9LL)];
//   //     cout << "L: " << L << "\n";
//   //     auto res1 = bit.ask(i);
//   //     auto res2 = bit.ask(L - 1);
//   //     vector<int> res(10, 0); 
//   //     for (int j = 0; j <= 9; j ++) {
//   //       res[j] = res1[j] - res2[j];
//   //     } 

//   //     for (int k = 0; k <= 9; k ++) {
//   //       // if ((j + k) % 10 == pre % 10)
//   //       int diff = ((pre % 10 == k) ? 10 : (pre - k) % 10);
//   //       // 当 pre == k 的时候, 如果可以成立
//   //       // res[k] 有可能包括 左边界在 L 左侧的不合法部分
//   //       // res[pre] 的左边界是 0
//   //       if (diff % j == 0) {
//   //         // if (pre == k and pre % j != 0) continue;
//   //         cout << "pre: " << pre % 10 << " diff: " << diff << " from: " << k << " ";
//   //         int plus = res[k];
//   //         // if (L > 0 and pre == k) {
//   //         //   ans = (ans - 1) % mod;
//   //         // }
//   //         cout << "plus: " << plus << "\n";
//   //         // cout << "orin: " << res[k] << "\n";
//   //         ans = (ans + plus) % mod;
//   //       }


//   //     }

//   //     for (int j = 1; j <= d; j ++) {
//   //       st[j] = i;
//   //     }

//   //   }


//   //   cout << "\n";
//   // }

//   cout << ans << "\n";
// }
// /*
// 预处理 每个数组元素的每个数字(1 - 9)
// 他们就是向左延伸的最大程度和最小长度
// 然后维护一个前缀和 ? 就是查一下之类的

// 前缀和存那个模数, %10 
// 然后就是暴政那个查出来的范围也是额那个什么的数量
// 可能有个二维偏序 ? 就是查前面有多少个就是
// pre[i] - d 然后按照位置排序, 在我们上面预处理的区间的有多少, 这个树桩数组吧

// 前缀和用线段树查询一下对可以
// */
// signed main() {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int tt = 1, _ = 0;
//   cin >> tt;
//   while(tt --) {
//     cout << "TEST_CASE: " << ' ' << ++_ << "\n";
//     solve();
//   }

//   return 0;
// }


// // array<int, 10> operator-(array<int, 10> &a, array<int, 10> &b) {
// //   array<int, 10> res;
// //   for (int i = 1; i <= 9; i ++) {
// //     res[i] = a[i] - b[i];
// //   }
// //   return res;
// // }

// // auto res = minus(bit.ask(i), bit.ask(L - 1));
// // res = res - bit.ask(L - 1);


// // vector<vector<int>> L(n + 1, vector<int>(10));
// // vector<stack<int>> st(10);
// // st[d], 前面大于等于 d 的最靠后的位置

// // if (d1 != d2) {
// //   ans = (ans + res[d2]) % mod;
// // }

// // bit.print();
// // for (int i = 1; i <= n; i ++) {
// //   for (int j = 0; j <= 9; j ++) {
// //     std::cout << bit.tree[i][j] << " ";
// //   } 
// //   std::cout << "\n";
// // }

// // d2 = (pre - d + 10) % 10;
// // cout << "d1 | d2: " << d1 << ' ' << d2 << "\n";

// // int d1 = (pre - d + 10) % 10;
// // cout << "d1: " << d1 << "\n";
// // // for (int j = 0; j <= 9; j ++) {
// // //   cout << res[j] << " \n"[j == 9];
// // // }
// // cout << "plus: " << res[d1] << "\n";
// // ans = (ans + res[d1]) % mod;

// // for (int j = d + 1; mp[j]; j ++) {
// //   ans = (ans + res[(pre - j + 10) % 10]);
// // }

// // if (pre == k and k % j != 0) continue;
// // if ((pre - k + 10 * j) % j == 0) 

// // if (pre % j == 0) {
// //   if (L > 0) {
// //     res[pre % 10] --;
// //   } else {
// //     ans ++;
// //   }
// //   // cout << "minus: " << ' ' << pre % 10 << ' ' << res[pre % 10] << "\n";
// // } 
#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
  // cout << 10 % 0 << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  // cin >> tt;
  while(tt --) {
    solve();
  }

  return 0;
}