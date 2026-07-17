/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream> 
#include <utility>
#include <bitset>
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <deque> 
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

// ========================== Namespace ========================================
using namespace std ;
// using namespace ranges ;

// ========================== Macro Definitions ================================
#define TUP tuple<int , int , int>
#define ull unsigned long long
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD1 = 998244353 ; 
const int MOD2 = 1e9 + 7 ; 
const int maxn = 1e9 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , k ;
int ans = 0 ; 

vector<int> tree ; 
// vector<vector<int>> dp ;


// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int lowbit( int i ) {
    return i & -i ;
}

void update( int pos , int deltaVal ) {
    for ( int i = pos ; i <= n ; i += lowbit(i) ){
        tree[i] += deltaVal ;
    }    
}

int query( int val ) {
    int cnt = 0 ; 
    for (int i = val ; i > 0 ; i -= lowbit(i) ) {
        cnt += tree[i] ;
    }  
    return cnt ; 
}


class FenwickTree {
private:
    vector<int> tree;
    int n;
    
public:
    FenwickTree(int size) : n(size) , tree(size , 0) {}

    int lowbit( int i )  { return i & -i ; }

    // val is not delta
    void update( int pos , int val ) {
        for ( int i = pos ; i <= n ; i += lowbit(i) ) {
            tree[i] += val ; 
        }
    }

    int sum( int val ) {
        int res = 0 ; 
        for ( int i = val ; i > 0 ; i -= lowbit(i) ) {
            res = ( res + tree[i] ) % MOD1 ; 
        }
        return res ;
    } 
    
} ;

void solve() {
     


}

// ========================== Idea =============================================
/*

可能这这道题的方式不能是枚举中间了

这里记录更小的是树状数组的 桶 , 之所以设置严格上升是为了
如果有两个相邻相同的值 , 那么他们俩的严格上升序列是多有的都长得是一样的 要不就出bug了

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

    cin >> n >> k ; 
    tree.resize( n + 1 ) ; 
    vector<int> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }
    vector<int> temp( arr ) ; sort( temp.begin() , temp.end() ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) { 
        arr[i] = lower_bound( temp.begin() + 1 , temp.end() , arr[i] ) - temp.begin() ; 
    }

    int ans = 0 ; 
    vector<FenwickTree> trees( k + 1 , FenwickTree(temp.size() + 1)) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        int temp = 0 ; 
        trees[1].update( arr[i] , 1 ) ; 
        for ( int j = 2 ; j <= k ; j ++ ) {
            int Sum = 0 ; 
            Sum = trees[j - 1].sum( arr[i] - 1 ) ; 
            trees[j].update( arr[i] , Sum ) ; 
            if ( j == k ) ans = ( ans + Sum ) % MOD1 ; 
        }
        
    }

    cout << ans << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/




// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 998244353;

// struct BIT {
//     vector<int> tree;
//     int n;
//     BIT(int n) : n(n), tree(n+1, 0) {}
//     void add(int i, int x) {
//         for(; i<=n; i+=i&-i) tree[i] = (tree[i] + x) % MOD;
//     }
//     int sum(int i) {
//         int s = 0;
//         for(; i>0; i-=i&-i) s = (s + tree[i]) % MOD;
//         return s;
//     }
// };

// int main() {
//     int n, K;
//     cin >> n >> K;
//     vector<int> a(n);
//     for(int i=0; i<n; i++) cin >> a[i];
    
//     // 离散化
//     vector<int> vals = a;
//     sort(vals.begin(), vals.end());
//     vals.erase(unique(vals.begin(), vals.end()), vals.end());
//     auto get_id = [&](int x) {
//         return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
//     };
    
//     int m = vals.size();
//     vector<BIT> bits(K+1, BIT(m)); // bits[k] 存储 dp[值][k]
    
//     long long ans = 0;
//     for(int i=0; i<n; i++) {
//         int id = get_id(a[i]); // 离散化后的值
        
//         // k=1 的情况
//         bits[1].add(id, 1);
        
//         // 从 k=2 到 K
//         for(int k=2; k<=K; k++) {
//             int sum = bits[k-1].sum(id-1); // 比 a[i] 小的所有值的 dp 和
//             bits[k].add(id, sum);
//             if(k == K) ans = (ans + sum) % MOD;
//         }
//     }
    
//     cout << ans << endl;
//     return 0;
// }
