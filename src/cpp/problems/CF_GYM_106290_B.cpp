// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() { 

  int n = 5 ; 
  	vector<vector<int>> vec(n + 1 , vector<int>(n + 1)) ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			for ( int j = 1 ; j <= n ; j ++ ) {
				char c ; cin >> c ; 
				vec[i][j] = c - '0' ; 
			}
		}

  auto check = [&](int x , int y) -> int {

		int row = 0 , col = 0 , diag1 = 0 , diag2 = 0 ;
		// same y , var x 
		for ( int i = x + 1 ; i <= n ; i ++ ) if ( vec[i][y] == 1 ) row ++ ; else break ; 
		for ( int i = x - 1 ; i >= 1 ; i -- ) if ( vec[i][y] == 1 ) row ++ ; else break ; 

		for ( int j = y + 1 ; j <= n ; j ++ ) if ( vec[x][j] == 1 ) col ++ ; else break ; 
		for ( int j = y - 1 ; j >= 1 ; j -- ) if ( vec[x][j] == 1 ) col ++ ; else break ; 

		int i = x + 1 , j = y + 1 ; 
		while ( i <= 5 && j <= 5 ) if ( vec[i][j] == 1 ) diag1 ++ , i ++ , j ++ ; else break ; 
		i = x - 1 , j = y - 1 ;
		while ( i >= 1 && j >= 1 ) if ( vec[i][j] == 1 ) diag1 ++ , i -- , j -- ; else break ; 

		i = x - 1 , j = y + 1 ;
		while ( i >= 1 && j <= n ) if ( vec[i][j] == 1 ) diag2 ++ , i -- , j ++ ; else break ; 
		i = x + 1 , j = y - 1 ;
		while ( i <= n && j >= 1 ) if ( vec[i][j] == 1 ) diag2 ++ , i ++ , j -- ; else break ;

		return max({row , col , diag1 , diag2}) ; 

  } ;  

	int ans = 0 ;
  for ( int i = 1 ; i <= n ; i ++ ) {
    for( int j = 1 ; j <= n ; j ++ ) {
      if ( vec[i][j] == 1 ) { 
				int temp = check(i , j) ;
				// cout << temp << endl ;
				if (temp == 4) { 
					cout << "Bingo!" << endl ; 
					return ;
				} else {
					ans += temp ;
					if ( temp == 0 ) ans ++ ;
				} 
			}
    }
  }

	cout << ans << endl ; 

}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;  std::cin.tie(nullptr) ;
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
