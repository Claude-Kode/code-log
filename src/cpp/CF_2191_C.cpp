// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

// Functions : 

int fp( int x , int p , int mod) {
  int res = 1 , base = x ; 
  while ( p ) {
    if ( p & 1 ) (res *= base) %= mod ; 
    (base *= base) %= mod , p >>= 1 ;
  }
  return res ; 
}

int lcm(int a , int b) { 
  return a / gcd(a , b) * b ; 
} 

int inv (int x , int mod) { 
  return fp(x , mod - 2 , mod) ; 
}

vector<int> prime(int n) {
  vector<int> vis(maxn , 0) , pr ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  return pr ; 
}

void dedup(vector<int>& vec ) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

void solve() { 

  int n; cin >> n; 
	string str ; cin >> str;
	if (is_sorted(str.begin(), str.end())) {
		cout << "Bob" << endl ; 
		return;
	}

	int cnt_0 = std::count(str.begin() , str.end(), '0');
	vector<int> ans; 
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( i < cnt_0 && str[i] == '1' ) ans.push_back(i + 1); 
		else if ( i >= cnt_0 && str[i] == '0') ans.push_back(i + 1);  
	}

	cout << "Alice" << endl << ans.size() << endl ;
	for (const auto &a : ans) cout << a << ' ';
	cout << endl ;

}

/*
把区间改到整体都得是递减的为止
每次挑个序列 , 前面全是 0 , 后面全是 1 , 然后把 0 全都反转成 1 , 1 全都反转成 0 
谁翻不了谁赢
每个人的修改最少会留下一个 0 , 所以 A 只要留下两个

我的思路是如果有 1... 1..... 0可以全部变成 , 0... 0.... 1 这样的
如果第一个 1 前面有 0 那么 alice 是必输的
但是最后的硬的条件是整个序列全部都是递增的才行
没毛啊卧槽 

找到第一个 1 , 把后面所有的 0 都变成 1 , 然后把这个 1 变成 0 , 这样他一定是一个递增的序列
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
