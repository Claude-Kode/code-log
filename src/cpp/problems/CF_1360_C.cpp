// @Author : GoryK 
#include <bits/stdc++.h> 
using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 


void solve() {

    int n ; cin >> n ; 
    vector<int> arr(n + 1) ; 
    unordered_map<int, int> mp ;
    vector<int> odd ;
    for ( int i = 1; i <= n ; i ++ ) { 
        cin >> arr[i] ;
        mp[arr[i]] ++  ;
        if ( arr[i] & 1 ) odd.push_back( arr[i] ) ;
    }
    
    for ( auto &a : odd ) {
        if ( mp[a - 1] ) { mp[a - 1] -- ; continue ; }
        if ( mp[a + 1] ) { mp[a + 1] -- ; continue ; }
        cout << "NO" << endl ; 
        return ; 
    }

    cout << "YES" << endl ;

}
    
    
signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;
    
    #ifdef GK
    freopen("in.txt", "r", stdin);   // 从in.txt读取
    freopen("out.txt", "w", stdout);  // 写到out.txt
    #endif

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ;      
}   

