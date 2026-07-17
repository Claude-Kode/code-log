#include <bits/stdc++.h>
using namespace std ; 

#define int long long 
#define endl '\n' 

void solve() {

    int x ; vector<int> vec(1) ; 
    while ( cin >> x && x != -1 ) {
        vec.push_back( x ) ;
    }

    unordered_map<int , int> ump ; 
    for ( int i = 1 ; i <= vec.size() - 1 ; i ++ ) {
        int lp = ump[vec[i]] ; 
        if ( lp >= 3 ) {
            if ( ump[vec[i - 1]] == lp - 1 && ump[vec[i - 2]] == lp - 2 ) {
                cout << vec[lp - 2] << ' ' << vec[lp - 1] << ' ' << vec[lp] << endl ;
                return ;  
            } 
        }
        ump[vec[i]] = i ; 
    }

    cout << "NONE" << endl ; 

}

signed main() {

    ios::sync_with_stdio(false) ; 
    cin.tie(nullptr) ; 
    cout.tie(nullptr) ; 

    int tt ; cin >> tt ; 
    while ( tt -- ) solve()  ;
    
    return 0 ; 
}