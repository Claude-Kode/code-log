// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

struct infor {
  int val ; string color ; 
  bool operator< (infor other) const {
    return val < other.val ; 
  } 
} ;

void solve() { 

  // 普通的 pq 是基于小于号进行比较的 当返回真值的时候证明前面的优先级是小于后面的 
  // 用 greater的时候则是基于大于号进行比较的
  int c , s , d ; cin >> c >> s >> d ; 
  priority_queue<infor> pq ; 
  pq.push({c , "Clubs"}) ; pq.push({s , "Spades"}) ; pq.push({d , "Diamonds"}) ;
  while ( 1 ) {
    auto [a , acolor] = pq.top() ; pq.pop() ; 
    auto [b , bcolor] = pq.top() ; pq.pop() ; 
    auto [c , ccolor] = pq.top() ; pq.pop() ; 

    if ( b == 0 ) break ; 

    if ( b == pq.top().val && a == b && b != 0 ) {
      cout << "NO" << endl ; 
      return ; 
    } 

    a -- , b -- , c ++ ; 

    pq.push({a , acolor}) ; 
    pq.push({b , bcolor}) ; 
    pq.push({c , ccolor}) ;

    cout << acolor << ' ' << a << endl ; 
    cout << bcolor << ' ' << b << endl ; 
    cout << pq.top().color << ' ' << pq.top().val + 1 << endl << endl ; 

  }
 
  cout << pq.top().color << endl ; 

}

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

  int tt ; cin >> tt ;
  while(tt --) solve() ;
  
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
