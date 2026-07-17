// @Author : GoryK  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

void solve() { 
  int n, k; cin >> n >> k;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= n - k - 2; i ++) {
    int a;
    cin >> a;
    int foot = i + k + 2;
    adj[foot].push_back(a);
    adj[a].push_back(foot);
  }

  vector<int> ans(n + 1), vis(n + 1, 0); 
  int val = n - 1;
  auto calc = [&](int base, int x) -> int {
    if (base + x >= 1 && base + x <= n && !vis[base + x]) return base + x;
    else return base - x;
  };

  ans[1] = 1; vis[1] = 1;
  // for(int i = 2; i <= n; i ++) {
  //   cout << ans[i - 1] << ' ' << val << endl;
  //   ans[i] = calc(ans[i - 1], val--);
  // }
  for(int i = 2; i <= k + 2; i ++) {
    int v = calc(ans[i - 1], val--);
    ans[i] = v; 
    vis[v] = 1;
    for(const auto &j : adj[i]) if (abs(j - i) > 1) { 
      // cout << i << ' '<< j << endl;
      int v = calc(ans[i], val--); 
      // dbug(v);
      ans[j] = v; 
      vis[v] = 1;
    }
  }

  // assert(val > -1);
  for(int i = 1; i <= n; i ++) {
    // cout << i << ' ' << ans[i] << endl;
    cout << ans[i] << " \n"[i == n];
  }
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false); 
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
void solve(){
    vector<vector<int>>a(4,vector<int>(4));
    const int N=1e6+1;
    vector<int>f(N),pre(N);
    f[1]=1,f[2]=1,pre[1]=0,pre[2]=0;
    for(int i=3;i<=N-1;i++){
        f[i]=f[i-1]+f[i-2];
        f[i]%=mod;
        pre[i]=pre[i-1]+pre[i-2]+f[i];
        pre[i]%=mod;
    }
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>a[i][j];
            ans+=pre[a[i][j]];
            ans%=mod;
        }
    }
    cout<<ans;
}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}