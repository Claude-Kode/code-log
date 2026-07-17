// // @Author : GoryK
// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")
// #include <bits/stdc++.h>
// using namespace std;

// #define int int_fast64_t
// #define endl "\n"

// const int mod = 1e9 + 7; 
// const int N = 2e5 + 10;

// void solve() { 



// }

// /*

// */

// signed main() {
  
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
  
//   #ifdef GK
//     freopen("INPUT.txt", "r", stdin);
//     freopen("OUTPUT.txt", "w", stdout);
//   #endif 

//   // cout << fixed << setprecision(6);

//   int tt , CNT = 0; cin >> tt;
//   while(tt -- && ++CNT) 
//     // cout << "TEST CASE : " << CNT << endl,
//     solve();
  
//   return 0;
// }

#include <cstdio>
using namespace std;
int check(long long n, long long b, int p) {
	while (n) {
		long long r = n % b;
		n /= b;
		for (int i = 1; i < p; ++i) {
			if (n % b != r) return 0;
			n /= b;
		}
	}
	return 1;
}
int main(){
	long long n, sum, pow;
	int T, i, j, k, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		if (n <= 2) {
			puts("0");
			continue;
		}
		ans = 1;
		if ((n & 1) == 0 && n >= 8) ans = 2;
		for (i = 3; 1ll * i * i < n; ++i) {
			if (n % i == 0) {
				ans += check(n, i - 1, 2);
				ans += check(n, 1ll * n / i - 1, 2);
			}
		}
		if (1ll * i * i == n) ans += check(n, i - 1, 2);
		for (i = 3; i <= 63; ++i) {
			for (j = 2; j <= 1000000; ++j) {
				sum = pow = 1;
				for (k = 1; k < i; ++k) {
					pow *= j;
					sum += pow;
					if (sum > n) break;
				}
				if (sum > n) break;
				if (n % sum == 0) ans += check(n, j, i);
			}
			if (j == 2) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}