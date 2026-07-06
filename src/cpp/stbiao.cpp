// ST
int n , q ; cin >> n >> q ;    
vector<int> arr(n + 1) ; 
for ( int i = 1 ; i <= n ; i ++ ) {
    cin >> arr[i] ; 
}

int exp = __lg(n) ; 
vector<vector<int>> st( exp + 1 , vector<int>( n + 1)) ; 
for ( int i = 1 ; i <= n ; i ++ ) {
    st[0][i] = arr[i] ; 
}

for ( int i = 1 ; i <= exp ; i ++ ) {
    for ( int j = 1 ; j + (1 << i) - 1 <= n ; j ++ ) {
        st[i][j] = max( st[i - 1][j] , st[i - 1][j + (1 << (i - 1))] ) ;  
    }
}

while ( q -- ) {
    int l , r ; cin >> l >> r ; 
    int exp = __lg( r - l + 1 ) ;  
    ans = min( st[exp][l + (1 << exp) - 1] , st[exp][r - (1 << exp) + 1] ) ; 
    cout << ans << endl ; 
} 


#include <bits/stdc++.h>
using namespace std;

// mx[k][i][j]：以(i,j)为左上角，边长为2^k的正方形的最大值
// mn[k][i][j]：以(i,j)为左上角，边长为2^k的正方形的最小值
int a, b, n, mx[11][1001][1001], mn[11][1001][1001];

int main() {
    cin >> a >> b >> n ;
    // 初始化：k=0时，边长为1，最大值和最小值就是元素本身
    for ( int i = 1 ; i <= a ; i ++ ) {
        for ( int j = 1 ; j <= b ; j ++ ) {
            cin >> mx[0][i][j] ;
            mn[0][i][j] = mx[0][i][j] ;
        }
    }

    // 预处理二维 ST 表
    // k表示正方形边长为2^k，范围是1到log2(n)
    for (int k = 1; k < log2(n) + 1; k++) {
        for (int i = 1; i + (1 << (k - 1)) <= a; i++) {
            for (int j = 1; j + (1 << (k - 1)) <= b; j++) {
                // 四个子正方形的最大值取max
                mx[k][i][j] = max({
                    mx[k-1][i][j],
                    mx[k-1][i + (1 << (k - 1))][j],
                    mx[k-1][i][j + (1 << (k - 1))],
                    mx[k-1][i + (1 << (k - 1))][j + (1 << (k - 1))]
                });
                // 四个子正方形的最小值取min
                mn[k][i][j] = min({
                    mn[k-1][i][j],
                    mn[k-1][i + (1 << (k - 1))][j],
                    mn[k-1][i][j + (1 << (k - 1))],
                    mn[k-1][i + (1 << (k - 1))][j + (1 << (k - 1))]
                });
            }
        }
    }

    // 计算查询时使用的k值
    int t = int(log2(n));
    int ans = 1e9;
    // 遍历所有可能的n×n正方形
    for (int i = 1; i + n - 1 <= a; i++) {
        for (int j = 1; j + n - 1 <= b; j++) {
            // 用四个2^t×2^t的正方形覆盖当前n×n正方形
            int u = max({
                mx[t][i][j],
                mx[t][i][j + n - (1 << t)],
                mx[t][i + n - (1 << t)][j],
                mx[t][i + n - (1 << t)][j + n - (1 << t)]
            });
            int v = min({
                mn[t][i][j],
                mn[t][i][j + n - (1 << t)],
                mn[t][i + n - (1 << t)][j],
                mn[t][i + n - (1 << t)][j + n - (1 << t)]
            });
            ans = min(ans, u - v);
        }
    }

    cout << ans;
    return 0;
}

class FenwickTree {
private :
    vector<int> tree ; 
    int n ; 
public : 
    FenwickTree(int size) : n(size) , tree.resize(size + 1, 0);  

    int lowbit( int i ) return i & -i ; 

    void update( int pos , int val ) {  
        for ( int i = pos ; i <= n ; i += lowbit(i) ) {
            tree[i] += val ; 
        }
    }   

    int query( int pos ) {
        int res = 0 ; 
        for ( int i = pos ; i > 0 ; i -= lowbit(i) ) {
            res += tree[i] ; 
        }
        return res ; 
    }

} ; 