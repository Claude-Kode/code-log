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
    vector<int> arr( n + 1 ) ; 
    int mx = INT_MIN , mn = INT_MAX ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ;
        mn = min( mn , arr[i] ) ;
        mx = max( mx , arr[i] ) ; 
    }

    if ( is_sorted( arr.begin() + 1 , arr.end() ) ) {
        cout << -1 << endl ; 
        return ; 
    }

    vector<int> temp = arr ; 
    sort( temp.begin() + 1 , temp.end() ) ; 

    int ans = INT_MAX ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( temp[i] == arr[i] ) continue ; 
        ans = min( ans , max(arr[i] - mn , mx - arr[i]) ) ;
    } 

    cout << ans << endl ; 

}

signed main() {


    std :: ios :: sync_with_stdio(false) ; std :: cin.tie(nullptr) ; std :: cout.tie(nullptr) ;

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
这道题的基本原理我是明白的
唯一就在收缩范围上面 我漏掉了一个不考虑的因素 , 还有实现方式我写的也不是很好

我本来的实现方式是 从最大最小的中值向外寻找找到第一个最接近的即可

但是有的数字是无效的 , 可以忽略的 是什么呢 
两个数字交换以后 , 其他的数字的相对位置不会发生任何改变 , 
也就是一个数字只要不交换 , 就可以一直保持在原位 , 就是这样 这是第一个结论
第二个结论是 , 如果一个数可以和其他的数随意交换 , 那么他可以把所以交换的数直接拍成有序的

第三个 排完之后的最小值应当是在最右端 , 最大值应当在最左端 , 这样可以完成有效的最后一次交换
但是这个结论没什么用

这道题有一个 trick 是 , arr[i] == sorted_arr[i] 的时候 , 
证明 arr[i] 这个元素拍完序之后仍然处在相同的位置 , 也就是他的本身的位置就是有序的

还有一个 trick

ans = min( ans , max(arr[i] - mn , mx - arr[i]) ) ;

这段代码的意义是在寻找某个点 , 这个点是该数组中最接近 (mn + mx) / 2 的数字
这段代码求的是这个点和最大值最小值距离的中的最小值 , 然后用 n 减去

再来梳理一遍 , 这个题是在找 [mn + k , mx] 和 [mn , mx - k]能覆盖数组所有为排序元素的最大 k
其中 k 越大范围越小 
即让这个区间的大小达到的最小值 , 也就是 另一个区间 [mn , mn + k] 达到最大值 

这道题有个单调性 , k 越小越能交换 , 所以对每个元素来说 , k 都有个下限
如果我的 k 地狱了某个元素的下限 , 就无法达到完整覆盖的目的 , 所以 ans 要取 min

那么这一个 max(arr[i] - mn , mx - arr[i]) , 就是枚举 , 如果当前元素被覆盖的最小 k 是多少
对于 大于中值的元素来说 , 他应该被最小元素排序 , 所以 k 是距离 mn 的同理可证小于 中值的元素应该被 mx 排序
所以取最大就是 k

*/