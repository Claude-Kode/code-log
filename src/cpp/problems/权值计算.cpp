// @Author : GoryK
// @Description : TEMPLATE-2
#include <bits/stdc++.h>

using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 + 5 ;

void solve() {
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    for ( int i = 0 ; i < n ; i ++ ) cin >> a[i] ;
    
    vector<int> g( n + 1 , 0 ) ;
    unordered_map<int, int> lst ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        int val = a[i - 1] ;
        int l = lst[val] ;
        int s = i - l ;
        g[i] = g[i - 1] + s  ; 
        lst[val] = i ;
    }
    
    int ans = 0 ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        ans += g[i] * (n - i + 1) ; 
    }

    cout << g[n] << endl ;
}

/*
贡献值的大小就是元素在当前数组中的前缀不同元素数量多少
*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;
    
    int tt ;
    cin >> tt ;
    while (tt --) solve() ;
    
    return 0 ;
}