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
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; 
    } 

    vector<int> dp1(n + 1, 1) ; 
    // dp[i] 表示以当前元素结尾的最长递增序列的长度
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = i - 1 ; j > 0 ; j -- ) if (vec[j] < vec[i]) {
            dp1[i] = max(dp1[j] + 1 , dp1[i]) ; 
        } 
    }
    
    vector<int> dp2(n + 1, 1) ;
    for ( int i = n ; i > 0 ; i -- ) {
        for ( int j = i + 1 ; j <= n ; j ++ ) if (vec[j] < vec[i]) {
            dp2[i] = max(dp2[j] + 1 , dp2[i]) ; 
        } 
    }

    // for ( auto &a : dp1 ) cout << a << ' ' ;
    // cout << endl  ;
    // for ( auto &a : dp2) cout << a << ' ' ;
    // cout << endl ;  

    int ans = 1 ; 
    for (int i = 1 ; i <= n ; i ++ ) {
        ans = max(ans , dp1[i] + dp2[i] - 1) ; 
    }

    cout << n - ans << endl ; 

}

/*
第一想法是枚举验证 枚举当前元素作为中间元素 想左右延伸的最长 非递增徐丽数量 
这个方法的朴素验证是 O(n²)

10
130 130 174 130 185 230 206 219 210 173

来看这个样例显然的来说 , 以 230 为中心 , 想做延伸的最长序列显然是 174 
不能选择 174 后面的 130 
所以对于新泽下一个递减序列来说 , 不恩给你使用贪心的思想了

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