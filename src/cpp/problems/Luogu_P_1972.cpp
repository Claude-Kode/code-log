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
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned int int
#define PII pair<int , int>
#define TUP tuple<int , int , int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f ;
const ll LINF = 1e18 ;
const int MOD = 1e9 + 7 ; 
const int MOD2 = 998244353 ; 

// ========================== Global Variables / Arrays ========================

// mt19937_64 rng( chrono :: steady_clock :: now().time_since_epoch().count() ) ;
// unordered_set<int> st ;

int n , m ; 
vector<int> ans ; 
vector<int> arr ;
vector<int> tree ; 
struct ques { int l ; int r ; int orinPos ; } ; 
vector<ques> q ; 


// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }

int lowbit( int i ) { return i & -i ; }

void update ( int pos , int del ) {
    for ( int i = pos ; i <= n ; i += lowbit(i) ) {
        tree[i] += del ; 
    }
}

int query( int pos ) {
    int res = 0 ;
    for ( int i = pos ; i > 0 ; i -= lowbit(i) ) {
        res += tree[i] ; 
    }
    return res ; 
}

void solve() {
     


}

// ========================== Idea =============================================
/*

普通的计数前缀和只能表示出 r 对比于 l 增加了多少个新元素 而不能证明 l -> r 有多少个元素

我是想分治 , 每个出现的元素的频率加合 , 每个元素的出现可以用桶树状数组

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
    
    cin >> n ; 
    tree.resize( n + 1 ) ; arr.resize( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> arr[i] ; 
    }

    cin >> m ;
    q.resize( m ) ; ans.resize( m ) ; 
    int cnt = 0 ; 
    for ( auto &[l , r , pos] : q ) {
        cin >> l >> r ; pos = cnt ++ ; 
    } 
    sort( q.begin() , q.end() , [&]( ques &a , ques &b ) {
        return a.r < b.r ; 
    }) ;

    vector<int> ans( m ) ; 
    unordered_map<int, int> prePos ; 
    int pre = 1 ; 
    for ( auto &[l , r , pos] : q ) {
        for ( int i = pre ; i <= r ; i ++ ) { 
            if ( prePos[arr[i]] ) {
                update( prePos[arr[i]] , -1 ) ; 
                update( i , 1 ) ; 
            }
            prePos[arr[i]] = i ; 
        }
        pre = r + 1 ;
        ans[pos] = query( r ) - query( l - 1 ) ; 
    }

    for ( auto &a : ans ) cout << a << endl ; 

    return 0 ;
}
// ========================== Question =========================================
/*

*/



// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// #define rint register int
// #define maxn 1000010
// using namespace std;

// int n , m ;
// int a[maxn] , ans[maxn] ;
// int vis[maxn] , tree[maxn] ;

// struct QUE {
// 	int l ;
// 	int r ;
// 	int id ;
// }q[maxn] ;

// inline void read(int &x){
// 	char ch = getchar() ; int f = 1 ; x = 0 ;
// 	while( !isdigit(ch) && ch ^ '-') ch=getchar() ;
// 	if( ch =='-' ) f = -1 , ch = getchar() ;
// 	while( isdigit(ch) ) x = x * 10 + ch - '0' , ch = getchar() ;
// 	x *= f ;
// }

// inline bool cmp(const QUE &a , const QUE &b){
// 	return a.r < b.r ;
// }

// inline int lowbit(int x){
// 	return x & (-x) ;
// }

// void modify(int p , int v){
// 	for( ; p <= n ; p += lowbit(p) )
// 		tree[p] += v ;
// }

// int query(int p){
// 	int res = 0 ;
// 	for( ; p ; p -= lowbit(p) )
// 		res += tree[p] ;
// 	return res ;
// }

// int main() { 
// 	read(n) ;
// 	for ( rint i = 1 ; i <= n ; i ++ ) read(a[i]) ;
// 	read(m) ;
// 	for ( rint i = 1 ; i <= m ; i ++ ) {
// 		read(q[i].l) ; 
//         read(q[i].r) ; 
//         q[i].id = i ;
// 	}
// 	sort(q + 1 , q + m + 1 , cmp) ;
	
// 	int pow = 1 ;
// 	for( rint i = 1 ; i <= m ; i ++ ) {
// 		for( rint j = pow ; j <= q[i].r ; j ++ ){
// 			if( vis[a[j]] ) modify(vis[a[j]] , -1) ;
// 			modify(j , 1) ;
// 			vis[a[j]] = j ;
// 		}
// 		pow = q[i].r + 1 ;
// 		ans[q[i].id] = query(q[i].r) - query(q[i].l-1) ;
// 	}
	
// 	for( rint i = 1 ; i <= m ; i ++ )
//     printf("%d\n" , ans[i]) ;
// 	return 0;
// }