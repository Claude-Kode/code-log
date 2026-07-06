// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int n ; 
vector<int> tree ; 

int lowbit(int i) { return i & -i ; }

void up( int p ) {
    for ( int i = p ; i <= n ; i += lowbit(i) ) {
        tree[i] ++ ;
    }
}

int q(int p) {
    int res = 0 ; 
    for ( int i = p ; i > 0 ; i -= lowbit(i) ) {
        res += tree[i] ;
    }
    return res ; 
} 

void solve() {

    cin >> n ; 
    vector<int> adj(n + 1) ;
    tree.resize(n + 1) ;  
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> adj[i] ; tree[i] = 0 ; 
    }

    int ans = 0 ;  
    for ( int i = n ; i >= 1 ; i -- ) {
        ans += q(adj[i]) ; 
        up(adj[i]) ; 
    }

    cout << ans << endl ; 

}

/*
预处理出 j > i 而且 adj[j] <= adj[i] 的即可

我们看 adj 中的 i 和 j
我们要求的是 对于当前的 i 他的后面有多少 j <= i 

*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}