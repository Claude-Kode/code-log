// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 998'244'353 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n ; cin >> n ; 
    vector<int> a(n) , b(n) ; 
    for ( auto &x : a ) cin >> x ; 
    for ( auto &x : b ) cin >> x ; 
    
    // 我担心的是牵一发而动全身 假如说我满足了这个唯一的递减 
    // 有可能我前面本来是递增的部分被破坏了
    // 但是这道题说保证又接了 所以我们不妨猜测一下这中医往往都是可以有最小链节处理的
    // 你并不需要去可考虑全局

    // 实际上是不是保证 我让一个数组尽可能的小的话 那么他是一定可以保证是非递减的
    // 这一点可以从阳历之中看出来
    for ( int i = 0 ; i < n ; i ++ ) if ( a[i] > b[i] ) {
         swap( a[i] , b[i] ) ; 
        // 如果这个位置可以交换可以不叫唤 那么这个地方就应该说是乘以 2 
        // 显然 如果 a[i]如果 < b[i] 那么这个地方是不能交换的
        // 如果说一个位置他换不换都不用影响结果 那么这个地方属于一个子集型
    } 

    // 这里的 ans 设置成初始值是  2 的原因是 , 我认为的规定 a 按位较小值
    // 对称的 , 如果把 b 设置成按位较小值 , 他的方法设计数是等价于 a 的
    // 其实对方法数量起改变的下标是不变的
    // 但是在一开始处理的时候的下标是完全不同的
    int ans = 2 ; 
    for ( int i = 1 ; i < n ; i ++ ) if ( a[i] >= b[i - 1] )  {
        (ans <<= 1) %= mod ; 
    } 

    cout << ans << endl ; 

}

/*
看到的第一想法就是计算冲突的点 然后算一下有多少交换可以解决冲突的位置
然后期间可能要用到组合数学

但是这个可能行不通 但是感觉就是差不多 , 每一个点的解决方案(改变当前点可能和前面的点的方案数量)累乘下来
我的思维卡在那里了 , 因为牵一发而动全身 , 交换了一个数之后可能会制造新的冲突 我不会快速的统计

总之总结下来就是 情况没有我想象的那么复杂一个简简单单的便利 + 分治就可以解决这道题目

是不是说这种给你一个数组或者字符串的 , 然后给以你一条规则 , 让你转化成指定的模式
都是可以把一个串改成单一的状态之后再去处理

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