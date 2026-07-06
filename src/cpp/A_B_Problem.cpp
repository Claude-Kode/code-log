// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std ;

// #define int long long
// #define endl '\n'

// const int mod = 998'244'353 ; 
// const int maxn = 1'000'000'000 ;

// unordered_map<int, int> mp ; 

// int fp( int n , int x ) {
//     int base = n , res = 1 ; 
//     while( x ) {
//         if( x & 1 ) res = (res * base) % mod ; 
//         base = (base % mod * base % mod) % mod ; 
//         x >>= 1 ; 
//     }
//     return res % mod ; 
// }

// int inv100 = fp(100 , mod - 2) % mod ; 

// int cal_p( int n ) {
//     int p = 1 ;
// switch (n) {
//         case 0:
//             p = mp[1] * mp[2] % mod ;
//             p = p * mp[3] % mod ;
//             p = p * mp[5] % mod ;
//             p = p * mp[6] % mod ;
//             p = p * mp[7] % mod ;
//             p = p * ((1 - mp[4] + mod) % mod) % mod ;
//             break ;
//         case 1:
//             p = mp[3] * mp[6] % mod ;
//             p = p * ((1 - mp[1] + mod) % mod) % mod ;
//             p = p * ((1 - mp[2] + mod) % mod) % mod ;
//             p = p * ((1 - mp[4] + mod) % mod) % mod ;
//             p = p * ((1 - mp[5] + mod) % mod) % mod ;
//             p = p * ((1 - mp[7] + mod) % mod) % mod ;
//             break ;
//         case 2:
//             p = mp[1] * mp[3] % mod ;
//             p = p * mp[4] % mod ;
//             p = p * mp[5] % mod ;
//             p = p * mp[7] % mod ;
//             p = p * ((1 - mp[2] + mod) % mod) % mod ;
//             p = p * ((1 - mp[6] + mod) % mod) % mod ;
//             break ;
//         case 3:
//             p = mp[1] * mp[3] % mod ;
//             p = p * mp[4] % mod ;
//             p = p * mp[6] % mod ;
//             p = p * mp[7] % mod ;
//             p = p * ((1 - mp[2] + mod) % mod) % mod ;
//             p = p * ((1 - mp[5] + mod) % mod) % mod ;
//             break;
//         case 4:
//             p = mp[2] * mp[3] % mod ;
//             p = p * mp[4] % mod ;
//             p = p * mp[6] % mod ;
//             p = p * ((1 - mp[1] + mod) % mod) % mod ;
//             p = p * ((1 - mp[5] + mod) % mod) % mod ;
//             p = p * ((1 - mp[7] + mod) % mod) % mod ;
//             break ;
//         case 5:
//             p = mp[1] * mp[2] % mod ;
//             p = p * mp[4] % mod ;
//             p = p * mp[6] % mod ;
//             p = p * mp[7] % mod ;
//             p = p * ((1 - mp[3] + mod) % mod) % mod ;
//             p = p * ((1 - mp[5] + mod) % mod) % mod ;
//             break ;
//         case 6:
//             p = mp[1] * mp[2] % mod ;
//             p = p * mp[4] % mod ;
//             p = p * mp[5] % mod ;
//             p = p * mp[6] % mod ;
//             p = p * mp[7] % mod ;
//             p = p * ((1 - mp[3] + mod) % mod) % mod ;
//             break ;
//         case 7:
//             p = mp[1] * mp[3] % mod ;
//             p = p * mp[6] % mod ;
//             p = p * ((1 - mp[2] + mod) % mod) % mod ;
//             p = p * ((1 - mp[4] + mod) % mod) % mod ;
//             p = p * ((1 - mp[5] + mod) % mod) % mod ;
//             p = p * ((1 - mp[7] + mod) % mod) % mod ;
//             break ;
//         case 8:
//             p = mp[1] * mp[2] % mod ;
//             p = p * mp[3] % mod ;
//             p = p * mp[4] % mod ;
//             p = p * mp[5] % mod ;
//             p = p * mp[6] % mod ;
//             p = p * mp[7] % mod ;
//             break ;
//         case 9:
//             p = mp[1] * mp[2] % mod ;
//             p = p * mp[3] % mod ;
//             p = p * mp[4] % mod ;
//             p = p * mp[6] % mod ;
//             p = p * mp[7] % mod ;
//             p = p * ((1 - mp[5] + mod) % mod) % mod ;
//             break ;
//     }
//     return p ;
// }


// void solve() {

//     int c ; cin >> c ; 

//     for ( int i = 1 ; i <= 7 ; i ++ ) {
//         int temp ; cin >> temp ; 
//         temp = temp * inv100 % mod ;
//         mp[i] = temp ;  
//     }   

//     unordered_map<int, int> digit;
//     for( int i = 0 ; i <= 9 ; i ++ ) {
//         digit[i] = cal_p(i) % mod ; 
//     } 

//     auto calc = [&](int x) -> int { 
//         if(x == 0) {
//             return digit[0] * digit[0] % mod * digit[0] % mod * digit[0] % mod;
//         }
//         int ans = 1 , len = 0 ;
//         while(x > 0) {
//             ans *= digit[x % 10] ;
//             ans %= mod ;
//             x /= 10 ;
//             len ++ ;
//         }
//         for( int i = 1 ; i <= 4 - len ; i ++ ) {
//             ans = (ans * digit[0]) % mod ;
//         }
//         return ans % mod ;
//     };

//     // for ( auto &[a , b] : mp ) cout << b << ' ' ; 
//     // cout << endl ; 
//     // for ( auto &[a , b] : digit ) cout << b << ' ' ; 
//     // cout << endl ; 

//     int ans = 0 ; 
//     for( int i = 0; i <= c; i ++ ) { ans = (ans + (calc(i) % mod * calc(c - i) % mod)) % mod ; }

//     cout << ans % mod << endl ; 

// }

// /*
// 预处理 2026 内每个数字的概率
// 然后来一个前缀乘积 
// 每个元素不存分数 , 只存分子 

// 题里面的这个概率不应该是越乘越小吗为啥还有大于一的数字
// */

// signed main() {
    
//     std::ios::sync_with_stdio(false) ;
//     std::cin.tie(nullptr) ;
//     std::cout.tie(nullptr) ;
    
//     #ifdef GK
//         freopen("INPUT.txt", "r", stdin) ;
//         freopen("OUTPUT.txt", "w", stdout) ;
//     #endif

//     cout << inv100 << endl ; 


//     int tt ; cin >> tt ;
//     while(tt --) solve() ;
    
//     return 0 ;
// }

// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998'244'353 ; 
const int maxn = 2e5 + 10 ;
const int inv100 = 828542813 ;

vector<int> num{
    0b11101110,
    0b01001000,
    0b10111010,
    0b11011010,
    0b01011100,
    0b11010110,
    0b11110110,
    0b01001010,
    0b11111110,
    0b11011110
};

void solve() {

    int c ; cin >> c ; 

    unordered_map<int, int> p;
    for ( int i = 1 ; i <= 7 ; i ++ ) {
        cin >> p[i] ; p[i] = p[i] * inv100 % mod ; 
    }
    
    vector<int> digit(10, 1) ; 
    for( int i = 0 ; i <= 9 ; i ++ ) {
        for( int j = 1 ; j <= 7 ; j ++ ) {
            if( (num[i] >> j) & 1 ) {
                digit[i] *= p[j] ;
            } else {
                // 有取模 , 要防止负数产生 要加上 mod 防止溢出
                digit[i] *= 1 + mod - p[j] ; 
            }
            digit[i] %= mod ; 
        }
    }

    auto cal_p = [&](int x) -> int {
        int len = 4 , res = 1 ; 
        while( x ) {
            res = res * digit[x % 10] ; 
            res %= mod ; 
            x /= 10 ; len -- ; 
        }
        while( len -- ) res = (res * digit[0]) % mod ; 
        return res ; 
    } ; 

    int ans = 0 ; 
    for( int i = 0 ; i <= c ; i ++ ) {
        ans = (ans + cal_p( i ) % mod * cal_p(c - i) % mod) % mod ;  
    }

    cout << ans << endl ; 

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

    int tt ; cin >> tt ;
    while(tt --) solve() ;
    
    return 0 ;
}