// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 

    vector<int> ans(n - 2) ; 
    iota(ans.begin() , ans.end() , 1) ; 
    reverse(ans.begin() , ans.end()) ; 
    if (n & 1) ans.pop_back() , cout << 1 << ' ' ;
    for ( auto &a : ans) cout << a << ' ' ;
    cout << n - 1 << ' ' << n << endl ; 
    

}

/*
根本还是从最后的值出发
最大值就是 2*n - 1 那么很容易就是最后两个值一定是 n -1 和 n
我想多了 我甚至把 n - 1还要拆成几个数 被自己气笑了666
然后保证前面 n-2 个数字的 x 值是 0 就可以
问题就出在这里 如果是偶数两两一组的低级爱你关系可以完美实现但是如果是奇数就不行
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