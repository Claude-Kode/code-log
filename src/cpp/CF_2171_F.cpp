#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'

int cnt = 0 ; 

void solve()  {

    cout << ++cnt << ": " << endl ; 

    int n ; cin >> n ; 
    vector<int> arr( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> arr[i] ; 
    }

    stack<int> st ; 
    vector<vector<int>> adj( n + 1 ) ; 

    for ( int i = n ; i > 0 ; i -- ) {

        while ( !st.empty() && arr[i] > arr[st.top()] ) 
            st.pop() ; 
        
        if ( st.empty() ) { st.push( i ) ; continue ; }

        // cout << arr[st.top()] << ' ' ; 

        adj[arr[i]].push_back( arr[st.top()] ) ; 
        adj[arr[st.top()]].push_back( arr[i] ) ; 

        st.push( i ) ;

    } 

    queue<int> q ; 
    vector<int> vis( n + 1 ) ; 
    q.push( n ) ; vis[n] = 1 ;
    vector<vector<int>> ans( n + 1 ) ; 
    while ( !q.empty() ) {

        int u = q.front() ; q.pop() ;
 
        for ( auto &v : adj[u] ) if ( !vis[v] ) {
            q.push( v ) , vis[v] = 1 ; 
            ans[u].push_back( v ) ; 
        }
        
    }

    for ( int i = 1 ; i <= n ; i ++ ) if ( !vis[i] ) { cout << "NO" << endl << endl ; return ; }

    cout << "YES" << endl ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( ans[i].empty() ) continue ; 
        for ( auto &a : ans[i] ) {
            cout << i << ' ' << a << endl ; 
        }
    }

    cout << endl ; 

}

signed main() {

    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ; 
    
    return 0 ;
}


#include <bits/stdc++.h>
using namespace std ; 

void solve() {
    int n ; cin >> n ; 
    vector<itn> arr(n + 1 ) ; 
}

int main() {
    int tt ; cin >> tt ;
     while ( tt -- ) solve() ; 
    return 0 ; 
}



