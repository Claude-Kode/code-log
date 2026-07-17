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
vector<int> vec, tag, bel;
vector<vector<int>> sorted;

int begin(int i) {return (i - 1) * block + 1;}
int end(int i) {return min(i * block, n);}
int to(int i) {return (i - 1) / block + 1;}

void init(){
  vec.assign(n + 1, 0);
  tag.assign(n + 1, 0);
  bel.assign(n + 1, 0);
  sorted.assign(n + 1, {});
  block = sqrt(n); 
  for(int i = 1; i <= n; i ++) bel[i] = to(i);
}

void reset(int x) {
  sorted[x].clear();
  for(int i = begin(x); i <= end(x); i ++) sorted[x].push_back(vec[i]);
  sort(sorted[x].begin(), sorted[x].end());
}

void update(int l, int r, int val) {
  int res = 0;
  int bl = to(l), br = to(r);
  if (bl == br) {
    for(int i = l; i <= r; i ++) vec[i] += val;
    reset(bl);
    return; 
  }

  for(int i = l; i <= end(bl); i ++) vec[i] += val;
  for(int i = bl + 1; i < br; i ++) tag[i] += val;
  for(int i = begin(br); i <= r; i ++) vec[i] += val;
  reset(bl); reset(br);
}

int query(int l, int r, int c) {
  int res = 0, t = c * c;
  int bl = to(l), br = to(r);
  if (bl == br) {
    for(int i = l; i <= r; i ++) res += vec[i] + tag[to(i)] < t;
    return res;
  }

  for(int i = l; i <= end(bl); i ++) res += vec[i] + tag[to(i)] < t;
  for(int i = bl + 1; i < br; i ++) {
    int L = begin(i), R = end(i);
    auto it = lower_bound(sorted[i].begin(), sorted[i].end(), t - tag[i]);
    res += it - sorted[i].begin();
  }
  for(int i = begin(br); i <= r; i ++) res += vec[i] + tag[to(i)] < t;
  return res;
}

void solve() { 

  cin >> n; init(); 
  for(int i = 1; i <= n; i ++) cin >> vec[i];
  
  int cnt = (n + block - 1) / block;
  for(int i = 1; i <= cnt; i ++) reset(i);

  for(int i = 1; i <= n;  i++) {
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