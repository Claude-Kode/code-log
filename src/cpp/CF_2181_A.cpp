// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

// 十五写完 , 十分钟debug
// 25分钟写了个暴力 , 还 TLE 了
// 我的解法是 n方 , 确实会 tle

// 这道题的正解竟然是个 dp 我真的没有想到 为啥呢
// 其实跟 dp 没啥关系 , 就是预处理出来每个字符串的字符数量

// 我可以预处理三份
// 第一份 原来订单对应的所有字符分别是多少
// 第二份 每个字符串原来的订单是多少
// 第三份 , 非订单, 单单一份字符串总共是多少

void solve() {

    int n , m ; cin >> n >> m ;

    unordered_map<char, int> sum ;
    vector<unordered_map<char, int>> cnt( n ) ; 
    for ( int i = 0 ; i < n ; i ++ ) {
        string temp ; cin >> temp ; 
        for ( auto &c : temp ) {
            cnt[i][c] ++ ; 
            sum[c] ++ ; 
        } 
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        auto have = sum ;
        auto need = sum ;
        for ( auto &[c , _cnt] : cnt[i] ) {
// have[c] = (sum[c] - cnt[i][c]) * m - cnt[i][c] ;
            have[c] -= _cnt; 
            have[c] *= m ; 
            have[c] -= _cnt ;             
        }
        int ans = INT_MAX ; 
        for ( auto &[c , _cnt] : need ) {
            need[c] -= cnt[i][c];
            if (have[c] < 0) {
                ans = -1;
                break;
            }
            if (need[c]) {
                ans = std::min(ans, have[c] / need[c]);
            }

        } 
        cout << ans << ' ' ; 
    }

}

signed main() {
    std :: ios :: sync_with_stdio(false) ; std :: cin.tie(nullptr) ; std :: cout.tie(nullptr) ;
    solve() ; 
    return 0 ; 
}   

// #include <bits/stdc++.h>

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;

// using u128 = unsigned __int128;
// using i128 = __int128;

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
    
//     int n, m;
//     std::cin >> n >> m;
    
//     std::vector<std::array<i64, 26>> cnt(n);
    // std::array<i64, 26> tot {};
//     for (int i = 0; i < n; i++) {
//         std::string s;
//         std::cin >> s;
//         for (auto c : s) {
//             cnt[i][c - 'A']++;
//             tot[c - 'A']++;
//         }
//     }
    
//     for (int i = 0; i < n; i++) {
//         auto have = tot;
//         for (int c = 0; c < 26; c++) {
//             have[c] -= cnt[i][c];
//             have[c] *= m;
//             have[c] -= cnt[i][c];  
//         }
//         auto need = tot;
//         i64 ans = 1E18;
//         for (auto c = 0; c < 26; c++) {
//             need[c] -= cnt[i][c];
//             if (have[c] < 0) {
//                 ans = -1;
//                 break;
//             }
//             if (need[c]) {
//                 ans = std::min(ans, have[c] / need[c]);
//             }
//         }
//         std::cout << ans << " \n"[i == n - 1];
//     }
    
//     return 0;
// }
