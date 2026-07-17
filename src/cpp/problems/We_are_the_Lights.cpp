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

int n, m, k;

int to(string op) {return op == "on";}

void solve() { 
  cin >> n >> m >> k;
  vector<int> row(n + 1);
  vector<int> col(m + 1);

  for(int i = 1; i <= k; i ++) {
    string temp,  op;  int num;
    cin >> temp >> num >> op;
    if (temp == "row") {
      row[num] = to(op);
    } else {
      col[num] = to(op);
    }
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