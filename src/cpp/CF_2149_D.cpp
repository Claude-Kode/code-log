// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

// 读题问题奥
// 第一个问题 能不能想到以谁为锚点
// 第二个 能不能想到这个锚点是中位数
// 第三个 对于某个元素 , 他的冒泡排序次数是中间需要交换的次数也就是他到下一个a的旁边有多少个 b
// 第四个 对于 a 或者 b 为什么都要算一遍然后取最小的

// 分块怎spj呢
// 第一步 判断最后的答案应该是张恒什么样子的
// 第二步 琢磨怎么转化
// 以某个字符为中心 , 统计他周围的相同的字符的逆序对
// 这题只支持 nlogn 做法

void solve() {

    int n ; cin >> n ;
    string str ; cin >> str ; 

    int cnt_a = 0 , cnt_b = 0 ; 
    for ( auto &c : str ) {
        cnt_a += c == 'a' ; 
        cnt_b += c == 'b' ; 
    }

    if ( !cnt_a || !cnt_b ) {
        cout << 0 << endl ; 
        return ; 
    }

    // baababababbbbb


    // 那个交换次数就是如果是连续一块的 字符他们的交换字符数数量都是跟第一个相同
    // 如果是不相连的部分 , 他们的交换次数等于前面的联通块的次数加上他俩之间的 另一种字符的数量
    // 就是到他为止非他的字符的数量即可

    // 第一个是确定一个目标点
    // 第二个这个确定了以后 , 这个字符换到目标点的次数总是能限行计算出来的
    // 排序这种专题貌似总是考冒泡排序

    // 正常这个题是考察中位数的计算 但是在这里可以得到的是 如果数据的个数是偶数个
    // 那么不需要取两个中位数的平均数  结果也是相等的
    // 左边是 n 个 , 右边是 n 个 , 两个中位数之间的差距是 k , 很容易自己证明出来是相等的
    int tara = (cnt_a + 1) / 2 ; 
    int tarb = (cnt_b + 1) / 2 ;

    int ans = 0 ; 

    int ansa = 0 , ansb = 0 ; 

    int pos = -1 , cnt = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        if (str[i] == 'a' ) cnt ++ , pos = i ;
        if ( cnt == tara ) break ; 
    }

    int temp = 0 ; 
    for ( int i = pos ; i >= 0 ; i -- ) {
        temp += str[i] == 'b' ; 
        if (str[i] == 'a') ans += temp ;
    }

    temp = 0 ; 
    for ( int i = pos ; i < n ; i ++ ) {
        temp += str[i] == 'b' ; 
        if (str[i] == 'a') ans += temp ;  
    }

    ansa = ans ; ans = 0 ; 


    pos = -1 , cnt = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        if (str[i] == 'b' ) cnt ++ , pos = i ;
        if ( cnt == tarb ) break ; 
    }

    temp = 0 ; 
    for ( int i = pos ; i >= 0 ; i -- ) {
        temp += str[i] == 'a' ; 
        if (str[i] == 'b') ans += temp ;
    }

    temp = 0 ; 
    for ( int i = pos ; i < n ; i ++ ) {
        temp += str[i] == 'a' ; 
        if (str[i] == 'b') ans += temp ;  
    }    

    ansb = ans ; 

    cout << min(ansa , ansb) << endl ; 

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
 