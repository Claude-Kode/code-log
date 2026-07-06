// @Author : GoryK 
// @Description : TEMPLATE-2 
#include <bits/stdc++.h> 

using namespace std ; 

#define int long long 
#define endl '\n'

const int mod = 1e9 + 7 ;
const int maxn = 2e5 ; 


// 就是最小值不能相等 , 任何一个区间都是
// 排序后的任何一个区间都不能是最小值相同的
// 这题我觉得是类似搜索的枚举写出来的我试试看

void solve() {

    int n ; cin >> n ;
    vector<int> arr( n + 1 ) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; 
    }

    sort( arr.begin() + 1 , arr.end() ) ; 

    vector<int> mex1(n + 1) , buckle1(n + 1) ; 
    for ( int i = 1 ; i <= n ; i ++ ) {
        buckle1[arr[i]] ++ ; 
        for ( int j = 0 ; j <= i ; j ++ ) if ( buckle1[j] == 0 ) {
            mex1[i] = j ; 
            break ; 
        }
    }

    vector<int> mex2(n + 1) , buckle2(n + 1) ; 
    for ( int i = n ; i > 0 ; i -- ) {
        buckle2[arr[i]] ++ ; 
        for ( int j = 0 ; j <= 100 ; j ++ ) if ( buckle2[j] == 0 ) {
            mex2[i] = j ; 
            break ; 
        }
    }

    if ( mex1[n / 2] == mex2[n / 2 + 1] ) { cout << "NO" << endl ; return ; }

    cout << "YES" << endl ;

}

/*

*/

signed main() {
    std::ios::sync_with_stdio(false) ; std::cin.tie(nullptr) ; std::cout.tie(nullptr) ;

    
    int tt ; cin >> tt ;
    while( tt -- ) solve() ; 


    return 0 ; 
}   

/*
    
*/