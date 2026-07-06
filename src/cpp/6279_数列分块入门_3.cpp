// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n, block;
vector<int> vec, tag;
vector<vector<int>> sorted;

int begin(int blk) {return (blk - 1) * block + 1;}
int end(int blk) {return min(blk * block, n);}
int to(int i) {return (i - 1) / block + 1;}

void init(){
  vec.assign(n + 1, 0);
  tag.assign(n + 1, 0);
  sorted.assign(n + 1, {});
  block = sqrt(n);
}

void reset(int blk) {
  sorted[blk].clear();
  for(int i = begin(blk); i <= end(blk); i ++) sorted[blk].push_back(vec[i]);
  sort(sorted[blk].begin(), sorted[blk].end());
} 

void update(int l, int r, int val) {
  int bl = to(l), br = to(r);
  if (bl == br) {
    for(int i = l; i <= r; i ++) vec[i] += val;
    reset(bl); return; 
  }

  for(int i = l; i <= end(bl); i ++) vec[i] += val;
  for(int i = bl + 1; i < br; i ++) tag[i] += val;
  for(int i = begin(br); i <= r; i ++) vec[i] += val;
  reset(bl); reset(br);
}

int query(int l, int r, int c) {
  int bl = to(l), br = to(r), res = -1, t = c;
  if (bl == br) {
    for(int i = l; i <= r; i ++) if (vec[i] + tag[to(i)] < t) res = max(res, vec[i] + tag[to(i)]);
    // cout << 1 << endl; 
    return res;
  }

  for(int i = l; i <= end(bl); i ++) if (vec[i] + tag[to(i)] < t) res = max(res, vec[i] + tag[to(i)]);
  for(int i = bl + 1; i < br; i ++) {
    auto it = lower_bound(sorted[i].begin(), sorted[i].end(), t - tag[i]);
    if (it != sorted[i].begin()) res = max(res, *--it + tag[i]);
  }
  for(int i = begin(br); i <= r; i ++) if (vec[i] + tag[to(i)] < t) res = max(res, vec[i] + tag[to(i)]);

  return res;
}

void solve() { 

  cin >> n; init();
  for(int i = 1; i <= n ; i++) cin >> vec[i];
  for(int i = 1; i <= to(n); i ++) reset(i); 
  for(int i = 1; i <= n ; i ++) {
    int op, l, r, c; cin >> op >> l >> r >> c;
    if (op == 0) {
      update(l, r, c);
    } else {
      cout << query(l, r, c) << endl; 
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