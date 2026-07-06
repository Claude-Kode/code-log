#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

int mod;  // 模数从输入读取
const int N = 1e5 + 10;

struct node{int sum; int mul; int add;};

int n; 
vector<node> seg; 
vector<int> vec;

int ls(int i) {return i << 1;}
int rs(int i) {return i << 1 | 1;}

// apply 的本质是应用标记到指定节点并更新指定节点的儿子标记
void apply(int node, int l, int r, int M, int A) {
  int &m = seg[node].mul, &a = seg[node].add, &s = seg[node].sum;
  m = (m * M) % mod;  
  a = (a * M + A) % mod;  
  // 如果每一次我都把新的标记应用到自己身上 就根本没有旧的标记
  s = (s * M + A * (r - l + 1)) % mod;  
}

// down : 标记应用到下层并释放本层标记
void down(int node, int l, int r) {
  if (seg[node].mul == 1 && seg[node].add == 0) return;
  int mid = (l + r) >> 1;
  apply(ls(node), l, mid, seg[node].mul, seg[node].add);
  apply(rs(node), mid + 1, r, seg[node].mul, seg[node].add);
  seg[node].mul = 1;
  seg[node].add = 0;
}

void build(int node, int l, int r) {
  seg[node].mul = 1;
  seg[node].add = 0;
  if (l == r) {
    seg[node].sum = vec[l] % mod;
    return;
  }
  int mid = (l + r) >> 1;
  build(ls(node), l, mid);
  build(rs(node), mid + 1, r);
  seg[node].sum = (seg[ls(node)].sum + seg[rs(node)].sum) % mod;
}

void update_add(int node, int l, int r, int ql, int qr, int val) {
  if (ql <= l && r <= qr) {
    apply(node, l, r, 1, val);  // 乘1加val
    return;
  }
  down(node, l, r);
  int mid = (l + r) >> 1;
  if (ql <= mid) update_add(ls(node), l, mid, ql, qr, val);
  if (qr > mid) update_add(rs(node), mid + 1, r, ql, qr, val);
  seg[node].sum = (seg[ls(node)].sum + seg[rs(node)].sum) % mod;
}

void update_mul(int node, int l, int r, int ql, int qr, int val) {
  if (ql <= l && r <= qr) {
    apply(node, l, r, val, 0);  // 乘val加0
    return;
  }
  down(node, l, r);
  int mid = (l + r) >> 1;
  if (ql <= mid) update_mul(ls(node), l, mid, ql, qr, val);
  if (qr > mid) update_mul(rs(node), mid + 1, r, ql, qr, val);
  seg[node].sum = (seg[ls(node)].sum + seg[rs(node)].sum) % mod;
}

int query(int node, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return seg[node].sum;
  down(node, l, r);
  int mid = (l + r) >> 1, res = 0;
  if (ql <= mid) res = (res + query(ls(node), l, mid, ql, qr)) % mod;
  if (qr > mid) res = (res + query(rs(node), mid + 1, r, ql, qr)) % mod;
  return res;
}

void solve() { 
  int q;
  cin >> n >> q >> mod;  // 读取模数
  vec.assign(n + 1, 0);
  seg.assign(4 * n + 1, {0, 1, 0});  // 线段树需要4倍空间
  
  for(int i = 1; i <= n; i++) {
    cin >> vec[i];
  }
  
  build(1, 1, n);
  
  while(q--) {
    int op, x, y, k;
    cin >> op;
    if(op == 1) {  // 区间乘
      cin >> x >> y >> k;
      update_mul(1, 1, n, x, y, k % mod);
    } else if(op == 2) {  // 区间加
      cin >> x >> y >> k;
      update_add(1, 1, n, x, y, k % mod);
    } else if(op == 3) {  // 区间查询
      cin >> x >> y;
      cout << query(1, 1, n, x, y) << endl;
    }
  }
}

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  // int tt, CNT = 0, cin >> tt;
  // while(tt-- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}