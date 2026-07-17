// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n, block; 
vector<int> vec, tag, sum; 

int begin(int i) {return (i - 1) * block + 1;}
int end(int i) {return min(i * block, n);}
int blk(int i) {return (i - 1) / block + 1;}
int sz(int i) {return end(i) - begin(i) + 1;}

void init() {
  vec.assign(n + 1, 0);
  sum.assign(n + 1, 0);
  tag.assign(n + 1, 0);
  block = sqrt(n);
}

void update(int l, int r, int val) {
  int bl = blk(l), br = blk(r);
  if (bl == br) {
    for(int i = l; i <= r; i ++) sum[bl] += val, vec[i] += val;
    return; 
  }

  for(int i = l; i <= end(bl); i ++) vec[i] += val, sum[bl] += val; 
  for(int i = bl + 1; i < br; i ++) tag[i] += val, sum[i] += val * sz(i);
  for(int i = begin(br); i <= r; i ++) vec[i] += val, sum[br] += val; 
}

int query(int l, int r) {
  int res = 0;
  int bl = blk(l), br = blk(r);
  if (bl == br) {    
    for(int i = l; i <= r; i ++) res += vec[i] + tag[bl];
    return res; 
  }  
  
  for(int i = l; i <= end(bl); i ++) res = res + vec[i] + tag[bl];
  for(int i = bl + 1; i < br; i ++) res = res + sum[i];
  for(int i = begin(br); i <= r; i ++) res = res + vec[i] + tag[br];
  return res;
}

void solve() { 

  cin >> n; init();
  for(int i = 1; i <= n; i ++) cin >> vec[i];
  for(int i = 1; i <= (n + block - 1) / block; i ++) {
    sum[i] = accumulate(vec.begin() + begin(i), vec.begin() + end(i) + 1, 0LL);
  }
  for(int i = 1; i <= n; i ++) {
    int op, l, r, c; cin >> op >> l >> r >> c;
    if (op == 0) {
      update(l, r, c);
    } else {
      cout << query(l, r) << endl; 
    }
  }
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt;
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}