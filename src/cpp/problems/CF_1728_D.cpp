// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {
    string str = " " , temp ; cin >> temp ; str += temp ; 
    int n = temp.size() ; 

    vector<vector<int>> dp(n + 1 , vector<int>(n + 1)) ; auto vis = dp ;  
    auto DFS = [&](this auto&& DFS , int l , int r) -> int {

        if ( vis[l][r] ) return dp[l][r] ; 
        vis[l][r] = 1 ; 

        if ( l == r - 1 ) return dp[l][r] = (str[l] != str[r]) ; 

        return dp[l][r] = max(
            min(
                (str[l] < str[l + 1]) + DFS(l + 2 , r) , 
                (str[l] < str[r]) + DFS(l + 1 , r - 1)  
            ) , 
            min(
                (str[r] < str[l]) + DFS(l + 1 , r - 1) , 
                (str[r] < str[r - 1]) + DFS(l , r - 2)
            )
        ) ;

    } ; 

    DFS(1 , n) ? cout << "Alice" << endl : cout << "Draw" << endl ; 

}



signed main() {
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    
    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}
