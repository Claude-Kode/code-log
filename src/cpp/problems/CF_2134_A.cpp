// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , a , b ; cin >> n >> a >> b ; 

    if ( a < b ) {
        if ( (n & 1) == (b & 1) ) cout << "YES" << endl ; 
        else cout << "NO" << endl ; 
    } else {
        if ( (n & 1) == (a & 1) && (n & 1) == (b & 1) ) cout << "YES" << endl ; 
        else cout << "NO" << endl ; 
    }

}

/*
n 减去着色的面积一定是一个偶数
蓝色具有优先级 所以优先图红色
问题是 红色怎么涂 涂多少 从哪里开始涂

我一开始的思路还是从填充策略的思路来思考的

其实是这样的 显然蓝色填充是更牛逼的 

当红色的更少的时候可以直接覆盖 这个时候遵循 剩下的格子数量一定是偶数的原则就可以了

其次的是 当红色的大于等于蓝色的时候 这个时候涂了之后可以保证 最后一定有红色的格子
其实样例给了我们启发 , 我们只要把蓝色的格子红色中间的位置填充  

我不知道咋想的一直想的是左边是红色右边是蓝色这样的是对称的
我tm在想啥我操了...

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
