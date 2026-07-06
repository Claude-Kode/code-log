// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

/*
最大的数和第二大的数一定在最终答案里面

我的想法是找一个依托点或者分界点 然后转化成统计某个区间的最大

我可以这样 , 我统计以当前数字为右端点的最大子段和 , 
统计以当前数字为左端点的最大字段和 然后求加合

*/

void solve() {

    int n ; cin >> n ;
    vector<int> arr( n + 1 ) ; 

    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }

    vector<int> l( n + 1 , 0 ) , r( n + 2 , 0 ) ; 

    int pre = arr[1] ; int mnl = min(arr[0] , arr[1]) ; 
    l[1] = arr[1] ; 
    for ( int i = 2 ; i <= n ; i ++ ) {
        pre += arr[i] ; 
        l[i] = max(l[i - 1] , pre - mnl) ; 
        mnl = min( mnl , pre ) ; 
    }

    r[n] = arr[n] ; 
    int suff = arr[n] ; int mnr = min(arr[0] , arr[n]) ; 
    for ( int i = n - 1 ; i > 0 ; i -- ) {
        suff += arr[i] ; 
        r[i] = max(r[i + 1] , suff - mnr) ; 
        mnr = min( mnr , suff ) ;  
    }

    // // 怎么保非空 应该是边界初始化 INT_MIN 
    // for ( int i = 1 ; i <= n ; i ++ ) cout << l[i] << ' ' ;
    // cout << endl ;
    // for ( int i = 1 ; i <= n ; i ++ ) cout << r[i] << ' ' ;
    // cout << endl ; 

    int ans = INT_MIN ; 
    for ( int i = 1 ; i < n - 1 ; i ++ ) {
        int res = l[i] + r[i + 1] ; 
        ans = max( ans , res ) ;
    }

    cout << ans << endl ; 

}

signed main() {


    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

