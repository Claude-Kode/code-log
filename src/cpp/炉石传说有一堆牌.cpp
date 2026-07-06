
// // // @Author : GoryK 
// // // @Description : TEMPLATE-2 
// // #include <bits/stdc++.h> 

// // using namespace std ; 

// // #define int long long 
// // #define endl '\n'

// // const int mod = 1e9 + 7 ;
// // const int maxn = 2e5 ; 

// // int n , m , k ; 
// // bool can = false ; 

// // vector<int> vis ; 
// // struct infor { int val ; int knd ; int eff ; } ; vector<infor> ifo ; 
// // vector<vector<int>> knd ;
// // vector<vector<int>> ans ; 
// // vector<vector<int>> temp ; 

// // void DFS( int step , int remVal , vector<int>& vis , vector<vector<int>>& temp ) {

// //     bool end = false ; 
// //     for ( int i = 1 ; i <= n ; i ++ ) {
// //         if ( vis[i] ) end = true ; 
// //     }

// //     if ( end ) {
// //         if ( step <= k ) {
// //             m = step ; 
// //             ans = temp ; 
// //             can = true ;
// //             return ; 
// //         }
// //     }

// //     if ( can || step > k ) return ; 

// //     // 或者说我直接就瞎选 , 选啥都行我不管 只要体力够我就选 反正我不管
// //     int curVal = 0 ; 
// //     bool thisStepEnd = true ; 
// //     for ( int i = 1 ; i <= n ; i++ ) {
// //         if ( vis[i] && ifo[i].val < remVal ) {
// //             thisStepEnd = false ; 
// //             break ; 
// //         } 
// //     }

// //     if ( thisStepEnd ) DFS( step + 1 , 10 , vis , temp ) ; 

// //     for ( int i = 1 ; i <= n ; i ++ ) {
// //         if ( !vis[i] ) {

// //             if ( ifo[i].eff == 1 ) {
// //                 if ( !temp[step].empty() && remVal - ifo[i].val > 0 ) {
// //                     vis[i] = 1 ;
// //                     temp[step].push_back( i ) ; 
// //                     DFS( step , remVal - ifo[i].val , vis , temp ) ; 
// //                 }
// //             }

// //             // 我要找一下上一次 效果是 2 的都是什么种类
// //             // 然后找一下 , 这些种类里面有哪些没用的 , 而且效果是 2 的 , 用进去
// //             if ( ifo[i].eff == 2 && !temp[step - 1].empty() ) {

// //                 unordered_set<int> last_eff2_knd ; 
// //                 for ( auto &x : temp[step - 1] ) {
// //                     last_eff2_knd.insert( ifo[x].knd ) ;
// //                 }

// //                 // last_eff2_knd 存的是 上一次用过的 效果是2 的牌的种类有哪些
// //                 for ( auto &x : last_eff2_knd ) {
// //                     for ( auto &xx : knd[x] ) {
// //                         if ( !vis[xx] && remVal - ifo[xx].val > 0 ) {
// //                             vis[xx] = 1 ; temp[step].push_back( xx ) ; 
// //                             DFS( step , remVal - ifo[xx].val , vis , temp ) ; 
// //                             vis[xx] = 0 ; temp[step].pop_back() ; 
// //                         }
// //                     }
// //                 }
// //             } 

// //             if ( ifo[i].eff == 3 && remVal == ifo[i].val ) {
// //                 vis[i] = 1 ; temp[step].push_back( i ) ;
// //                 DFS( step + 1 , 10 , vis , temp ) ;
// //                 vis[i] = 0 ; temp[step].pop_back() ; 
// //             } 

// //         }
// //     }

// //     // int rem = 10 ; 
// //     // vector<int> curknd ; 
// //     // // 找一下上回和用过拿些
// //     // // 上回和使用的下标 : 遍历 temp[step - 1]
// //     // // 遍历一下 b , 找一下哪些可以用
// //     // // x 是 效果为 2 的下标

// //     // // 找出上一回合用过的 效果为 2 的种类
// //     // vector<int> lastUsed_2_index ; 

// //     // for ( auto &x : temp[step - 1] ) if ( ifo[x].knd == 2 ) lastUsed_2_index.push_back( x ) ;

// //     // // 这里面是上回合用的效果是 2 的下标 , 接下来要看
// //     // for ( auto &i : lastUsed_2_index ) 

// // }

// // void solve() {

// //     cin >> n >> k ;

// //     vis.resize( n + 1 ) ; 
// //     knd.resize( n + 1 ) ; 
// //     ifo.resize( n + 1 ) ; 
// //     temp.resize( k + 10 ) ; 

// //     int mx3val = 0 ; 
// //     for ( int i = 1 ; i <= n ; i ++ ) {
// //         cin >> ifo[i].val >> ifo[i].knd >> ifo[i].eff ;
// //         knd[ifo[i].knd].push_back( i ) ; 
// //     }

// //     DFS( 1 , 10 , vis , temp ) ; 

// //     // 到这里 , 每张牌一定是能随便打都能的出去的
// //     // 到了这里 重点的就是出发效果了

// //     // 效果是 3 的牌必须搭配别的牌或者自己打出去
    
// //     // 效果是 2 的牌 , 只要自己的类型存在了随便打都可以 , 这个可以搭配 3 
// //     // 效果是 1 的牌 , 只要别人的类型存在也是随便打 , 也可以搭配 3 
// //     // 也就是说 , 我一开始尽可能的吧各种类型的牌打的出去 
// //     // 然后这道题不要求最优解 , 有解即可
// //     // 那么重点就是 3 能不能打得出去
// //     // 1 必须和其他牌搭配打出去

// //     // 如果单个回合出现法力值 > 10 , -1
// //     // 三号牌比较特殊


// //     // 1 必须和其他牌搭配打出去
// //     // 2 必须要之前打过同种类的牌

// //     // 第一张牌必须是 3 
// //     // 

// //     if ( !can ) { cout << -1 << endl ; return ; }

// //     cout << m << endl ; 
// //     for ( int i = 1 ; i <= m ; i ++ ) {
// //         if ( ans.empty() ) continue ;  
// //         for ( auto &a : ans[i] ) {
// //             cout << a << ' ' ;  
// //             if ( a == ans[i].back() ) cout << endl ;  
// //         }
// //     }

// // }

// // signed main() {

    
// //     solve() ; 


// //     return 0 ; 
// // }   



// // // @Author : GoryK 
// // // @Description : TEMPLATE-2 
// // #include <bits/stdc++.h> 

// // using namespace std ; 

// // #define int long long 
// // #define endl '\n'

// // const int mod = 1e9 + 7 ;
// // const int maxn = 2e5 ; 

// // int n , m , k ; 
// // bool can = false ; 

// // vector<int> vis ; 
// // struct infor { int val ; int knd ; int eff ; } ; vector<infor> ifo ; 
// // vector<vector<int>> knd ;
// // vector<vector<int>> ans ; 
// // vector<vector<int>> temp ; 

// // void DFS( int step , int remVal , vector<int>& vis , vector<vector<int>>& temp ) {

// //     bool end = false ; 
// //     for ( int i = 1 ; i <= n ; i ++ ) {
// //         if ( vis[i] ) end = true ; 
// //     }

// //     if ( end ) {
// //         if ( step <= k ) {
// //             m = step ; 
// //             ans = temp ; 
// //             can = true ;
// //             return ; 
// //         }
// //     }

// //     if ( can || step > k ) return ; 

// //     // 或者说我直接就瞎选 , 选啥都行我不管 只要体力够我就选 反正我不管
// //     int curVal = 0 ; 
// //     bool thisStepEnd = true ; 
// //     for ( int i = 1 ; i <= n ; i++ ) {
// //         if ( vis[i] && ifo[i].val < remVal ) {
// //             thisStepEnd = false ; 
// //             break ; 
// //         } 
// //     }

// //     if ( thisStepEnd ) DFS( step + 1 , 10 , vis , temp ) ; 

// //     for ( int i = 1 ; i <= n ; i ++ ) {
// //         if ( !vis[i] ) {

// //             if ( ifo[i].eff == 1 ) {
// //                 if ( !temp[step].empty() && remVal - ifo[i].val > 0 ) {
// //                     vis[i] = 1 ;
// //                     temp[step].push_back( i ) ; 
// //                     DFS( step , remVal - ifo[i].val , vis , temp ) ; 
// //                 }
// //             }

// //             // 我要找一下上一次 效果是 2 的都是什么种类
// //             // 然后找一下 , 这些种类里面有哪些没用的 , 而且效果是 2 的 , 用进去
// //             if ( ifo[i].eff == 2 && !temp[step - 1].empty() ) {

// //                 unordered_set<int> last_eff2_knd ; 
// //                 for ( auto &x : temp[step - 1] ) {
// //                     last_eff2_knd.insert( ifo[x].knd ) ;
// //                 }

// //                 // last_eff2_knd 存的是 上一次用过的 效果是2 的牌的种类有哪些
// //                 for ( auto &x : last_eff2_knd ) {
// //                     for ( auto &xx : knd[x] ) {
// //                         if ( !vis[xx] && remVal - ifo[xx].val > 0 ) {
// //                             vis[xx] = 1 ; temp[step].push_back( xx ) ; 
// //                             DFS( step , remVal - ifo[xx].val , vis , temp ) ; 
// //                             vis[xx] = 0 ; temp[step].pop_back() ; 
// //                         }
// //                     }
// //                 }
// //             } 

// //             if ( ifo[i].eff == 3 && remVal == ifo[i].val ) {
// //                 vis[i] = 1 ; temp[step].push_back( i ) ;
// //                 DFS( step + 1 , 10 , vis , temp ) ;
// //                 vis[i] = 0 ; temp[step].pop_back() ; 
// //             } 

// //         }
// //     }

// //     // int rem = 10 ; 
// //     // vector<int> curknd ; 
// //     // // 找一下上回和用过拿些
// //     // // 上回和使用的下标 : 遍历 temp[step - 1]
// //     // // 遍历一下 b , 找一下哪些可以用
// //     // // x 是 效果为 2 的下标

// //     // // 找出上一回合用过的 效果为 2 的种类
// //     // vector<int> lastUsed_2_index ; 

// //     // for ( auto &x : temp[step - 1] ) if ( ifo[x].knd == 2 ) lastUsed_2_index.push_back( x ) ;

// //     // // 这里面是上回合用的效果是 2 的下标 , 接下来要看
// //     // for ( auto &i : lastUsed_2_index ) 

// // }

// // void solve() {

// //     cin >> n >> k ;

// //     vis.resize( n + 1 ) ; 
// //     knd.resize( n + 1 ) ; 
// //     ifo.resize( n + 1 ) ; 
// //     temp.resize( k + 10 ) ; 

// //     int mx3val = 0 ; 
// //     for ( int i = 1 ; i <= n ; i ++ ) {
// //         cin >> ifo[i].val >> ifo[i].knd >> ifo[i].eff ;
// //         knd[ifo[i].knd].push_back( i ) ; 
// //     }

// //     DFS( 1 , 10 , vis , temp ) ; 

// //     // 到这里 , 每张牌一定是能随便打都能的出去的
// //     // 到了这里 重点的就是出发效果了

// //     // 效果是 3 的牌必须搭配别的牌或者自己打出去
    
// //     // 效果是 2 的牌 , 只要自己的类型存在了随便打都可以 , 这个可以搭配 3 
// //     // 效果是 1 的牌 , 只要别人的类型存在也是随便打 , 也可以搭配 3 
// //     // 也就是说 , 我一开始尽可能的吧各种类型的牌打的出去 
// //     // 然后这道题不要求最优解 , 有解即可
// //     // 那么重点就是 3 能不能打得出去
// //     // 1 必须和其他牌搭配打出去

// //     // 如果单个回合出现法力值 > 10 , -1
// //     // 三号牌比较特殊


// //     // 1 必须和其他牌搭配打出去
// //     // 2 必须要之前打过同种类的牌

// //     // 第一张牌必须是 3 
// //     // 

// //     if ( !can ) { cout << -1 << endl ; return ; }

// //     cout << m << endl ; 
// //     for ( int i = 1 ; i <= m ; i ++ ) {
// //         if ( ans.empty() ) continue ;  
// //         for ( auto &a : ans[i] ) {
// //             cout << a << ' ' ;  
// //             if ( a == ans[i].back() ) cout << endl ;  
// //         }
// //     }

// // }

// // signed main() {

    
// //     solve() ; 


// //     return 0 ; 
// // }   




// // @Author : GoryK 
// // @Description : TEMPLATE-2 
// #include <bits/stdc++.h> 

// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int mod = 1e9 + 7 ;
// const int maxn = 2e5 ; 

// int m ; 
// int n , k ; 

// bool can ; 

// struct infor { int val ; int knd ; int eff ; } ; vector<infor> ifo ; 

// vector<int> vis ; 
// vector<vector<int>> ans ; 
// vector<vector<int>> temp ; 
// vector<vector<int>> kindToIndex ; 


// void DFS( int step , int remVal , vector<int>& vis , vector<vector<int>>& temp ) {

//     // 递归边界
//     if ( can ) return ; 

//     bool end = true ; 
//     for ( int i = 1 ; i <= n ; i ++ ) {
//         if ( !vis[i] ) {
//             end = false ; 
//             break ; 
//         } 
//     }

//     if ( end && step <= k + 1 ) {
//         can = false ; 
//         ans = temp ; 
//         m = step - 1 ; 
//         return ; 
//     }

//     if ( end && step > k ) return ; 


//     // 枚举新牌并搜索
//     for ( int i = 1 ; i <= n ; i ++ ) if ( !vis[i] ) {

//         int curknd = ifo[i].knd ; 
//         // 花完当前的体力还剩下多少
//         int curVal = remVal - ifo[i].val ;

//         if ( ifo[i].eff == 1 && !temp[step].empty() && curVal >= 0 ) {
//             vis[i] = 1 ; temp[step].push_back( i ) ; 
//             DFS( step , curVal , vis , temp ) ; 
//             vis[i] = 0 ; temp[step].pop_back() ; 
//         }

//         if ( ifo[i].eff == 2 && !temp[step - 1].empty() ) {
//             // 首先找上一轮都用过什么牌
//             unordered_map<int, int> lastTurnUsedKinds ; 
//             for ( auto &x : temp[step - 1] ) {
//                 lastTurnUsedKinds[x] = 1 ; 
//             }

//             if ( lastTurnUsedKinds[i] && curVal >= 0 ) {
//                 vis[i] = 1 ; temp[step].push_back( i ) ; 
//                 DFS( step , curVal , vis , temp ) ; 
//                 vis[i] = 0 ; temp[step].pop_back() ; 
//             }

//         }        
        
//         if ( ifo[i].eff == 3 && curVal == 0 ) {
//             vis[i] = 1 ; temp[step].push_back( i ) ; 
//             DFS( step + 1 , curVal , vis , temp ) ;
//             vis[i] = 0 ; temp[step].pop_back() ; 
//         }

//     } 

// }



// signed main() {


//     cin >> n >> k ;

//     ifo.resize( n + 1 ) ;
//     vis.resize( n + 1 ) ; 
//     temp.resize( n + 1 ) ;  
//     kindToIndex.resize( n + 1 ) ; 


//     for ( int i = 1 ; i <= n ; i ++ ) {
//         cin >> ifo[i].val >> ifo[i].knd >> ifo[i].eff ; 
//         kindToIndex[ifo[i].knd].push_back( i ) ; 
//     }

//     DFS( 1 , 0 , vis , temp ) ; 

//     if ( can ) {
//         for ( int i = 1 ; i <= m ; i ++ ) {
//             for ( auto &a : ans[i] ) {
//                 cout << a << ' ' ;
//             }
//             cout << endl ; 
//         }
//     }

//     cout << -1 << endl ; 

//     return 0 ; 
// }   




// /*
// Author：ForgotMe
// 花与剑无痕，高挂一轮明灯。 
// */
// #include <cstdio>
// #include <map>
// #include <iostream>
// #include <algorithm>
// #include <bitset>
// #include <queue>
// #include <stack>
// #include <vector>
// #include <random>
// #include <cstring>
// #include <ctime>
// #include <cmath>
// #include <assert.h> 
// #include <unordered_map>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// #define LL long long
// #define pp pair<int,int>
// #define mp make_pair 
// #define ull unsigned long long
// namespace IO{
//     const int sz=1<<22;
//     char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
//     inline char gc(){
//     //  return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
//         return getchar();
//     }
//     template<class T> void gi(T& x){
//         x=0; int f=1;char c=gc();
//         if(c=='-')f=-1;
//         for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
//         for(;c>='0'&&c<='9';c=gc())
//             x=x*10+(c-'0');
//         x=x*f;
//     }
//     inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
//     inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
//     template<class T> void pi(T x,char c='\n'){
//         if(x<0)pc('-'),x=-x;
//         if(x==0) pc('0'); int t=0;
//         for(;x;x/=10) p[++t]=x%10+'0';
//         for(;t;--t) pc(p[t]); pc(c);
//     }
//     struct F{~F(){flush();}}f; 
// }
// using IO::gi;
// using IO::pi;
// using IO::pc;
// const int mod=998244353;
// const int inv2=(mod+1)>>1;
// const int Groot=3;
// inline int add(int x,int y){
//     return x+y>=mod?x+y-mod:x+y;
// }
// inline int dec(int x,int y){
//     return x-y<0?x-y+mod:x-y;
// }
// inline int mul(int x,int y){
//     return 1ll*x*y%mod;
// }
// inline int qkpow(int a,LL b){
//     if(b<0)return 0;
//     int ans=1,base=a%mod;
//     while(b){
//         if(b&1)ans=1ll*ans*base%mod;
//         base=1ll*base*base%mod;
//         b>>=1;
//     }
//     return ans;
// }
// int fac[1000005],inv[1000005],Invn[1000005];
// inline int binom(int n,int m){
//     if(n<m||m<0||n<0)return 0;
//     return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
// }
// void init_C(int n){
//     fac[0]=1;
//     for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod; 
//     inv[0]=1;
//     inv[n]=qkpow(fac[n],mod-2);
//     for(int i=n-1;i>=1;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
//     Invn[0]=1;
//     for(int i=1;i<=n;i++)Invn[i]=1ll*inv[i]*fac[i-1]%mod;
// }
// struct Card{
// 	int cost,race,effect,idx;
// };
// int n,K;
// vector<Card>cards;
// vector<vector<int>>ans;
// bool fl;
// inline bool checkit(const Card& card,int now,const vector<int>& cr,int rm,const set<int>& lr) {
//     switch(card.effect){
//         case 1: 
//             return !cr.empty(); 
//         case 2:
//             if(!now) return 0;
//             return lr.count(card.race)>0;
//         case 3:
//             return card.cost==rm;
//         default:
//             return 0;
//     }
// }
// inline void dfs(int now,int rm,vector<bool>& used,vector<vector<int>>& rd,vector<int>& cr,const set<int>& lr) {
//     if (fl)return;
//     if (rd.size()+(cr.empty()?0:1)<=K){
//         bool pd = true;
//         for(bool u:used){
//             if(!u){
//                 pd=0;
//                 break;
//             }
//         }
//         if(pd){
//             fl=1;
//             ans=rd;
//             if(!cr.empty()) 
//                 ans.push_back(cr);
//             return;
//         }
//     }
//     if(rd.size()>=K)return;
//     if(!cr.empty()){
//         set<int> ccr;
//         for (int idx:cr) 
//             ccr.insert(cards[idx].race);
//         rd.push_back(cr);
//         vector<int> ncr;
//         dfs(now+1,10,used,rd,ncr,ccr);
//         rd.pop_back();
//         if(fl)return;
//     }
//     for(int i=0;i<n;i++){
//         if(used[i])continue;
//         if(cards[i].cost>rm) continue;
//         if(!checkit(cards[i],now,cr,rm,lr))continue;
//         used[i]=1;
//         cr.push_back(i);
//         dfs(now,rm-cards[i].cost,used,rd,cr,lr);
//         cr.pop_back();
//         used[i]=0;
//         if(fl)return;
//     }
// }
// inline void solve(){
// 	gi(n),gi(K);
// 	for(int i=0;i<n;i++){
// 		int x,y,z;
// 		gi(x),gi(y),gi(z);
// 		cards.push_back(Card{x,y,z,i});
// 	}
//     vector<bool>used(n,0);
//     vector<vector<int>>rd;
//     vector<int>cr;
//     set<int> lr;
//     dfs(0,10,used,rd,cr,lr);
//     if(fl){
//     	cout<<ans.size()<<endl;
//     	for(auto S:ans){
//     		for(auto Idx:S)cout<<Idx+1<<" ";
//     		cout<<endl;
// 		}
// 	}else cout<<-1<<endl;


// }
// /*
// 10->4
// */
// signed main(){
//     cin.tie(0)->sync_with_stdio(0);
//     srand(time(0));
//     init_C(100000);
//     int t=1;
//   //  cin>>t;
//     while(t--)solve();
//     return 0;
// }
// /*

// */



// vector<vector<int>> ans ; 

// bool checkSingleCard( int i , int remVal , unordered_set<int>& lstknd ) {

//     int knd = ifo[i].knd ; 
//     int eff = ifo[i].eff ; 
//     int cost = ifo[i].cost ; 

    

//     if ( eff == 1 ) {

//         return remVal < 10 ; 

//     } else if ( eff == 2 ) {

//         return lstknd.count( knd ) ;
        
//     } else {

//         return remVal == cost ;

//     }
// }

// // 有没有情况是 非贪心的 , 比如说 这一轮加不进去 你返回了 false , 但是其实新开一轮就能加的进去了
// // 这张卡牌可以是效果是 3 吗 , 可以 , 他的消耗等于 10 就可以
// // 这张卡牌可以是效果是 2 吗 ? 只要值够就可以
// // 这张卡牌可以是效果是 1 吗 ? 不可以
// // 所以应该是只要检测到值不够了 , 就应该新开一个回合  

// bool check( vector<int> permutation ) {
//     // 还没用当前卡牌的情况下 还剩下多少体力
//     int cnt_turn ; 
//     int remVal = 10 ; 
//     unordered_set<int> lstknd ; 
//     vector<int> turn ;
//     for ( int i = 1 ; i <= n ; i ++ ) { 

//         if ( remVal - ifo[i].cost < 0 ) { 
//             remVal = 10 ; 
//             lstknd.clear() ; 
//             for ( auto &a : ans.back() ) {
//                 lstknd.insert( ifo[a].knd ) ;
//             }
//             ans.push_back( turn ) ;
//             turn.clear() ;
//         }

//         if ( checkSingleCard(i , remVal) ) turn.push_back( i ) ; 
//         else return false ; 

//     }

//     return ans.size() <= k ;

// }

// bool check( vector<int> permutation ) {
//     ans.clear() ;  // ✅ 应该加上这句！
    
//     int remVal = 10 ; 
//     unordered_set<int> lstknd ; 
//     vector<int> turn ;
    
//     for ( int i = 1 ; i <= n ; i ++ ) { 
//         // 情况1：费用不够，结束回合
//         if ( remVal - ifo[permutation[i]].cost < 0 ) { 
//             // if (turn.empty()) return false ;  // ✅ 空回合费用还不够，无解
            
//             // 收集当前回合的种族 ✅ 先收集 turn 的种族
//             lstknd.clear() ; 
//             for ( auto &a : turn ) {
//                 lstknd.insert( ifo[a].knd ) ;
//             }
//             // 保存当前回合 ✅ 正确顺序
//             ans.push_back( turn ) ;
            
//             // 重置
//             turn.clear() ;
//             remVal = 10 ;
//         }
        
//         // 检查能否使用
//         if ( checkSingleCard(permutation[i] , remVal ,lstknd ) ) {
//             // 使用卡牌
//             turn.push_back( permutation[i] ) ; 
//             remVal -= ifo[permutation[i]].cost ;  // ✅ 记得扣费！
//         } else {
//             return false ;  // ❌ 这里有问题！
//         }
//     }
    
//     // 处理最后一回合 ✅
//     ans.push_back( turn ) ; 
//     return ans.size() <= k ;
// }

// 有没有情况是 非贪心的 , 比如说 这一轮加不进去 你返回了 false , 但是其实新开一轮就能加的进去了
// 这张卡牌可以是效果是 3 吗 , 可以 , 他的消耗等于 10 就可以
// 这张卡牌可以是效果是 2 吗 ? 只要值够就可以
// 这张卡牌可以是效果是 1 吗 ? 不可以
// 所以应该是只要检测到值不够了 , 就应该新开一个回合  

// bool check(vector<int> permutation) {
//     ans.clear() ;  // 清空全局ans
    
//     int remVal = 10 ; 
//     unordered_set<int> lstknd ; 
//     vector<int> turn ;
    
//     for (int i = 1; i <= n; i++) {
//         int cardIdx = permutation[i] ;
//         int cardCost = ifo[cardIdx].cost ;
        
//         // 情况1：费用不够，必须结束当前回合
//         if (cardCost > remVal) {
//             // 如果当前回合是空的，费用还不够 → 无解
//             if (turn.empty()) return false ;
            
//             // 修改2：正确收集当前回合的种族
//             unordered_set<int> curRaces ;
//             for (int idx : turn) {
//                 curRaces.insert(ifo[idx].knd) ;
//             }
            
//             // 保存当前回合
//             ans.push_back(turn) ;
            
//             // 更新给下一回合用的种族集合
//             lstknd = curRaces ;
            
//             // 重置状态
//             turn.clear() ;
//             remVal = 10 ;
            
//             // 重新检查费用（万一卡牌费用>10）
//             if (cardCost > remVal) return false ;
//         }
        
//         // 检查这张卡能否使用
//         // 修改3：传递是否是第一回合
//         bool isFirstTurn = ans.empty() ;  // ans为空说明这是第一回合
//         bool canUse = checkSingleCard(cardIdx, remVal, lstknd, isFirstTurn) ;
        
//         // 情况2：不能用但可能结束当前回合后能用
//         if (!canUse) {
//             // 如果当前回合是空的，结束回合也没用
//             if (turn.empty()) return false ;
            
//             // 结束当前回合（即使费用还够）
//             unordered_set<int> curRaces ;
//             for (int idx : turn) {
//                 curRaces.insert(ifo[idx].knd) ;
//             }
            
//             ans.push_back(turn) ;
//             lstknd = curRaces ;
//             turn.clear() ;
//             remVal = 10 ;
            
//             // 重新检查（现在肯定不是第一回合了）
//             canUse = checkSingleCard(cardIdx, remVal, lstknd, false) ;
//             if (!canUse) return false ;
//         }
        
//         // 使用这张卡
//         turn.push_back(cardIdx) ;
//         remVal -= cardCost ;
//     }
    
//     // 处理最后一回合
//     if (!turn.empty()) {
//         ans.push_back(turn) ;
//     }
    
//     return ans.size() <= k ;
// }                 





// #include <bits/stdc++.h> 
// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int mod = 1e9 + 7 ;
// const int maxn = 2e5 ; 

// int n , k ; 

// struct infor { int cost ; int knd ; int eff ; } ;
// vector<infor> ifo ; 
// vector<vector<int>> ans ; 

// // 修改1：添加参数判断是否是第一回合
// bool checkSingleCard(int i, int remVal, unordered_set<int>& lstknd, bool isFirstTurn) {
//     int knd = ifo[i].knd ; 
//     int eff = ifo[i].eff ; 
//     int cost = ifo[i].cost ; 

//     if (eff == 1) {
//         return remVal < 10 ;  // 本回合已花费过法力值
//     } else if (eff == 2) {
//         // 修改：不是第一回合且种族匹配
//         return !isFirstTurn && lstknd.count(knd);
//     } else {
//         return remVal == cost ;
//     }
// }

// bool check(vector<int> permutation) {
//     ans.clear() ;  // 清空全局ans
    
//     int remVal = 10 ; 
//     unordered_set<int> lstknd ; 
//     vector<int> turn ;
    
//     for (int i = 1; i <= n; i++) {
//         int cardIdx = permutation[i] ;
//         int cardCost = ifo[cardIdx].cost ;
        
//         // 情况1：费用不够，必须结束当前回合
//         if (cardCost > remVal) {
//             // 如果当前回合是空的，费用还不够 → 无解
//             if (turn.empty()) return false ;
            
//             // 修改2：正确收集当前回合的种族
//             unordered_set<int> curRaces ;
//             for (int idx : turn) {
//                 curRaces.insert(ifo[idx].knd) ;
//             }
            
//             // 保存当前回合
//             ans.push_back(turn) ;
            
//             // 更新给下一回合用的种族集合
//             lstknd = curRaces ;
            
//             // 重置状态
//             turn.clear() ;
//             remVal = 10 ;
            
//             // 重新检查费用（万一卡牌费用>10）
//             if (cardCost > remVal) return false ;
//         }
        
//         // 检查这张卡能否使用
//         // 修改3：传递是否是第一回合
//         bool isFirstTurn = ans.empty() ;  // ans为空说明这是第一回合
//         bool canUse = checkSingleCard(cardIdx, remVal, lstknd, isFirstTurn) ;
        
//         // 情况2：不能用但可能结束当前回合后能用
//         if (!canUse) {
//             // 如果当前回合是空的，结束回合也没用
//             if (turn.empty()) return false ;
            
//             // 结束当前回合（即使费用还够）
//             unordered_set<int> curRaces ;
//             for (int idx : turn) {
//                 curRaces.insert(ifo[idx].knd) ;
//             }
            
//             ans.push_back(turn) ;
//             lstknd = curRaces ;
//             turn.clear() ;
//             remVal = 10 ;
            
//             // 重新检查（现在肯定不是第一回合了）
//             canUse = checkSingleCard(cardIdx, remVal, lstknd, false) ;
//             if (!canUse) return false ;
//         }
        
//         // 使用这张卡
//         turn.push_back(cardIdx) ;
//         remVal -= cardCost ;
//     }
    
//     // 处理最后一回合
//     if (!turn.empty()) {
//         ans.push_back(turn) ;
//     }
    
//     return ans.size() <= k ;
// }

// void solve() {
//     cin >> n >> k ; 
    
//     ifo.resize(n + 1) ;
    
//     for (int i = 1; i <= n; i++) {
//         cin >> ifo[i].cost >> ifo[i].knd >> ifo[i].eff ; 
//     }
    
//     vector<int> permutation(1) ; 
    
//     for(int i = 1; i <= n; i++) {
//         permutation.push_back(i) ; 
//     }
    
//     // 修改4：先检查初始排列
//     if (check(permutation)) {
//         cout << ans.size() << endl ; 
//         for (auto &row : ans) {
//             for (auto &a : row) {
//                 cout << a << ' ' ;
//             }
//             cout << endl ;  
//         }
//         return ;
//     }
    
//     while(next_permutation(permutation.begin() + 1, permutation.end())) {
//         if (check(permutation)) {
//             cout << ans.size() << endl ; 
//             for (auto &row : ans) {
//                 for (auto &a : row) {
//                     cout << a << ' ' ;
//                 }
//                 cout << endl ;  
//             }
//             return ; 
//         }
//     }
    
//     cout << -1 << endl ; 
// }

// signed main() {
//     solve() ; 
//     return 0 ; 
// }

//  @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 

int n , k ; 

struct infor { int cost ; int knd ; int eff ; } ;
vector<infor> ifo ; 
vector<vector<int>> ans ; 

// 题解是把check单独再拆出来写 写DFS , 要简洁很多
// 看来我那个分治的思想还是要加强加强
// 像我那个也可以接着拆 先验证合法性
// 然后在根据 remval 出一遍答案就简单很多

bool checkSingleCard( int i , int remVal , unordered_set<int>& lstknd ) {

    int knd = ifo[i].knd ; 
    int eff = ifo[i].eff ; 
    int cost = ifo[i].cost ; 

    

    if ( eff == 1 ) {

        return remVal < 10 ; 

    } else if ( eff == 2 ) {

        return !ans.empty() && lstknd.count( knd ) ;
        
    } else {

        return remVal == cost ;

    }
}



bool check( vector<int> permutation ) {

    ans.clear() ; 

    // 还没用当前卡牌的情况下 还剩下多少体力
    int cnt_turn ; 
    int remVal = 10 ; 
    unordered_set<int> lstknd ; 
    vector<int> turn ;
    for ( int i = 1 ; i <= n ; i ++ ) { 

        if ( remVal - ifo[permutation[i]].cost < 0 ) { 
            if (turn.empty()) return false ;
            remVal = 10 ; 
            lstknd.clear() ; 
            for ( auto &a : turn ) {
                lstknd.insert( ifo[a].knd ) ;
            }
            ans.push_back( turn ) ;
            turn.clear() ;
        }

        if ( checkSingleCard(permutation[i] , remVal ,lstknd ) ) turn.push_back( permutation[i] ) , remVal -= ifo[permutation[i]].cost ; 
        else return false ; 

    }

    ans.push_back( turn ) ; 
    return ans.size() <= k ;

}

void solve() {

    cin >> n >> k ; 

    ifo.resize( n + 1 ) ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> ifo[i].cost >> ifo[i].knd >> ifo[i].eff ; 
    }

    vector<int> permutation(1) ; 

    for( int i = 1 ; i <= n ; i ++ ) {
        permutation.push_back( i ) ; 
    }

    if ( check(permutation) ) {
        cout << ans.size() << endl ; 
        for ( auto &row : ans ) {
            for ( auto &a : row ) {
                cout << a << ' ' ;
            }
            cout << endl ;  
        }
        return ;
    }

    while( std :: next_permutation( permutation.begin() + 1 , permutation.end())  ) {
        if ( check(permutation) ) {
            cout << ans.size() << endl ; 
            for ( auto &row : ans ) {
                for ( auto &a : row ) {
                    cout << a << ' ' ;
                }
                cout << endl ;  
            } 
            return ; 
        }
    }


    cout << -1 << endl ; 

}

signed main() {


    solve() ; 


    return 0 ; 
} 