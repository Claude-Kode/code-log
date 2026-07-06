//#include <bits/stdc++.h>
//
//using namespace std ; 
//
//#define int long long 
//#define endl '\n'
//#define PII pair<int , int> 
//
//const int maxn = 1e9 ;
//const int mod = 1e9 + 7 ; 
//
//void solve() {
//	
//	
//	
//}
//
//signed main() {
//	
//	int tt ; cin >> tt ; 
//	while ( tt -- ) {
//	
//		int n , m , k ; cin >> n >> m >> k ; 
//		string str ; cin >> str;  
//		int l = 0 , r = 0 ; 
//		int cnt = 0 ;
//		int mn = 0 ; 
//		unordered_map<int , int> ump ; 
//		
//		vector<PII> ans ; 
//		while ( r < n && l < n ) {
//			
//			if ( cnt < m || mn < k ) {
//				r ++ ; 
//				if ( ump[str[r]] == 0 ) {
//					cnt ++ ; 
//				}
//				ump[str[r]] ++ ; 
//				mn = min( mn , ump[str[r]] ) ; 
//			}
//			 
//			else {
//				
//				ans.emplace_back( l , r ) ; 
//                ump[str[l]] -- ; 
//                
//                if ( ump[str[l]] ) {
//                    mn = min ( mn , ump[str[l]] ) ; 
//                } 
//                
//                else {
//                	cnt -- ; 
//				}
//				
//				l ++ ; 
//			}
//			
//		}
//	
//		if ( ans.empty() ) {
//			cout << -1 << endl ;
//			continue ; 
//		}
//			
//		int resl = 0 , resr = 0 , mnl = n ;
//		for ( auto &[l , r] : ans ) {
//			int dis = r - l + 1 ;  
//			if ( mnl > dis ) {
//				mnl = dis ; 
//				resl = l ; 
//				resr = r ; 
//			}
//		}
//		
//		cout << resl << ' ' << resr << endl ; 
//		
//	}
//	
//	return 0 ; 
//}



#include <bits/stdc++.h>

using namespace std ; 

#define int long long 
#define endl '\n'
#define PII pair<int , int> 
const int maxn = 1e9 ;
const int mod = 1e9 + 7 ; 

void solve() {
	
	
	
}

signed main() {
	
	int tt ; cin >> tt ; 
	while ( tt -- ) {
	
		int n , m , k ; cin >> n >> m >> k ; 
		string str ; cin >> str ; 
		vector<PII> ans ; 
		for ( int i = 0 ; i < n - m ; i ++ ) {
			unordered_map<int , int> ump ; 
			for ( int j = i ; j < n ; j ++ ) {
				ump[str[j]] ++ ; 
// 				mn = min( mn , ump[str[j]] ) ;
				if ( ump.size() == m ) {
					int mn = INT_MAX ; 
                    for ( auto &[a , cnt] : ump ) {
                        mn = min ( mn , cnt ) ; 
                    }
                    if ( mn >= k ) {
                        ans.emplace_back( i + 1 , j + 1 ) ; 
//                         cout << i << ' ' << j << endl ; 
                        break ;                       
                    }
				}
			}
		}
	
		if ( ans.empty() ) {
			cout << -1 << endl ;
			continue ; 
		}
	
		int resl , resr , mn = INT_MAX ; 
		for ( auto &[l , r] : ans ) {
			if ( mn > r - l + 1 ) {
				mn = r - l + 1 ; 
				resl = l , resr = r ; 
			}
		}
		
		cout << resl << ' ' << resr << endl ; 
		
	}
	
	return 0 ; 
}