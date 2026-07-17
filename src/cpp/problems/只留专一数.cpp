// // @Author : GoryK 
// // @Description : TEMPLATE-2 
// #include <bits/stdc++.h> 

// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int mod = 1e9 + 7 ;
// const int maxn = 2e5 ; 

// bool check( int a ) {
//     int lim = sqrt( a ) ; 
//     for ( int i = 2 ; i <= lim ; i ++ ) 
//         if ( a % i == 0 ) return false ; 
//     return true ;
// }

// void solve() {

//     int n ; cin >> n ;
//     vector<int> arr( n + 1 ) ; 
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         cin >> arr[i] ; 
//     }

//     for ( int i = 1 ; i <= n ; i ++ ) {
//         int cnt = 0 , lim = sqrt( arr[i] ) ; 
//         for ( int j = 2 ; j <= lim ; j ++ ) {
//             if ( arr[i] % j == 0 ) {
//                 int a = j , b = arr[i] / j ; 
//                 cout << a << ' ' << b << endl ; 
//                 cnt += check(a) ; cnt += check(b) ; 
//             }
//         }
//         cout << "cnt " << cnt << endl ; 
//         if ( cnt == 1 ) { cout << "YES" << endl ; return ; }
//     }

//     cout << "NO" << endl ; 

// }

// /*

// */

// signed main() {
//     std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
//     int tt ; cin >> tt ;
//     while( tt -- ) solve() ; 


//     return 0 ; 
// }   

// /*
    
// */
// @Author : GoryK 

// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

bool is_prime(int a) {
    if (a < 2) return false;
    int lim = sqrt(a);
    for (int i = 2; i <= lim; i++) 
        if (a % i == 0) return false;
    return true;
}

void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        int x = arr[i];
        if (is_prime(x)) {
            cout << "YES" << endl;
            return;
        }

        int lim = sqrt(x);
        bool found = false;
        for (int j = 2; j <= lim; j++) {
            if (x % j == 0) {
                if (is_prime(j)) {
                    int temp = x;
                    while (temp % j == 0) {
                        temp /= j;
                    }
                    if (temp == 1) {
                        found = true;
                        break;
                    }
                }
                int k = x / j;
                if (is_prime(k)) {
                    int temp = x;
                    while (temp % k == 0) {
                        temp /= k;
                    }
                    if (temp == 1) {
                        found = true;
                        break;
                    }
                }
            }
        }
        if (found) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr) ; std::cout.tie(nullptr);

    int tt; 
    cin >> tt;
    while (tt--) solve();

    return 0;
}