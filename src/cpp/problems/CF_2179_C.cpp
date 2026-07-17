// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

// 没看出单调性不能用二分
// 然后坑你是有一个最小值的界限就是数组本身的最小值
// 答案一定大于等于最小值
// 那么答案有没有上线呢
// 可以确定的是结果一定是最小值

// 20 min 解决
// 中间还是想错了 , 是至少 , 模 k 就可以

int gcd ( int a , int b ) { return b == 0 ? a : gcd(b , a % b) ; }

void solve() {

    int n ; cin >> n ; 
    vector<int> arr( n + 1)  ;

    int mn = INT_MAX ;
    for ( int i = 1; i <= n ; i ++ ) {
        cin >> arr[i] ; 
        mn = min( mn , arr[i] ) ; 
    }

    // 最后的结果是所有数组的元素都等于最小值
    for ( int i = 1; i <= n ; i ++ ) {
        arr[i] -= mn ; 
    }

    sort( arr.begin() , arr.end() ) ;

    // for ( int i = 1 ; i <= n ; i ++ ) cout << arr[i] << ' ' ;
    // cout << endl ; 

    int ans = INT_MAX ; 
    for ( int i = 1; i <= n ;i  ++ ) {
        if ( arr[i] == 0 ) continue ; 
        ans = min( ans , arr[i] ) ; 
    }

    cout << max( mn , ans ) << endl ; 

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


// int money = 100 ; 
// while (1) if ( 京爷 ) {
//     money ++ ;
// }
// bool jingye = false ; 