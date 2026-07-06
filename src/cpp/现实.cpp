// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

struct infor { int x ; int y ; } ; 
vector<infor> ifo ;  

/*

    这道题的思路我一眼就是贡献法做到 O(n*m) 遍历即可
    但是求的是 MEX 而不是最小值的那个数 , 就是一个数字不能的单独产生贡献

    0 除外 , 这个是可以自己单独产生贡献的



*/

void solve() {

    int n , m ; cin >> n >> m ;
    vector<vector<int>> arr( n + 1 , vector<int>( m + 1 )) ;

    ifo.resize( n*m + 1 ) ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            cin >> arr[i][j] ; 
            ifo[arr[i][j]].x = i ;
            ifo[arr[i][j]].y = j ;
        }
    }

    

}

signed main() {


    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   