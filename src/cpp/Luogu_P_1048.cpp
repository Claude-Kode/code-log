// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    // 总时间 总个数
    int t , m ; cin >> t >> m ; 
    
    // time , value 
    vector<pair<int, int>> vec(m + 1) ; 
    for ( int i = 1 ; i <= m ; i ++ ) {
        cin >> vec[i].first >> vec[i].second ;
    }

    // dp[i] means the max value you can get with capacity of i 
    // dp[i] means the max value you can get with i_cnt of objects 
    // choose the first one 


    // THE STATE MUST BE A PART OF CONDITION 
    vector<int> dp(t + 1) ; 
    for (int i = 1 ; i <= m ; i ++ ) {
        int tim = vec[i].first , val = vec[i].second ; 
        // the range dont include j == 0 , and get wrong , why ? 
        // the state is to use num to  decribe a state
        // explain the attribute

        // y the traversal should be in reverse order but not in order
        // the reason is following :
        // dp[tim + j](j == 0) , through the traverse , when j == tim , 
        // this time the object is repeated 
    
        for (int j = t ; j >= 0 ; j -- ) if ( tim + j <= t ) {
            dp[tim + j] = max( dp[tim + j] , val + dp[j] ) ; 
        }
    }

    cout << *max_element(dp.begin() , dp.end()) << endl ; 

}

/*

*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif
    
    solve() ;
    
    return 0 ;
}