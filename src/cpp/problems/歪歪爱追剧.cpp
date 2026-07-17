// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

template<typename Infor, typename Tag> 
class SegmentTree {
 public:
  int n;
  vector<Infor> seg = {};
  vector<Tag> tag = {};

  SegmentTree(int _n) : n(_n) { 
    init();
  }

  SegmentTree(const vector<int>& a) : n(a.size() - 1){
    init();
    build(1, 0, n, a);
  }

  void init() {
    seg.assign(4 * n + 1, Infor());
    tag.assign(4 * n + 1, Tag());
  }

  void build(int p, int l, int r, const vector<int>& a) {
    if (l == r) {
      apply(p, l, r, Tag{a[l]});
    } else {
      int m = (l + r) >> 1;
      build(p << 1, l, m, a);
      build(p << 1 | 1, m + 1, r, a);
      pull(p);
    }
  }

  void apply(int p, int l, int r, Tag v) {
    seg[p].mx = v;
    tag[p] = v;
  }

  void push(int p, int l, int r) {
    if (tag[p] == Tag()) return;
    int m = (l + r) >> 1;
    apply(p << 1, l, m, tag[p]);
    apply(p << 1 | 1, m + 1, r, tag[p]);
    tag[p] = Tag();
  }

  void pull(int p) {
    seg[p].mx = max(seg[p << 1].mx, seg[p << 1 | 1].mx);
  }

  void set(int p, int l, int r, int pos, int v) {
    if (l == r) {
      apply(p, l, r, Tag{v});
    } else {
      push(p, l, r);
      int m = (l + r) / 2;
      if (pos <= m) set(p << 1, l, m, pos, v);
      else set(p << 1 | 1, m + 1, r, pos, v);
      pull(p);
    }
  }

  Infor ask(int p, int l, int r, int L, int R) {
    if (L <= l and r <= R) {
      return seg[p];
    } else {
      push(p, l, r);
      int m = (l + r) >> 1; Infor res;
      if (L <= m) res += ask(p << 1, l, m, L, R);
      if (R > m)  res += ask(p << 1 | 1, m + 1, r, L, R);
      return res;
    }
  }

 public:
  void set(int p, int v) {
    set(1, 0, n, p, v);
  }

  Infor ask(int l, int r) { 
    return ask(1, 0, n, l, r); 
  }
};

struct Infor{
  int mx = 0;
  // 可以重载一个 信息之间的加号
  Infor& operator+=(const Infor &other) {
    mx = max(mx, other.mx);
    return *this;
  }
};

void solve() {
  int sz, n, m;
  cin >> sz >> n >> m;

  vector<int> val(1, 0);
  vector<array<int, 2>> vec(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> vec[i][0] >> vec[i][1];
    val.push_back(vec[i][0]);
    val.push_back(vec[i][1]);
  }

  unordered_map<int, int> ump;
  for (int i = 1; i <= m; i ++) {
    int tmp; cin >> tmp;
    ump[tmp] = 1; val.push_back(tmp);
  }

  sort(vec.begin() + 1, vec.end(), [&](const auto &a, const auto &b){
    return a[1] < b[1];
  });

  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());

  auto get = [&](int i) -> int {
    return lower_bound(val.begin(), val.end(), i) - val.begin();
  };

  vector<int> have(val.size(), 0);
  for (const auto &[k, v] : ump) {
    have[get(k)] ++;
  }

  for (int i = 1; i < have.size(); i ++) {
    have[i] += have[i - 1];
  }

  vector<int> temp(val.size(), -1); temp[0] = 0;
  SegmentTree<Infor, int> dp(temp); 
  for (int i = 1; i <= n; i ++) {
    int l = get(vec[i][0]), r = get(vec[i][1]), v = vec[i][1] - vec[i][0] + 1;
    if (!(have[r] - have[l - 1])) continue; 
    int mx = dp.ask(0, l - 1).mx;
    dp.set(r, max(mx + v, dp.ask(r, r).mx));
  }


  cout << dp.ask(0, val.size()).mx << "\n";
} 

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