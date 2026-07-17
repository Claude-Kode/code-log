// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Infor {
  int ls, rs;
  int cnt = 0;
};

int cnt = 0;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  vector<Infor> seg(n * 25 + 1);
  // 参数的 p 是为了知道当前的节点编号是多少
  // 然后我们保证 set 里面全部都在开新的点, 也就是 set 进入的一开始
  // 当前操作的节点永远是空的
  // 外部每一次调用 set 相当
  auto set = [&](auto&& sef, int pre, int l, int r, int pos) -> int {
    int p = ++cnt;
    seg[p] = seg[pre];
    seg[p].cnt++;
    if (l != r) {
      int m = (l + r) / 2;
      if (pos <= m)
        seg[p].ls = sef(sef, seg[pre].ls, l, m, pos);
      else
        seg[p].rs = sef(sef, seg[pre].rs, m + 1, r, pos);
    }
    return p;
  };

  auto ask = [&](auto&& sef, int prev, int pres, int l, int r, int k) -> int {
    if (l == r) {
      return l;
    } else {
      int m = (l + r) / 2,
          cnt_l = seg[seg[pres].ls].cnt - seg[seg[prev].ls].cnt;
      if (k <= cnt_l)
        return sef(sef, seg[prev].ls, seg[pres].ls, l, m, k);
      else
        return sef(sef, seg[prev].rs, seg[pres].rs, m + 1, r, k - cnt_l);
    }
  };

  auto sorted = vec;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin() + 1, sorted.end()), sorted.end());

  auto get = [&](int i) -> int {
    return lower_bound(sorted.begin() + 1, sorted.end(), i) - sorted.begin();
  };

  int lim = sorted.size() - 1;

  vector<int> rt(n + 1);
  rt[0] = 0;
  for (int i = 1; i <= n; i++) {
    rt[i] = set(set, rt[i - 1], 1, n, get(vec[i]));
  }

  for (int i = 1; i <= m; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << sorted[ask(ask, rt[l - 1], rt[r], 1, n, k)] << "\n";
  }
}

/*
树是二维结构  主席树相当于三维, 新加的一维相当于是时间维度
*/

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

// BIT 套 seg
#include <bits/stdc++.h>
using namespace std;

// 线段树节点：和之前主席树一样，只存 lson, rson, cnt
struct Node {
  int ls, rs;
  int cnt;
};
vector<Node> tree(1);  // 下标从 1 开始，0 留空表示空节点

// 动态开点：在节点 p 的值域线段树中，位置 val 处加上 delta (delta 为 1 或 -1)
void update(int& p, int l, int r, int val, int delta) {
  if (!p) p = tree.size(), tree.push_back({0, 0, 0});
  tree[p].cnt += delta;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (val <= mid)
    update(tree[p].ls, l, mid, val, delta);
  else
    update(tree[p].rs, mid + 1, r, val, delta);
}

// 查询：获取前缀对应的所有线段树根节点在值域 [l,r] 内的第 k 小
// 传入两个根数组：add_roots 对应前缀 r，sub_roots 对应前缀 l-1，用于差分
int query(vector<int>& add_roots, vector<int>& sub_roots, int l, int r, int k) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  // 计算左子树的 cnt 差值：所有 add 的左边 cnt 之和 - 所有 sub 的左边 cnt 之和
  int left_cnt = 0;
  for (int p : add_roots)
    if (p) left_cnt += tree[tree[p].ls].cnt;
  for (int p : sub_roots)
    if (p) left_cnt -= tree[tree[p].ls].cnt;

  if (k <= left_cnt) {
    // 全部转向左子树
    for (int& p : add_roots)
      if (p) p = tree[p].ls;
    for (int& p : sub_roots)
      if (p) p = tree[p].ls;
    return query(add_roots, sub_roots, l, mid, k);
  } else {
    // 全部转向右子树
    for (int& p : add_roots)
      if (p) p = tree[p].rs;
    for (int& p : sub_roots)
      if (p) p = tree[p].rs;
    return query(add_roots, sub_roots, mid + 1, r, k - left_cnt);
  }
}

// 树状数组
struct Fenwick {
  int n;
  vector<int> roots;  // 每个树状数组节点存一棵线段树的根
  Fenwick(int n, vector<int>& a, vector<int>& vals) : n(n), roots(n + 1, 0) {
    // 注意：这里的 vals 是离散化后的数组下标，值域为 [1, m]
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += j & -j) {
        update(roots[j], 1, m, a[i], 1);
      }
    }
  }

  // 修改 a[x] -> val (val 是离散化后的新值，delta = 1 增加，-1 删除)
  void modify(int x, int old_val, int new_val) {
    for (int i = x; i <= n; i += i & -i) {
      update(roots[i], 1, m, old_val, -1);
      update(roots[i], 1, m, new_val, 1);
    }
  }

  // 查询区间 [l, r] 第 k 小
  int kth(int l, int r, int k) {
    vector<int> add_roots, sub_roots;
    for (int i = r; i; i -= i & -i) add_roots.push_back(roots[i]);
    for (int i = l - 1; i; i -= i & -i) sub_roots.push_back(roots[i]);
    return query(add_roots, sub_roots, 1, m, k);
  }

  static int m;  // 值域大小，设为全局方便函数内使用
};
int Fenwick::m = 0;  // 在 main 里设置

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  // 离线读取所有操作，收集所有可能的数值以便离散化
  vector<tuple<char, int, int, int>> ops;    // 操作类型 参数...
  vector<int> all_vals(a.begin(), a.end());  // 初始数组的值
  for (int i = 0; i < q; i++) {
    char type;
    cin >> type;
    if (type == 'C') {  // 修改 a[x] = y
      int x, y;
      cin >> x >> y;
      ops.emplace_back('C', x, y, 0);
      all_vals.push_back(y);
    } else {  // 查询 l r k
      int l, r, k;
      cin >> l >> r >> k;
      ops.emplace_back('Q', l, r, k);
    }
  }

  // 离散化
  sort(all_vals.begin() + 1, all_vals.end());  // a[0] 未使用
  all_vals.erase(unique(all_vals.begin() + 1, all_vals.end()), all_vals.end());
  Fenwick::m = all_vals.size() - 1;  // 值域 [1, m]
  auto get_id = [&](int x) -> int {
    return lower_bound(all_vals.begin() + 1, all_vals.end(), x) -
           all_vals.begin();
  };

  // 将初始数组离散化
  vector<int> disc_a(n + 1);
  for (int i = 1; i <= n; i++) disc_a[i] = get_id(a[i]);

  // 建树状数组套线段树
  Fenwick fenwick(n, disc_a, all_vals);

  // 处理操作
  for (auto& op : ops) {
    if (get<0>(op) == 'C') {
      int x = get<1>(op), y = get<2>(op);
      int new_val = get_id(y);
      fenwick.modify(x, disc_a[x], new_val);
      disc_a[x] = new_val;  // 更新当前值
    } else {
      int l = get<1>(op), r = get<2>(op), k = get<3>(op);
      int ans_id = fenwick.kth(l, r, k);
      cout << all_vals[ans_id] << '\n';
    }
  }
  return 0;
}