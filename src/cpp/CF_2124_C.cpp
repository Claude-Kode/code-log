// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int gcd( int a , int b ) { return b == 0 ? a : gcd(b , a % b ) ; }

int lcm( int a , int b ) {
    return a * b / gcd( a , b ) ; 
}

void solve() {

    int n ; cin >> n ; 
    vector<int> arr(n + 1) ; 
    for( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }

    int ans = 1 ; 
    for( int i = n ; i > 1 ; i -- ) {
        if( arr[i] % arr[i - 1] ) {
            int k = lcm(arr[i] , arr[i - 1]) / arr[i] ;
            ans = lcm(ans , k) ; 
        }
    }

    cout << ans << endl ; 

}

/*
我是想先确定哪些数字有问题 然后从这些数字中找到规律
判断数字有问题的特征是前一项大于后一项那么绝对是前一项有问题
那么如果后一项不能被后一项整除呢 又该是谁的问题

验证之后是只有大小会产生影响
然后 根号n 分解 + 验证

但是可以反着想 , 把另外没变小的数字也扩大 k 倍 , 然后验证这个最小 k 

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
