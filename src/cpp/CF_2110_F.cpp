// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> vec(n + 1) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ; 
    }

    for ( int i = 11 ; i <= 21 ; i ++ ) {
        for (int j = 1 ; j <= 10 ; j ++ ) {
            cout << (i % j) << ' ' ;  
        } cout << endl ; 
    }



    cout << endl ; 

    // a < b , f(a , b) == a + b % a ; 
    // c < a < b , f(a , b) < f(c , b)  
    // 如果我新添加一个元素 那么这个元素要是什么样的能大于当前的答案呢
    // 首先一个元素一定是由 最大值得到的 
    // 那么我就是快速求出 前面的 a + b % a 的最大值
    // 如果 a 和 b 互质呢 , 那么答案就等于 b 
    // 如果说是互质的话 , 就找到前面里面最大的 a 和 b 互质的
    // 假如说前面的所有数字和 当前的最大值都不互质呢
    // 0 2 4 6 8
    // 没有不互质的就是 0 
    // 如果不互质就是 a
    // f(a , b) b 一定是 mx , 
    // 如果前面存在和 mx 互质的数字 , a + mx % a 
    // 如果没有就是 取最大小于 a 的数就可以
    // cout << (4 % 8) << endl ; 



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

// Functions : 

int fp( int x , int p , int mod) {
    int res = 1 , base = x ; 
    while ( p ) {
        if ( p & 1 ) (res *= base) %= mod ; 
        (base *= base) %= mod ; 
        p >>= 1 ;
    }
    return res ; 
}

int lcm (int a , int b) { return a / gcd(a , b) * b  ; } 

int inv (int x , int mod) { return fp(x , mod - 2 , mod ) ; }

void dedup(vector<int>& vec) { 
    sort(vec.begin() + 1 , vec.end()) ;
    vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

