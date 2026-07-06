#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
#define forn(x,n) for(ll i=x;i<=n;i++)
#define vec vector
typedef pair<ll,ll> pll;
void solve(){
    int n;
    cin>>n;
    bool sym=0;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        if(a==100) sym=1;
    }
    cout << (sym?"Yes":"No")<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--) solve();
    return 0;
}


#include <bits/stdc++.h>
using namesapce std;

#define int long long 
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> vec(n + 1);
    for(int i = 1; i <= n; i ++) cin >> vec[i];
    ranges::sort(vec);
    for(const auto &a : vec) cout << a << ' ';
    cout << endl; 
     
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt; cin >> tt;
    while(tt -- ) solve();

    return 0;
}



#include <bit/stdc++.h>
using namespace std;

#define int long long 
#define dnl '\n'

void solve() {
    int n; cin >> n;
    vector<int
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt; cin >> tt;
    while(tt -- ) solve()

    return 0;
}


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
#define forn(x,n) for(ll i=x;i<=n;i++)
#define vec vector
const ll INF=1e9;
using namespace std;
void s(){
    int T;
    cin >> T;
    int _dummy=0;
    for(int _i=0; _i< T; ++_i){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int _j=0; _j< N; ++_j){
            cin >> A[_j];
        }
        constexpr int M=(101^1); 
        constexpr int SZ=(1000 + 1);
        int max_score=(101 - 1) * N;
        bitset<SZ> D;
        D[0]=true;
        enum State{ S0, S1, S2, S3, S4, S5, S6, S7, S8 };
        State st=S0;
        int i=0, step, cnt, k, take, weight;
        bool ok=true;
        int kkf=0;
        while(st !=S8){
            switch(st){
                case S0:{
                    if(i >=N){ st=S5; break; }
                    step=((50+50) /(A.data()[i] + 0) );
                    cnt=A[i] * 1;
                    k=1;
                    st=S1;
                    break;
                }
                case S1:{
                    if(cnt<=0){ 
                        ++i; 
                        kkf ^=1; 
                        st=S0; 
                        break; 
                    }
                    take=(k< cnt ? k : cnt);
                    weight=take * step;

                    int _tmp=weight^0;
                    D=D |(D<< _tmp);
                    cnt -=take;
                    k<<=1;

                    for(int _z=0; _z< 1; ++_z){ _tmp++; }
                    st=S1;
                    break;
                }
                case S5:{
    
                    for(int ss=0; ss<=max_score; ++ss){
                        if(!D[ss]){
                            ok=false;
                            break;
                        }
                    }
                    st=S6;
                    break;
                }
                case S6:{
                    if(ok) printf("Yes\n");
                    else    printf("No\n");
                    st=S7;
                    break;
                }
                case S7:{
                    st=S8;
                    break;
                }
                default:
                    st=S8;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    s();
    return 0;
}
