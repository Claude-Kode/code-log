// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#else
#define dbug(...)
#endif

// REGISTER_REFLECT()

// DSU
class DSU {
 public:
  vector<int> f, siz, dis;

 public:
  DSU(int n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
    dis.assign(n, 0);
  }

  int find(int x) {
    int root = x;
    while (root != f[root]) root = f[root];
    while (x != root) {
      int nxt = f[x];
      f[x] = root;
      x = nxt;
    }
    return root;
  }

  // int find(int x) {
  //   if (x != f[x]) {
  //     int ffx = find(f[x]);
  //     f[x] = ffx;
  //   }
  //   return f[x];
  // }

  bool same(int x, int y) { return find(x) == find(y); }

  bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
      return false;
    }
    f[fx] = fy;
    siz[fy] += siz[fx];
    return true;
  }

  int size(int x) { return siz[find(x)]; }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  unordered_map<int, int> cnt;
  unordered_map<int, int> first, last;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    if (!first.count(a[i])) first[a[i]] = i;
    last[a[i]] = i;
  }

  // 找出所有“坏值”：出现多次且不连续
  vector<int> bad;
  for (auto &p : cnt) {
    int v = p.first;
    if (p.second > 1 && last[v] - first[v] + 1 > p.second) {
      bad.push_back(v);
    }
  }

  // 原本就合法
  if (bad.empty()) {
    cout << "YES\n";
    return;
  }

  // 坏值超过两个，一次交换无法修复
  if (bad.size() > 2) {
    cout << "NO\n";
    return;
  }

  // 检查函数：交换 p 和 q，判断是否合法
  auto chk = [&](int p, int q) -> bool {
    swap(a[p], a[q]);
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] == a[i - 1]) {
        dsu.merge(i - 1, i);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (dsu.size(i) != cnt[a[i]]) {
        swap(a[p], a[q]);
        return false;
      }
    }
    swap(a[p], a[q]);
    return true;
  };

  // 构造候选交换位置
  set<int> cand;
  for (int v : bad) {
    cand.insert(first[v]);
    cand.insert(last[v]);

    // 第一个不等于 v 的位置
    int p1 = -1;
    for (int i = first[v]; i <= last[v]; i++) {
      if (a[i] != v) {
        p1 = i;
        break;
      }
    }
    if (p1 != -1) {
      cand.insert(p1);
      int u = a[p1];
      if (first.count(u)) {
        cand.insert(first[u]);
        cand.insert(last[u]);
      }
    }

    // 最后一个不等于 v 的位置
    int p2 = -1;
    for (int i = last[v]; i >= first[v]; i--) {
      if (a[i] != v) {
        p2 = i;
        break;
      }
    }
    if (p2 != -1 && p2 != p1) {  // 避免重复
      cand.insert(p2);
      int w = a[p2];
      if (first.count(w)) {
        cand.insert(first[w]);
        cand.insert(last[w]);
      }
    }
  }

  // 枚举候选交换
  vector<int> pos(cand.begin(), cand.end());
  for (size_t i = 0; i < pos.size(); i++) {
    for (size_t j = i + 1; j < pos.size(); j++) {
      int x = pos[i], y = pos[j];
      if (x < 1 || x > n || y < 1 || y > n) continue;
      if (chk(x, y)) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
}

// void solve() {
//   int n;
//   cin >> n;
//   vector<int> vec(n + 1);
//   unordered_map<int, int> cnt;
//   for (int i = 1; i <= n; i++) {
//     cin >> vec[i];
//     cnt[vec[i]]++;
//   }

//   DSU dsu(n + 1);
//   for (int i = 1; i <= n; i++) {
//     if (vec[i] == vec[i - 1]) {
//       dsu.merge(i - 1, i);
//     }
//   }

//   auto chk = [&](int a, int b) -> bool {
//     swap(vec[a], vec[b]);
//     DSU dsu(n + 1);
//     for (int i = 1; i <= n; i++) {
//       if (vec[i] == vec[i - 1]) {
//         dsu.merge(i - 1, i);
//       }
//     }

//     for (int i = 1; i <= n; i++) {
//       if (dsu.size(i) != cnt[vec[i]]) {
//         swap(vec[a], vec[b]);
//         return false;
//       }
//     }
//     swap(vec[a], vec[b]);
//     return true;
//   };

//   if (chk(0, 0)) {
//     cout << "YES" << "\n";
//     return;
//   }

//   // 后面只剩下不合法情况
//   // 不合法的局面分两种(可修复的)
//   // 第一种是 单个元素的出现阻断了左右两边的相同元素合并
//   // 第二种那是 单个元素的出现,
//   // 让他没能和另外的相同元素进行合并从而得到合法局面

//   // 筛选单个元素 找配对的 的局面
//   unordered_map<int, int> sign;
//   for (int i = 1; i <= n; i++) {
//     if (dsu.size(i) == 1 and cnt[vec[i]] != 1) {
//       sign[vec[i]] = 1;
//     }
//   }

//   if (sign.size() > 2) {
//     cout << "NO" << "\n";
//     return;
//   }

//   if (sign.empty()) {
//     // 此时存在两种情况
//     // 第一种, 没有单个出现的元素, 无法修复
//     // 第二种, 单个出现的纯单个元素
//     int p = 0, ele = 0;
//     bool single = false;
//     for (int i = 2; i < n; i++) {
//       // 这里的边界
//       if (dsu.size(i) == 1 and (single = true) and vec[i - 1] == vec[i + 1])
//       {
//         p = i;
//         ele = vec[i - 1];
//         break;
//       }
//     }

//     if (!single) {
//       cout << "NO" << "\n";
//       return;
//     }

//     assert(p);

//     int l = p, r = p;
//     // 这里的边界
//     while (r + 1 <= n and vec[r + 1] == ele) r++;
//     while (l - 1 >= 1 and vec[l - 1] == ele) l--;
//     if (chk(p, l) or chk(p, r)) {
//       cout << "YES" << "\n";
//       return;
//     }
//   }

//   // 到这里只剩下, 有单个的元素 且有多个联通块的元素
//   // 策略是把单个的贴到另一个连通块的两边即可
//   int tar = sign.begin()->first, pos = 0;
//   vector<array<int, 2>> info;
//   for (int i = 1; i <= n; i++) {
//     if (vec[i] == tar) {
//       info.push_back({i, i});
//       int j = i;
//       // 这里的边界
//       while (j + 1 <= n and vec[j + 1] == tar) {
//         j++;
//       }
//       info.back()[1] = j;
//       if (j == i) pos = i;
//       i = j;
//     }
//   }

//   // assert(info.size() > 1);

//   for (auto& [s, t] : info) {
//     if (s == pos) continue;
//     if (s > 1) {
//       if (chk(s - 1, pos)) {
//         cout << "YES" << "\n";
//         return;
//       }
//     }
//     if (t < n) {
//       if (chk(pos, t + 1)) {
//         cout << "YES" << "\n";
//         return;
//       }
//     }
//   }

//   cout << "NO" << "\n";
// }

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
