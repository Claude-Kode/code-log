// // @Author : GoryK 
// #include <bits/stdc++.h> 
// using namespace std ; 

// #define int long long 
// #define endl '\n'


// const int mod = 1e9 + 7 ;
// const int maxn = 2e5 ; 

// // 这道题我想麻烦的点在于 没想到用 uset
// // 因为我的思维还是用搜索的方式 , 从而把一个链节中的不同字符之间增添了关系
// // 事实上每个链节的每个字符之间是互相独立的 , 行就是行不行就是不行
// // 如果不行整个答案都应该被废掉
// // 我想成搜索了 太傻逼了
// // 直接用 uset 可以快速得知有没有这个字符 记住这个小技巧

// void solve() {

//     int n , k ; cin >> n >> k ; 
//     vector<string> str(k + 1, " ") ;
//     for (int i = 1 ; i <= k ; i ++) {
//         string temp ; cin >> temp ; 
//         str[i] += temp ;
//     } 

//     vector<unordered_set<char>> uset(n + 1) ; 
//     for (int i = 1 ; i <= n ; i ++ ) {
//         for ( int j = 1 ; j <= k ; j ++ ) {
//             uset[i].insert(str[j][i]) ; 
//         }
//     }

//     vector<int> facs ; int lim = sqrt( n ) ;
//     for( int i = 1 ; i <= lim ; i ++ ) if ( n % i == 0 ) {
//         facs.push_back(i) , facs.push_back(n / i) ; 
//     }

//     sort( facs.begin() , facs.end() ) ; 

//     string ans = "" ; 
//     for( int fac : facs ) {
//         bool fac_ok = true ; 

//         for( int r = 1 ; r <= fac ; r ++ ) {

//             unordered_map<char, int> ump ; 
//             for( int i = r ; i <= n ; i += fac ) {
//                 for( char c : uset[i] ) ump[c] ++ ; 
//             }

//             bool col_ok = false ; 
//             for( auto [c , cnt] : ump ) if ( cnt == n / fac ) {
//                 ans += c ; col_ok = true ; break ; 
//             }

//             if ( !col_ok ) { fac_ok = false ; break ; }

//         }

//         if ( !fac_ok ) ans = "" ; 
//         else { 
//             for( int i = 1 ; i <= n / fac ; i ++ ) cout << ans ;
//             cout << endl ; return ; 
//         }
//     }    

// }
    
    
// signed main() {

//     std::ios::sync_with_stdio(false) ; 
//     std::cin.tie(nullptr) ; 
//     std::cout.tie(nullptr) ;
    
//     #ifdef GK
//         freopen( "INPUT.out" , "r" , stdin ) ; 
//         freopen( "OUTPUT.out" , "w" , stdout ) ; 
//     #endif

//     int tt ; cin >> tt ;
//     while( tt -- ) solve() ; 


//     return 0 ;      
// }   

// // @Author : GoryK 
// #include <bits/stdc++.h> 
// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int mod = 1e9 + 7 ;
// const int maxn = 2e5 ; 

// void solve() {

//     int n , k ; cin >> n >> k ; 
//     vector<string> str(k) ;
//     for ( int i = 0 ; i < k ; i ++ ) {
//         cin >> str[i] ;
//     }

//     // 每列掩码
//     vector<int> col_msk(n, 0) ;
//     for ( int i = 0 ; i < n ; i ++ ) {
//         int msk = 0 ;
//         for ( int j = 0 ; j < k ; j ++ ) {
//             msk |= (1 << (str[j][i] - 'a')) ;
//         }
//         col_msk[i] = msk ;
//     } 

//     // 所有因子
//     vector<int> fac ;
//     int lim = sqrt(n) ; 
//     for ( int i = 1 ; i <= lim ; i ++ ) {
//         if ( n % i == 0 ) {
//             fac.push_back(i) ;
//             if ( i != n / i ) {
//                 fac.push_back(n / i) ;
//             }
//         }
//     }

//     sort(fac.begin() , fac.end()) ; 

//     for ( auto &d : fac ) {
//         bool ok = true ;
//         vector<char> cls_ans(d , '?') ;  
        
//         for ( int r = 0 ; r < d ; r ++ ) {
//             int msk = col_msk[r] ;
//             for ( int pos = r + d ; pos < n ; pos += d ) {
//                 msk &= col_msk[pos] ;
//                 if ( msk == 0 ) break ;
//             }
//             if ( msk == 0 ) {
//                 ok = false ;
//                 break ;
//             }
            
//             char c ;
//             for ( int i = 0 ; i < 26 ; i ++ ) {
//                 if ( msk >> i & 1 ) {
//                     c = 'a' + i ;
//                     break ;
//                 }
//             }
//             cls_ans[r] = c ;
//         }
        
//         if ( ok ) {
//             string ans ;
//             for ( int i = 0 ; i < n ; i ++ ) {
//                 int r = i % d ;
//                 ans += cls_ans[r] ;
//             }
//             cout << ans << endl ; 
//             return ;
//         }

//     }
// }
    
// signed main() {

//     ios::sync_with_stdio(false) ; 
//     cin.tie(nullptr) ; 
//     cout.tie(nullptr) ;
    
//     #ifdef GK
//         freopen( "INPUT.out" , "r" , stdin ) ; 
//         freopen( "OUTPUT.out" , "w" , stdout ) ; 
//     #endif

//     int tt ; cin >> tt ;
//     while( tt -- ) solve() ; 

//     return 0 ;      
// }




// @Author : GoryK
#include <bits/stdc++.h>
#include <bit>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

void binary_output( int a ) {
    vector<int> num(32 , 0) ; 
    int cnt = 1 ; 
    while( a ) {
        num[cnt] = (a & 1) ; 
        a /= 2 ; 
        cnt ++ ; 
    } 

    for( int i = 31 ; i > 0 ; i -- ) cout << num[i] ;
    cout << endl ;  
    
}

void solve() {

    int n , k ; cin >> n >> k ; 
    vector<string> str(k + 1, " ") ;
    vector<int> msk(n + 1) ; 
    for( int i = 1 ; i <= k ; i ++ ) {
        cin >> str[i] ; 
    }

    for( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= k ; j ++ ) {
            msk[i] |=(1 << (str[i][j] - 'a' + 1)) ; 
        }
    }
    


}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    #endif

    // int tt ; cin >> tt ; 
    // while ( tt -- ) solve() ; 

    cout << __builtin_popcount( 3 ) ;

    return 0;
}