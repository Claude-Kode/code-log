// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> arr(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i ] ; 
    arr.push_back( INT_MAX ) ; arr[0] = INT_MAX ;
    // 每个索引是偶数的地方都应该大于两边的和
    int ans = 0 , cnt = 0 ;
    for ( int i = 1 ; i <= n - !(n & 1) ; i ++ )if ( i & 1 )  {
        int diff = arr[i] - min(arr[i - 1] , arr[i + 1]) / 2  ;
        if ( diff > 0 ) ans += diff ;
    }

    cout << ans << endl ;
    
}

/*
能不能做到减少一个数对其他的数不会产生影响
当 n 是偶数的时候可能要特殊处理
其实就是变相说 不能减到负数
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
