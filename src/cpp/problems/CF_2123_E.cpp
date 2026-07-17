// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

// 正难则反 , 我们从 0 开始添加数字 , 看看 mex 有多少种值的方式
// 只要新添加的数字不是当前的 mex , 那么 mex 值就不变

// 或者就是 1到 n 的滑动窗口有多少种值
// 这种所有的滑动窗口我想到的就是贡献法

// 二十分钟卡住了

/*
新思路 当前的原数组的 mex 要是大于等于 k 那么无论你怎么删除他的 mex 一定是 k 只有一种

只要删除的数种类不是小于等于当前的 mex , mex 就不会改变 

所以要给每个数字计数 , 然后算一下 mex ,
只有从 0 --> mex 每个数字保留一个 剩下都是凑数的就可以了

对这些数字的数量做一个后缀和
假设当前数字是 i , 一共有 n 个数字 
只要 k <= n - i - 1 即可

*/

void solve() {

    int n ; cin >> n ; 

    set<int> mexs ; 
    for ( int i = 0 ; i <= n ; i ++ ) {
        mexs.insert( i ) ;
    }

    vector<int> arr(n + 1) ;
    map<int, int> freq ; 
    for ( int i = 1; i <= n ; i ++ ) {
        cin >> arr[i] ; freq[arr[i]] ++ ; 
        mexs.erase( arr[i] ) ; 
    }

    map<int, vector<int>> invfreq ; 
    for ( auto &[num , feq] : freq ) {
        invfreq[feq].push_back( num ) ; 
    } 

    int init_mex = *mexs.begin() ;
    // cout << init_mex << endl ; 
    set<int> ans ; ans.insert( init_mex ) ; 
    for ( int k = 0 ; k <= n ; k ++ ) {
        ans.erase( n - k + 1 ) ; 
        for ( int num : invfreq[k] ) {
            int lim = min( init_mex , n - k ) ; 
            if ( num <= lim ) ans.insert( num ) ; 
        } 
        cout << ans.size() << (k == n ? endl : ' ' ) ; 
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


// int money = 100 ; 
// while (1) if ( 京爷 ) {
//     money ++ ;
// }
// bool 京爷 = false ; 


