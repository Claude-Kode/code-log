// @Author : GoryK 
#include <bits/stdc++.h> 
using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 


void solve() {

    int n ;cin >> n ;
    int nn = 1 << n ; 
    
    for ( int i = 0 ; i < nn; i ++ ) {
        int num  = i ^ (i >> 1) ;
        cout << num << ' ' ;
    }

}
   
/*
我的想法就是让两项之间异或的大小尽可能的小
也就是我想到的就是 二进制位数相同的尽可能放在一起异或
但是如果是这样的策略的话 按照顺序输出即可了 得到了一个WA 
*/
    
signed main() {

    std::ios::sync_with_stdio(false) ; 
    std::cin.tie(nullptr) ; 
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen( "INPUT.out" , "r" , stdin ) ; 
        freopen( "OUTPUT.out" , "w" , stdout ) ; 
    #endif

    solve() ; 


    return 0 ;      
}   

