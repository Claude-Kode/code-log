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
	int n; cin >> n;
	vector<int> vec(n + 1);

	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	for(int i = 1; i <= n; i ++) {
		int temp; cin >> temp;
		if (pq1.empty() || pq1.top() >= temp)
			pq1.push(temp);
		else 
			pq2.push(temp);

		while(pq1.size() > pq2.size() + 1) {
			pq2.push(pq1.top()); 
			pq1.pop();
		}

		while(pq2.size() > pq1.size() - 1) {
			pq1.push(pq2.top()); 
			pq2.pop();
		}

		if (i & 1) cout << pq1.top() << endl;
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
