// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

void solve() {

    int n , k ; cin >> n >> k ; 
    vector<int> vec(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> vec[i] ;  
    }

    auto temp = vec ; sort(temp.begin() , temp.end()) ; 
    // temp.erase(unique(temp.begin() , temp.end()), temp.end()) ; 
    
    int th = INT_MAX ; 
    if ( (temp.size() - 1) >= k ) th = min(th , temp[k] ) ;

    // cout << "TH " << th << endl ; 

    vector<int> ans ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( vec[i] <= th ) {
            ans.push_back( vec[i] ) ; 
            // cout << vec[i] << ' ' ; 
        }
    }

    // cout << endl ; 

    int l = 0 , r = ans.size() - 1 , cnt = ans.size() - (k - 1) ; 
    // cout << "CNT: " << cnt << endl ; 
    while ( l <= r ) {
        if ( ans[l] == ans[r] ) {
            l ++ , r -- ; 
        } else {
            if ( ans[r] == th && cnt > 0 ) r -- , cnt -- ; 
            else if ( ans[l] == th && cnt > 0 ) l ++ , cnt -- ; 
            else { cout << "NO" << endl ; return ; }
        }
    } 

    cout << "YES" << endl ; 

}

/*

    第一想法就是答案长成什么样子
    回文串 我给答题分了两种情况 
    第一种就是普通的回文串 , 在一半的子串中有不同的元素 
    第二种就是整个会汶川都是单一的字符

    第二有了这两种的大概的样子我就能知道这个回文串长成什么样子
    我就知道我应该删除什么元素 
    然后我再 On验证这个元素能不能被搞在一个数组中成为 第 k 打元素被删掉

    同时还有一个新问题 , 删除的操作之间是否存在顺序女问题 , 即元素 a 和 b 应该被删掉 , 
    在删除 a 后 , b 找不到子数组使其成为第 k 大元素

    还有这个区间的选择 , 需要当前的元素至少是有 k 个不同元素

    但这些是具体的操作执行过程 , 我只需要关心操作能不能执行

    // 问题
    怎么找出最后的数组的样子
    有多种回文串的样式可以选我应该怎么选
    删除操作直接遍历需要删除的操作就可以吗 , 还是需要从小到大删除 , 删掉元素会不会影响删不掉别的元素 ? 
    怎么验证 ? 

    // 二级结论
    能删掉的数字长什么样子 ? : 整个数组中小于第 k 小的数字永远不能被删掉

    // 终极结论
    只要当前数字是大于第 k - 1 大的数字 , 那么他一定可以被随意抹除 
    其实可以想象 , l 和 r 的操作就是想做向右扩张区间 , 只要区间扩张到小于当前数字的数字有 k - 1 个的时候就可以直接删掉当前元素
    这个区间最大是整个数组 , 也就是说极限能删除最小的数字是整个原数组汇总第 k 大的数字

    新的问题来了 , 我能确定那些元素是可以被删除的 , 那么我怎么能确定最后的回文长什么样子呢

    答案的策略是 对于大于第 k 大的数字全部删掉 
    确实是可以的 , 如果选择性删掉  > k大 的数字后还是回文 , 那么删掉此时回文中 > k 大的数字依旧还是回文数字

    对于 < k 大的数字无法参与 那么此时只能剩下一种可以删除的数字了 
    也就是正好等于第 k 大的数字

    通过选择删除 第 k 大的数字看能不能得到回文就可以了

    不对应该全删了吧 感觉是

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



