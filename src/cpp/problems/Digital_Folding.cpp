// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    string L , R ; cin >> L >> R ; 

    if ( L == R ) {
        while (R.back() == '0') R.pop_back() ; 
        reverse( R.begin() , R.end() ) ; 
        cout << R << endl ; 
        return ; 
    }

    int n = R.size() ; 
    L = to_string( max(stoll(L), (int)pow(10, n - 1)) ) ;

    int cnt1 = count(R.begin() , R.end() , '1') , 
        cnt0 = count(R.begin() , R.end() , '0') ;
    
    if ( cnt1 == 1 && cnt0 == n - cnt1 ) {
        string ans(n - 1, '9') ; 
        cout << ans << endl ;
        return ; 
    }

    string ans ; 
    int l = stoll(L) , r = stoll(R) , flag = -1 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( L[i] != R[i] ) { flag = i ; break ; }
    }

    bool minus = false ; 
    for ( int i = flag + 1 ; i < n ; i ++ ) {
        ans += '9' ; 
        if ( R[i] != '9' ) { minus = true ; }
    }

    if ( minus ) {
        ans += R[flag] - 1 ;
    } else {
        ans += R[flag] ;
    }

    for ( int i = flag - 1 ; i >= 0 ; i -- ) {
        ans += R[i] ;
    }

    cout << ans << endl ;

}

/*

这题那道题只能想到一个思路 , 就是按位贪了 , 每一位选择能选的最大的 但是不知道咋写了卧槽了

这道题是这样的 首先可以证明 L 的位数是 <= R的位数 的
而且 , 要让翻转数最大 , 那么反转前的数字一定是和 R 的位数相同的 
所以 L 的位数如果 <= R 的位数直接把 L 等价于 1 ^ (R的位数) 即可

接下来就是按位贪心 , 从后到前每一位尽可能的取 9 
若中间有任何一位不能取 9 的话就取一个别的数 , 让后面的数都能够取 9 

// 为啥这个贪心策略是从后向前找到 L 和 R 第一个不一样的后面全是 9 就行 wtf 

哦哦其实确实是这样 我一开始想的是 , 从高位开始 , 如果一样确实是跳过 , 
然后不一样了就 - 1 , 剩下全是 9 , 确实是这样我想的差不多了

这题我一开始会担心有进位的问题 , 也就是单独处理那个 -1的时候如果 R flag 是 0 怎么办
首先 L 一定是 < R , 所以在前方全部等于的情况下 , 每一位的 L 都 <= R (因为检测到不一样就会break)
还能有啥比 0 小呢 不可能了 , 所以保证 L <= R , L这一位必须等于 0 , 因此不用考虑进位问题

还有两个问题 , 第一个是 L = to_string( max(stoll(L), (int)pow(10, n - 1)) ) ;
要去最大值要不会出问题

第二个 一开始 L和 R 相等应该直接输出反转的 R 

但是变换 L 之后和 R 相等应该输出 R - 1 了就是

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

