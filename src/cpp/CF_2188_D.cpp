// // 首先可以证明的是直接取反对齐不是最优解
// // 首先 , 对齐之后只能确保位数和 y 相同 , 
// // 如果相同位数下 , y 的后面全是 0 
// // 比如 x == 101010101010 , y = 100000
// // ~x == 010101010101 , 对齐 y 之后是 010101 , 显然 , 对于绝对值运算来说
// // q == y 是最优解
// // 首先我觉得贪心的策略 , 直接让 p == x 是一种很好的选择
// // 剩下我们只要让 p 和 q 通过加减然后 &= 0 即可

// // 这道题可以直接变成 , 通过最少加减次数使得两个数 &= 0
// // 也就是说 x 和 y 本身是存在一些冲突的位置的 , 
// // 就是 x 和 y 有一些的位置都有 1  , 我们要把它解决掉就可以
// // 如果某一位是 1 , 想要把他变成 0 的话 , 我可以通过加法让他进位
// // 或者通过减法让他消去
// // 我的第一个问题 加减法之后 , 这个位置的左右邻居的数字肯定会改变 , 产生新的冲突怎么办

// // @Author : GoryK 
// // @Description : TEMPLATE-2 
// #include <bits/stdc++.h>

// using i64 = long long;

// void solve() {
//     i64 x, y;
//     std::cin >> x >> y;
//     i64 min = 1e18, p, q;
//     auto upd = [&](i64 _p, i64 _q) -> void {
//         if ((_p & _q) == 0 && abs(_p - x) + abs(_q - y) < min) {
//             min = abs(_p - x) + abs(_q - y);
//             p = _p;
//             q = _q;
//         }  
//     };
//     upd(x, y);


//     // 核心思想是
//     // 1. 按位解决都是 1 的冲突
//     // 2. 我要保证处理完这一位之后不能有新的冲突产生 , 不能有跟大噶的冲突产生
//     // 3. 不好判断我就枚举所有解决冲突的手段即可

//     // 左移右移就是下标
//     for (int i = 29; i >= 0; i--) {
//         // 直接 &= 后的结果 , 是 1 的就是 x 和 y 的冲突位置
//         // x 和 y 在bitset 中 i 索引的位置都是 1 
//         if ((x & y) >> i & 1) {
//             // x 和 y 的第 i 位都是 1

//             // 对于 x 和 y 的冲突位置 , 尝试把其中一个变 1 , 另一个不变
//             // 然后 1 变 0 的方式是加法或者减法 
//             // 但是要让指定的位数变成 0 , 怎么办呢
//             // 很简单 1000 + 1000 = 10000 , 把这个后面清空加上 lowbit 即可
//             // 减法只要保证 1后面都是 0 , 然后 - 1 就会连锁反应退位
//             // 1000 - 1 == 0111

//             // p = x从第i位和后面全部清空 , 然后 第i位变成 0 , 上面进位 , y 不变试试
//             upd((x >> i << i) + (1LL << i), y);
//             // q = y , 把 q 的第  i 位 后面全部清空 然后 i 变成 0 , 向上进位试试
//             upd(x, (y >> i << i) + (1LL << i));
//             // 同理清空 , 但是 1 -> 0 的方式是减 , 然后向下退位
//             upd(x >> i << i, (y >> i << i) - 1);
//             // 同理清空 , 但是 1 -> 0 的方式是减 , 然后向下退位
//             upd((x >> i << i) - 1, y >> i << i);
//         }
//     }
//     std::cout << p << " " << q << "\n";
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);

//     int t;
//     std::cin >> t;
//     while (t--) {
//         solve();
//     }
// }


// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 



void solve() {

    int x , y ; cin >> x >> y ;
    int target = (x & y) ; 

    if ( !target ) { cout << x << ' ' << y << endl ; return ; }

    int p = x , q = y , min = INT_MAX ;
    auto update = [&]( int a , int b ) -> void {
        if ( (a & b) == 0 && abs(a - x) + abs(b - y) < min ) {
            p = a ; 
            q = b ; 
            min = abs(a - x) + abs(b - y) ; 
        }
    } ; 

    for ( int i = 31 ; i >= 0 ; i -- ) {
        if (target >> i & 1) {

            update( (x >> i << i) + (1 << i) , y ) ; 
            update( x , (y >> i << i) + (1 << i) ) ;
            update( (x >> i << i) - 1 , y >> i << i) ; 
            update( x >> i << i , (y >> i << i) - 1) ;

        }
    }

    cout << p << ' ' << q << endl ; 

}

int main() {


    std :: ios :: sync_with_stdio(false) ; std :: cin.tie(nullptr) ; std :: cout.tie(nullptr) ;

    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
    
*/