// @Author : GoryK
#include <bits/stdc++.h>

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

void solve() {}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tt = 1, _ = 0;
  std::cin >> tt;
  while (tt-- && ++_)
    // std::cout << "TEST CASE : " << _ << endl,
    solve();

  return 0;
}

class Tree {
 public:
  vector<int> tree;
  vector<int> Add;
  vector<int> Max;
  vector<int> Reset;
  vector<bool> hasReset;
  void setting(int n) {
    tree.resize(4 * n + 1);
    Add.resize(4 * n + 1);
    Max.resize(4 * n + 1);
    Reset.resize(4 * n + 1);
    hasReset.resize(4 * n + 1, false);
  }
  void lazy(int i, int v, int n) {
    tree[i] += v * n;
    Add[i] += v;
    Max[i] += v;
  }
  void lazyReset(int i, int v, int n) {
    tree[i] = v * n;
    Max[i] = v;
    Reset[i] = v;
    hasReset[i] = true;
    Add[i] = 0;
  }
  void build(vector<int>& a, int i, int l, int r) {
    if (l == r) {
      tree[i] = a[l];
      Max[i] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(a, i << 1, l, mid);
    build(a, i << 1 | 1, mid + 1, r);
    up(i);
  }

  void up(int i) {
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
    Max[i] = max(Max[i << 1], Max[i << 1 | 1]);
  }

  void down(int i, int ln, int rn) {
    if (hasReset[i]) {
      lazyReset(i << 1, Reset[i], ln);
      lazyReset(i << 1 | 1, Reset[i], rn);
      hasReset[i] = false;
    }
    if (Add[i]) {
      lazy(i << 1, Add[i], ln);
      lazy(i << 1 | 1, Add[i], rn);
      Add[i] = 0;
    }
  }
  void add(int jobl, int jobr, int jobv, int i, int l, int r) {
    if (jobl > jobr) return;
    if (jobl <= l && jobr >= r) {
      lazy(i, jobv, r - l + 1);
    } else {
      int mid = (l + r) >> 1;
      down(i, mid - l + 1, r - mid);
      if (jobl <= mid) {
        add(jobl, jobr, jobv, i << 1, l, mid);
      }
      if (jobr > mid) {
        add(jobl, jobr, jobv, i << 1 | 1, mid + 1, r);
      }
      up(i);
    }
  }
  void reset(int jobl, int jobr, int jobv, int i, int l, int r) {
    if (jobl > jobr) return;
    if (jobl <= l && jobr >= r) {
      lazyReset(i, jobv, r - l + 1);
    } else {
      int mid = (l + r) >> 1;
      down(i, mid - l + 1, r - mid);
      if (jobl <= mid) {
        reset(jobl, jobr, jobv, i << 1, l, mid);
      }
      if (jobr > mid) {
        reset(jobl, jobr, jobv, i << 1 | 1, mid + 1, r);
      }
      up(i);
    }
  }
  int querySum(int jobl, int jobr, int i, int l, int r) {
    if (jobl > jobr) return 0;
    if (jobl <= l && jobr >= r) {
      return tree[i];
    }
    int mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    int ans = 0;
    if (jobl <= mid) {
      ans += querySum(jobl, jobr, i << 1, l, mid);
    }
    if (jobr > mid) {
      ans += querySum(jobl, jobr, i << 1 | 1, mid + 1, r);
    }
    return ans;
  }
  int queryMax(int jobl, int jobr, int i, int l, int r) {
    if (jobl > jobr) return -1e18;
    if (jobl <= l && jobr >= r) {
      return Max[i];
    }
    int mid = (l + r) >> 1;
    down(i, mid - l + 1, r - mid);
    int ans = -1e18;
    if (jobl <= mid) {
      ans = max(ans, queryMax(jobl, jobr, i << 1, l, mid));
    }
    if (jobr > mid) {
      ans = max(ans, queryMax(jobl, jobr, i << 1 | 1, mid + 1, r));
    }
    return ans;
  }
};

// 默认的数据节点结构
template <typename T>
struct DefaultData {
  T sum;    // 区间和
  T max;    // 区间最大值
  T min;    // 区间最小值
  int len;  // 区间长度

  DefaultData() : sum(T()), max(T()), min(T()), len(0) {}
  DefaultData(T val) : sum(val), max(val), min(val), len(1) {}

  // 合并两个区间
  static DefaultData merge(const DefaultData& a, const DefaultData& b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;

    DefaultData res;
    res.sum = a.sum + b.sum;
    res.max = std::max(a.max, b.max);
    res.min = std::min(a.min, b.min);
    res.len = a.len + b.len;
    return res;
  }
};

// 默认的标记结构
template <typename T>
struct DefaultTag {
  T add;  // 加法标记

  DefaultTag() : add(0) {}
  DefaultTag(T val) : add(val) {}

  bool has_tag() const { return add != 0; }

  void clear() { add = 0; }

  // 标记合并
  void apply(const DefaultTag& other) { add += other.add; }
};

// 主线段树类
template <typename DataType,  // 数据类型
          typename TagType,   // 标记类型
          typename MergeFunc = std::function<DataType(
              const DataType&, const DataType&)>,  // 合并函数
          typename ApplyTagFunc = std::function<void(
              DataType&, const TagType&, int, int)>,  // 应用标记函数
          typename PushdownFunc =
              std::function<void(TagType&, TagType&, TagType&)>  // 下传标记函数
          >
class SmartSegmentTree {
 private:
  struct Node {
    DataType data;  // 节点数据
    TagType tag;    // 懒标记
    bool has_lazy;  // 是否有懒标记

    Node() : has_lazy(false) {}
  };

  int n;
  std::vector<Node> tree;

  MergeFunc merge_func;
  ApplyTagFunc apply_tag_func;
  PushdownFunc pushdown_func;

  // 构建线段树
  void build(int node, int l, int r,
             const std::vector<typename DataType::value_type>& init_vals) {
    if (l == r) {
      tree[node].data = DataType(init_vals[l]);
      return;
    }

    int mid = (l + r) >> 1;
    build(node << 1, l, mid, init_vals);
    build(node << 1 | 1, mid + 1, r, init_vals);
    tree[node].data =
        merge_func(tree[node << 1].data, tree[node << 1 | 1].data);
  }

  // 应用标记到节点
  void apply_to_node(int node, int l, int r, const TagType& tag) {
    apply_tag_func(tree[node].data, tag, l, r);

    if (l != r) {
      tree[node].has_lazy = true;
      tree[node].tag.apply(tag);
    }
  }

  // 下传标记
  void push_down(int node, int l, int r) {
    if (!tree[node].has_lazy) return;

    int mid = (l + r) >> 1;
    pushdown_func(tree[node].tag, tree[node << 1].tag, tree[node << 1 | 1].tag);

    apply_tag_func(tree[node << 1].data, tree[node].tag, l, mid);
    apply_tag_func(tree[node << 1 | 1].data, tree[node].tag, mid + 1, r);

    tree[node << 1].has_lazy = tree[node << 1 | 1].has_lazy = true;
    tree[node].has_lazy = false;
    tree[node].tag.clear();
  }

  // 区间更新
  void update_range(int node, int l, int r, int ql, int qr,
                    const TagType& tag) {
    if (ql <= l && r <= qr) {
      apply_to_node(node, l, r, tag);
      return;
    }

    push_down(node, l, r);
    int mid = (l + r) >> 1;

    if (ql <= mid) update_range(node << 1, l, mid, ql, qr, tag);
    if (qr > mid) update_range(node << 1 | 1, mid + 1, r, ql, qr, tag);

    tree[node].data =
        merge_func(tree[node << 1].data, tree[node << 1 | 1].data);
  }

  // 区间查询
  DataType query_range(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return tree[node].data;
    }

    push_down(node, l, r);
    int mid = (l + r) >> 1;

    DataType left_result, right_result;
    bool has_left = false, has_right = false;

    if (ql <= mid) {
      left_result = query_range(node << 1, l, mid, ql, qr);
      has_left = true;
    }

    if (qr > mid) {
      right_result = query_range(node << 1 | 1, mid + 1, r, ql, qr);
      has_right = true;
    }

    if (has_left && has_right) {
      return merge_func(left_result, right_result);
    } else if (has_left) {
      return left_result;
    } else {
      return right_result;
    }
  }

 public:
  SmartSegmentTree(int size, MergeFunc merge = MergeFunc(),
                   ApplyTagFunc apply_tag = ApplyTagFunc(),
                   PushdownFunc pushdown = PushdownFunc())
      : n(size),
        tree(4 * size),
        merge_func(merge),
        apply_tag_func(apply_tag),
        pushdown_func(pushdown) {}

  // 从数组构建
  void build(const std::vector<typename DataType::value_type>& init_vals) {
    build(1, 0, n - 1, init_vals);
  }

  // 区间更新
  void update(int l, int r, const TagType& tag) {
    update_range(1, 0, n - 1, l, r, tag);
  }

  // 单点更新
  void update(int pos, const TagType& tag) {
    update_range(1, 0, n - 1, pos, pos, tag);
  }

  // 区间查询
  DataType query(int l, int r) { return query_range(1, 0, n - 1, l, r); }

  // 单点查询
  DataType query(int pos) { return query_range(1, 0, n - 1, pos, pos); }
};