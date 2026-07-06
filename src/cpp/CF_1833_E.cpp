
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long int;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<set<int>> g(n);
    vector<set<int>> neighbours(n);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        g[i].insert(a[i]);
        g[a[i]].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        d[i] = g[i].size();
    }
    int bamboos = 0, cycles = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            vector<int> component = {i};
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                        component.push_back(v); 
                    }
                }
            }
            bool bamboo = false;
            for (int j: component) {
                if (d[j] == 1) {
                    bamboo = true;
                    break;
                }
            }
            if (bamboo) {
                bamboos++;
            } else {
                cycles++;
            }
        }
    }
    cout << cycles + min(bamboos, 1) << ' ' << cycles + bamboos << '\n';
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
}

/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

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
#define ull unsigned int int
#define PII pair<int , int>
#define int long long
#define ll long long
#define endl '\n'

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const int MOD2 = 998244353 ; 
const int MOD = 1e9 + 7 ; 
const ll LINF = 1e18 ;

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n ; 
vector<int> fa ;

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

void init() {
    fa.resize(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) fa[i] = i ; 
}

int Find( int a ) {
    return a == fa[a] ? a : fa[a] = Find( fa[a] ) ; 
}

void merge( int a , int b ) {
    int ra = Find( a ) ;
    int rb = Find( b ) ;
    fa[ra] = rb ;
}

void solve() {
     


}

// ========================== Idea =============================================
/*

根据邻居的关系判断最大环数量和最小环数量

先来看看并查集的作用 , 即有一条无向边 , 那么两个点联通 , 这两个点的集合也是联通的
对于这道题来说 , 一个连通块意味着可以成环 , 所以所有的连通块都是可以各自成环的 , 也就是这个图的最多的环的数量

为什么连通块一定可以成环 , 因为题给的数据保证了每个节点的度数不会超过 2 , 也就是说每个连通块一定是一个环或者一个链条

特殊的 , 对于一个二元环来说 , 由于边是无向边 , 2 -> 1 === 1 -> 2 , 所以两个点的度数仍然是 1 

当我们想要求得最少环数量 , 我们可以直接判断这个连通块是环状的还是链状的
对于所有的链状的联通块 , 我们可以直接把他们连成一个环

那么问题来了 , 怎么判断一个连通块是环状的还是链状的呢( 这种每个节点的度数都严格小于等于 2 的而且首尾度数严格等于 1 的图一般被称为 bamboo )
特殊的 , 我们认为孤立的节点也算作竹子图 



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        cin >> n ; 
        int mn = 0 , mx = 0 ; 
        init() ; 
        vector<int> arr( n + 1 ) ;
        for ( int i = 1 ; i <= n ; i ++ ) {
            cin >> arr[i] ; 
		}
        for ( int i = 1 ; i <= n ; i ++ ) {
			// 检测这两个点是不是环 实际上这里是在统计环的数量
			// 如果两个点已经被连通起来了 , 而且
			// 哦哦这里是这样的 如果 x 和 y已经联通了 , 看到没有 , 这里给出条件了, 他俩是有一条边的
			// 所以这里能直接判断是环了
			// 然后后面再判断一下二元环
			mn += (Find( i ) == Find( arr[i] ) && i != arr[arr[i]]) ; 
            merge( i , arr[i] ) ;
        }

        // mn 是不可扩张环的数量 , 即
        for ( int i = 1 ; i <= n ; i ++ ) {
            mx += fa[i] == i ; 
        }
		
		// 有二元换就可以吧二元换都并在一起
		// 此时 mn  + 1 
		// 如果没有二元环, 那么最小值就是总的环数

		// mn == mx 的时候 , 说明全都是环 , 没有竹子 , 不能串成新的
        cout << mn + (mn != mx) << ' ' << mx << endl ; 

    }
    

    return 0 ;
}
// ========================== Question =========================================
/*

*/

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long 
// #define endl '\n'
// struct node {
// 	int f;
// };
// struct node ar[200010];
// int find(int x) {
// 	if (ar[x].f != x) {
// 		return ar[x].f = find(ar[x].f);
// 	}
// 	return x;
// }

// void uniond(int x,int y) {
// 	int xx = find(x);
// 	int yy = find(y);
// 	if (xx!=yy) {
// 		ar[xx].f = yy;
// 	}
// }

// signed main () {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
// 	int t;
// 	cin>>t;
// 	while (t--)
// 	{
// 		int n;
// 		cin>>n;
// 		for (int i=1;i<=n;i++) {
// 			ar[i].f = i;
// 		}
// 		int ans1= 0;
// 		int a[n+1] = {};
// 		for (int i=1;i<=n;i++) cin>>a[i];
// 		for (int i=1;i<=n;i++) {
// 			int x = a[i];
// 			int as = find(x);
// 			int bs = find(i);
// 			if (as == bs && i != a[a[i]]) {
// 				ans1++;
// 			}
// 			uniond(x,i);
// 		}	
// 		int ans2 = 0;
// 		for (int i=1;i<=n;i++) {
// 			if (ar[i].f == i) {
// 				ans2++;
// 			}
// 		}
// 		if (ans1==ans2) {
// 			cout<<ans1<<" "<<ans2<<endl;
// 		} else {
// 			cout<<ans1+1<<" "<<ans2<<endl;
// 		}
		
		
// 	}	
// 	return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;
// #define int long long 
// #define endl '\n'
// int ar[200010];
// int find(int x) {
// 	if (ar[x] != x) {
// 		return ar[x] = find(ar[x]);
// 	}
// 	return x;
// }

// void uniond(int x,int y) {
// 	int xx = find(x);
// 	int yy = find(y);
// 	if (xx!=yy) {
// 		ar[xx] = yy;
// 	}
// }

// signed main () {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
// 	int t;
// 	cin>>t;
// 	while (t--)
// 	{
// 		int n;
// 		cin>>n;
// 		for (int i=1;i<=n;i++) {
// 			ar[i] = i;
// 		}
// 		int ans1= 0;
// 		int a[n+1] = {};
// 		for (int i=1;i<=n;i++) cin>>a[i];
// 		for (int i=1;i<=n;i++) {
// 			int x = a[i];
// 			int as = find(x);
// 			int bs = find(i);
// 			if (as == bs && i != a[x]) {
// 				ans1++;
// 			}
// 			uniond(x,i);
// 		}	
// 		int ans2 = 0;
// 		for (int i=1;i<=n;i++) {
// 			if (ar[i] == i) {
// 				ans2++;
// 			}
// 		}
// 		if (ans1==ans2) {
// 			cout<<ans1<<" "<<ans2<<endl;
// 		} else {
// 			cout<<ans1+1<<" "<<ans2<<endl;
// 		}
		
		
// 	}	
// 	return 0;
// }