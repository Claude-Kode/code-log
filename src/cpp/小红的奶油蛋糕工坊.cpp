/*
 * @Author: GoryK
 * @Date: Doomsday
 * @Description: TEMPLATE
 */

// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")

// ========================== Header Files =====================================
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
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

int n ; 

vector<int> arr ; 

// ========================== Functions ========================================


// int rand_num( int l , int r, bool unique = false) {
//     while (1) {
//         int x = l + (unsigned int)rng() % (r - l + 1) ;
//         if ( !unique || st.insert(x).second ) return x ;
//     }
// }



void solve() {
     


}

// ========================== Idea =============================================
/*



*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    
    cin >> n ;
    arr.resize( n + 1 ) ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ; 
    
    int k = ( n + 2 ) / 2 - !(n & 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( arr[i] >= 1 && arr[i] <= k ) cout << (k + 2) / 2 << ' ' ;
        else cout << arr[i] << ' ' ;
    }

//    if ( n & 1 ) {
//         int l = (n + 1) / 2 - (n + 1) / 4 ; 
//         int r = (n + 1) / 4 + (n + 1) / 2 ; 
//         for ( int i = 1 ; i <= n ; i ++ ) {
//             if ( arr[i] >= l && arr[i] <= r ) {
//                 cout << (n + 1) / 2 << ' ' ;
//             } else cout << arr[i] << ' ' ;
//         }
//     } else {
//         int l = n / 2 - n / 4 ;
//         int r = n / 2 + n / 4 - 1 ;
//         for ( int i = 1 ; i <= n ; i ++ ) {
//             if ( arr[i] >= l && arr[i] <= r ) {
//                 cout << (n + 1) / 2 << ' ' ;
//             } else cout << arr[i] << ' ' ;
//         }
//     }
    
    return 0 ;
}
// ========================== Question =========================================
/*

*/



#include<bits/stdc++.h>
using namespace std;
struct rec
{
	long long nxt;
	long long to;
	long long w;
}e[100000],ee[100000];
long long head[5000],cnt,headw[5000],cntw;
long long n,m;
long long st,ed;
long long Map[100][100],wzc[100][100];
long long dis[5000];
bool vis1[5000],vis2[5000],spfa[5000],con[5000][5000];
long long que[5000],h[5000][5000];
bool qj[5000][5000];
long long ans[5000];
void add(long long x,long long y,long long w)
{
    e[++cnt].nxt=head[x];
	e[cnt].to=y;
	e[cnt].w=w;
	head[x]=cnt;
}
void add_w(long long x,long long y)
{
	ee[++cntw].nxt=headw[x];
	ee[cntw].to=y;
	headw[x]=cntw;
}
void SPFA()
{
	queue<long long>q;
	q.push(st);
	spfa[st]=1;
	dis[st]=0;
	ans[st]=1;
	while(!q.empty())
	{
		long long flag=q.front();
		q.pop();
		spfa[flag]=0;
		for(long long i=headw[flag];i;i=ee[i].nxt)
			if(dis[ee[i].to]>dis[flag]+1)
			{
				dis[ee[i].to]=dis[flag]+1;
				ans[ee[i].to]=ans[flag];
				if(!spfa[ee[i].to])
				{
					q.push(ee[i].to);
					spfa[ee[i].to]=1;
				}
			}
			else if(dis[ee[i].to]==dis[flag]+1)ans[ee[i].to]+=ans[flag];
	}
}
void dfs1(long long x)
{
	vis1[x]=1;
	for(long long i=head[x];i;i=e[i].nxt)
	{
		if(!vis1[e[i].to])
		{
			if(e[i].w)que[++que[0]]=e[i].to;
			else dfs1(e[i].to);
		}
	}
}
void dfs2(long long x)
{
	vis2[x]=1;
	for(long long i=1;i<=que[0];i++)
		if(!con[x][que[i]])
		{
			h[x][++h[x][0]]=que[i];
			con[x][que[i]]=1;
		}
	for(long long i=head[x];i;i=e[i].nxt)
		if(!e[i].w&&!vis2[e[i].to])
			dfs2(e[i].to);
}
int main()
{
	for(long long i=1;i<=3000;i++)dis[i]=20020923002002092300;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
		{
			scanf("%lld",&Map[i][j]);
			wzc[i][j]=++wzc[0][0];
			if(Map[i][j]==3)
			{
				st=wzc[i][j];
				Map[i][j]=0;
			}
			if(Map[i][j]==4)
			{
				ed=wzc[i][j];
				Map[i][j]=0;
			}
		}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
		{
			if(Map[i][j]==2)continue;
			if(i-1>0&&j-2>0&&Map[i-1][j-2]!=2)
			{
				if(Map[i-1][j-2])add(wzc[i][j],wzc[i-1][j-2],0);
				else add(wzc[i][j],wzc[i-1][j-2],1);
			}
			if(i-2>0&&j-1>0&&Map[i-2][j-1]!=2)
			{
				if(Map[i-2][j-1])add(wzc[i][j],wzc[i-2][j-1],0);
				else add(wzc[i][j],wzc[i-2][j-1],1);
			}
			if(i-1>0&&j+2<=m&&Map[i-1][j+2]!=2)
			{
				if(Map[i-1][j+2])add(wzc[i][j],wzc[i-1][j+2],0);
				else add(wzc[i][j],wzc[i-1][j+2],1);
			}
			if(i-2>0&&j+1<=m&&Map[i-2][j+1]!=2)
			{
				if(Map[i-2][j+1])add(wzc[i][j],wzc[i-2][j+1],0);
				else add(wzc[i][j],wzc[i-2][j+1],1);
			}
			if(i+1<=n&&j-2>0&&Map[i+1][j-2]!=2)
			{
				if(Map[i+1][j-2])add(wzc[i][j],wzc[i+1][j-2],0);
				else add(wzc[i][j],wzc[i+1][j-2],1);
			}
			if(i+2<=n&&j-1>0&&Map[i+2][j-1]!=2)
			{
				if(Map[i+2][j-1])add(wzc[i][j],wzc[i+2][j-1],0);
				else add(wzc[i][j],wzc[i+2][j-1],1);
			}
			if(i+1<=n&&j+2<=m&&Map[i+1][j+2]!=2)
			{
				if(Map[i+1][j+2])add(wzc[i][j],wzc[i+1][j+2],0);
				else add(wzc[i][j],wzc[i+1][j+2],1);
			}
			if(i+2<=n&&j+1<=m&&Map[i+2][j+1]!=2)
			{
				if(Map[i+2][j+1])add(wzc[i][j],wzc[i+2][j+1],0);
				else add(wzc[i][j],wzc[i+2][j+1],1);
			}
		}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
			if(Map[i][j]==1&&!vis1[wzc[i][j]])
			{
				que[0]=0;
				dfs1(wzc[i][j]);
				memset(vis2,0,sizeof(vis2));
				dfs2(wzc[i][j]);
			}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
		{
			if(Map[i][j]==2||Map[i][j]==1)continue;
			for(long long k=head[wzc[i][j]];k;k=e[k].nxt)
				if(e[k].w)
				{
					if(!qj[wzc[i][j]][e[k].to])
					{
						qj[wzc[i][j]][e[k].to]=1;
						add_w(wzc[i][j],e[k].to);
					}
				}
				else
				{
					for(long long l=1;l<=h[e[k].to][0];l++)
						if(!con[wzc[i][j]][h[e[k].to][l]]&&!qj[wzc[i][j]][h[e[k].to][l]])
						{
							qj[wzc[i][j]][h[e[k].to][l]]=1;
							add_w(wzc[i][j],h[e[k].to][l]);
							con[wzc[i][j]][h[e[k].to][l]]=1;
						}
				}
		}
	SPFA();
	if(dis[ed]==20020923002002092300)puts("-1");
	else cout<<dis[ed]-1<<endl<<ans[ed]<<endl;
	return 0;
}

