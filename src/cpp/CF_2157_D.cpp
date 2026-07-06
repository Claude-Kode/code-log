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
#include <utility>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

// ========================== Namespace ========================================
using namespace std;
// using namespace ranges;

// ========================== Macro Definitions ================================
#define endl '\n'
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int, int>
#define TUP tuple<int, int, int>

// ========================== Constants ========================================
const int INF = 0x3f3f3f3f3f3f3f3f;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

// ========================== Global Variables / Arrays ========================
struct treenode {
    int val ;
    treenode* pre ;
    treenode* nex ; 

} ;

// ========================== Functions ========================================



// ========================== Idea =============================================
/*

*/
// ========================== Main Function ====================================
signed main() {
    ios_base :: sync_with_stdio( false ) ; cin.tie( NULL ) ; cout.tie( NULL ) ;
    int tt ; cin >> tt ; 
    while ( tt -- ) {
        int n , l , r ; cin >> n >> l >> r ; 
        vector<int> arr ( n + 1 ) ; 
        for ( int i = 1 ; i <= n ; i ++ ) cin >> arr[i] ; 
        sort ( arr.begin() + 1 , arr.end() ) ;
        int mid = 0 ; 
        ( n & 1 ) == 1 ? mid = arr[( n + 1 ) / 2] : mid = ( arr[n / 2] + arr[( n / 2 ) + 1] ) / 2 ;
        if ( mid < l ) mid = l ; 
        if ( mid > r ) mid = r ;
        int ans = 0 ;
        for ( int i = 1 ; i <= n ; i ++ )   
            ans += abs ( arr[i] - mid ) ;
        cout << ans << endl ; 
    }
    return 0 ;
}
// ========================== Question =========================================
/*

*/
// #include <bits/stdc++.h>
// using namespace std;

// long long a[200005];

// void solve() {
// 	long long n,l,r;
// 	cin>>n>>l>>r;
// 	for(int i=1;i<=n;i++) cin>>a[i];
// 	sort(a+1,a+1+n);
// 	long long ans=0;
// 	if(n%2){
// 		int x=a[(n+1)/2];
// 		if(x<l) x=l;
// 		if(x>r) x=r;
// 		for(int i=1;i<=n;i++) ans+=abs(a[i]-x);
// 	}
// 	else{
// 		int x=(a[n/2]+a[(n/2)+1])/2;
// 		if(x<l) x=l;
// 		if(x>r) x=r;
// 		for(int i=1;i<=n;i++) ans+=abs(a[i]-x);
// 	}
// 	cout<<ans<<'\n';
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
	
// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		solve();
// 	}
	
// 	return 0;
// }