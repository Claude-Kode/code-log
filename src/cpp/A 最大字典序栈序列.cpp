// //#include <bits/stdc++.h>
// //
// //using namespace std ; 
// //
// //#define int long long 
// //#define endl '\n'
// //
// //const int maxn = 1e9 ;
// //const int mod = 1e9 + 7 ; 
// //
// //void solve() {
// //	
// //	
// //	
// //}
// //
// //signed main() {
// //	
// //	int tt ; cin >> tt ; 
// //	while ( tt -- ) {
// //	
// //		int n ; cin >> n ; 
// //		vector<int> arr( n ) ;
// //        for ( auto &a : arr ) {
// //            cin >> a ; 
// //        }
// //		vector<int> ans ;
// //		unordered_map<int , int> beenUsed ; 
// //        unordered_map<int , int> bu ; 
// //        stack<int> st ; 
// //		int cnt = 0 ; 
// //		int preMxPos = 0 ; 
// //		while ( preMxPos < n - 1 ) {
// //			int mx = INT_MIN , curMxPos ; 
// //			for ( int i = preMxPos + 1 ; i < n ; i ++ ) {
// //				if ( mx < arr[i] && !beenUsed[i] ) {
// //					mx = arr[i] ; 
// //					curMxPos = i ; 
// //				}
// //			}
// //			beenUsed[mx] = 1 ; 
// //			preMxPos = curMxPos ; 
// //			ans.push_back( mx ) ; 
// //            
// //            for ( int i = curMxPos - 1 ; i >= 0 ; i -- ) {
// //            	if ( arr[i + 1] - arr[i] == 1 ) {
// //            		ans.push_back( arr[i] ) ; 
// //					beenUsed[arr[i]] = 1 ;          		
// //				}
// //			}
// //    
// //		}
// //		
// //		for ( int i = n - 1 ; i >= 0 ; i -- ) {
// //			if ( !beenUsed[arr[i]] ) {
// //				ans.push_back( arr[i] ) ;
// //			}
// //		}
// //		
// //		for ( int i = 0 ; i < n ; i ++ ) {
// //			cout << ans[i] << ' ' ;
// //		}                           
// //		 
// //		cout << endl ; 
// //		
// //	}
// //	
// //	return 0 ; 	
// //		
// //}






// #include <bits/stdc++.h>

// using namespace std ; 

// #define int long long 
// #define endl '\n'

// const int maxn = 1e9 ;
// const int mod = 1e9 + 7 ; 

// void solve() {
	
	
	
// }

// signed main() {
	
// 	int tt ; cin >> tt ; 
// 	while ( tt -- ) {
	
// 		int n ; cin >> n ; 
// 		vector<int> arr( n ) , ans ; 
// 		for ( auto &a : arr ) {
// 			cin >> a ;
// 		}
		
// 		unordered_map<int , int> beenUsed ; 
		
// 		int prep = 0 ;
// 		while ( prep < n - 1 ) {
// 			int mx = INT_MIN , curp = 0 ; 
// 			for ( int i = prep ; i < n ; i ++ ) {
// 				if ( mx < arr[i] ) {
// 					curp = i ; 
// 					mx = arr[i] ; 
// 				}
// 			}
			
// 			ans.push_back( mx ) ; 
// 			beenUsed[mx] = 1 ; 
// 			prep = curp + 1 ; 
			
// 			for ( int i = curp - 1 ; i >= 0 ; i -- ) {
// 				if ( arr[i] + 1 == arr[i + 1] ) {
// 					ans.push_back( arr[i] ) ;
// 					beenUsed[arr[i]] = 1 ;
// 				} 
//                 else {
//                     break ; 
//                 }
// 			}
			
// 		}
	
// 		for ( int i = n - 1 ; i >= 0 ; i -- ) {
// 			if ( !beenUsed[arr[i]] ) 
// 				ans.push_back( arr[i] ) ;
// 		}
		
// 		for ( int i = 0 ; i < n ; i ++ ) {
// 			cout << ans[i] << ' ' ;
// 		}	
	
// 		cout << endl ; 
	
// 	}
	
// 	return 0 ; 
// }


#include<bits/stdc++.h>

using namespace std;
typedef long long int;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > a(n);
        int _max = n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        stack < int > ans;
        vector < int > ak(n);
        vector<bool> am(n+1,false);
        vector<int> acm(n);
        acm[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            acm[i]=max(acm[i+1],a[i]);
        }
        int o = 0;
        int ok=n;
        for (int i = 0; i < n; i++) {
            if (a[i] == _max) {
                ak[o] = a[i];
                o++;
                am[a[i]]=1;
                continue;
            }
            if (o != 0) {
                while (!ans.empty()) {
                    if (ans.top() < a[i]) {
                        break;
                    }
                    if(acm[i]>ans.top()) break;
                    ak[o] = ans.top();
                    o++;
                    ans.pop();
                }
                ans.push(a[i]);
            } else {
                am[a[i]]=1;
                ans.push(a[i]);
            }
        }
        while (!ans.empty()) {
            ak[o] = ans.top();
            o++;
            ans.pop();
        }
        for (int i = 0; i < o; i++) cout << ak[i] << " ";
        cout << '\n';
    }
}

/**
* @runId: 578948
* @language: C++ 20 With O2
* @author: 取名字好难
* @submitTime: 2025-12-28
*/