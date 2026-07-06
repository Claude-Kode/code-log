#include <bits/stdc++.h>
using namespace std ; 

#define int long long 
#define endl '\n' 

string cal_t( int t ) {
    string ss = to_string(t % 60) ; 
    if (ss.size() == 1) ss = '0' + ss ; 
    t -= stoll(ss) ; t /= 60 ; 
    string mm = to_string(t % 60) ; 
    if ( mm.size() == 1) mm = '0' + mm ;
    t -= stoll(mm) ; t /= 60 ; 
    string hh = to_string(t % 60) ; 
    if ( hh.size() == 1 ) hh = '0' + hh ; 

    return (hh + ':' + mm + ':' + ss) ; 
}

void solve() {

    // cout << cal_t(6666) << endl ; 

    int a , b ; cin >> a >> b ; 
    int ans = a + b ; 
    int x = 0 , t = -1 ; 
    bool ac = false ; 

    int lx = 0 ; string lt = "" ; 
    while ( cin >> x ) {
        t += 2 ;

        string time = cal_t(t) ; 

        if ( x == ans && !ac ) {
            cout << x << ' ' << "Accepted" << ' ' << time << endl ; 
            ac = true ; 
        }

        if ( t <= 10800 && !ac ) {
            lx = x ; lt = time ; 
        }

    }

    if ( !ac ) {
        cout << lx << ' ' << "Wrong Answer" << ' ' << lt << endl ; 
    } 

}

signed main() {

    ios::sync_with_stdio(false) ; 
    cin.tie(nullptr) ; 
    cout.tie(nullptr) ; 

    solve()  ;
    
    return 0 ; 
}