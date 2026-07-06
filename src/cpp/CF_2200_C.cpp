// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    string str ; cin >> str ; 

    // 没想到用栈来维护 傻逼了
    while (!str.empty()) {

        int sz = str.size() ; bool f = false;
        for ( int i = 1 ; i < sz; i ++ ) {
            if (str[i] == str[i - 1]) {
                str[i - 1] = '*' ;
                str[i] = '*' ; 
                f = true ;
                i ++ ;  
            }
        }
        
        // 移除所有 '*'
        str.erase( remove_if(str.begin(), str.end() , [](char c) { 
            return c == '*'; 
        }) , str.end() ) ;
        
        if ( !f && !str.empty() ) {
            cout << "NO" << endl ;
            return ;
        }
    }
    
    cout << "YES" << endl ;

}

/*
1. 能变成 * 的都变成 * 
2. 从每一段连续的 * 向外面扩展 看能不能扩展 不能扩展就没了
直接模拟 相邻的一样的直接删掉
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

