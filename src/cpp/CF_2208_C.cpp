// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;


void solve() {

    int n ; cin >> n ; 
    vector<double> c(n + 1) , p(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> c[i] >> p[i] ;

    vector<double> dp(n + 1) ; dp[n] = max(c[n] , 1.0) ;  
    for ( int i = n - 1 ; i > 0 ; i -- ) {
        dp[i] = max(dp[i + 1] , c[i] + (1 - p[i] / 100) * dp[i + 1]) ; 
    } 

    cout << dp[1] << endl ;      
    
}

/*
可以是看作当前增加一定的分数然后让后面的分数都缩水一些应该怎么选
但是如果是最后一个应该怎么选呢 答案是一定会选 因为他不会对任何得分造成影响了

虽然是有后效性 但是倒着过来看 
我把每个点的初始体力值假设成 1 (因为转移到最后我们要算的就是开头是假设是 1 )
这个点后面的状态都可以变成一个数 , 这个数是固定的
如果选了这个数会缩水固定的比例 , 不选就不会缩水
所以满足可以状态转移

*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    cout << fixed << setprecision(10) ;

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}

