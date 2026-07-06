// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> x(n + 1), y(n + 1) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> x[i] >> y[i] ; 
    }

    vector<int> seq(n + 1) ; 
    iota(seq.begin() + 1 , seq.end() , 1) ;
    sort( seq.begin() + 1 , seq.end() , [&](int i , int j){
        return x[i] < x[j] ;
    });
    sort( seq.begin() + 1 , seq.begin() + 1 + n/2 , [&](int i , int j){
        return y[i] < y[j] ;
    }) ; 
    sort( seq.begin() + 1 + n/2 , seq.end() , [&](int i , int j){
        return y[i] < y[j] ;
    }) ; 

    for ( int i = 1 ; i <= n / 2 ; i ++ ) {
        cout << seq[i] << ' ' << seq[n - i + 1] << endl ; 
    }

}

/*

    我觉得最佳策略就是每次找到和当前点距离最大的点加入即可

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