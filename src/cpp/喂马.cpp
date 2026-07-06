// // @Author : GoryK
// // #pragma GCC optimize("Ofast,fast-math")
// // #pragma GCC target("avx,avx2")
// #include <bits/stdc++.h>
// using namespace std;

// #define int int_fast64_t
// #define endl "\n"

// const int mod = 1e9 + 7; 
// const int N = 2e5 + 10;

// int n, m, q; 
// vector<int> vec, ans;
// //  color, lzy-color
// vector<array<int, 2>> seg;

// void init() {
//   vec.assign(n + 1, 0);
//   ans.assign(m + 1, 0);
//   seg.assign(n << 2 | 1, {0, -1});
// }

// int ls(int i) {return i << 1;}
// int rs(int i) {return i << 1 | 1;}

// void apply(int node, int col) {
//   seg[node][0] = seg[node][1] = col;
// }

// void push_down(int node, int l, int r) {
//   if (seg[node][1] == -1) return; 
//   int mid = (l + r) / 2, &tag = seg[node][1];
//   apply(ls(node), tag);
//   apply(rs(node), tag);
//   tag = -1;
// }

// void push_up(int node) {
//   int lc = seg[ls(node)][0], rc = seg[rs(node)][0];
//   if (lc == rc) seg[node][0] = lc;
//   else seg[node][0] = -1;
// }

// void build(int node, int l, int r) {
//   if (l == r) {seg[node] = {vec[l], -1}; return;}
//   int mid = (l + r) / 2;
//   build(ls(node), l, mid);
//   build(rs(node), mid + 1, r);
//   push_up(node);
// }

// void update_col(int node, int l, int r, int ql, int qr, int col) {
//   if (ql <= l && r <= qr) {
//     seg[node][0] = col;
//     seg[node][1] = col;
//     return; 
//   }
//   push_down(node, l, r);
//   int mid = (l + r) / 2;
//   if (ql <= mid) update_col(ls(node), l, mid, ql, qr, col);
//   if (mid  < qr) update_col(rs(node), mid + 1, r, ql, qr, col);
//   push_up(node);
// }

// void update_val(int node, int l, int r, int ql, int qr, int val) {
//   if (ql <= l && r <= qr && seg[node][0] >= 0) {
//     // assert(seg[node][0] != -1);
//     if (seg[node][0]) ans[seg[node][0]] += (r - l + 1) * val; 
//     return; 
//   }
//   push_down(node, l, r);
//   int mid = (l + r) / 2;
//   if (ql <= mid) update_val(ls(node), l, mid, ql, qr, val);
//   if (mid  < qr) update_val(rs(node), mid + 1, r, ql, qr, val);
//   push_up(node);
// }

// void solve() { 
//   cin >> n >> m >> q; init();
//   for(int i = 1; i <= n; i ++) cin >> vec[i];
//    build(1, 1, n);
//   for(int i = 1; i <= q; i ++) {
//     int op, l, r, x; cin >> op >> l >> r >> x;
//     if (op == 1) {
//       update_col(1, 1, n, l, r, x);
//     } else {
//       update_val(1, 1, n, l, r, x);
//     }
//   }

//   for(int i = 1; i <= m; i ++) {
//     cout << ans[i] << " \n"[i == m];
//   }
// }

// /*

// 总结 : 
// 懒标记不代表自身还有什么没更新 代表他的所有儿子还有什么没更新
// 这个题本质上 op 1 是改变映射关系, 
// 而 op 2 说是区间加法 本质上是把一些值最后夹到一个点上
// 他的本质上就不是一个区间的加法 而是一个单点的加法 
// 这个题的本质上就是维护区间映射, 区间最后会映射成一个点, 所以我们的 val 根本就不需要什么懒标记之类的 
// 我们最终维护的只是一个 区间的映射关系罢了

// 有了这样的想法 剩下的内容就很简单了
// apply 的含义是 应用一些更新(大部分是上层传下来的更新) 经常搭配 down 函数使用
// down 函数的意义是 把当前节点的懒标记更新 如果你不更新就更新子节点会出 bug
// push-up函数的意义就是 把更新了之后的东西传递上去即可 因为大的区间要代表小的区间的内容

// 这个题还是真的挺好的

// */

// signed main() {
  
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
  
//   #ifdef GK
//     freopen("INPUT.txt", "r", stdin);
//     freopen("OUTPUT.txt", "w", stdout);
//   #endif 

//   // cout << fixed << setprecision(6);

//   int tt , CNT = 0; cin >> tt;
//   while(tt -- && ++CNT) 
//     // cout << "TEST CASE : " << CNT << endl,
//     solve();
  
//   return 0;
// }



// // ODT 做法
// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl "\n"

// const int N = 2e6 + 10;

// int n, m, q; 
// vector<int> vec, ans;

// struct Node {
//   int l, r;
//   mutable int v;
//   Node(int _l, int _r = -1, int _v = 0) : l(_l), r(_r), v(_v) {}
//   bool operator<(const Node& o) const { return l < o.l; }
// };

// set<Node> odt;

// void init() { vec.assign(n + 1, 0); ans.assign(m + 1, 0); odt.clear();}

// auto odt_split(int pos) {
//   if (pos > n) return odt.end();
//   auto it = odt.lower_bound(Node(pos));
//   if (it != odt.end() && it->l == pos) return it;
//   --it;
//   int l = it->l, r = it->r, v = it->v;
//   odt.erase(it);
//   odt.insert(Node(l, pos - 1, v));
//   auto ret = odt.insert(Node(pos, r, v)).first;
//   return ret;
// }

// void odt_assign(int l, int r, int v) {    
//   auto itr = odt_split(r + 1), itl = odt_split(l);
//   odt.erase(itl, itr);
//   odt.insert(Node(l, r, v));
// }

// void odt_traverse(int l, int r, int val, auto&& func) {
//   auto itr = odt_split(r + 1), itl = odt_split(l);
//   for (auto it = itl; it != itr; ++it) 
//     func(it->l, it->r, it->v, val);
// }

// void solve() { 
//   cin >> n >> m >> q; 
//   init();
//   for(int i = 1; i <= n; i++) cin >> vec[i];
  
//   for (int i = 1; i <= n; i++)
//     odt.insert(Node(i, i, vec[i]));
  
//   for(int i = 1; i <= q; i++) {
//     int op, l, r, x; cin >> op >> l >> r >> x;
//     if (op == 1) {
//       odt_assign(l, r, x);
//     } else {
//       auto add_func = [&](int L, int R, int c, int val) {
//         if (c > 0) ans[c] += (R - L + 1) * val;
//       };
//       odt_traverse(l, r, x, add_func);
//     }
//   }
  
//   for(int i = 1; i <= m; i++) {
//     cout << ans[i] << " \n"[i == m];
//   }
// }

// signed main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
  
//   int tt; cin >> tt;
//   while(tt--) solve();
  
//   return 0;
// }
 

// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int n, m, q; 
struct Node { int l, r; mutable int v; bool operator< (const Node &o) const {return l < o.l;} };
vector<int> ans, vec; set<Node> odt;

void init(){
  vec.assign(n + 1, 0);
  ans.assign(m + 1, 0);
  odt.clear();
}

// 分裂出一个 以 p 为左端点的区间
auto split(int p) {
  auto it = odt.lower_bound(Node{p, 0, 0}); if (p > n) return odt.end();
  if (it != odt.end() && it -> l == p) return it;
  it --; // it == p - 1
  int l = it -> l, r = it -> r, v = it -> v;
  odt.erase(it);
  odt.insert(Node{l, p - 1, v});
  auto ret = odt.insert(Node{p, r, v}).first;
  return ret;
}

void assign(int l, int r, int v) {
  auto l_it = split(l); auto r_it = split(r + 1); 
  odt.erase(l_it, r_it);
  odt.insert(Node{l, r, v});
}

void traverse(int l, int r, int v, auto&& func) {
  auto l_it = split(l), r_it = split(r + 1);
  for(auto it = l_it; it != r_it; it ++) {
    func(it, v);
  }
}

void solve() { 
  cin >> n >> m >> q;
  init();
  for(int i = 1; i <= n; i ++) cin >> vec[i], odt.insert(Node{i, i, vec[i]});

  for(int i = 1 ;i <= q; i ++) {
    int op, l, r, x; cin >> op >> l >> r >> x;
    if (op == 1) {
      split(l), split(r + 1);
      assign(l, r, x);
    } else {
      auto func = [&](auto it, int val)  -> void {
        if (it -> v > 0) ans[it -> v] += (it -> r - it -> l + 1) * val;
      };
      traverse(l, r, x, func);
    }
  }
  
  for(int i = 1; i <= m; i ++) {
    cout << ans[i] << " \n"[i == m];
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

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}

