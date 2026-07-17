#ifdef __GNUC__
// #pragma GCC optimize("fast-math") 
#pragma GCC optimize("Ofast, unroll-loops = full")
#pragma GCCtarget("avx, avx2")
#endif

// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

const int mod = 1e9 + 7;
const int N = 5e5 + 1;

vector<int> fact(N);
void init() {
  fact[0] = fact[1] = 1;
  for(int i = 2; i <= N - 1; i ++) fact[i] = (fact[i - 1] * i) % mod;
}

int fp(int x, int p, int mod) {
  int res = 1 , base = x ; 
  while (p) {
    if (p & 1) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int inv (int x , int mod) { 
  return fp(x , mod - 2 , mod) ; 
}

int cmb(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * fact[n] * inv(fact[k], mod) % mod * inv(fact[n - k], mod) % mod;
}

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  if (accumulate(vec.begin(), vec.end(), 0LL) != (n + 1) * n / 2) {
    cout << 0 << "\n";
    return;
  }

  static auto calc = [&](auto&& sef, int l, int r) -> int {
    if (l > r) {
      return 1;
    }

    if (l == r) {
      return vec[l] == 1;
    }

    for (int d = 0; d <= r - l + 1; d ++) {
      int i = l + d, L = i - l + 1, R = r - i + 1;
      if (L * R == vec[i]) {
        return (
          sef(sef, l, i - 1) % mod * 
          sef(sef, i + 1, r) % mod *
          cmb(r - l, L - 1) % mod
        );
      }
    }
    return 0;
  };

  cout << calc(calc, 1, n) << "\n";
}

/*
提出最值首先可以想到唯一性, 即任意的数组, 最值只有一个
所以 a 的和一定等于 所有子数组的数量

反过来, 一个数字所对应的长度最大的子数组, 也是唯一的, 而且这个元素的位置是确定的
此时剩下位置的元素集合是可以确定的
但是顺序数量不定
然后我们可以有一个归纳法, 

在一个合法区间里，根（最小值）的位置被 a 数组唯一钉死；剩下的数字可以任意分成左右两堆，
然后在左右子树内部再次任意排列——整个过程就是“选根 → 分堆 → 子区间自由重排”的递归。

我们每次处理数组的时候都保证 L * R == vec[i]的 i 元素在 l, r 中一定是最小的元素即可
因为越小的元素覆盖的范围越大
数字的具体值不重要，重要的是它们在各自子树里能排出一个大小关系

找到一个最小值后, 他会把两边进行分割, 很明显的分治就是这个了
*/

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  init();

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

