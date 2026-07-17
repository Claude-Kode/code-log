// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {  

    int n , p ; cin >> n >> p ; 
    vector<int> vec(n + 1) ; 
    int mn = INT_MAX , ans = INT_MIN , l = 0 , r = 0 ; 
    unordered_map<int, int> ump ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ;
        (vec[i] += vec[i - 1]) %= p ; 
        ans = max(ans , (vec[i] - mn + p) % p) ; 
        mn = min(mn , vec[i]) ; 
    } 

    cout << ump[mn] << ' ' << ump[mn + ans] << ' ' << ans << endl ; 
    
}

/*
结果是确定的吗 肯定不是确定的 
但是题目保证每个数的大小都是小于等于 p
我一开始的想法就是线性遍历 选或者不算当前的数字 

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

