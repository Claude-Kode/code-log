
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 1e6 + 10;

int fac = 0;

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
    while (a % x == 0) factors.insert(x), a /= x, fac = x;
    if ( a < x ) { if (a > 1) factors.insert(a); break; }
  } 
  return {factors.size(), *factors.begin()};
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
      auto res = prime_factor(vec[i], pr);
      if (res.first == 1) vec[i] = res.second;
      else vec[i] = INT_MAX;
      
    }
  }

  // cout << "VEC: ";
  // for(int i = 1; i <= n; i ++) cout << vec[i] << ' ';
  // cout << endl;

  if (is_sorted(vec.begin() + 1, vec.end())) cout << "Bob" << endl; 
  else cout << "Alice" << endl; 
}

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  vis = prime(N - 10);
  pr = primes(N - 10);

  vis[1] = 0;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    solve();
  
  return 0;
}
