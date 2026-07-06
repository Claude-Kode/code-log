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
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }


}

/*
单调栈 找到第一个大于等于他的结果加等于下标之差
当前柱子作为底 , 能盛多少水
答案是 min(l_higher , r_higher) * (r_higher_index - l_higher_index)
即可
*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    int n ; cin >> n ; 
    vector<int> arr(n + 1) ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ; 

    vector<int>  l( n + 1 ) , r( n + 1 ) ; 
    l[1] = arr[1] ; r[n] = arr[n] ; 
    for ( int i = 2 ;  i <= n ; i ++ ) l[i] = max( arr[i] , l[i - 1] ) ; 
    for ( int i = n - 1 ;  i > 0 ; i -- ) r[i] = max( arr[i] , r[i + 1] ) ; 

    int ans = 0 ; 
    for ( int i = 1; i <= n ; i++ ) {
        if ( l[i] && r[i] ) {
            ans += min( l[i] , r[i] ) - arr[i] ;
        } 
    }
    
    cout << ans << endl ;

    return 0 ; 
}   

/*
这个是每个柱子的贡献是多少
*/

// 我这个算法相当于是枚举柱子 , 当前柱子作为这一段的底能搞多少水

// 单调栈写法是吧当前算作右边界的话 , 能存多少水
// 这个单调栈写法可以分解着看
// 对于一个坑来说 , 我们按照坑的右边的递增的高度分开统计 
// 实际上是统计 这一段 2 的高度能往左边跑多少
// 这个写法真的好牛逼
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int> height(n);
//     for (int i = 0; i < n; i++)
//         cin >> height[i];

//     stack<int> st;  // 存储下标，保持高度递减
//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         // 当当前柱子比栈顶高时，说明可能形成积水
//         while (!st.empty() && height[i] > height[st.top()]) {
//             int bottom_idx = st.top();  // 凹槽底部
//             st.pop();
//             // 如果栈空了，说明没有左边界，不能积水
//             if (st.empty()) break;
            
//             int left_idx = st.top();    // 左边界
//             int right_idx = i;          // 右边界
            
//             // 积水高度 = 左右边界较小值 - 底部高度
//             int h = min(height[left_idx], height[right_idx]) - height[bottom_idx];
//             // 积水宽度 = 右边界 - 左边界 - 1
//             int w = right_idx - left_idx - 1;
             
//             ans += h * w;
//         }
//         st.push(i);  // 将当前柱子入栈
//     }
    
//     cout << ans << endl;
//     return 0;
// }