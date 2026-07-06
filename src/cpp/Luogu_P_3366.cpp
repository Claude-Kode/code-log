// // /*
// //  * @Author: GoryK
// //  * @Date: Doomsday
// //  * @Description: TEMPLATE 链式前向星1-base 完美最终AC版
// //  */

// // // #pragma GCC optimize("Ofast,fast-math")
// // // #pragma GCC target("avx,avx2")

// // // ========================== Header Files =====================================
// // #include <unordered_map>
// // #include <unordered_set>
// // #include <algorithm>
// // #include <iostream>
// // #include <cstdlib>
// // #include <cstring>
// // #include <iomanip>
// // #include <numeric>
// // #include <sstream> 
// // #include <utility>
// // #include <bitset>
// // #include <chrono>
// // #include <random>
// // #include <string>
// // #include <vector>
// // #include <array>
// // #include <cmath>
// // #include <deque> 
// // #include <queue>
// // #include <stack>
// // #include <list>
// // #include <map>
// // #include <set>

// // // ========================== Namespace ========================================
// // using namespace std ;

// // // ========================== Macro Definitions ================================
// // #define TUP tuple<int , int , int>
// // #define ull unsigned long long  // ✅ 可选：消除警告，不改也能AC
// // #define PII pair<int , int>
// // #define int long long
// // #define ll long long
// // #define endl '\n'

// // // ========================== Constants ========================================
// // const int INF = 0x3f3f3f3f3f3f3f3f ;
// // const int MOD2 = 998244353 ; 
// // const int MOD = 1e9 + 7 ; 
// // const int LINF = 1e18 ;

// // // ========================== Global Variables / Arrays ========================
// // struct edge{
// //     int v ; 
// //     int w ; 
// //     int next ; 
// // } ; 

// // int n , m ;
// // vector<int> dis ; 
// // vector<int> head ; 
// // vector<bool> vis ; 
// // vector<edge> edges(1) ;  // ✅ 你的完美1-base边数组，正确！
 

// // // ========================== Functions ========================================
// // void add( int u , int v , int w ) {
// //     edges.emplace_back( edge{v, w, head[u]} ) ; 
// //     head[u] = edges.size() - 1 ;  // ✅ 修改1：致命错误，加-1，唯一必改！
// // }

// // void init() {
// //     cin >> n >> m ;
// //     dis.resize( n + 1 , INF ) ; 
// //     vis.resize( n + 1 , false ) ;
// //     head.resize( n + 1 , 0 ) ; 
// //     while ( m -- ) {
// //         int u , v , w ; 
// //         cin >> u >> v >> w ; 
// //         add(u , v , w) ; 
// //         add(v , u , w) ; 
// //     }
// // }

// // void prim() {
// //     init() ; 
// //     int ans = 0 ; 
// //     int now = 1 ; 
// //     int cnt = 1 ; 

// //     for ( int i = head[1] ; i ; i = edges[i].next ) {
// //         dis[edges[i].v] = min( dis[edges[i].v] , edges[i].w ) ; 
// //     }
// //     vis[1] = true ; dis[1] = 0 ; 

// //     while ( cnt < n ) {  // ✅ 修改2：循环条件 <=n 改成 <n，必改！
        
// //         int minw = INF ; 
// //         for ( int i = 1 ; i <= n ; i++ ) {
// //             if ( !vis[i] && minw > dis[i] ) {
// //                 minw = dis[i] ; 
// //                 now = i ; 
// //             }
// //         }

// //         if ( minw == INF ) { cout << "orz" << endl ; return ; }  
        
// //         ans += minw ; 
// //         vis[now] = true ; 

// //         for ( int i = head[now] ; i ; i = edges[i].next ) {
// //             dis[edges[i].v] = min( dis[edges[i].v] , edges[i].w ) ; 
// //         }

// //         cnt ++ ; 
// //     }
// //     cout << ans << endl ; 
// // }

// // void solve() {}

// // // ========================== Main Function ====================================
// // signed main() {
// //     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
// //     prim() ; 
// //     return 0 ;
// // }



// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned int int
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD2 = 998244353 ; 
// const int MOD = 1e9 + 7 ; 
// const int LINF = 1e18 ;
// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// // 链式前向星 , 不到为啥非得起这么装逼的名字 , 何意味
// struct edge{
//     // 这条边连着的节点
//     int v ; 
//     // 这条边的权重
//     int w ; 
//     // 下条边存在数组哪里 , 即下标
//     int next ; 
// } ; 

// int n , m ;

// vector<int> dis ; 
// vector<int> head ; 
// vector<bool> vis ; 
// // init error
// vector<edge> edges(1) ; 
 

// // ========================== Functions ========================================

// void add( int u , int v , int w ) {
//     edges.emplace_back( edge{v, w, head[u]} ) ; 
//     // error
//     head[u] = edges.size() - 1;
// }

// void init() {

//     cin >> n >> m ;
//     dis.resize( n + 1 , INF ) ; 
//     vis.resize( n + 1 , false ) ;
//     head.resize( n + 1 , 0 ) ; 
//     while ( m -- ) {
//         int u , v , w ; 
//         cin >> u >> v >> w ; 
//         add(u , v , w) ; 
//         add(v , u , w) ; 
//     }

// }

// void prim() {

//     init() ; 

//     // 边权加合
//     int ans = 0 ; 

//     // 当前正在以哪个节点为根节点向外拓展最小生成树   
//     int now = 1 ; 

//     // 已经加入最小生成树的节点的数量 
//     int cnt = 1 ; 

//     // 以 1 为起点开始生成最小生成树
//     // 1. 找到非最小生成树里距离最小生成树最近的节点
//     // 2. 加入最小生成树
//     // 3. 更新加入最小生成树的节点相连的节点到最小生成树的距离

//     // error
//     for ( int i = head[1] ; i ; i = edges[i].next ) {
//         dis[edges[i].v] = min( dis[edges[i].v] , edges[i].w ) ; 
//     }
//     // error
//     vis[1] = true ; dis[1] = 0 ; 

//     // 1 到 1 自己是 0 , 边权就不用算了  


//     // maybe error ? 
//     // ori is cnt <= n 
//     while ( cnt < n ) {

//         // 找到距离最小生成树最近的节点并加入
//         // 这里是要遍历所有的节点到生成树的距离
        
//         int minw = INF ; 
//         for ( int i = 1 ; i <= n ; i++ ) {
//             if ( !vis[i] && minw > dis[i] ) {
//                 minw = dis[i] ; 
//                 now = i ; 
//             }
//         }

//         if ( minw == INF ) { cout << "orz" << endl ; return ; }  
        
//         ans += minw ; 
//         vis[now] = true ; 
//         cnt ++ ;

//         for ( int i = head[now] ; i ; i = edges[i].next ) {
//             dis[edges[i].v] = min( dis[edges[i].v] , edges[i].w ) ; 
//         }

//     }

//     cout << ans << endl ; 

// }

// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     prim() ; 
    

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */


// // #include<bits/stdc++.h>
// // using namespace std;
// // #define re register
// // #define il inline
// // il int read()
// // {
// //     re int x=0,f=1;char c=getchar();
// //     while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
// //     while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
// //     return x*f;
// // }//快读，不理解的同学用cin代替即可
// // #define inf 123456789
// // #define maxn 5005
// // #define maxm 200005
// // struct edge
// // {
// // 	int v,w,next;
// // }e[maxm<<1];
// // //注意是无向图，开两倍数组
// // int head[maxn],dis[maxn],cnt,n,m,tot,now=1,ans;
// // //已经加入最小生成树的的点到没有加入的点的最短距离，比如说1和2号节点已经加入了最小生成树，那么dis[3]就等于min(1->3,2->3)
// // bool vis[maxn];
// // //链式前向星加边
// // il void add(int u,int v,int w)
// // {
// // 	e[++cnt].v=v;
// // 	e[cnt].w=w;
// // 	e[cnt].next=head[u];
// // 	head[u]=cnt;
// // }
// // //读入数据
// // il void init()
// // {
// //     n=read(),m=read();
// //     for(re int i=1,u,v,w;i<=m;++i)
// //     {
// //         u=read(),v=read(),w=read();
// //         add(u,v,w),add(v,u,w);
// //     }
// // }
// // il int prim()
// // {
// // 	//先把dis数组附为极大值
// // 	for(re int i=2;i<=n;++i)
// // 	{
// // 		dis[i]=inf;
// // 	}
// //     //这里要注意重边，所以要用到min
// // 	for(re int i=head[1];i;i=e[i].next)
// // 	{
// // 		dis[e[i].v]=min(dis[e[i].v],e[i].w);
// // 	}
// //     while(++tot<n)//最小生成树边数等于点数-1
// //     {
// //         re int minn=inf;//把minn置为极大值
// //         vis[now]=1;//标记点已经走过
// //         //枚举每一个没有使用的点
// //         //找出最小值作为新边
// //         //注意这里不是枚举now点的所有连边，而是1~n
// //         for(re int i=1;i<=n;++i)
// //         {
// //             if(!vis[i]&&minn>dis[i])
// //             {
// //                 minn=dis[i];
// // 				now=i;
// //             }
// //         }
// //         ans+=minn;
// //         //枚举now的所有连边，更新dis数组
// //         for(re int i=head[now];i;i=e[i].next)
// //         {
// //         	re int v=e[i].v;
// //         	if(dis[v]>e[i].w&&!vis[v])
// //         	{
// //         		dis[v]=e[i].w;
// //         	}
// // 		}
// //     }
// //     return ans;
// // }
// // int main()
// // {
// //     init();
// //     printf("%d",prim());
// //     return 0;
// // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // #define re register
// // #define il inline
// // il int read()
// // {
// //     re int x=0,f=1;char c=getchar();
// //     while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
// //     while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
// //     return x*f;
// // }//快读，不理解的同学用cin代替即可
// // #define inf 123456789
// // #define maxn 5005
// // #define maxm 200005
// // struct edge
// // {
// // 	int v,w,next;
// // }e[maxm<<1];
// // //注意是无向图，开两倍数组
// // int head[maxn],dis[maxn],cnt,n,m,tot,now=1,ans;
// // //已经加入最小生成树的的点到没有加入的点的最短距离，比如说1和2号节点已经加入了最小生成树，那么dis[3]就等于min(1->3,2->3)
// // bool vis[maxn];
// // //链式前向星加边
// // il void add(int u,int v,int w)
// // {
// // 	e[++cnt].v=v;
// // 	e[cnt].w=w;
// // 	e[cnt].next=head[u];
// // 	head[u]=cnt;
// // }
// // //读入数据
// // il void init()
// // {
// //     n=read(),m=read();
// //     for(re int i=1,u,v,w;i<=m;++i)
// //     {
// //         u=read(),v=read(),w=read();
// //         add(u,v,w),add(v,u,w);
// //     }
// // }
// // il int prim()
// // {
// // 	//先把dis数组附为极大值
// // 	for(re int i=2;i<=n;++i)
// // 	{
// // 		dis[i]=inf;
// // 	}
// //     //这里要注意重边，所以要用到min
// // 	for(re int i=head[1];i;i=e[i].next)
// // 	{
// // 		dis[e[i].v]=min(dis[e[i].v],e[i].w);
// // 	}
// //     while(++tot<n)//最小生成树边数等于点数-1
// //     {
// //         re int minn=inf;//把minn置为极大值
// //         vis[now]=1;//标记点已经走过
// //         //枚举每一个没有使用的点
// //         //找出最小值作为新边
// //         //注意这里不是枚举now点的所有连边，而是1~n
// //         for(re int i=1;i<=n;++i)
// //         {
// //             if(!vis[i]&&minn>dis[i])
// //             {
// //                 minn=dis[i];
// // 				now=i;
// //             }
// //         }
// //         ans+=minn;
// //         //枚举now的所有连边，更新dis数组
// //         for(re int i=head[now];i;i=e[i].next)
// //         {
// //         	re int v=e[i].v;
// //         	if(dis[v]>e[i].w&&!vis[v])
// //         	{
// //         		dis[v]=e[i].w;
// //         	}
// // 		}
// //     }
// //     return ans;
// // }
// // int main()
// // {
// //     init();
// //     printf("%d",prim());
// //     return 0;
// // }

// /*
//  * @Author: GoryK
//  * @Date: Doomsday
//  * @Description: TEMPLATE
//  */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

// // ========================== Header Files =====================================
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <iomanip>
// #include <numeric>
// #include <sstream> 
// #include <utility>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <string>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <deque> 
// #include <queue>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>

// // ========================== Namespace ========================================
// using namespace std ;
// // using namespace ranges ;

// // ========================== Macro Definitions ================================
// #define TUP tuple<int , int , int>
// #define ull unsigned int int
// #define PII pair<int , int>
// #define int long long
// #define ll long long
// #define endl '\n'

// // ========================== Constants ========================================
// const int INF = 0x3f3f3f3f3f3f3f3f ;
// const int MOD2 = 998244353 ; 
// const int MOD = 1e9 + 7 ; 

// // ========================== Global Variables / Arrays ========================

// // mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// // unordered_set<int> st ;

// //  n 是节点的数量 , m 是边的数量
// int n , m ; 
// // ans 是最终最小生成树的总边权
// int ans = 0 ; 

// // dis[i] 表示节点 i 到最小生成树的距离
// vector<int> dis ;
// // vis[i] 表示节点 i 是否已经加入最小生成树
// vector<int> vis ;
// // adjencent list 邻接表存图
// // adj[i] = { { j , w } ... } 表示 i 到 j 的边权是 w 
// vector<vector<PII>> adj ; 

// // ========================== Functions ========================================


// // int rand_num( int l , int r, bool unique = false) {
// //     while (1) {
// //         int x = l + (unsigned int)rng() % (r - l + 1) ;
// //         if ( !unique || st.insert(x).second ) return x ;
// //     }
// // }

// void solve() {
     


// }

// // ========================== Idea =============================================
// /*



// */
// // ========================== Main Function ====================================
// signed main() {
//     ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    

//     cin >> n >> m ; 
//     // 初始化 , 未加入最小生成树的节点我们默认到最小生成树的距离是 INF
//     dis.resize(n + 1 , INF) ;
//     vis.resize(n + 1) ;
//     adj.resize(n + 1) ; 

//     int sum = 0 ; 
//     while ( m-- ) {
//         int u , v , w ; 
//         cin >> u >> v >> w ; 
//         // 因为是无向边 , 所以一条边要存两次 , 方向相反
//         adj[u].emplace_back( v , w ) ;
//         adj[v].emplace_back( u , w ) ; 
//     } 

//     // cnt 代表当前已经加入最小生成树的节点数量
//     // now 表示当前找到的距离最小生成树最短的节点是啥
//     // 这里是以 1 作为根节点生成最小生成树 , 下面是处理部分
//     int cnt = 1 , now = 1 ; vis[now] = 1 ; 
//     // 这一步其实可有可无 , 因为 find 的时候只要 vis[i] 被设置了就可以了
//     dis[1] = 0 ; 
//     // 更新 1 的周围的节点到最小生成树的距离
//     for ( auto &[v , w] : adj[now] ) {
//         dis[v] = min( dis[v] , w ) ; 
//     }
//     while ( cnt < n ) {
//         // 找节点
//         int min_dis = INF ; 
//         for ( int i = 1 ; i <= n ; i ++ ) {
//             if ( !vis[i] && min_dis > dis[i] ) {
//                 now = i ; 
//                 min_dis = dis[i] ;
//             }
//         } 

//         // 这里说明没找到
//         if ( min_dis == INF ) {
//             cout << "orz" << endl ; 
//             return 0 ; 
//         }

//         // 加入最小生成树
//         vis[now] = 1 ; 
//         ans += min_dis ;
//         cnt++ ; 

//         // 更新距离
//         for ( auto &[v , w] : adj[now] ) {
//             dis[v] = min( dis[v] , w ) ; 
//         }

//     }

//     cout << ans << endl ; 

//     return 0 ;
// }
// // ========================== Question =========================================
// /*

// */


#include<bits/stdc++.h>

using namespace std ;

struct edge{
	int u ;
    int v ;
    int w ;
} edges[200005] ;

int n , m ; 
int ans , cnt ;
int fa[5005] ; 

void init() {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ ) {
        fa[i] = i ;
    }
    for ( int i = 0 ; i < m ; i++ ) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w ;   
    }
}

int find(int x) {
    if ( x != fa[x] ) 
        return fa[x] = find( fa[x] ) ;
    return x ; 
}

void kruskal() {

    init() ; 

    sort( edges , edges + m , []( edge a , edge b ) {
        return a.w < b.w ; 
    }) ;


    // error : i < m && ++cnt < n 
    // true : cnt++ < n 
    for ( int i = 0 ; i < m ; i++ ) {

        int fu , fv ; 
        fu = find( edges[i].u ) ;
        fv = find( edges[i].v ) ;

        if ( fu != fv ) {
            fa[fu] = fv ;
            ans += edges[i].w ;
            if ( ++cnt == n - 1 ) {
                break ; 
            }
        }

    }


    // not all in judge 
    // int flag = 0 ; 
    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     flag += fa[i] == i ;  
    // }

    // if ( flag > 1 ) { cout << "orz" << endl ; return ; }
    if ( cnt < n - 1 ) { cout << "orz" << endl ; return ; }

    cout << ans << endl ; 

}

int main() {
    kruskal() ;
    return 0 ;
}
