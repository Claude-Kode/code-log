#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
using db=long double;
using lll = __int128;
ll a[400009];
bool cmp(ll x,ll y){
  return x>y;
}
ll b[400009];
db e[400009];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
ll tt=1;//cin>>tt;
  while (tt--) {
ll n,c,k;cin>>n>>c>>k;
for(ll i=1;i<=n;i++)
{
  cin>>a[i];
}
sort(a+1,a+n+1,cmp);
for(ll i=1;i<=n;i++){b[i]=b[i-1]+a[i];}
e[400001]=0;
ll p=n+1;
for(ll i=400000;i>=0;i--)
{
if(a[n]>=e[i+1]){
  e[i]=(db)b[p-1]/(db)n-(db)c-(db)i*k;
}
else{
while(p>1&&(db)a[p-1]<e[i+1]){
  p--;
}
e[i]=(db)(n-p+1)*(db)e[i+1]/(db)n+(db)b[p-1]/(db)n-(db)c-(db)i*k;
}
}
//cout<<p<<" ";
printf("%.10Lf\n",e[0]);
  }

  return 0;
}