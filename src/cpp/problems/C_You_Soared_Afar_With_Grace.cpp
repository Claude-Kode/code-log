// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif 

// #define int int64_t
// #define endl "\n"

// const int mod = 1e9 + 7; 
// const int N = 2e5 + 10;

// void solve() { 
//   int n; cin >> n;
//   vector<int> a(n + 1), b(n + 1);
//   unordered_map<int, int>  ap, bp;
//   for(int i = 1; i <= n; i ++) {
//     cin >> a[i]; ap[a[i]] = i;
//   }

//   for(int i = 1; i <= n; i ++) {
//     cin >> b[i]; bp[b[i]] = i;
//   }

//   int cnt = 0;
//   for(int i = 1; i <= n; i ++) cnt += (a[i] == b[i]);

//   if (cnt >= 2) {cout << -1 << endl; return;}

//   auto inv  = [&](int i) -> int {return n + 1 - i;};
//   auto work = [&](int i, int j) -> void {
//     swap(a[i], a[j]);
//     swap(b[i], b[j]);
//     swap(ap[a[i]], ap[a[j]]);
//     swap(bp[b[i]], bp[b[j]]);
//   };

//   vector<pair<int, int>> ans;
//   for (int i = 1; i <= n; i ++) if (a[i] != b[n + 1 - i]) {
//     int pos1 = bp[a[i]];   
//     int pos2 = n + 1 - i;     
//     ans.push_back({pos1, pos2});
//     work(pos1, pos2);
//   } 

//   cout << ans.size() << endl;
//   for(const auto &[k, v] : ans) {
//     cout << k << ' ' << v << endl;
//   }
// } 

// /*

// */

// signed main() {
  
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   // cout << fixed << setprecision(6);

//   int tt , CNT = 0; cin >> tt; 
//   while(tt -- && ++CNT) 
//     // cout << "TEST CASE : " << CNT << endl,
//     solve();
  
  
//   return 0;
// }


#include <bits/stdc++.h>
using namespace std;

const int maxn = 200100;

int n, a[maxn], b[maxn], m, p[maxn], ans[maxn][2];

inline void work(int x, int y) {
	// if (x == y) {
	// 	return;
	// }
	ans[++m][0] = x;
	ans[m][1] = y;
	swap(a[x], a[y]);
	swap(p[a[x]], p[a[y]]);
	swap(b[x], b[y]);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	m = 0;
	int x = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == b[i]) {
			if (n % 2 == 0 || x) {
				cout << "-1\n";
				return;
			}
			x = i;
		} else if (b[p[b[i]]] != a[i]) {
			cout << "-1\n";
			return;
		}
	}
	// if (n & 1) {
	// 	work(x, (n + 1) / 2);
	// }
	for (int i = 1; i <= n / 2; ++i) {
		work(p[b[i]], n - i + 1);
	}
	cout << m << '\n';
	for (int i = 1; i <= m; ++i) {
		cout << ans[i][0] << ' ' << ans[i][1] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}