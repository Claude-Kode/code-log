// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 998244353 ;
const int maxn = 2e5 ; 

int fac( int n ) {
    int res = 1 ; 
    for ( int i = 2 ; i <= n ; i ++ ) res *= i , res %= mod ; 
    return res % mod ; 
} 

// 我的一个思路是对的 就是得分是一定的 
// 最大得分无关顺序 , 就是数子给你了的时候最大的分已经被定义了
// 得分的时候不会影响不得分组别的数组 , 不得分的组别的数字不会消失
// 也就是说一组最多就 n 个数字可以得分
// 其次就是排列 , 排列的意义就是两个数字之间只会存在大于或者小于的关系 , 也就是要么得分要么不得分

// 所以我们把数字分成两部分 , 得分的部分就是大于量一个组别的最小值的数字的数量就是得分

void solve() {

    int n ; cin >> n ; 
    vector<int> a(n + 1) , b(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> b[i] ;

    sort( a.begin() + 1 , a.end() ) ; 
    sort( b.begin() + 1 , b.end() ) ; 

    int part1 = upper_bound( a.begin() + 1 , a.end() , b[1] ) - a.begin() - 1 ; 
    int part2 = n - part1 ; 
    int ans = fac(part1) * fac(part2) % mod ;

    cout << ans << endl ;

}

/*

*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
    
*/