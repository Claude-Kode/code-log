// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

void solve() {

    int a , b ; cin >> a >> b ;
    
    if (a == b) {
        while( a -- ) cout << "10" ; cout << endl ;   
        return ;
    } 

    // 应该就是把 1 均匀的插入 0 之间
    char c0 = '0' , c1 = '1' ; 
    if ( a < b ) swap(a , b) , swap(c0 , c1) ; 
    int aa = a / (b + 1) , rema = a % (b + 1) ; 
    string ans = "" ; 
    for ( int i = 1 ; i <= b + 1 ; i ++ ) {
        ans += string(aa + (rema --> 0) , c0) + c1 ; 
    }
    ans.pop_back() ; 
    cout << ans << endl ; 
}

/*
让所有的 字符串最好都包含 01 即可
最好字符串就是长成这样 01010101
让我们来这样思考
010101011111
110110110110
这两个字符串的 mex 是否是等价的否则的话应该怎么样

01 == 10 > 00 == 0 > 11 == 1

有时候的最大化问题想不通或许可以用最小化问题

*/

signed main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    #ifdef GK
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    #endif

    int tt ; cin >> tt ;
    while (tt--) solve() ;
    
    return 0;
}