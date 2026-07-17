// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n, m;
vector<int> vec, seg, tag;
int ls(int i) {return i << 1;}
int rs(int i) {return i << 1 | 1;}

void init() {vec.assign(n + 1, 0); seg.assign(n << 2 | 1, 0); tag.assign(n << 2 | 1, 0);}

void apply(int node, int l, int r, int val) {
  tag[node] += val;
  seg[node] += (r - l + 1) * val;
}

void down(int node, int l, int r) {
  int mid = (l + r) / 2, &val = tag[node];
  apply(ls(node), l, mid, val);
  apply(rs(node), mid + 1, r, val);
  val = 0;
}

void build (int node, int l, int r) {
  if (l == r) {seg[node] = vec[l]; return;}
  int mid = (l + r) / 2;
  build(ls(node), l, mid);
  build(rs(node), mid + 1, r);
  seg[node] = seg[ls(node)] + seg[rs(node)];
}

void update(int node, int l, int r, int ql, int qr, int val) {
  if(node <= 0 || node >= 4 * n) {cerr << 1 << endl;}
  if (ql <= l && qr >= r) {apply(node, l, r, val); return;}
  down(node, l, r);
  int mid = (l + r) / 2;
  if (mid >= ql) update(ls(node), l, mid, ql, qr, val);
  if (mid < qr) update(rs(node), mid + 1, r, ql, qr, val);
  seg[node] = seg[ls(node)] + seg[rs(node)];
} 

int query(int node, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) {return seg[node];}
  down(node, l, r);
  int mid = (l + r) / 2, res = 0;
  if (mid >= ql) res += query(ls(node), l, mid, ql, qr);
  if (mid < qr) res += query(rs(node), mid + 1, r, ql, qr);
  return res;
}

void solve() { 
  cin >> n >> m;
  init();
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }
  build(1, 1, n);

  for(int i = 1; i <= m; i ++) {
    int op; cin >> op;
    if (op == 1) {
      int x, y, k; cin >> x >> y >> k;
      update(1, 1, n, x, y, k);
    } else {
      int l, r; cin >> l >> r;
      cout << query(1, 1, n, l, r) << endl; 
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

