// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1)) ; 

    for ( int i = 1 ; i <=n ; i ++ ) {
        if ( !(i & 1) ) {
            for ( int j = i ; j <= n ; j ++ ) {
                arr[i][j] = 1 ;
                arr[j][i] = 1 ; 
            }
        }
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= n ; j ++ ) {
            cout << arr[i][j] ; 
        }
        cout << endl ; 
    }

}

/*

这道题的答题思路还是很好想的 , 就是一换套一环 每一环 1 的数量都越多

但是有一种特殊的情况 , 如果最大的那一环是 1 的话 , 那么就会出现 row == n 的情况 , 
而且还有一种情况 , 就是 n == 1 的时候要求等于 0 
第二点问题可以通过 !(i & 1) 来解决问题 , 但是出现 row == n 的情况是不可避免的

所以这个时候把整个他徐康倒置过来 , 相当于从 1 的矩阵里面填充 0 就好办了 , 也就是说 我们从 row == n - 1 开始实现
这样能保证出现数字的上限一定是 n - 1 , 下限一定是 0 

另外如果本题要求的是 1 - n的话 
i & 1 加上正序填充即可解决问题

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