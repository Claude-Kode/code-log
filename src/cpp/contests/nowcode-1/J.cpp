#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else
  #define dbug(...)
#endif

using VEC = vector<int>;

auto to_num = [](char c) -> int {
  if (c == 'A') return 13;
  if (c == 'K') return 12;
  if (c == 'Q') return 11;
  if (c == 'J') return 10;
  if (c == 'T') return 9;
  if (c == '9') return 8;
  if (c == '8') return 7;
  if (c == '7') return 6;
  if (c == '6') return 5;
  if (c == '5') return 4;
  if (c == '4') return 3;
  if (c == '3') return 2;
  if (c == '2') return 1;
  return 0;
};

auto to_sign = [](char c) -> int {
  if (c == 'C') return 1;
  if (c == 'D') return 2;
  if (c == 'H') return 3;
  if (c == 'S') return 4;
  return 0;
};

struct Card {
  map<int, int, greater<int>> num_cnt;
  map<int, vector<int>, greater<int>> cnt_num;
  map<int, int> sig_cnt;
  vector<int> cnts;
};

// REGISTER_REFLECT(Card, num_cnt, cnt_num, sig_cnt, cnts);

void solve() {
  Card A, B;
  vector<vector<int>> rem(14, vector<int>(5, 1));
  for (int i = 1; i <= 4; i++) {
    string s;
    cin >> s;
    int val = to_num(s[0]);
    int sig = to_sign(s[1]);
    A.num_cnt[val]++;
    A.sig_cnt[sig]++;
    rem[val][sig] = 0;
  }

  for (int i = 1; i <= 4; i++) {
    string s;
    cin >> s;
    int val = to_num(s[0]);
    int sig = to_sign(s[1]);
    B.num_cnt[val]++;
    B.sig_cnt[sig]++;
    rem[val][sig] = 0;
  }

  auto work = [&](Card& t) -> void {
    auto& [num_cnt, cnt_num, sig_cnt, cnts] = t;
    for (auto& [num, cnt] : num_cnt) {
      cnt_num[cnt].push_back(num);
    }

    for (auto& [cnt, nums] : cnt_num) {
      for (int i = 0; i < (int)nums.size(); i++) {
        cnts.push_back(cnt);
      }
    }
  };

  // work(A);
  // work(B);
  // cout << "A: \n";
  // dbug(A);
  // cout << "B: \n";
  // dbug(B);

  auto mask = [&](map<int, vector<int>, greater<int>> cnt_num, bool spe) -> int {
    vector<int> vals; 
    if (spe) {
      cnt_num[1] = {4, 3, 2, 1, 0};
    }
    for (auto& [cnt, nums] : cnt_num) {
      for (int i = 1; i <= cnt; i++) {
        for (auto& x : nums) {
          vals.push_back(x);
        }
      }
    }
    int res = 0, base = 1;
    while (!vals.empty()) {
      res += vals.back() * base;
      vals.pop_back();
      base *= 13;
    }

    return res;
  };

  auto best = [&](Card& t) -> pair<int, int> {
    auto& [num_cnt, cnt_num, sig_cnt, cnts] = t;
    int mx_val = num_cnt.begin()->first, mn_val = prev(num_cnt.end())->first,
        mx_dif = mx_val - mn_val + 1;

    bool spe = true;
    for (int i = 1; i < 5; i ++) {
      spe &= num_cnt[i] & (num_cnt[13] == 1);
    }

    for (int i = 0; i <= 13; i ++) {
      if (num_cnt[i] == 0) {
        num_cnt.erase(i);
      }
    }

    // 9: 一种花色, 四种值, 连续
    if (sig_cnt.size() == 1 and mx_val == 13 and mn_val == 9 and
        num_cnt.size() == 5) {
      return pair(9LL, mask(cnt_num, false));
    }

    // 8: 一种花色, 5种值, 连续
    if (sig_cnt.size() == 1 and num_cnt.size() == 5 and (mx_dif == 5 or spe)) {
      return pair(8LL, mask(cnt_num, spe));
    }

    // 7: 4 + 1
    if (cnts == VEC{4, 1}) {
      return pair(7LL, mask(cnt_num, false));
    }

    // 6: 3 + 2
    if (cnts == VEC{3, 2}) {
      return pair(6LL, mask(cnt_num, false));
    }

    // 5: 同花, 没有相同值
    if (sig_cnt.size() == 1 and num_cnt.size() == 5) {
      return pair(5LL, mask(cnt_num, false));
    }

    // 4: 递增排列,
    if (num_cnt.size() == 5 and (mx_dif == 5 or spe)) {

      return pair(4LL, mask(cnt_num, spe));
    }

    // 3: 3 + 1 + 1
    if (cnts == VEC{3, 1, 1}) {
      return pair(3LL, mask(cnt_num, false));
    }

    // 2: 2 + 2 + 1
    if (cnts == VEC{2, 2, 1}) {
      return pair(2LL, mask(cnt_num, false));
    }

    // 1: 2 + 1 + 1 + 1
    if (cnts == VEC{2, 1, 1, 1}) {
      return pair(1LL, mask(cnt_num, false));
    }

    // 0: 1 + 1 + 1 + 1 + 1
    if (cnts == VEC{1, 1, 1, 1, 1}) {
      return pair(0LL, mask(cnt_num, false));
    }

    return {-1, -1};
  };

  auto F = [&](Card& t, int i, int j) -> void {
    t.num_cnt[i] ++;
    t.sig_cnt[j] ++;
    t.cnts.clear();
    t.cnt_num.clear();
    work(t);
  };

  bool no_win = false;
  for (int i1 = 1; i1 <= 13; i1++) {
    for (int j1 = 1; j1 <= 4; j1++) {
      if (rem[i1][j1] == 0) continue;
      auto a = A; F(a, i1, j1); auto res_a = best(a);
      bool a_win = true;
      for (int i2 = 1; i2 <= 13; i2++) {
        for (int j2 = 1; j2 <= 4; j2++) {
          if (rem[i2][j2] == 0) continue;
          if (i1 == i2 and j1 == j2) continue;
          auto b = B; F(b, i2, j2); auto res_b = best(b);
          if (res_a <= res_b) {
            a_win = false;
          } 
          if (res_a == res_b) {
            no_win = true;
          } 
        }
      }
      if (a_win) {
        cout << "WoYaoYanPai" << "\n";
        return;
      }
    }
  }

  if (no_win) {
    cout << "PaiMeiYouWenTi" << "\n";
  } else {
    cout << "GeiWoCaPiXie" << "\n";
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- and ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

/*
位置	改动
1	外循环 rem[i1][j1] 检查	从内层 continue 移到外循环顶部单独 continue，防止选已占牌时 a_win 保持 true 误判必胜
2	best 函数删掉 if (num_cnt[13]) { swap; work } 块	原有副作用：只要手牌有 A 就把 13 换成 0，破坏大部分手牌
3	best 加 is_wheel 检测	mx_val==13 && mn_val==1 && num_cnt.size()==5 && count(2) && count(3) && count(4)
4	rank 8/4 条件 mx_dif == 5 → mx_dif == 5 || is_wheel	同花顺/顺子兼容 A-2-3-4-5
5	rank 8/4 的 mask：wheel 时调用 wheel_mask（把 13→0）	wheel 的 A 算最小避免 mask 偏大
6	res_a == res_b 时加 a_win = false	平局不应算必胜
*/

// // #include <bits/stdc++.h>
// // using namespace std;

// // #define int long long

// // #ifdef LOCAL
// //   #include "__DEBUG_TOOL.h"
// // #else
// //   #define dbug(...)
// // #endif

// // using VEC = vector<int>;

// // auto to_num = [](char c) -> int {
// //   if (c == 'A') return 13;
// //   if (c == 'K') return 12;
// //   if (c == 'Q') return 11;
// //   if (c == 'J') return 10;
// //   if (c == 'T') return 9;
// //   if (c == '9') return 8;
// //   if (c == '8') return 7;
// //   if (c == '7') return 6;
// //   if (c == '6') return 5;
// //   if (c == '5') return 4;
// //   if (c == '4') return 3;
// //   if (c == '3') return 2;
// //   if (c == '2') return 1;
// //   return 0;
// // };

// // auto to_sign = [](char c) -> int {
// //   if (c == 'C') return 1;
// //   if (c == 'D') return 2;
// //   if (c == 'H') return 3;
// //   if (c == 'S') return 4;
// //   return 0;
// // };

// // struct Card {
// //   map<int, int, greater<int>> num_cnt;
// //   map<int, vector<int>, greater<int>> cnt_num;
// //   map<int, int> sig_cnt;
// //   vector<int> cnts;
// // };

// // void solve() {
// //   Card A, B;
// //   vector<vector<int>> rem(14, vector<int>(5, 1));
// //   for (int i = 1; i <= 4; i++) {
// //     string s;
// //     cin >> s;
// //     int val = to_num(s[0]);
// //     int sig = to_sign(s[1]);
// //     A.num_cnt[val]++;
// //     A.sig_cnt[sig]++;
// //     rem[val][sig] = 0;
// //   }
// //   for (int i = 1; i <= 4; i++) {
// //     string s;
// //     cin >> s;
// //     int val = to_num(s[0]);
// //     int sig = to_sign(s[1]);
// //     B.num_cnt[val]++;
// //     B.sig_cnt[sig]++;
// //     rem[val][sig] = 0;
// //   }

// //   auto work = [&](Card& t) -> void {
// //     auto& [num_cnt, cnt_num, sig_cnt, cnts] = t;
// //     for (auto& [num, cnt] : num_cnt)
// //       cnt_num[cnt].push_back(num);
// //     for (auto& [cnt, nums] : cnt_num)
// //       for (int i = 0; i < (int)nums.size(); i++)
// //         cnts.push_back(cnt);
// //   };

// //   work(A);
// //   work(B);

// //   auto mask = [&](const map<int, vector<int>, greater<int>>& cnt_num) -> int {
// //     vector<int> vals;
// //     for (auto& [cnt, nums] : cnt_num)
// //       for (int i = 1; i <= cnt; i++)
// //         for (auto& x : nums)
// //           vals.push_back(x);
// //     int res = 0, base = 1;
// //     while (!vals.empty()) {
// //       res += vals.back() * base;
// //       vals.pop_back();
// //       base *= 13;
// //     }
// //     return res;
// //   };

// //   // wheel 时把 cnt_num 中的 13 替换为 0 后求 mask
// //   auto wheel_mask = [&](const map<int, vector<int>, greater<int>>& cnt_num) -> int {
// //     auto wcnt = cnt_num;
// //     for (auto& [_, v] : wcnt) for (auto& x : v) if (x == 13) x = 0;
// //     return mask(wcnt);
// //   };

// //   auto best = [&](Card& t) -> pair<int, int> {
// //     auto& [num_cnt, cnt_num, sig_cnt, cnts] = t;
// //     int mx_val = num_cnt.begin()->first,
// //         mn_val = prev(num_cnt.end())->first,
// //         mx_dif = mx_val - mn_val + 1;

// //     // [FIX] wheel 检测: A-2-3-4-5
// //     bool is_wheel = (mx_val == 13 && mn_val == 1
// //         && num_cnt.size() == 5 && num_cnt.count(4));

// //     // 9: 皇家同花顺
// //     if (sig_cnt.size() == 1 && mx_val == 13 && mn_val == 9 && num_cnt.size() == 5)
// //       return {9LL, mask(cnt_num)};

// //     // 8: 同花顺 (含 wheel)
// //     if (sig_cnt.size() == 1 && num_cnt.size() == 5 && (mx_dif == 5 || is_wheel)) 
// //       return {8LL, is_wheel ? wheel_mask(cnt_num) : mask(cnt_num)};        

// //     // 7: 四条
// //     if (cnts == VEC{4, 1})
// //       return {7LL, mask(cnt_num)};

// //     // 6: 葫芦
// //     if (cnts == VEC{3, 2})
// //       return {6LL, mask(cnt_num)};

// //     // 5: 同花
// //     if (sig_cnt.size() == 1 && num_cnt.size() == 5)
// //       return {5LL, mask(cnt_num)};

// //     // 4: 顺子 (含 wheel)
// //     if (num_cnt.size() == 5 && (mx_dif == 5 || is_wheel))                    
// //       return {4LL, is_wheel ? wheel_mask(cnt_num) : mask(cnt_num)};         

// //     // 3: 三条
// //     if (cnts == VEC{3, 1, 1})
// //       return {3LL, mask(cnt_num)};

// //     // 2: 两对
// //     if (cnts == VEC{2, 2, 1})
// //       return {2LL, mask(cnt_num)};

// //     // 1: 一对
// //     if (cnts == VEC{2, 1, 1, 1})
// //       return {1LL, mask(cnt_num)};

// //     // 0: 高牌
// //     if (cnts == VEC{1, 1, 1, 1, 1})
// //       return {0LL, mask(cnt_num)};

// //     return {-1, -1};
// //   };

// //   auto F = [&](Card& t, int i, int j) -> void {
// //     t.num_cnt[i]++;
// //     t.sig_cnt[j]++;
// //     t.cnts.clear();
// //     t.cnt_num.clear();
// //     work(t);
// //   };

// //   bool no_win = false;
// //   for (int i1 = 1; i1 <= 13; i1++) {
// //     for (int j1 = 1; j1 <= 4; j1++) {
// //       if (rem[i1][j1] == 0) continue;
// //       auto a = A; F(a, i1, j1); auto res_a = best(a);
// //       bool a_win = true;
// //       for (int i2 = 1; i2 <= 13; i2++) {
// //         for (int j2 = 1; j2 <= 4; j2++) {
// //           if (rem[i2][j2] == 0) continue;
// //           if (i1 == i2 && j1 == j2) continue;
// //           auto b = B; F(b, i2, j2); auto res_b = best(b);
// //           if (res_a < res_b) {
// //             a_win = false;
// //           } else if (res_a == res_b) {
// //             a_win = false;  
// //             no_win = true;
// //           }
// //         }
// //       }
// //       if (a_win) {
// //         cout << "WoYaoYanPai\n";
// //         return;
// //       }
// //     }
// //   }

// //   cout << (no_win ? "PaiMeiYouWenTi" : "GeiWoCaPiXie") << "\n";
// // }

// // int32_t main() {
// //   ios::sync_with_stdio(false);
// //   cin.tie(nullptr);
// //   cout.tie(nullptr);
// //   int tt = 1;
// //   cin >> tt;
// //   while (tt--) solve();
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// #ifdef LOCAL
//   #include "__DEBUG_TOOL.h"
// #else
//   #define dbug(...)
// #endif

// using VEC = vector<int>;

// auto to_num = [](char c) -> int {
//   if (c == 'A') return 13;
//   if (c == 'K') return 12;
//   if (c == 'Q') return 11;
//   if (c == 'J') return 10;
//   if (c == 'T') return 9;
//   if (c == '9') return 8;
//   if (c == '8') return 7;
//   if (c == '7') return 6;
//   if (c == '6') return 5;
//   if (c == '5') return 4;
//   if (c == '4') return 3;
//   if (c == '3') return 2;
//   if (c == '2') return 1;
//   return 0;
// };

// auto to_sign = [](char c) -> int {
//   if (c == 'C') return 1;
//   if (c == 'D') return 2;
//   if (c == 'H') return 3;
//   if (c == 'S') return 4;
//   return 0;
// };

// struct Card {
//   map<int, int, greater<int>> num_cnt;
//   map<int, vector<int>, greater<int>> cnt_num;
//   map<int, int> sig_cnt;
//   vector<int> cnts;
// };

// void solve() {
//   Card A, B;
//   vector<vector<int>> rem(14, vector<int>(5, 1));
//   for (int i = 1; i <= 4; i++) {
//     string s;
//     cin >> s;
//     int val = to_num(s[0]);
//     int sig = to_sign(s[1]);
//     A.num_cnt[val]++;
//     A.sig_cnt[sig]++;
//     rem[val][sig] = 0;
//   }
//   for (int i = 1; i <= 4; i++) {
//     string s;
//     cin >> s;
//     int val = to_num(s[0]);
//     int sig = to_sign(s[1]);
//     B.num_cnt[val]++;
//     B.sig_cnt[sig]++;
//     rem[val][sig] = 0;
//   }

//   auto work = [&](Card& t) -> void {
//     auto& [num_cnt, cnt_num, sig_cnt, cnts] = t;
//     for (auto& [num, cnt] : num_cnt)
//       cnt_num[cnt].push_back(num);
//     for (auto& [cnt, nums] : cnt_num)
//       for (int i = 0; i < (int)nums.size(); i++)
//         cnts.push_back(cnt);
//   };

//   work(A);
//   work(B);

//   auto mask = [&](const map<int, vector<int>, greater<int>>& cnt_num) -> int {
//     vector<int> vals;
//     for (auto& [cnt, nums] : cnt_num)
//       for (int i = 1; i <= cnt; i++)
//         for (auto& x : nums)
//           vals.push_back(x);
//     int res = 0, base = 1;
//     while (!vals.empty()) {
//       res += vals.back() * base;
//       vals.pop_back();
//       base *= 13;
//     }
//     return res;
//   };

//   auto wheel_mask = [&](const map<int, vector<int>, greater<int>>& cnt_num) -> int {
//     auto wcnt = cnt_num;
//     for (auto& [_, v] : wcnt) for (auto& x : v) if (x == 13) x = 0;
//     return mask(wcnt);
//   };

//   auto best = [&](Card& t) -> pair<int, int> {
//     auto& [num_cnt, cnt_num, sig_cnt, cnts] = t;
//     int mx_val = num_cnt.begin()->first,
//         mn_val = prev(num_cnt.end())->first,
//         mx_dif = mx_val - mn_val + 1;

//     // [FIX] wheel 检测: A-2-3-4-5 (编码 {13,4,3,2,1})
//     bool is_wheel = (mx_val == 13 && mn_val == 1 && num_cnt.size() == 5
//         && num_cnt.count(2) && num_cnt.count(3) && num_cnt.count(4));

//     // 9: 皇家同花顺
//     if (sig_cnt.size() == 1 && mx_val == 13 && mn_val == 9 && num_cnt.size() == 5)
//       return {9LL, mask(cnt_num)};

//     // 8: 同花顺 (含 wheel)
//     if (sig_cnt.size() == 1 && num_cnt.size() == 5 && (mx_dif == 5 || is_wheel))
//       return {8LL, is_wheel ? wheel_mask(cnt_num) : mask(cnt_num)};

//     // 7: 四条
//     if (cnts == VEC{4, 1})
//       return {7LL, mask(cnt_num)};

//     // 6: 葫芦
//     if (cnts == VEC{3, 2})
//       return {6LL, mask(cnt_num)};

//     // 5: 同花
//     if (sig_cnt.size() == 1 && num_cnt.size() == 5)
//       return {5LL, mask(cnt_num)};

//     // 4: 顺子 (含 wheel)
//     if (num_cnt.size() == 5 && (mx_dif == 5 || is_wheel))
//       return {4LL, is_wheel ? wheel_mask(cnt_num) : mask(cnt_num)};

//     // 3: 三条
//     if (cnts == VEC{3, 1, 1})
//       return {3LL, mask(cnt_num)};

//     // 2: 两对
//     if (cnts == VEC{2, 2, 1})
//       return {2LL, mask(cnt_num)};

//     // 1: 一对
//     if (cnts == VEC{2, 1, 1, 1})
//       return {1LL, mask(cnt_num)};

//     // 0: 高牌
//     if (cnts == VEC{1, 1, 1, 1, 1})
//       return {0LL, mask(cnt_num)};

//     return {-1, -1};
//   };

//   auto F = [&](Card& t, int i, int j) -> void {
//     t.num_cnt[i]++;
//     t.sig_cnt[j]++;
//     t.cnts.clear();
//     t.cnt_num.clear();
//     work(t);
//   };

//   bool no_win = false;
//   for (int i1 = 1; i1 <= 13; i1++) {
//     for (int j1 = 1; j1 <= 4; j1++) {
//       if (rem[i1][j1] == 0) continue;
//       auto a = A; F(a, i1, j1); auto res_a = best(a);
//       bool a_win = true;
//       for (int i2 = 1; i2 <= 13; i2++) {
//         for (int j2 = 1; j2 <= 4; j2++) {
//           if (rem[i2][j2] == 0) continue;
//           if (i1 == i2 && j1 == j2) continue;
//           auto b = B; F(b, i2, j2); auto res_b = best(b);
//           if (res_a < res_b) {
//             a_win = false;
//           } else if (res_a == res_b) {
//             a_win = false;
//             no_win = true;
//           }
//         }
//       }
//       if (a_win) {
//         cout << "WoYaoYanPai\n";
//         return;
//       }
//     }
//   }

//   cout << (no_win ? "PaiMeiYouWenTi" : "GeiWoCaPiXie") << "\n";
// }

// int32_t main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
//   int tt = 1;
//   cin >> tt;
//   while (tt--) solve();
// }