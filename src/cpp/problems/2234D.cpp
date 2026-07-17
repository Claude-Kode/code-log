// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int int64_t

// #ifdef LOCAL
//   #include "__DEBUG_TOOL.h"
// #else 
//   #define dbug(...)
// #endif

// // REGISTER_REFLECT()

// void solve() {
//   int n;
//   cin >> n;

//   int L = 0b10111, R = 0b1010;
//   cout << L << ' ' << R << ' ' << (L ^ R) << '\n';

//   vector<int> vec;
//   unordered_map<int, int> used;
//   auto work = [&](auto && sef, int l, int r) -> void {
//     int mid = (l + r) / 2;
//     if (used[mid]) return; 
//     used[mid] = 1;
//     vec[mid] = vec[l] ^ vec[r];
//     sef(sef, l, mid);
//     sef(sef, mid, r);
//   };

//   auto calc = [&](int k) -> array<int, 3> {
//     int N = (1 << k | 1);
//     dbug(N);
//     vec.assign(N + 1, 0);
//     used.clear();

//     vec[1] = L; 
//     vec[N] = R;
//     used[1] = used[N] = 1;
//     // cout << "PRE: \n";
//     // dbug(vec);

//     work(work, 1, N);
//     int a = 0, b = 0, c = 0;
//     for (int i = 1; i <= N; i ++) {
//       a += (vec[i] == L);
//       b += (vec[i] == (L ^ R));
//       c += (vec[i] == R);
//     }

//     dbug(a, b, c);
//     return array<int, 3>{a, b, c};
//   };  

//   for (int i = 1; i <= n; i ++) {
//     cout << "I: " << i << "\n";
//     auto temp = calc(i);
//     dbug(temp);
//   }
// } 

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
  
//   int tt = 1, _ = 0;
//   std::cin >> tt;
//   while (tt-- && ++_)
//     std::cout << "TEST CASE : " << _ << endl,
//     solve();

//   return 0;
// }

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

namespace tools {
  int count(const string &s, char c) {
    return count(s.begin(), s.end(), c);
  }

  int count(const string &s, int l, int r, char c) {
    return count(s.begin() + l, s.begin() + r + 1, c);
  }
}

string operator^(auto & a, auto &b) {
  auto c = a;
  for (int i = 0; i < a.size(); i ++) {
    c[i] = (a[i] == b[i] ? '0' : '1');
  }
  return c;
}

const int N = 1e5 + 1;

vector<int> arr(N + 1);

void solve() {
  int n, k;
  cin >> n >> k;
  string L, R, M;
  cin >> L >> R;
  M = L ^ R;

  int L1 = tools::count(L, '1');
  int L0 = tools::count(L, '0');
  int M1 = tools::count(M, '1');
  int M0 = tools::count(M, '0');
  int R1 = tools::count(R, '1');
  int R0 = tools::count(R, '0');

  // dbug(L, M, R);
  // dbug(L1, L0, M1, M0, R1, R0);

  // dbug(arr[k], (1 << k | 1) - 2 * arr[k], arr[k]);

  cout << (
    arr[k] * (L1 * L0) + 
    arr[k] * (R1 * R0) + 
    ((1 << k | 1) - 2 * arr[k]) * (M1 * M0)
  ) << "\n";
} 

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  arr[1] = 1;

  for (int i = 2; i <= N; i ++) {
    if (i & 1) {
      arr[i] = 2 * arr[i - 1] - 1;
    } else {
      arr[i] = 2 * arr[i - 1];
    }
  }

  // for (int i = 1; i <= 15; i ++) {
  //   cout << "i: " << i << "\n";
  //   dbug(arr[i]);
  // }

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}
