// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 
  int n, m; cin >> n >> m; 
  vector<pair<int, int>> vec(n + 1);
  vector<int> c(m + 1);
  priority_queue<int> pq;  // 最大堆，存储金属量

  for (int i = 1; i <= n; i++) cin >> vec[i].first; 
  for (int i = 1; i <= n; i++) cin >> vec[i].second; 
  
  for (int i = 1; i <= m; i++) {
    int temp; cin >> temp; 
    pq.push(temp);
  }

  // 先按first排序，first相同按净消耗小的排序
  sort(vec.begin() + 1, vec.end(), [&](auto a, auto b) {
      if (a.first != b.first) return a.first < b.first;
      int diff1 = a.first - a.second;
      int diff2 = b.first - b.second;
      return diff1 < diff2;
  });

  // 覆盖过程：维护最佳净消耗
  int best_a = vec[1].first, best_b = vec[1].second;
  int best_diff = best_a - best_b;
  for (int i = 1; i <= n; i++) {
    int cur_diff = vec[i].first - vec[i].second;
    
    if (cur_diff < best_diff || 
        (cur_diff == best_diff && vec[i].first < best_a)) {
        best_a = vec[i].first;
        best_b = vec[i].second;
        best_diff = cur_diff;
    }
    
    vec[i].first = best_a;
    vec[i].second = best_b;
  }

  int ans = 0;
  while (!pq.empty()) {
    int t = pq.top(); pq.pop();
    
    // 二分查找最后一个first <= t的位置
    int l = 1, r = n, pos = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (vec[mid].first <= t) {
        pos = mid;
        l = mid + 1;  
      } else {
        r = mid - 1;
      }
    }
    
    if (pos != -1) {
      int a = vec[pos].first, b = vec[pos].second;
      int diff = a - b;
      if (diff > 0) {
        int cnt = (t - a) / diff + 1;
        ans += 2 * cnt;
        int rem = t - cnt * diff;
        if (rem > 0) {
          pq.push(rem);
        }
      }
    }
  }

  cout << ans << endl; 
}

// void solve() { 
//   int n, m; cin >> n >> m; 
//   vector<pair<int, int>> vec(n + 1);
//   queue<int> q;

//   for (int i = 1; i <= n; i++) cin >> vec[i].first; 
//   for (int i = 1; i <= n; i++) cin >> vec[i].second; 
  
//   for (int i = 1; i <= m; i++) {
//     int temp; cin >> temp; q.push(temp);
//   }

//   // 先按first排序，first相同按净消耗小的排序
//   sort(vec.begin() + 1, vec.end(), [&](auto a, auto b) {
//       if (a.first != b.first) return a.first < b.first;
//       int diff1 = a.first - a.second;
//       int diff2 = b.first - b.second;
//       return diff1 < diff2;
//   });

//   // 覆盖过程：维护最佳净消耗
//   int best_a = vec[1].first, best_b = vec[1].second;
//   int best_diff = best_a - best_b;
//   for (int i = 1; i <= n; i++) {
//     int cur_diff = vec[i].first - vec[i].second;
    
//     // 如果当前净消耗更小，或者净消耗相同但制作消耗更小
//     if (cur_diff < best_diff || 
//         (cur_diff == best_diff && vec[i].first < best_a)) {
//         best_a = vec[i].first;
//         best_b = vec[i].second;
//         best_diff = cur_diff;
//     }
    
//     vec[i].first = best_a;
//     vec[i].second = best_b;
//   }

//   int ans = 0;
//   while (!q.empty()) {
//     int t = q.front(); q.pop();
    
//     // 二分查找最后一个first <= t的位置
//     int l = 1, r = n, pos = -1;
//     while (l <= r) {
//       int mid = (l + r) / 2;
//       if (vec[mid].first <= t) {
//         pos = mid;
//         l = mid + 1;  
//       } else {
//         r = mid - 1;
//       }
//     }
    
//     if (pos != -1) {
//       int a = vec[pos].first , b = vec[pos].second ;
//       int diff = a - b ; 
//       if (diff > 0) {
//         int cnt = (t - a) / diff + 1 ;  // 向上取整
//         ans += 2 * cnt ;
//         int rem = t - cnt * diff ;
//         if (rem > 0) {
//           q.push(rem) ;
//         }
//       }
//     }
//   }

//   cout << ans << endl ; 

// }

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;

  solve() ;
  
  return 0 ;
}

// Functions : 

int fp( int x , int p , int mod) {
  int res = 1 , base = x ; 
  while ( p ) {
    if ( p & 1 ) (res *= base) %= mod ; 
    (base *= base) %= mod ; 
    p >>= 1 ;
  }
  return res ; 
}

int lcm(int a , int b) { return a / gcd(a , b) * b  ; } 

int inv (int x , int mod) { return fp(x , mod - 2 , mod ) ; }

void dedup(vector<int>& vec ) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

