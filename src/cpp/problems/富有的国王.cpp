// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int n , m ; 

/*
就是数联通快的
*/


signed main() {


    cin >> n >> m ; 

    for ( int i = 1 ; i <= m ; i ++ ) {
        int u , v ; cin >> u >> v ; 
    }

    cout << (n * (n - 1)) - m << endl ; 

    return 0 ; 
}   

