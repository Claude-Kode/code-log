// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

struct infor { int l ; int r ; int p ; } ;

void solve() {

    int n ; cin >> n ; 
    vector<infor> vec(n + 1) ; 
    for ( int i = 1 ;i  <= n ; i ++ )  {
        cin >> vec[i].l >> vec[i].r ; vec[i].p = i ; 
    }

    sort(vec.begin() + 1 , vec.end() , [&](infor a , infor b ){
        if ( a.l != b.l ) return a.l < b.l ;
        else return a.r > b.r ; 
    }) ;

    set<int> s ; stack<int> st ;
    vector<int> ans(n + 1 , 0) ; 
    s.insert(vec[1].r) ; ans[vec[1].p] = 0 ; st.push(1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {

        int p = vec[i].p ;

        while ( !st.empty() && vec[st.top()].r < vec[i].r ) st.pop() ;

        if ( st.empty() ) { 
            ans[p] = 0 ; 
            st.push(i) ; 
            continue ; 
        }

        int lst_l = vec[st.top()].l ; 

        int len = vec[i].r - vec[i].l + 1 ;
        auto it = s.lower_bound(vec[i].r) ;
        
        if ( it == s.end() ) ans[p] = 0 ;
        else ans[p] = *it - lst_l + 1 - len ; 

        if ( i < n && vec[i].l == vec[i + 1].l && vec[i].r == vec[i + 1].r ) ans[p] = 0 ; 

        st.push(i) ; 
        s.insert(vec[i].r) ; 
    }

    for ( int i = 1 ; i <= n ;i  ++ ) cout << ans[i] << endl ;

}

/*

首先是这样的 一个区间要符合两个条件
第一个是 l 要小于等于 , 在这个基础上寻找最大的解 
其次 , 在这个基础上 符合这些条件的组别里面 . r 要符合条件 , 也就是大于等于当前的 r

本质上来说就是好多层的心智套在了一起
我先一用排序来锁定第一个顺序

然后在用单调栈来满足另一个个性质 
最后使用 set 来满足最后一个性质即可
非常用优雅好吧 ovo

这种题目叫做什么二维偏序问题 之类的

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

