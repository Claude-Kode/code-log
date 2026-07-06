// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    /*
    00 -> 00
    01 -> 11 -> 00 
    10 -> 11 -> 00 
    11 -> 00 
    */

    int n ; cin >> n ; 
    string s , t ; cin >> s >> t ; 

    if ( s == t ){
        cout << "YES" << endl ;
        return ; 
    }

    if ( count(s.begin() , s.end() , '1') == 0 ) {
        cout << "NO" << endl ; 
        return ; 
    }

/*
就是其实是这样的 我们先把 s 全部看成 1  , 然后 t 里面任意一段 0 的地方我们可以轻易变的过去 
所以直接不用考虑 , 我们可以直接把 t 里面连续 0 的段全部变成 1 就可以(continue_cnt_0 >= 2)
剩下的都是单个出现的被两边夹住的 0  , 也就是这样的结构
11111 -> 11011 或者 11111 -> 10111 或者 11111 -> 11101 或者 11111 -> 01111 或者 11111 -> 11110
其实都是一样的 那第一个举例子
11111 -> 11001 -> 111011 , 把第 i 位变成 0 需要 i+1 的参与 , 也需要 i+2 的参与这两者都要是 1 
或者是 i-1 和 i-2 的参与

也就是说只要一个 被夹住的 0 的邻居是两个连续的 0 或者 1 都可以(0在前面已经被转化成 1了)

那么我们不妨想想极端情况了 , 如果所有的被架住的 0 周围都没有连续的两个 1 呢
那他应该是长这样的
0101010101或者101010101
我们不禁又想了 , 如果我只添加一个连续的 1 呢
比如 010101010, 11 我们仅仅通过一个11能不能把左边一串的10101010转化成全 1 呢
答案是可以的

我们来看01010101的情况
也就是
11111111 -> 01010101
11111111 -> 00111111 -> 01111111 -> 01001111 -> 01011111 ->
01010011 -> 01010111 -> 01010100 
道了这里 , 最右边的0的右边没有 1 可以组成 01 从而转化成 11 了 , 所以对于一串 01交替串 , 
只要一个 11 或者 00 就可以 , 无论他在哪里 , 只要有就可以

这题真牛逼

*/

    for ( int i = 0 ; i < n - 1 ; i ++ ) if ( t[i] == t[i + 1] ) {
        cout << "YES" << endl ; 
        return ; 
    }

    cout << "NO" << endl ; 

//   11111111111
//   01010101011

}

/*

// 可以吧任意一段 1 全都变成 0 
// 可以直接把 s == 1 但是 t == 0 的地方全都变好
// 然后剩下的都是 s == 0 但是 t == 1 的地方
// 或者是说只要 s 有一个 1 就可以把所有的东西全都变成 1 然后再按照范围往下面校园
// 这种属于找出关键特征直接输出 YES 或者 NO 的题
// 我们想想那些位置的 0 是不可以被消掉的

// if (s.front() == '0' && t.front() == '1' || s.back() == '0' && t.back() == '1' ) {
//     cout << "NO" << endl ; 
//     return ; 
// }

// cout << "YES" << endl ; 

// auto ch = [&]( string o , string t ) -> bool {
//     if ( o == "00" ) return false ; 
//     else if ( o == "01" || o == "10" ) return t == "11" || t == "00"; 
//     else return t == "11" || t == "00" ; 
// } ;

// // from r to l change every two ele 
// for ( int i = 1 ; i < n ; i ++ ) if ( s[i] != t[i] || s[i - 1] != t[i - 1] ) {
//     string ss = {s[i - 1] , s[i]} , tt = {t[i - 1], t[i]} ; 
//     // cout << ss[1] << ' ' << tt << endl ;
//     if ( ch(ss, tt) ) {
//         s[i - 1] = t[i - 1] , s[i] = t[i] ;
//     } else {
//         // break ; 
//         cout << "NO"  << endl ; 
//         return ; 
//     }   
// }

// cout << "YES" << endl ; 


// for ( int i = n ; i > 1 ; i -- ) if ( s[i] != t[i] || s[i - 1] != t[i - 1] ) {
//     string ss = string(1 , s[i - 1]) + s[i] , tt = string (1 , t[i - 1])  + t[i] ;
//     if ( ch(ss, tt) ) {
//         s[i - 1] = t[i - 1] , s[i] = t[i] ;
//     } else {
//         cout << "NO" << endl ; 
//         return ; 
//     }   
// }

// cout << "YES" << endl ; 

*/

signed main() {
    
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin) ;
        freopen("OUTPUT.txt", "w", stdout) ;
    #endif

    solve() ;
    
    return 0 ;
}