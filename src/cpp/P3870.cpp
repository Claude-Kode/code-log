// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n;
vector<int> vec, seg, tag;

int ls(int i) {return i << 1;}
int rs(int i) {return i << 1 | 1;}

void init() {vec.assign(n + 1, 0); seg.assign(n << 2 | 1, 0); tag.assign(n << 2 | 1, 0);}

void apply(int node, int l, int r, int val) {
  tag[node] ^= val;
  seg[node] = (r - l + 1) - seg[node];
}

void down(int node, int l, int r) {
  int mid = (l + r) / 2, &val = tag[node];
  if (!val) return;
  apply(ls(node), l, mid, val);
  apply(rs(node), mid + 1, r, val);
  val = 0;
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
  int m; cin >> n >> m; init();
// tag[i] == 0 不改变 tag[i] == 1 所有的子区间需要 ^= 1
  for(int i = 1; i <= m; i ++) {
    int c, l, r; cin >> c >> l >> r;
    if (!c) { 
      update(1, 1, n, l, r, 1);
    } else {
      cout << query(1, 1, n, l, r) << endl; 
    }
  }
}

/*
本质上是我没搞懂 seg 数组的含义
我混淆了 seg 数组和 tag 数组的含义
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