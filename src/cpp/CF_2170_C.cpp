#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'

void solve() {
    int n , k ; cin >> n >> k ; 
    vector<int> q( n ) , r( n ) ; 
    for ( auto &a : q ) cin >> a ; sort ( q.begin() , q.end() ) ;
    for ( auto &a : r ) cin >> a ; sort ( r.begin() , r.end() ) ;
    // 这道题题解用的是 二分 和 排序 
    // 但是为什么我的双指针不对呢 直接双层循环试试看
    // 而且答案是在一个区间内部进行直接配对的
    // 一个区间内部的 r 的最大值和 q 的最小值进行配对有一个配对不成功就不行
    // 这个是为什么呢 按贪心来说 q 应该是找最大的 r 进行配对啊
    int res = 0 , rp = n - 1 ;
    for ( int i = 0 ; i < n && rp > -1; i ++ ) {
        while ( rp >= 0 ) {
            if ( q[i] * ( r[rp] + 1 ) + r[rp] <= k ){ res ++ ; rp -- ; break ; }
            rp -- ;
        }    
    }
    cout << res << endl ;
}
// 这道题明明一开始思路其实就是对的
signed main() {
    int tt ; cin >> tt ; 
    while ( tt -- ) solve() ; 
    return 0 ; 
}

