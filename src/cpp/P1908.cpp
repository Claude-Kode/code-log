// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //必须的前置库
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds; //若写了则之后定义时不需要再加命名空间
#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n; 
vector<int> seg, tag, vec;

tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tr;


int ls(int i) {return i << 1;}
int rs(int i) {return i << 1 | 1;}

void apply(int node, int l, int r, int val) {
  tag[node] += val; seg[node] += (r - l + 1) * val;
}

void down(int node, int l, int r) {
  int mid = (l + r) / 2, &val = tag[node];
  apply(ls(node), l, mid, val);
  apply(rs(node), mid + 1, r, val);
  val = 0;
}

void build(int node, int l, int r) {
  if (l == r) {seg[node] ++; return;}
  int mid = (l + r) / 2;
  build(ls(node), l, mid);
  build(rs(node), mid + 1, r);
  seg[node] = seg[ls(node)] + seg[rs(node)];
}

void update(int node, int l, int r, int ql, int qr, int val) {
  if (ql <= l && qr >= r) {apply(node, l, r, val); return;}
  down(node, l, r);
  int mid = (l + r) / 2;
  if (ql <= mid) update(ls(node), l, mid, ql, qr, val);
  if (qr > mid) update(rs(node), mid + 1, r, ql, qr, val);
  seg[node] = seg[ls(node)] + seg[rs(node)];
}

int query(int node, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) {return seg[node];}
  down(node, l, r);
  int mid = (l + r) / 2, res = 0;
  if (mid >= ql) res += query(ls(node), l, mid, ql, qr);
  if (qr > mid) res += query(rs(node), mid + 1, r, ql, qr);
  return res;
}

void dedup(vector<int>& vec) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}

int getId(int x, vector<int>& vec){
  return lower_bound(vec.begin() + 1, vec.end() , x) - vec.begin();
}

void solve() { 

  cin >> n;
  vec.assign(n + 1, 0);
  tag.assign(4 * n + 1, 0);
  seg.assign(4 * n + 1, 0);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  auto temp = vec; dedup(temp);
  for(int i = 1; i <= n; i ++) {
    vec[i] = getId(vec[i], temp);
    // cout << vec[i] << ' ';
  }

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    if (vec[i] < n)ans += query(1, 1, n, vec[i] + 1, n);
    update(1, 1, n, vec[i], vec[i], 1);
  }

  cout << ans << endl;
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

