// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 
const double minn = 1e-4 ;


void solve() {

    int n ; cin >> n ;

    double sumx = 0 , sumy = 0 ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        double x , y ; cin >> x >> y ; 
        sumx += x ; sumy += y ; 
    }

    cout << sumx / n << ' ' << sumy / n << endl ; 

}

signed main() {

    cout << fixed << setprecision(3) ; 

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

