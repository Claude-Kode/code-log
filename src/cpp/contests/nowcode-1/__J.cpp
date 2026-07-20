#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T> ostream &operator<<(ostream &os, const vector<T> &as);
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }
#define COLOR(s) ("\x1b[" s "m")


int bsr(int a) {
  return 31 - __builtin_clz(a);
}

// Returns the submask containing highest k bits set.
// Returns -1 instead if  popcnt(a) < k.
int highBits(int a, int k) {
  int b = 0;
  for (int i = 0; i < k; ++i) {
    if (!a) return -1;
    b |= 1 << (31 - __builtin_clz(a));
    a &= ~b;
  }
  return b;
}

constexpr char RANKS_STR[16] = "0123456789TJQKA";
constexpr char SUITS_STR[5] = "CDHS";
enum Poker {
  HIGH_CARD,
  ONE_PAIR,
  TWO_PAIR,
  THREE_OF_A_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  STRAIGHT_FLUSH,
};

// poker suit
constexpr char POKER_STR[9][20] = {
  "HIGH_CARD",
  "ONE_PAIR",
  "TWO_PAIR",
  "THREE_OF_A_KIND",
  "STRAIGHT",
  "FLUSH",
  "FULL_HOUSE",
  "FOUR_OF_A_KIND",
  "STRAIGHT_FLUSH",
};

// Parses a card in a format as "2C" or "C2".
// Returns  card = 4 (rank - 2) + suit  (2 <= rank <= 14)
int parseCard(const char *str) {
  int r, s;
  for (s = 0; s < 4; ++s) if (SUITS_STR[s] == str[1]) break;
  if (s < 4) {
    // "2C"
    for (r = 2; r < 15; ++r) if (RANKS_STR[r] == str[0]) break;
    assert(r < 15);
  } else {
    // "C2"
    for (s = 0; s < 4; ++s) if (SUITS_STR[s] == str[0]) break;
    assert(s < 4);
    for (r = 2; r < 15; ++r) if (RANKS_STR[r] == str[1]) break;
    assert(r < 15);
  }
  return (r - 2) << 2 | s;
}

// Read a card from standard input.
int readCard() {
  static char buf[3];
  scanf("%s", buf);
  return parseCard(buf);
}

// Transforms a card in a format as "2C" (or "C2" if rev).
string cardString(int card, bool rev = false) {
  const int r = card / 4 + 2, s = card % 4;
  return rev ? (string() + SUITS_STR[s] + RANKS_STR[r]) : (string() + RANKS_STR[r] + SUITS_STR[s]);
}

// Returns the best poker hand with the tie-breaker in [0, 2^20).
//   cards must be distinct.
pair<Poker, int> poker(const vector<int> &cards) {
  assert(cards.size() >= 5);
  // a: ranks for all, bs[suit]: ranks, cs[rank]: count, ds[count]: ranks
  int a = 0, bs[4] = {}, cs[15] = {}, ds[5] = {};
  for (const int card : cards) { const int r = (card >> 2) + 2, s = card & 3; a |= bs[s] |= 1 << r; ++cs[r]; }
  for (int r = 2; r < 15; ++r) ds[cs[r]] |= 1 << r;
  // 8. STRAIGHT_FLUSH: highest (5 for A2345)
  {
    int straightFlush = 0;
    for (int s = 0; s < 4; ++s) straightFlush |= bs[s] & bs[s] << 1 & bs[s] << 2 & bs[s] << 3 & (bs[s] << 4 | bs[s] >> 14 << 5);
    if (straightFlush) return make_pair(STRAIGHT_FLUSH, bsr(straightFlush));
  }
  // 7. FOUR_OF_A_KIND: quadruple, other card
  if (ds[4]) {
    const int r4 = bsr(ds[4]);
    return make_pair(FOUR_OF_A_KIND, r4 << 4 | bsr(a ^ 1 << r4));
  }
  // 6. FULL_HOUSE: triple, pair
  if (ds[3]) {
    const int r3 = bsr(ds[3]);
    const int d = (ds[3] ^ 1 << r3) | ds[2];
    if (d) {
      const int r2 = bsr(d);
      return make_pair(FULL_HOUSE, r3 << 4 | r2);
    }
  }
  // 5. FLUSH: 5 highest cards
  {
    int flush = -1;
    for (int s = 0; s < 4; ++s) { const int h = highBits(bs[s], 5); if (flush < h) flush = h; }
    if (flush >= 0) return make_pair(FLUSH, flush);
  }
  // 4. STRAIGHT: highest (5 for A2345)
  {
    const int straight = a & a << 1 & a << 2 & a << 3 & (a << 4 | a >> 14 << 5);
    if (straight) return make_pair(STRAIGHT, bsr(straight));
  }
  // 3. THREE_OF_A_KIND: triple, 2 highest other cards
  if (ds[3]) {
    const int r3 = bsr(ds[3]);
    return make_pair(THREE_OF_A_KIND, r3 << 16 | highBits(a ^ 1 << r3, 2));
  }
  // 2. TWO_PAIR: larger pair, smaller pair, other card
  // 1. ONE_PAIR: pair, 3 highest other cards
  if (ds[2]) {
    const int r2 = bsr(ds[2]);
    const int d = ds[2] ^ 1 << r2;
    if (d) {
      const int r22 = bsr(d);
      return make_pair(TWO_PAIR, r2 << 8 | r22 << 4 | bsr(a ^ 1 << r2 ^ 1 << r22));
    }
    return make_pair(ONE_PAIR, r2 << 16 | highBits(a ^ 1 << r2, 3));
  }
  // 0. HIGH_CARD: 5 highest cards
  return make_pair(HIGH_CARD, highBits(a, 5));
}

////////////////////////////////////////////////////////////////////////////////


int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (int caseId = 1; caseId <= numCases; ++caseId) {
    int A[8];
    for (int i = 0; i < 8; ++i) A[i] = readCard();
    
    bool used[52] = {};
    for (int i = 0; i < 8; ++i) used[A[i]] = 1;
    int ans = +1;
    for (int y = 0; y < 52; ++y) if (!used[y]) {
      const auto you = poker({A[4], A[5], A[6], A[7], y});
      int mx = -1;
      for (int x = 0; x < 52; ++x) if (!used[x] && y != x) {
        const auto me = poker({A[0], A[1], A[2], A[3], x});
        if (me > you) {
          chmax(mx, +1);
          break;
        } else if (me == you) {
          chmax(mx, 0);
        }
      }
      chmin(ans, mx);
      if (ans < 0) break;
    }
    puts((ans > 0) ? "WoYaoYanPai" : (ans < 0) ? "GeiWoCaPiXie" : "PaiMeiYouWenTi");
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}



// 返回最优扑克牌型，以及一个用于比大小的 tie‑breaker（范围 [0, 2^20)）
// 前提：cards 中的牌必须互不相同
pair<Poker, int> poker(const vector<int> &cards) {
  assert(cards.size() >= 5);

  // a     ：所有牌的点数集合（跨花色）
  // bs[s] ：某一花色中出现的所有点数
  // cs[r] ：点数 r 出现的次数（1~4）
  // ds[c] ：出现次数为 c 的所有点数集合
  int a = 0, bs[4] = {}, cs[15] = {}, ds[5] = {};

  // 遍历每一张牌，填充统计信息
  for (const int card : cards) {
    const int r = (card >> 2) + 2; // 点数：2~14（2=2，14=A）
    const int s = card & 3;        // 花色：0~3
    a |= bs[s] |= 1 << r;          // 记录点数（用 bitmask）
    ++cs[r];                       // 点数出现次数 +1
  }

  // 根据出现次数，归类点数
  // 例如：ds[2] 存放所有对子的点数
  for (int r = 2; r < 15; ++r)
    ds[cs[r]] |= 1 << r;

  // ============================================================
  // 8. 同花顺（Straight Flush）
  //    同花色 + 连续五张
  //    tie‑breaker：顺子中最大的那张牌（A2345 时为 5）
  // ============================================================
  {
    int straightFlush = 0;
    for (int s = 0; s < 4; ++s)
      straightFlush |=
        bs[s]
        & (bs[s] << 1)
        & (bs[s] << 2)
        & (bs[s] << 3)
        & (bs[s] << 4 | (bs[s] >> 14) << 5); // 特殊处理 A2345
    if (straightFlush)
      return make_pair(STRAIGHT_FLUSH, bsr(straightFlush));
  }

  // ============================================================
  // 7. 四条（Four of a Kind）
  //    tie‑breaker：高 4 位为四条点数，低 4 位为 kicker
  // ============================================================
  if (ds[4]) {
    const int r4 = bsr(ds[4]); // 四条的点数
    return make_pair(
        FOUR_OF_A_KIND,
        r4 << 4 | bsr(a ^ (1 << r4)) // 去掉四条后的最大单牌
    );
  }

  // ============================================================
  // 6. 葫芦（Full House）
  //    三条 + 一对
  //    tie‑breaker：高 4 位为三条点数，低 4 位为一对点数
  // ============================================================
  if (ds[3]) {
    const int r3 = bsr(ds[3]);              // 最大的三条
    const int d = (ds[3] ^ (1 << r3)) | ds[2]; // 剩余的三条或现存的对子
    if (d) {
      const int r2 = bsr(d); // 一对的点数
      return make_pair(FULL_HOUSE, r3 << 4 | r2);
    }
  }

  // ============================================================
  // 5. 同花（Flush）
  //    同一花色中最大的 5 张牌
  //    tie‑breaker：5 张最大牌的 bitmask
  // ============================================================
  {
    int flush = -1;
    for (int s = 0; s < 4; ++s) {
      const int h = highBits(bs[s], 5); // 取该花色最大的 5 张牌
      if (flush < h) flush = h;
    }
    if (flush >= 0)
      return make_pair(FLUSH, flush);
  }

  // ============================================================
  // 4. 顺子（Straight）
  //    不同花色，连续五张
  //    tie‑breaker：顺子中最大的那张牌（A2345 时为 5）
  // ============================================================
  {
    const int straight =
      a & (a << 1)
        & (a << 2)
        & (a << 3)
        & (a << 4 | (a >> 14) << 5); // A2345 特殊处理
    if (straight)
      return make_pair(STRAIGHT, bsr(straight));
  }

  // ============================================================
  // 3. 三条（Three of a Kind）
  //    tie‑breaker：高 16 位为三条点数，低 20 位为两张 kicker
  // ============================================================
  if (ds[3]) {
    const int r3 = bsr(ds[3]);
    return make_pair(
        THREE_OF_A_KIND,
        r3 << 16 | highBits(a ^ (1 << r3), 2)
    );
  }

  // ============================================================
  // 2. 两对（Two Pair）
  // 1. 一对（One Pair）
  // ============================================================
  if (ds[2]) {
    const int r2 = bsr(ds[2]);           // 较大的对子
    const int d = ds[2] ^ (1 << r2);     // 剩余的对子（如果有）
    if (d) {
      const int r22 = bsr(d);            // 较小的对子
      return make_pair(
          TWO_PAIR,
          r2 << 8 | r22 << 4 | bsr(a ^ (1 << r2) ^ (1 << r22))
      );
    }
    // 只有一对的情况
    return make_pair(
        ONE_PAIR,
        r2 << 16 | highBits(a ^ (1 << r2), 3)
    );
  }

  // ============================================================
  // 0. 高牌（High Card）
  //    tie‑breaker：5 张最大牌的 bitmask
  // ============================================================
  return make_pair(HIGH_CARD, highBits(a, 5));
}

