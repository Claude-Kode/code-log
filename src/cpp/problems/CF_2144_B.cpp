// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> vec(n + 1) , buckle(n + 1) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; buckle[vec[i]] ++ ; 
    }

    vector<int> nums ; 
    for ( int i = 1 ; i <= n ; i ++ ) if ( buckle[i] == 0 ) {
        nums.push_back( i ) ; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) if(vec[i] == 0) {
        vec[i] = nums.back() ; nums.pop_back() ;
    }

    if ( is_sorted(vec.begin() + 1 , vec.end()) ) {
        cout << 0 << endl  ; return ; 
    }

    int mn = INT_MAX , mx = INT_MIN ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( vec[i] != i ) {
            mn = i ; break ; 
        }
    }
    for ( int i = n ; i >= 1 ; i -- ) {
        if ( vec[i] != i ) {
            mx = i ; break ; 
        }
    }
    
    cout << mx - mn + 1 << endl ;

}

/*
第一个你怎么界定最短子段
我想的是树立几个标杆 当前元素处于对的位置上然后
*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}