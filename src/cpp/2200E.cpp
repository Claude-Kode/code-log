// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 1e6 + 10;

vector<int> vis;
vector<int> pr;

vector<int> prime(int n) {
  vector<int> vis(N , 0) , pr ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  return vis; 
}

vector<int> primes(int n) {
  vector<int> vis(N , 0) , pr ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  return pr; 
}

pair<int, int> prime_factor(int a, vector<int>& pr) {
  set<int> factors;
  for (const auto &x : pr) if(a % x == 0) {
    while (a % x == 0) factors.insert(x), a /= x;
    if ( a < x ) { if (a > 1) factors.insert(a); break; }
  } 
  return {factors.size(), factors.size() == 1 ? *factors.begin() : INT_MAX};
}

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  if (is_sorted(vec.begin() + 1, vec.end())) {cout << "Bob" << endl; return; }

  vector<int> b(n + 1); pair<int, int> res;
  for(int i = 1; i <= n; i ++) {
    if (vis[vec[i]] ) {
      vec[i] = prime_factor(vec[i], pr).second;
    }
  }

  cout << "VEC: ";
  for(int i = 1; i <= n; i ++) cout << vec[i] << ' ';

  if (is_sorted(vec.begin() + 1, vec.end()) && *max_element(vec.begin() + 1, vec.end()) != INT_MAX) cout << "Bob" << endl; 
  else cout << "Alice" << endl; 
}
/*
对于 alice 来说 他的目的是让数组不要非递增

bob 让数组递增 alice 让数组递减

我们或许可以这样考虑
谁会挑选具有什么特征的数字

bob可能会这样 他会挑选能 破坏递增的数字进行操作 比如峰 
他应该会这样 挑选这样的峰 然后找两个数值相同的数字 替换这个数字
不会 如果他是一个峰 那么 bob 会挑选左边和右边的数字 比如 1 3 2 --> 1 1 2 2 
但是如果是 2 3 1 可能会 
或者我们额考虑一个这样的操作 如果
alice 则 

如果数组中只有一个数是可以操作的 那么另一个人每次只能修补另一个人的操作 ? 让我们来考虑这样的可能
6 7 无法操作 alice 获胜

alice 拆出一个数的时候总会想要去反着放置

我们做一个 guess  alice 只要能进行操作那么 bob 就一定输了

不对 是随便换啊 那么有没有一种可能 3 是最后一个可以被替换的数字在无数次替换后 
也就是在这个过程黄总如果会出现递增的情况或者到了最后数组 中只会剩下 1 and 2 
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

  vis = prime(N - 10);
  pr = primes(N - 10);

  vis[1] = 0;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}