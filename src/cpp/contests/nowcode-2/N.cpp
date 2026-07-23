#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long 

void solve() {
 
}
ll a[2000009];
ll b[2000009];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt = 1;
  cin >> tt;
  while (tt --) {
    solve();
    ll n,k;cin>>n>>k;ll ans=0;
    for(ll i=1;i<=n;i++)
    {cin>>a[i];ans+=a[i];}
    sort(a+1,a+n+1);
    ll x=k/2+1;
    ll sum1=0;
    for(ll i=1;i<=k-x;i++)
    {
sum1+=a[i];
    }
    ll sum2=0;
    for(ll i=k-x+1;i<=k;i++)
    {
sum2+=a[i];
    }
    b[k-x+1]=sum2;
ll mx=0;
for(ll i=k+1;i<=n;i++)
{
sum2-=a[i-x];
sum2+=a[i];
b[i-x+1]=sum2;
}
if(k&1){
for(ll i=k;i<=n;i++)
{
  ll sum3=-sum1-b[i-x+1]+a[i-x+1]*k;
mx=max(mx,sum3);
}
}
else{
for(ll i=k;i<=n;i++)
{
ll sum3=-sum1-b[i-x+1]+(a[i-x+1]+a[i-x+2])*k/2;
mx=max(mx,sum3);
}

}
cout<<ans+mx<<"\n";
for(ll i=1;i<=n;i++){b[i]=0;}
  }
}