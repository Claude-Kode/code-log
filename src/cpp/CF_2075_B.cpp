// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define MAX *max_element
#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , k ; cin >> n >> k ; 
    vector<int> vec(n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ;   
    }
    
    int ans = 0 ;
    if ( k > 1 ) {
        sort(vec.begin() + 1 , vec.end() , greater<int>()) ; 
        ans = accumulate(vec.begin() + 1 , vec.begin() + k + 2 , 0LL) ; 
    } else {
        int l = MAX(vec.begin() + 1 , vec.end() - 1) ;
        int r = MAX(vec.begin() + 2 , vec.end()) ;
        cout << l << ' ' << r << endl ; 
        ans = max(vec[1] + r , vec[n] + l) ;
    }

    cout << ans << endl ; 

}

/*

1 hour

对于一段红色区域来说 只要他的两侧都有一个蓝色的格子 我就一定能选出这个区间里面最大的格子

其实是不对的 跟选不选两边是没关系啊 只要好似

就是其实是这样的 我原来是这样想的 , 如果前 k 大的数字不包含数组两端的数字
那么我剩下想挑选的那个数字不能做到我直接选到 k + 1 打 但是其实是可以的

如果 k + 1 大不在两端那两段里面 , 可以直接先把两端那两段拿完
然后剩下的就都是 左右两段都有蓝色格子的段了 , 就可以取到指定的格子

如果 k + 1 大在两端那两段里面 , 可以不先选前 k 大 , 
我们只要保证前 k + 1 大的两端被选中 中间的跟上一个策略一样就可以了

也就是说 , 只要我们保证前 k + 1 大的这几个数字的两端被选中 
我们一定可以得到最后的结果就是前 k + 1 大

但是有一个 前提 , 你一开始得取到两端啊 如果 k == 1 的话你只能取一个数
也就不能形成一个闭合的区间

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

