// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define fir first
#define sec second

#define ckmn(a, b) ((b) < (a) ? (a) = (b), 1 : 0)
#define ckmx(a, b) ((b) > (a) ? (a) = (b), 1 : 0)

#ifdef LOCAL
  #include "__DEBUG_TOOL.h"
#else 
  #define dbug(...)
#endif

// REGISTER_REFLECT()

void solve() {
  int la, ra, lb, rb;
  cin >> la >> ra >> lb >> rb;

  using pbb = pair<bool, bool>;
  static int dp[12][2][2][12][2]; 
  // tight, cnt_mx
  int mx_d = 1; string A, B; 
  // carry 是这一位是否要求产生进位
  auto dfs = [&](this auto&& dfs, int P, pbb T, int cnt_mx, int carry) -> int {
    int len = A.size();
    if (P == len) {
      return (carry == 0 && cnt_mx > 0);
    }

    auto [Ta, Tb] = T;
    if (dp[P][Ta][Tb][cnt_mx][carry] != -1) {
      return dp[P][Ta][Tb][cnt_mx][carry];
    }

    int res = 0;
    int lim_a = T.fir ? A[P] - '0' : 9LL;
    int lim_b = T.sec ? B[P] - '0' : 9LL;

    for (int da = 0; da <= lim_a; da ++) {
      for (int db = 0; db <= lim_b; db ++) {
        // 枚举低位(P + 1)向本位的进位, 这个没有枚举
        for (int cin = 0; cin <= 1; cin ++) {   
          int dsum = da + db + cin, dcur = dsum % 10;
          if (dcur > mx_d) continue;
          // 本位向高位的进位必须与父要求一致
          if ((dsum >= 10) != carry) continue;   
          // if (cin and dcur >= mx_d) continue;
          res +=
          dfs(
            P + 1,
            pbb(T.fir & (da == (A[P] - '0')), T.sec & (db == (B[P] - '0'))),
            cnt_mx + (dcur == mx_d),
            cin // 子调用的 carry = 本位收到的低位进位
          );
        }
      }
    }

    return dp[P][Ta][Tb][cnt_mx][carry] = res;
  };

  auto chg = [&](int a, int b) -> void {
    A = to_string(a), B = to_string(b);
    int lim = max(A.size(), B.size()) + 1;
    while (A.size() < lim) A = '0' + A;
    while (B.size() < lim) B = '0' + B;
    memset(dp, -1, sizeof dp); 
  };

  int ans = 0;
  while (mx_d <= 9) {
    chg(ra, rb);
    ans += mx_d * dfs(0, pbb(true, true), 0, false);
    
    chg(la - 1, rb);
    ans -= mx_d * dfs(0, pbb(true, true), 0, false);

    chg(ra, lb - 1);
    ans -= mx_d * dfs(0, pbb(true, true), 0, false);

    chg(la - 1, lb - 1);
    ans += mx_d * dfs(0, pbb(true, true), 0, false);
    
    // dbug(mx_d);
    mx_d ++;
  }

  cout << ans << "\n";
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

// // 这个题 其实可以去掉进位的影响
// // 每一位最多进位是 1, 
// // 如果 我的最大数字不是 9 的话就一定不会产生连环进位
// // 如果 mx_d == 9 了, 那么进位之后最多也只会产生 0, 不会威胁到 mx_d 的实现
// // 哦但是这样有可能影响到 mx_d 的出现次数
