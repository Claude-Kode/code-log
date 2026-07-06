// // @Author : GoryK 
// // @Description : TEMPLATE-2 
// #include <bits/stdc++.h> 

// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int mod = 1e9 + 7 ;
// const int maxn = 2e5 ; 

// int n , m , k ; 

// vector<vector<int>> grid ;
// vector<vector<vector<int>>> dp ;

// signed main() {


//     cin >> n >> m >> k ;
//     grid.resize( n + 1 , vector<int>( m + 1 )) ;
//     // 为什么要初始化成 INT_MAX 呢
//     // 因为取结果的时候是 min , 为了确保初始化的值不会影响状态转移
//     // 所以初始化成 INT_MAX
//     dp.resize( k + 1 , vector<vector<int>>( n + 1  , vector<int>( m + 1 , INT_MAX ))) ; 

//     for ( int i = 1 ; i <= n ; i ++ ) {
//         for ( int j = 1 ; j <= m ; j ++ ) {
//             cin >> grid[i][j] ; 
//         }
//     }

//     // 边界要初始化成 0 是因为边界情况的状态转移方程是不一样的
//     // 但是难道要重新改写公式吗 ? 肯定不啊 , 只要把边界情况的值代入状态转移方程不影响最终结果就可以
//     for ( int kk = 1 ; kk <= k ; kk ++ ) {
//         // 这个 1 , 1都是初始化成 0 才是正确的 我没有考虑到
//         // 因为在递推公式里有四个来源 , (1, 1)的四个来源都是边界 , 所以要初始化
//         dp[kk][1][1] = 0 ;
//     }
    


//     // 这里还漏掉了一个初始化 , 我是从 k == 1 开始推的 但是 k == 1 是从 k == 0 开始推的 , k == 0 的情况我没有处理
//     // 也可以不初始化 , 因为状态转移方程都差不多 , 
//     // for ( int i = 1 ; i <= n ; i ++ ) {
//     //     for ( int j = 1 ; j <= m ; j ++ ) {
//     //         dp[0][i][j] = min( max( dp[0][i - 1][j] , grid[i][j] ) , max( dp[0][i][j - 1] , grid[i][j] ) ) ;
//     //         cout << dp[0][i][j] << ' ' ;
//     //     }
//     //     cout << endl ; 
//     // }

//     // dp[kk][i][j] = min({ max( dp[kk][i - 1][j] , grid[i][j] ) , max( dp[kk][i][j - 1] , grid[i][j] ) , dp[kk - 1][i - 1][j] , dp[kk - 1][i][j - 1] })
//     dp[0][1][1] = grid[1][1] ;
//     // for ( int kk = 0 ; kk <= k ; kk ++ {
//         for ( int i = 1 ; i <= n ; i ++ ) {
//             for ( int j = 1 ; j <= m ; j ++ ) {

//                 if ( i == 1 && j == 1 ) continue ; 

//                 if ( kk < 1 ) dp[kk][i][j] = min( max( dp[kk][i - 1][j] , grid[i][j] ) , max( dp[kk][i][j - 1] , grid[i][j] ) ) ;

//                 else dp[kk][i][j] = min({ max( dp[kk][i - 1][j] , grid[i][j] ) , max( dp[kk][i][j - 1] , grid[i][j] ) , dp[kk - 1][i - 1][j] , dp[kk - 1][i][j - 1] }) ;

//             }
//         } 
//     }

//     // for ( int kk = 0 ; kk <= k ; kk ++ ) {
//     //     for ( int i = 1 ; i <= n ; i ++ ) {
//     //         for ( int j = 1 ; j <= m ; j ++ ) {
//     //             cout << dp[kk][i][j] << ' ' ; 
//     //         }
//     //         cout << endl ;
//     //     }
//     //     cout << endl << endl ; 
//     // }

//     cout << dp[k][n][m] << endl ; 

//     return 0 ; 
// }


// // 初始化到底在初始化什么
// // 第一是初始化递推的起点 , 让递推公式能 站在正确的角度进行递推
// // 第二是初始化处理边界情况 让递推公式中的因子都是正确的

// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int n , m , k ;

void solve() {


    cin >> n >> m >> k ; 
    vector<vector<int>> grid( n + 1 , vector<int>( m + 1 )) ; 
    
    int mx = INT_MIN ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            cin >> grid[i][j] ; 
            mx = max( mx , grid[i][j] ) ; 
        }
    } 

    // 二分枚举这条路的最小代价 
    // 问题转换成 , 如果要以 kk 这个代价从(1, 1) 到达(n, m) 要消掉多少值最少要消掉多少
    // 这个好像是个 dp
    auto  check = [&](int test) -> bool {
        int cnt = k ; 
        // dp[i][j] 在当前 test 中 路径中大于等于 test 的最小路径上有多少个 
        vector<vector<int>> dp( n + 1 , vector<int>( m + 1  , INT_MAX )) ;

        // for ( int i = 0 ; i <= n ; i ++ ) dp[i][0] = 0 ;
        // for ( int j = 0 ; j <= m ; j ++ ) dp[0][j] = 0 ;

        dp[1][1] = (grid[1][1] > test) ; 

        for ( int i = 1 ; i <= n ; i ++ ) {
            for ( int j = 1 ; j <= m ; j ++ ) {
                if ( i == 1 && j == 1 ) continue ; 
                // if ( i == 1 ) dp[i][j] = dp[i][j - 1] + (grid[i][j] > test) ; 
                // else if ( j == 1 ) dp[i][j] = dp[i - 1][j] + (grid[i][j] > test) ; 
                dp[i][j] = min( dp[i - 1][j] + (grid[i][j] > test) , dp[i][j - 1] + (grid[i][j] > test)) ; 
            }
        }
        
        // for ( int i = 1 ; i <= n ; i ++ ) {
        //     for ( int j = 1 ; j <= m ; j ++ ) {
        //         cout << dp[i][j] << ' ' ;
        //     }
        //     cout << endl ;
        // }

        // cout << endl ; 

        // cout << "test : " << test << ' ' << "min_cnt: " << dp[n][m] << endl ; 

        return dp[n][m] <= k ; 

    } ;

    int l = 0 , r = mx , ans = -1 ; 
    while ( l <= r ) {
        // cout << "l " << l << "  r " << r << endl ;
        int mid = ( l + r ) / 2 ;
        if ( check(mid) ) ans = mid , r = mid - 1 ;  
        else l = mid + 1 ;
    }

    cout << ans << endl ;  

}

signed main() {


    solve() ; 


    return 0 ; 
}   


