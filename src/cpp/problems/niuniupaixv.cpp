#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'

int n ;

vector<int> arr , tree1 , tree2 ;

int lowbit( int i ) {
	return i & -i ; 
}
 
void update( int pos , int val , vector<int>& tree ) {
	for ( int i = pos ; i <= n ; i += lowbit(i) ) {
		tree[i] += val ; 
	} 
}

int query( int pos , vector<int>& tree ) {
	int res = 0  ;
	for ( int i = pos ; i > 0 ; i -= lowbit(i) ) {
		res += tree[i] ;  
	}
	return res ; 
}

void slove() {
	
		
	
}

signed main() {
	
	
	cin >> n ; 
	arr.resize( n + 1 ) ; 
	tree1.resize( 1e5 + 1 ) ; 
	tree2.resize( 1e5 + 1 ) ; 
    
    int res = 0 , sum = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> arr[i] ; sum += arr[i] ; 
        update( arr[i] , arr[i] , tree1 ) ; 
        update( arr[i] , 1 , tree2 ) ; 
        int pre = sum - query( arr[i] , tree1 ) ; 
        int cnt = i - query( arr[i] , tree2 ) ; 
        res += pre + cnt * arr[i] ; 
    }
    
    cout << res << endl ;
    
	return 0 ; 
}