// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {


    int n , m ; cin >> n >> m ;
    priority_queue<int> pq1 ;
    priority_queue<int> pq2 ;

    for ( int i = 1 ; i <= n ; i ++ ){
        int temp ; cin >> temp ; 
        pq1.push( temp ) ; 
    }

    for ( int i = 1 ; i <= m ; i ++ ) {
        int temp ; cin >> temp ; 
        pq2.push( temp ) ; 
    }

    int cnt = 0 ; 
    
    while ( !pq1.empty() && !pq2.empty() ) {

        if ( (cnt & 1) == 0 ) {
            int a = pq1.top() ; 
            int b = pq2.top() ; 
            pq2.pop() ; 
            if ( b - a >= 0 ) pq2.push( b - a ) ; 

            // cout << 1 << ' ' << a << ' ' << b << ' ' << ' ' << b - a << endl ; 

        } else {

            int a = pq1.top() ; 
            int b = pq2.top() ; 
            pq1.pop() ; 
            if ( a - b >= 0 ) pq1.push( a - b ) ; 

            // cout << "2 " << a << ' ' << b << ' ' << ' ' << a - b << endl ; 

        }

        cnt ++ ; 
        
    }

    // cout << endl << endl ; 

    if ( pq1.empty() ) { cout << "Bob" << endl ; return ; }
    if ( pq2.empty() ) { cout << "Alice" << endl ; return ;  }

}

signed main() {


    std :: ios :: sync_with_stdio(false) ; std :: cin.tie(nullptr) ; std :: cout.tie(nullptr) ;

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

