#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

mt19937 rng(time(0));

int rn(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

void p(int l, int r, vector<int>& vec) {
	iota(vec.begin() + 1, vec.end(), 1LL);
	shuffle(vec.begin() + 1, vec.end(), rng);
} 

void solve(){
  int n = 3e5, m = 3e5;
  cout << n << ' ' << m << "\n";
  for (int i = 1; i <= n; i ++) {
    cout << rn(0, 1e9) << " \n"[i == n];;
  }

  for (int i = 1; i <= m; i ++) {
    int c = rn(0, 2);
    // int c = 1;
    int x = rn(1, 1e9);
    cout << c << ' ' << x << "\n";
  }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();

	return 0;
}