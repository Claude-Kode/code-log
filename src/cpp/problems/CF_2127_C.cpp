// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

// A选索引 B来排序
// 每次都选择相同的索引 , 让他改变不了
// 找两个索引 , 让中间两个元素的差最小就可以
// 14min出了正经思路
// 但是不会写代码 18min不出代码

// 答案首先说了 , 这个题 a , b数组的元素是可以所以交换的 , 不会影响答案 , 这一点毋庸置疑
// 我的思路也是对的 , A每次都选择同一个索引 , B最多的增量是中间两个元素的差值
// 就是 a < c < b < d 最好的情况是 B会增加 b - c 这种情况
// 那么怎么找到这种东西呢 , 答案是对 a数组进行排序 

void solve() {

    int n , k; cin >> n >> k ;

    int ans = 0 ; 

    vector<int> a(n + 1) , b(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i] ; 
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> b[i] ; ans += abs(b[i] - a[i]) ;
    }
    
    int mni , mnj , mnv = INT_MAX ; 
    for ( int i = 1 ; i <= n ; i ++ ) {

    }

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


