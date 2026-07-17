// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

class FenwickTree {
public: 
  int n; 
  std::vector<int> tree;  
public: 
  FenwickTree(int _n = 1) : n(_n) {tree.assign(n + 1, 0);}
  static int lowbit(int i) {return i & -i;} 

  void update(int p, int v) { // 不能 update(0, ?) 会死循环
    if (p <= 0) return;
    for(int i = p; i <= n; i += lowbit(i)) {
      tree[i] += v;
    }
  }

  int query (int p) {
    if (p <= 0) return 0;
    int res = 0;
    for(int i = p; i > 0; i -= lowbit(i)) {
      res += tree[i];
    }
    return res;
  }
};

void solve() {    
  int n, m; 
  std::cin >> n >> m;
  std::vector<int> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    std::cin >> vec[i];
  }

  FenwickTree t1(n), t2(n);
  auto work = [&](int l, int r, int k, int d) -> void {
    t1.update(l, k); t2.update(l, l * k);
    if (l + 1 <= n) {
      t1.update(l + 1, d - k);
      t2.update(l + 1, (l + 1) * (d - k));
    } 
    if (r + 1 <= n) {
      t1.update(r + 1, -(k + (r - l + 1) * d));
      t2.update(r + 1, (r + 1) * -(k + (r - l + 1) * d));
    }
    if (r + 2 <= n) {
      t1.update(r + 2, k + (r - l) * d);
      t2.update(r + 2, (r + 2) * (k + (r - l) * d));
    }
  };

  while (m --) {
    int op; 
    std::cin >> op;
    if (op == 1) {
      int l, r, k, d; 
      std::cin >> l >> r >> k >> d;
      work(l, r, k, d);
    }

    if (op == 2) {
      int p; 
      std::cin >> p;
      std:: cout << vec[p] + (p + 1) * t1.query(p) - t2.query(p) << "\n";
    }
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0; 
  // std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

// // @Author : GoryK
// #include <bits/stdc++.h>

// #define int long long

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif

// class segmentTree {
// public: 
//   int n; 
//   std::vector<int> seg;
//   std::vector<int> tag;
// public: 
//   segmentTree(int _n, const std::vector<int>& vec) : n(_n) {
//     seg.assign(n << 2 | 1, 0);
//     tag.assign(n << 2 | 1, 0);
//     build(1, 1, n, vec);
//   }

//   static int ls(int i) {return i << 1;}
//   static int rs(int i) {return i << 1 | 1;}

//   void up(int node) {
//     seg[node] = seg[ls(node)] + seg[rs(node)];
//   }

//   void apply(int node, int l, int r, int val) {
//     seg[node] += (r - l + 1) * val;
//     tag[node] += val;
//   }

//   void down(int node, int l, int r) {
//     if (!tag[node]) return;
//     int mid = (l + r) / 2, &val = tag[node];
//     apply(ls(node), l,  mid, val);
//     apply(rs(node), mid + 1,  r, val);
//     val = 0;
//   }

//   void build(int node, int l, int r, const std::vector<int>& vec) {
//     if (l == r) {
//       seg[node] = vec[l];
//       return;
//     }
//     int mid = (l + r) / 2;
//     build(ls(node), l, mid, vec);
//     build(rs(node), mid + 1, r, vec);
//     up(node);
//   }

//   void update(int node ,int l, int r, int ql, int qr, int val) {
//     if (ql <= l && r <= qr) {
//       apply(node, l, r, val);
//       return;
//     }
//     down(node, l, r);
//     int mid = (l + r) / 2;
//     if (ql <= mid) update(ls(node), l, mid, ql, qr, val);
//     if (mid < qr) update(rs(node), mid + 1, r, ql, qr, val);
//     up(node);
//   }

//   int query(int node, int l, int r,  int ql, int qr) {
//     if (ql <= l && r <= qr) {
//       return seg[node];
//     }
//     down(node, l, r) ;
//     int mid = (l + r) / 2, res = 0;
//     if (ql <= mid) res += query(ls(node), l, mid, ql, qr);
//     if (mid < qr) res += query(rs(node), mid + 1, r, ql, qr);
//     return res;
//   }
// };

// void solve() {    
//   int n, m; std::cin >> n >> m;
//   std::vector<int> vec(n + 1, 0);
//   for (int i = 1; i <= n; i ++) {
//     std::cin >> vec[i];
//   }

//   segmentTree seg(n, std::vector<int>(n + 1, 0));
//   while (m --) {
//     int op; 
//     std::cin >> op;
//     if (op == 1) {
//       int l, r, k, d; 
//       std::cin >> l >> r >> k >> d;
//       // 维护相加等差数列的实际含义就是对 差分数组做一个差分数组 
//       // 然后我们先对差分数组的差分数组做前缀和, 然后在对查分数租做前缀和 可以求出第 q 位置
//       // l = 1, r = 5, (k, d, d, d, d, -(k + (r - l) * d))
//       seg.update(1, 1, n, l, l, k);   
//       seg.update(1, 1, n, l + 1, r, d);
//       if (r < n) seg.update(1, 1, n, r + 1, r + 1, -(k + (r - l) * d));   
//     }

//     if (op == 2) {
//       int p; 
//       std::cin >> p;
//       std::cout << vec[p] + seg.query(1, 1, n, 1, p) << "\n";
//     }
//   }
// } 

// int32_t main() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);

//   int tt = 1, _ = 0; 
//   // std::cin >> tt;
//   while (tt-- && ++_)
//     // std::cout << "TEST CASE : " << _ << endl,
//     solve();

//   return 0;
// }