// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'
#define UMP unordered_map<int, int>

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

struct edge { int v ; int w ; } ;

void solve() {

    int n , m ; cin >> n >> m ;
    vector<int> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ; 

    UMP ump ;
    while ( m -- ) {
        int u , v ; cin >> u >> v ; 
        ump[u] = v , ump[v] = u ;
    }

     

}

/*

*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
    
*/