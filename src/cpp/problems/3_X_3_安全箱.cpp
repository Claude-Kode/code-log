// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

// #define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1 ; i <= n; i ++)  

}

/*

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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}




// #include <bits/stdc++.h>

// using namespace std;
// #define int = long long;
// // const ll mod = 1e9 + 7;
// const int mod = 998244353;
// const int MAX = 1000009;
// using db = long double;

// // ll a[1000009], b[1000009], c[1000009];
// struct note {
//     int a, b, c;
// } stu[1000009];

// int d[10][10];
// int e[10][10][15];

// bool cmp(note x, note y) {
//     return x.c > y.c;
// }

// int f(int x) {
//     int ans = 0;
//     for (int i = 0; i <= x / 2; i++) {
//         int xx = e[1][2][i] + e[1][1][x - 2 * i];
//         ans = max(ans, xx);
//     }
//     return ans;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tt = 1;
//     cin >> tt;
//     while (tt--) {
//         int n;
//         cin >> n;
//         for (int i = 1; i <= n; i++) {
//             cin >> stu[i].a >> stu[i].b >> stu[i].c;
//             if (stu[i].a > stu[i].b) {
//                 swap(stu[i].a, stu[i].b);
//             }
//         }
//         sort(stu + 1, stu + 1 + n, cmp);
//         for (int i = 1; i <= n; i++) {
//             int a1 = stu[i].a;
//             int b1 = stu[i].b;
//             int c1 = stu[i].c;
//             if (d[a1][b1] <= 9) {
//                 d[a1][b1]++;
//                 e[a1][b1][d[a1][b1]] = c1;
//             } 
//         }
//         for (int i = 1; i <= 3; i++) {
//             for (int j = i; j <= 3; j++) {
//                 for (int h = 1; h <= 9; h++) {
//                     e[i][j][h] += e[i][j][h - 1];
//                 }
//             }
//         }

//         int ans = 0;
//         ans = max(ans, e[3][3][1]);
//         ans = max(ans, e[2][3][1] + e[1][3][1]);
//         ans = max(ans, e[2][3][1] + f(3));
//         ans = max(ans, e[2][2][1] + e[1][3][1] + f(2));
//         ans = max(ans, e[2][2][1] + f(5));
//         ans = max(ans, e[1][3][3]);
//         ans = max(ans, e[1][3][2] + f(3));
//         ans = max(ans, e[1][3][1] + f(6));
//         ans = max(ans, f(9));
//         cout << ans << "\n";
//         for (int i = 1; i <= 3; i++) {
//             for (int j = 1; j <= 3; j++) {
//                 for (int h = 1; h <= 9; h++) {
//                     e[i][j][h] = 0;
//                     d[i][j] = 0;
//                 }
//             }
//         }
//     }
//     return 0;
// }
