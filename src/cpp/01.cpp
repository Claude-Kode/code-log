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
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  s=" "+s;
  int g=__gcd(n,k);
  int l=1,r=n;
  while(l<=r){
    if(s[l]==s[r]){
      l++,r--;
    }else{
      if(l+g<r){
        if(s[l+g]=='1')s[l+g]='0';
        else s[l+g]='1';
      }else{
        cout<<"NO"<<"\n";
        return;
      }
      l++,r--;
    }
  }
  cout<<"YES"<<"\n";
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}