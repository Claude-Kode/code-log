// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned int int
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD2 = 998244353 ; 
// const int MOD = 1e9 + 7 ; 
// const ll LINF = 1e18 ;
// const int maxn = 2e6 + 1 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;



// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
//     vector<int> arr(maxn , 0) ; 
//     vector<int> squares; 
//     unordered_map<int, int> ump ; 
//     for ( int i = 1 ; i <= 1e3 ; i ++ ) {
//         squares.push_back(i * i) ;  
//         ump[i * i] ++ ; 
//     }
//     for ( int i = 0 ; i < 1e3 ; i ++ ) {
//         for ( int j = i + 1 ; j < 1e3 ; j ++ ) {
// //             cout << arr[i] << ' ' << arr[j] ;
//             string num1 = to_string(squares[i]) ; 
//             string num2 = to_string(squares[j]) ; 
//             int val1 = stoll(num1 + num2) ;
//             int val2 = stoll(num2 + num1) ; 

//             if (ump[val1]) {
//                 arr[val1] ++ ; 
//             }

//             if (ump[val2]) {
//                 arr[val2] ++ ; 
//             }
            
//         }
//     }
    
//     for ( int i = 0 ; i < 1e3 ; i ++ ) {
//         int val = squares[i] ; 
//         while ( val <= 2e6 ) {
//             if ( ump[val] ) 
//                 arr[i] = 1 ;
//             val *= 10 ; 
//         }
//     }

//     for ( int i = 1 ; i <= maxn ; i ++ ) {
//         arr[i] += arr[i - 1] ; 
//     }

//     int tt ; cin >> tt ; 
//     while ( tt -- ) {
//         int x , y ; cin >> x >> y ;
//         cout << arr[y] - arr[x - 1] << endl ; 
//     }
    

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */

#include <bits/stdc++.h>

using namespace std;

int maxn = 2e6 ;
int a[2000009] ;

inline int Length( int x ) {
	int len = 0 ;
    while( x && ++len ) x /= 10 ;
	return len ;
}

inline bool sj( int x ) { 
    return ceil(sqrt(x)) * ceil(sqrt(x)) == x ; 
}

inline bool judge( int x ) {

    if ( !sj(x) ) {
        return false ; 
    }

	int len = Length( x ) ;
    for ( int i = 1 ; i < len ; i ++ ) {
        
        int m = x / pow(10 , i) ;
        int n = x - m * pow(10 , i) ;

        if ( sj(m) && sj(n) ) {
            return true ;
        }

    }

    return false ;

}

int main () {

    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;

    
	for ( int i = 1 ; i <= maxn + 1; i ++ ) {
        a[i] = judge(i) , a[i] += a[i - 1] ; 
	}
    
	int tt ; cin >> tt ;
	while( tt -- ) {
		int x , y ; cin >> x >> y ;
		cout << a[y] - a[x - 1] << '\n' ;
	}
	
	return 0 ;

}