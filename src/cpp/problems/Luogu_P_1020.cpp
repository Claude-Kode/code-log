// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

// #define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;



void solve() {

    // tc required nlogn
    vector<int> vec(1 , 0) ; int temp ; 
    while ( cin >> temp  ) vec.push_back( temp ) ; 

    int m = *max_element(vec.begin() , vec.end()) ;

    int n = vec.size() - 1 ; vector<int> tree(m + 1) ; 

    auto lowbit = [&](int i) -> int { return i & -i ; } ; 
    auto up = [&](int p , int d) -> void { 
        for (int i = p ; i < m ; i += lowbit(i) ) {
            tree[i] = max(tree[i] , d) ; 
        } 
    } ; 
    auto qu = [&](int p) -> int { 
        int res = INT_MIN ;  
        for ( int i = p ; i > 0 ; i -= lowbit(i) ) res = max(res , tree[i]) ; 
        return res ; 
    } ; 

    int mx = INT_MIN ; 
    vector<int> dp(n + 1 , 1) ; up(vec[n] , 1) ; 
    // dp[i] 代表以 i 开头的最长非递增序列长度
    // time complexity here is O(n²)
    // oob here
    for (int i = n - 1 ; i > 0 ; i --) {
        // here can be optimized 
        // mantain a sorted seq and used binary search 
        // 1. the max dp[j] && vec[i] >= vec[j]
        // maybe can use fenwick tree to do this 
        // index shoudld be the val , 
        // cout << 1 << endl ; 
        dp[i] = max(dp[i] , qu(vec[i]) + 1) ; 
        // cout << 1 << endl ; 
        up(vec[i] , dp[i]) ; 
        mx = max(mx , dp[i]) ; 
    }

    // for ( const auto &a : dp ) cout << a << ' ' ; 

    int cnt = 0 , ans = 0 , cur = 0 ; unordered_map<int, int> ump ; 
    // time complexity here == O(n)
    while ( cnt < n ) {
        for ( int i = 1 ; i <= n ; i ++ ) if(!ump[i]) {
            cur = vec[i] ; break ;
        }
        for (int i = 1 ; i <= n ; i ++ ) if ( !ump[i] && cur >= vec[i] ) {
            cur = vec[i] , cnt ++ , ump[i] ++ ;
        }
        ans ++ ; 
    }

    // 最少用几个这样的序列可以覆盖整个数组 ? 
    // 第一个元素是一定要参与的
    // 然后我的随流就是暴力的往后面一直找就可以了
    // 但是感觉不是这样的呢
    cout << mx << endl << ans << endl ;     
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
