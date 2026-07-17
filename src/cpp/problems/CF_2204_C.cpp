// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int lcm(int a , int b) {return a * b / gcd(a , b) ; }

void solve() {

    int a , b , c , m ; cin >> a >> b >> c >> m ; 
    
    

    cout << m / a * 6 - m / (a * b / gcd(a , b)) * 3 - m / (a * c / gcd(a , c)) * 3 + m / lcm(lcm(a , b) , c) * 2 << ' ' ; 
    cout << m / b * 6 - m / (b * a / gcd(a , b)) * 3 - m / (b * c / gcd(b , c)) * 3 + m / lcm(lcm(a , b) , c) * 2 << ' ' ; 
    cout << m / c * 6 - m / (c * b / gcd(c , b)) * 3 - m / (c * a / gcd(c , a)) * 3 + m / lcm(lcm(a , b) , c) * 2 << ' ' ; 
    cout << endl ; 

}

/*

*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    // cout << fixed << setprecision(6) ;

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}

