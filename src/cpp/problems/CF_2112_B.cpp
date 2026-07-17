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
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ;
    }

    // 当数组长度是 2 的时候不会进入循环
    for ( int i = 2 ; i <= n - 1 ; i ++ ) {
        if ( abs(arr[i] - arr[i - 1]) <= 1 || abs( arr[i + 1] - arr[i]) <= 1 ) {
            cout << 0 << endl ; 
            return ; 
        }
    }

    // 对于三元问题往往都是枚举中间的元素来的更方便
    // for ( int i = 1 ; i <= n - 1 ; i ++ ) {
    //     if ( abs( arr[i + 1] - arr[i]) <= 1 ) {
    //         cout << 0 << endl ; 
    //         return ; 
    //     }
    // }

    for ( int i = 1 ; i <= n - 2 ; i ++ ) {
        if ( arr[i] <= arr[i + 1] && arr[i] >= arr[i + 2] || arr[i] >= arr[i +1] && arr[i] <= arr[i + 2] ) {
            cout << 1 << endl ; 
            return ;
        }
    }

    for ( int i = n ; i >= 3 ; i -- ) {
        if ( arr[i] <= arr[i - 1] && arr[i] >= arr[i - 2] || arr[i] >= arr[i - 1] && arr[i] <= arr[i - 2] ) {
            cout << 1 << endl ; 
            return ;
        }
    }

    cout << -1  << endl ; 

    // if ( is_sorted( arr.begin() + 1  , arr.end() ) ) cout << -1 << endl ; 
    // else cout << 1 << endl ; 

    // for ( int i = 1 ; i <= n - 2 ; i ++ ) {
    //     if ( abs(arr[i + 2] - arr[i] <= 1) ) {
    //         cout << 1 << endl ; 
    //         return ; 
    //     }
    // }

    // for ( int i = n ; i >= 3 ; i -- ) {
    //     if ( abs(arr[i] - arr[i - 2] <= 1) ) {
    //         cout << 1 << endl ; 
    //         return ; 
    //     }
    // }

    // cout << -1 << endl ; 

}

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