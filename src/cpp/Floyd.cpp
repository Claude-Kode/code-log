// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n; cin >> n ;  
    vector<vector<int>> grid(n + 1 , vector<int>(n + 1 , INT_MAX)) ; 
    for (int i = 1 ; i <= n ; i ++ ) {
        int u , v , w ; cin >> u >> v >> w ; 
        grid[u][v] = w; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        grid[i][i] = 0 ; 
    }

    int x , y ; cin >> x >> y ; 
    vector<vector<vector<int>>> f(n + 1 , vector<vector<int>>(grid)) ;
    // 三维数组写法
    for ( int k = 1 ; k <= n ; k ++ ) {
        for ( int i = 1 ; i <= n ; i ++ ) {
            for ( int j = 1 ; j <= n ; j ++ ) { 
                f[k][x][y] = min(
                    f[k - 1][x][y] , 
                    f[k - 1][x][k] + f[k - 1][k][y]
                ) ;
            }   
        }
    }

    // 二维数组写法
    for ( int k = 1 ; k <= n ; k ++ ) {
        for ( int i = 1 ; i <= n ; i ++ ) {
            for ( int j = 1 ; j <= n ; j ++ ) { 
                f[x][y] = min(f[x][y] , f[x][k - 1] + f[k - 1][y] ) ;
            }   
        }
    }

}

/*
Floyd相当于 每次从当前的图中尝试增加一个节点
看能不能有更短的路径产生


对于给定的 k，当更新 f[k][x][y] 时，涉及的元素总是来自 f[k-1] 数组的第 k 行和第 k 列．然后我们可以发现，对于给定的 k，当更新 f[k][k][y] 或 f[k][x][k]，总是不会发生数值更新，因为按照公式 f[k][k][y] = min(f[k-1][k][y], f[k-1][k][k]+f[k-1][k][y]),f[k-1][k][k] 为 0，因此这个值总是 f[k-1][k][y]，对于 f[k][x][k] 的证明类似．

因此，如果省略第一维，在给定的 k 下，每个元素的更新中使用到的元素都没有在这次迭代中更新，因此第一维的省略并不会影响结果．
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

