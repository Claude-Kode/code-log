// #include <bits/stdc++.h>
// using namespace std ; 

// #define int long long 
// #define endl '\n' 


// int Find ( int a , vector<int>& fa) {
//     if ( fa[a] == a ) return a ; 
//     else return fa[a] = Find(fa[a] , fa) ; 
// } 

// void un (int a , int b, vector<int>& fa) {
//     int ra = Find(a ,  fa) , rb = Find(b , fa) ; 
//     // if ( ra == rb ) return ; 
//     fa[ra] = rb ;
// } 

// void solve() {

//     int n , m ; cin >> n >> m ; 

//     vector<int> fa(m + 1) ; 
//     for ( int i = 1 ; i <= m ; i ++ ) fa[i] = i ; 

//     vector<vector<int>> vec(n + 1 , vector<int>(m + 1)) ;
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         int mm = 0 ; cin >> mm ;
//         for ( int j = 1 ; j <= mm ; j ++ ) {
//             cin >> vec[i][j] ; 
//             if ( j > 1 ) un(vec[i][j] , vec[i][j - 1] , fa) ; 
//         }
//     }

//     int cnt = 0 ; vector<vector<int>> adj(m + 1) ;  
//     for ( int i = 1 ; i <= m ; i ++ ) {
//         int fi = 0 ;
//         // int fi = Find( i , fa) ; 
//         adj[fi].push_back( i ) ; 
//     }

//     vector<int> ans ; 
//     for ( int i = 1 ; i <= m ; i ++ ) {
//         ans.push_back( *min_element( adj[i].begin() , adj[i].end()) ) ; 
//     }

//     sort(ans.begin() , ans.end()) ; 
//     for ( const auto &a : ans ) { 
//         cout << a ;
//         if ( a != ans.back() ) cout << ' ' ; 
//     }
//     cout << endl ;

// }

// signed main() {

//     ios::sync_with_stdio(false) ; 
//     cin.tie(nullptr) ; 
//     cout.tie(nullptr) ; 

//     solve()  ;
    
//     return 0 ; 
// }

#include <bits/stdc++.h>
using namespace std ; 

#define int long long 
#define endl '\n' 

vector<int> fa ; 


int Find ( int a ) {
    if ( fa[a] == a ) return a ; 
    else return fa[a] = Find(fa[a]) ; 
} 

void un (int a , int b) {
    int ra = Find(a) , rb = Find(b) ; 
    if ( ra == rb ) return ; 
    fa[ra] = rb ;
} 

void solve() {

    int n , m ; cin >> n >> m ; 

    fa.assign(m + 1 , 0) ; 
    for ( int i = 1 ; i <= m ; i ++ ) fa[i] = i ; 


    vector<vector<int>> vec(n + 1 , vector<int>(m + 1)) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        int mm = 0 ; cin >> mm ;
        for ( int j = 1 ; j <= mm ; j ++ ) {
            cin >> vec[i][j] ; 
            if ( j > 1 ) un(vec[i][j] , vec[i][j - 1]) ; 
        }
    }

    vector<vector<int>> adj(m + 1) ;  
    for ( int i = 1 ; i <= m ; i ++ ) {
        int fi = Find( i ) ; 
        adj[fi].push_back( i ) ; 
    }

    vector<int> ans ; 
    for ( int i = 1 ; i <= m ; i ++ ) if ( !adj[i].empty() ) {
        ans.push_back( *min_element( adj[i].begin() , adj[i].end()) ) ; 
    }

    sort(ans.begin() , ans.end()) ; 
    for ( const auto &a : ans ) {
        cout << a ;
        if ( a != ans.back() ) cout << ' ' ;
    }
    cout << endl ;

}

signed main() {

    ios::sync_with_stdio(false) ; 
    cin.tie(nullptr) ; 
    cout.tie(nullptr) ; 

    solve()  ;
    
    return 0 ; 
}