// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , y ; cin >> n >> y ; 
    vector<int> c(n + 1) , cnt(2e5 + 5 , 0) , pre(2e5 + 5 , 0) ; 

    int mx = INT_MIN ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> c[i] ; 
        cnt[c[i]] ++ ; 
        mx = max(mx , c[i]) ; 
    }

    if ( mx < 2 ) { cout << n << endl ; return ; }
    for ( int i = 1 ; i <= mx ; i ++ ) {
        pre[i] = pre[i - 1] + cnt[i] ;
    }

    int ans = LLONG_MIN ; 
    for ( int x = 2 ; x <= mx ; x ++ ) {
        int cost = 0 , lim = (mx + x - 1) / x ; 
        for ( int i = 1 ; i <= lim ; i ++ ) {
            int l = (i - 1) * x + 1 , r = min(mx , i * x) ;
            int c = pre[r] - pre[l - 1] ;
            cost += i * c ; 
            cost -= y * max(0LL , c - cnt[i]) ;  
        } 
        ans = max(ans , cost) ; 
    }

    cout << ans << endl ; 

}

/*

就是这个除法他是有规律的 , 统一向上取整或者向下去整

原来的正向思路是 , 循环当前这个列表计算单亲该你这个值会映射到原数组哪个值
然后计算次数

反向这来 , 我们枚举变化后的值可能是多少 , 这个值可以由一定范围的数字变化而来
我们知道这些数字的个数之后就可以计算这个数在原数组出现过多少次 , 免费出多少次
还有就是知道这么多个数最后都会变成这个数 , 最后胡

最最最重要的是 , 这个每个数覆盖的区域是互不干扰的 这个是最重要的

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

/*

// cost = max(cost , sum - (n - cnt) * y) ; 

// 统计的是当前 x 下面转换前后数组有多少对相同的值
// int cnt = 0 , sum = 0 ;
// auto nc = c ; auto uump = ump ; 
// for ( int i = 1 ; i <= n ; i ++ ) {
//     nc[i] = (c[i] + x - 1) / x ; 
//     sum += nc[i] ; 
// } 

// for ( int i = n ; i <= n ; i ++ ) if ( uump[nc[i]] ) {
//     cnt ++ ; uump[nc[i]] -- ;
// }

// // if cnt the same , the greater ans is better
// int cost = sum - (n - cnt) * y ;
// if (mx < cost) {
//     mx = cost ; ans = x ;
// }

find x that ary_c / x -> ary nc have max same pairs
n = 2e5 

the transformed val is rouneded up 
so it mayebe cant predict 

at the same time you need to constider the cost and the income 

i'll first try a brutal 

*/


