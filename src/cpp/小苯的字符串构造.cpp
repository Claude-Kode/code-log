// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;


void solve() {

    int n ; cin >> n ; 
    if (n & 1) cout << string(n , 'a') << endl ; 
    else cout << string(n - 1 , 'a') << 'b' << endl ; 
    
}

/*
对于每个长度为奇数的字符串 , 生成他的下一个排列然后接上去 最好的办法或许是直接倒置 ? 
或者说干脆直接制造一个字符串让所有出现的长度为奇数的子串都是唯一的
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