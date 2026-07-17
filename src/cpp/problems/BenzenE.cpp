// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

// 每次的异或和只能是越来越大
// 也不一定

// 我想不到阶段性检验怎么做
// 第二个 , 我想不到枚举怎么去做, 不去做剪枝枚举不了
// 任意切割出来的两部分异或和是相等的
// 我想不到按位异或怎么操作

void solve() {

    

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


// int money = 100 ; 
// while (1) if ( 京爷 ) {
//     money ++ ;
// }
// bool 京爷 = false ; 


#include <bits/stdc++.h>
using namespace std;

const int MAXB = 30;

struct LinearBasis {
    int base[MAXB];  // 基向量
    int from[MAXB];  // 这个基向量来自哪个原始下标

    LinearBasis() {
        memset(base, 0, sizeof base);
        memset(from, -1, sizeof from);
    }

    // 尝试插入 x，来源下标 idx
    bool insert(int x, int idx) {
        for (int i = MAXB-1; i >= 0; i--) {
            if (x >> i & 1) {
                if (base[i]) {
                    x ^= base[i];
                } else {
                    base[i] = x;
                    from[i] = idx;
                    return true;
                }
            }
        }
        return false; // x 变成 0 了
    }

    // 判断 x 能否被表示，并返回表示用的下标集合
    pair<bool, vector<int>> represent(int x) {
        vector<int> idxs;
        for (int i = MAXB-1; i >= 0; i--) {
            if (x >> i & 1) {
                if (base[i] == 0) {
                    return {false, {}};
                }
                x ^= base[i];
                idxs.push_back(from[i]);
            }
        }
        return {true, idxs};
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), d(n);
    int xor_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xor_a ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        d[i] = a[i] ^ b[i];
    }

    LinearBasis lb;
    for (int i = 0; i < n; i++) {
        lb.insert(d[i], i);
    }

    auto [ok, idxs] = lb.represent(xor_a);
    if (!ok) {
        cout << -1 << "\n";
        return;
    }

    // 构造 c
    vector<int> c = a;  // 先全选 a
    for (int idx : idxs) {
        c[idx] = b[idx];  // 换成 b
    }

    // 验证（比赛时不需要）
    int check = 0;
    for (int v : c) check ^= v;
    if (check != 0) {
        // 不应该发生
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << c[i] << " \n"[i == n-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}