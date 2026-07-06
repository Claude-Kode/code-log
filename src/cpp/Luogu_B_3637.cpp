// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7; 
const int maxn = 2e5 + 10;



void solve() { 

  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1 ; i <= n ; i++ ) {
    cin >> vec[i];
  }
  
  vector<int> lis; lis.push_back(vec[1]);
  for(int i = 2; i <= n; i ++) {
    if (vec[i] > lis.back()) lis.push_back(vec[i]);
    else {
      int pos = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
      lis[pos] = vec[i];
    }
  }

  cout << lis.size() << endl; 
}

/*
单调栈是维护一个以当前元素为结尾的递增或者递减子序列
你可以说 dp 其实是由前面的单调栈转移过来的
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

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
    
//     vector<int> d;
//     d.push_back(a[0]);  // 初始化
    
//     for (int i = 1; i < n; i++) {
//         if (a[i] > d.back()) {
//             d.push_back(a[i]);
//         } else {
//             // 二分查找第一个大于等于 a[i] 的位置
//             int pos = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
//             d[pos] = a[i];
//         }
//     }
    
//     cout << d.size() << endl;
//     return 0;
// }