// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> vec(n + 1) ;
    for (int i = 1 ; i <= n ; i ++) {
        cin >> vec[i] ; 
    }

    
    
}

/* 
面对一个数的时候有两种选择 第一种是把它变成 1 留给后面减去较大的数
第二个是直接把他变成 0 , 然后让后面的减掉 1 
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