// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

int __lg10(int x) {
    int cnt = 0 ; 
    while ( x ) cnt ++ , x /= 10 ;
    return cnt ;     
}

void solve() {

    int n ; cin >> n ; 
    vector<int> a(n + 1) , b(n + 1) ;
    priority_queue<int> pqa ; 
    priority_queue<int> pqb ;  
    for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i] , pqa.push(a[i]) ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> b[i] , pqb.push(b[i]) ;  

 

}

/*
首先我们来思考一种策略 
其实这道题就很像一个压缩的这么一个东西 , 就是可以把一定范围的数字都变成相同的
我们先贪心的想 , 就是把一开始就相同的数字先排除 , 然后处理那部分不需要处理的数字就可以

这个题就是很有意思 

其实简单来说他的思路就是 把大的变小
首先是直接把一开始就相等的数字去掉 , 那么剩下的都是两两不相同的数组

然后直接把 a 和 b 数组里面所有的数都压缩 , 然后再去掉相等的 再把不等的压缩
因为压缩的终点都是 1  , 所以压缩到最后一定能相等 , 这是一个很朴素的思路

我想明白了 , 这道题为什么不能用小根堆
实际上是这样的 当我弹出一个元素 , 他和当前元素不匹配之后 应该会变化一下 , 然后和当前元素或者其他元素进行匹配
如果是最小堆的话  变化的方向只能是变小 , 
入堆之后弹出的还是这个元素 , 也就是说 , 我在按照原数组排序的顺序后对两组元素相对应的位置的元素进行强制配对

但是如果是最大堆的话 , 一个元素变化了之后可能插到各个位置 

我这有一个思路很自然
对于一个在当前状态下 , 没有配对的数字来说

1. 他减小 , 然后找别人配对
2. 另一个数组中的别人减小找他配对

所以策略很简单了 , 我们每次取出不配对集合中各一个数
更大的那个只有一个选项 , 变小 , 然后找别人 
第二小的可以等等 , 先等别人变小找他配对 , 逼得不行了 , 自己都成最大的了 ,再变小找别人配对

这是对于每个数来说的单独处理方案那种的 可以作为一种考虑的方向

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