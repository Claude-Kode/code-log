// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int n ; cin >> n ;
    string str ; cin >> str ; 
    int ans = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( str[i] == '1' ) {
            ans ++ ; 
            if ( i - 1 >= 0 ) str[i - 1] = '2' ; 
            if ( i + 1 < n ) str[i + 1] = '2' ; 
        }
    }

    // cout << str << endl ; 

    int cnt = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        cnt += str[i] == '0' ; 
        if ( str[i] != '0' ) {
            // cout << cnt << ' ' ; 
            ans += (cnt + 2) / 3 ; 
            cnt = 0 ; 
        }
    }

    // cout << endl ; 

    if ( cnt ) ans += (cnt + 2) / 3 ; 

    // if ( ans == 0 ) ans = (n + 2) / 3 ; 

    cout << ans << endl ; 

}

signed main() {


    std :: ios :: sync_with_stdio(false) ; std :: cin.tie(nullptr) ; std :: cout.tie(nullptr) ;

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
第一 这题没读好题 , 我不知道原来的人也算 导致分析错误 这是第一个原因
第二 这题没读好题 我没看到禁止相邻的人禁止就坐
第三 这题的实现方式没搞好 就是一个人可以占三个位置
所以最少爹人数就是一段 0 中没有被占据的位置 , 除以三向上取整 , 
但是如何求没有被占的 0 的位置呢 , 
10001 的有效 0 的位置其实是 12021 中间的 0 
这里可以用另一个数字进行标记 这个 trick 我没有想到
*/