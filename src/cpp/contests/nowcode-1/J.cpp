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

    int sz = cnts.size();

    // 7: 4 + 1
    if (sz == 2 && cnts[0] == 4) {
      return pair(7LL, mask(cnt_num, false));
    }

    // 6: 3 + 2
    if (sz == 2 && cnts[0] == 3) {
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
    if (sz == 3 && cnts[0] == 3) {
      return pair(3LL, mask(cnt_num, false));
    }

    // 2: 2 + 2 + 1
    if (sz == 3 && cnts[0] == 2) {
      return pair(2LL, mask(cnt_num, false));
    }

    // 1: 2 + 1 + 1 + 1
    if (sz == 4) {
      return pair(1LL, mask(cnt_num, false));
    }

    // 0: 1 + 1 + 1 + 1 + 1
    if (sz == 5) {
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

  vector<pair<pair<int, int>, int>> a_all, b_all;
  for (int i1 = 1; i1 <= 13; i1++)
    for (int j1 = 1; j1 <= 4; j1++)
      if (rem[i1][j1]) {
        Card ca = A; F(ca, i1, j1);
        a_all.push_back({best(ca), i1 * 5 + j1});
        Card cb = B; F(cb, i1, j1);
        b_all.push_back({best(cb), i1 * 5 + j1});
      }

  // 我赢: 对手任意选择, 我都能找到回应 > 他
  bool i_win = true;
  for (auto& [br, bc] : b_all) {
    bool ok = false;
    for (auto& [ar, ac] : a_all)
      if (ac != bc and ar > br) { ok = true; break; }
    if (!ok) { i_win = false; break; }
  }

  if (i_win) {
    cout << "WoYaoYanPai" << "\n";
    return;
  }

  // 对手赢: 存在一种对手选择, 我所有回应都 <= 他
  bool o_win = false;
  for (auto& [br, bc] : b_all) {
    bool ok = true;
    for (auto& [ar, ac] : a_all)
    // 这里是严格输给对方
      if (ac != bc and ar >= br) { ok = false; break; }
    if (ok) { o_win = true; break; }
  }

  if (o_win) {
    cout << "GeiWoCaPiXie" << "\n";
    return;
  }

  cout << "PaiMeiYouWenTi" << "\n";
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



// card = 4 * (rank - 2) + suit
// rank:  2 ~ 14  (2 = A? 不, 2 = 2，14 = A)
// suit: 0 = C, 1 = D, 2 = H, 3 = S