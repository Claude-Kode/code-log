// // @Author : GoryK
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// #ifdef LOCAL
// #include "__DEBUG_TOOL.h"
// #endif

// const int mod = 1e9 + 7;

// class ODT {
//  public:
//   int n;
//   struct Node {
//     int l, r;
//     mutable int v;
//     bool operator<(const Node& o) const { return l < o.l; }
//   };
//   set<Node> odt;

//  public:
//   ODT(int _n = 0) : n(_n) {
//     if (n > 0) {
//       odt.insert({1, n, 0});
//     }
//   }

//   template<typename Iter>
//   ODT(Iter first, Iter last) {
//     n = distance(first, last);
//     odt.clear();
//     if (first == last) return;

//     int pos = 1;
//     int prev = *first;
//     int s = 1;
//     Iter it = first;
//     ++ it;

//     for (; it != last; ++ it , pos ++) {
//       if (*it != prev) {
//         odt.insert({s, pos, prev});
//         s = pos + 1;
//         prev = *it;
//       }
//     }
//     odt.insert({s, n, prev});
//     // odt.insert({n + 1, n + 1, 0LL});
//   }

//   std::set<Node>::iterator split(int p) {
//     if (p > n) return odt.end();
//     auto it = odt.lower_bound(Node{p, 0, 0});
//     if (it != odt.end() && it -> l == p) return it;
//     it --; // it == p - 1
//     int l = it -> l, r = it -> r, v = it -> v;
//     odt.erase(it);
//     odt.insert(Node{l, p - 1, v});
//     auto ret = odt.insert(Node{p, r, v}).first;
//     return ret;
//   }

//   void assign(int l, int r, int v) {
//     auto l_it = split(l);
//     auto r_it = split(r + 1);
//     odt.erase(l_it, r_it);
//     odt.insert({l, r, v});
//   }

//   int sum(int l, int r) {
//     int res = 0;
//     auto l_it = split(l);
//     auto r_it = split(r + 1);
//     for (auto it = l_it; it != r_it; ++ it) {
//       res += (it -> r - it -> l + 1) * it -> v;
//       res %= mod;
//     }
//     return res % mod;
//   }

//   void copy(int l1, int r1, int l2, int r2) {
//     if (l1 < l2) {
//       auto r2_it = split(r2 + 1);
//       auto l2_it = split(l2);
//       auto r1_it = split(r1 + 1);
//       auto l1_it = split(l1);

//       vector<Node> tmp;
//       for (auto it = l1_it; it != r1_it; ++it) {
//         tmp.push_back(*it);
//       }

//       odt.erase(l2_it, r2_it);
//       int offset = l2 - l1;
//       for (const auto& node : tmp) {
//         odt.insert({node.l + offset, node.r + offset, node.v});
//       }
//     } else {
//       auto r1_it = split(r1 + 1);
//       auto l1_it = split(l1);
//       auto r2_it = split(r2 + 1);
//       auto l2_it = split(l2);

//       vector<Node> tmp;
//       for (auto it = l1_it; it != r1_it; ++it) {
//         tmp.push_back(*it);
//       }

//       odt.erase(l2_it, r2_it);
//       int offset = l2 - l1;
//       for (const auto& node : tmp) {
//         odt.insert({node.l + offset, node.r + offset, node.v});
//       }
//     }
//   }

  // void swap(int l1, int r1, int l2, int r2) {
  //   if (l1 > l2) {
  //     std::swap(l1, l2);
  //     std::swap(r1, r2);
  //   }
  //   vector<Node> v1, v2;

  //   auto r2_it = split(r2 + 1);
  //   auto l2_it = split(l2);
  //   auto r1_it = split(r1 + 1);
  //   auto l1_it = split(l1);

  //   for (auto it = l2_it; it != r2_it; ++it) {
  //     v2.push_back(*it);
  //   }

  //   for (auto it = l1_it; it != r1_it; ++it) {
  //     v1.push_back(*it);
  //   }

  //   odt.erase(l2_it, r2_it);
  //   odt.erase(l1_it, r1_it);

  //   int offset = l2 - l1;
  //   for (const auto node : v1) {
  //     odt.insert({node.l + offset, node.r + offset, node.v});
  //   }

  //   for (const auto node : v2) {
  //     odt.insert({node.l - offset, node.r - offset, node.v});
  //   }
  // }

//   void reverse(int l, int r) {
//     auto l_it = split(l);
//     auto r_it = split(r + 1);
//     vector<Node> tmp;
//     for (auto it = l_it; it != r_it; ++it) {
//       tmp.push_back(*it);
//     }

//     odt.erase(l_it, r_it);
//     for (int i = tmp.size() - 1; i >= 0; i --) {
//       odt.insert({r + l - tmp[i].r, r + l - tmp[i].l, tmp[i].v});
//     }
//   }

//   template<typename Func>
//   void traverse(int l, int r, Func func) {
//     auto l_it = split(l);
//     auto r_it = split(r + 1);
//     for (auto it = l_it; it != r_it; ++ it) {
//       func(it);
//     }
//   }
// };

// void solve() {
//   int n, m;
//   cin >> n >> m;
//   vector<int> vec(n + 1);
//   for (int i = 1; i <= n; i ++) {
//     cin >> vec[i];
//   }

//   /*
//   1 1 7
//   2 2 1
//   3 3 3
//   4 5 2
//   6 6 4
//   7 7 0
//   8 8 1
//   9 10 2
//   */

//   /*
//   1 1 7
//   2 2 1
//   3 3 3
//   4 5 2
//   6 6 4
//   7 7 0
//   8 8 1
//   9 10 2
//   */

//   ODT odt(vec.begin() + 1, vec.end());
//   for (int i = 1; i <= m; i ++) {
//     int op;
//     cin >> op;
//     if (op == 1) {

//       int l, r;
//       cin >> l >> r;
//       cout << odt.sum(l, r) % mod << "\n";

//     } else if (op == 2) {

//       int l, r, v;
//       cin >> l >> r >> v;
//       odt.assign(l, r, v);

//     } else if (op == 3) {

//       int l, r, v;
//       cin >> l >> r >> v;
//       auto add = [&](auto it) -> void {
//         it -> v = (it -> v + v) % mod;
//       };
//       odt.traverse(l, r, add);

//     } else if (op == 4) {

//       int l1, r1, l2, r2;
//       cin >> l1 >> r1 >> l2 >> r2;
//       odt.copy(l1, r1, l2, r2);

//     } else if (op == 5) {

//       int l1, r1, l2, r2;
//       cin >> l1 >> r1 >> l2 >> r2;
//       odt.swap(l1, r1, l2, r2);

//     } else {

//       int l, r;
//       cin >> l >> r;
//       odt.reverse(l, r);

//     }
//   }

//   int cnt = 0;
//   for (const auto& node : odt.odt) {
//     for (int i = node.l; i <= node.r; i++) {
//       cout << node.v << " ";
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

// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

const int mod = 1e9 + 7;

class ODT {
 public:
  int n;
  struct Node {
    int l, r;
    mutable int v;
    bool operator<(const Node& o) const { return l < o.l; }
  };
  set<Node> odt;

  ODT(int _n = 0) : n(_n) {
    if (n > 0) {
      odt.insert({1, n, 0});
    }
  }

  template<typename Iter>
  ODT(Iter first, Iter last) {
    n = distance(first, last);
    odt.clear();
    if (first == last) return;

    int pos = 1;
    int prev = *first;
    int s = 1;
    Iter it = first;
    ++ it;

    for (; it != last; ++ it , pos ++) {
      if (*it != prev) {
        odt.insert({s, pos, prev});
        s = pos + 1;
        prev = *it;
      }
    }
    odt.insert({s, n, prev});
  }

  std::set<Node>::iterator split(int p) {
    if (p > n) return odt.end();
    auto it = odt.lower_bound(Node{p, 0, 0});
    if (it != odt.end() && it -> l == p) return it;
    it --; // it == p - 1
    int l = it -> l, r = it -> r, v = it -> v;
    odt.erase(it);
    odt.insert(Node{l, p - 1, v});
    auto ret = odt.insert(Node{p, r, v}).first;
    return ret;
  }

  // 保证区间 [l, r] 两端的边界被分裂（先右后左，安全）
  void split_range(int l, int r) {
    split(r + 1);
    split(l);
  }

  void assign(int l, int r, int v) {
    split_range(l, r);
    odt.erase(odt.lower_bound({l, 0, 0}), odt.upper_bound({r, 0, 0}));
    odt.insert({l, r, v});
  }

  int sum(int l, int r) {
    split_range(l, r);
    int res = 0;
    auto it = odt.lower_bound({l, 0, 0});
    for (; it != odt.end() && it->l <= r; ++it) {
      res = (res + (it->r - it->l + 1) % mod * it->v) % mod;
    }
    return res;
  }

  void copy(int l1, int r1, int l2, int r2) {
    if (l1 < l2) {
      auto r2_it = split(r2 + 1);
      auto l2_it = split(l2);
      auto r1_it = split(r1 + 1);
      auto l1_it = split(l1);

      vector<Node> tmp;
      for (auto it = l1_it; it != r1_it; ++it) {
        tmp.push_back(*it);
      }

      odt.erase(l2_it, r2_it);
      int offset = l2 - l1;
      for (const auto& node : tmp) {
        odt.insert({node.l + offset, node.r + offset, node.v});
      }
    } else {
      auto r1_it = split(r1 + 1);
      auto l1_it = split(l1);
      auto r2_it = split(r2 + 1);
      auto l2_it = split(l2);

      vector<Node> tmp;
      for (auto it = l1_it; it != r1_it; ++it) {
        tmp.push_back(*it);
      }

      odt.erase(l2_it, r2_it);
      int offset = l2 - l1;
      for (const auto& node : tmp) {
        odt.insert({node.l + offset, node.r + offset, node.v});
      }
    }
  }

  void swap(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
      std::swap(l1, l2);
      std::swap(r1, r2);
    }
    vector<Node> v1, v2;

    auto r2_it = split(r2 + 1);
    auto l2_it = split(l2);
    auto r1_it = split(r1 + 1);
    auto l1_it = split(l1);
    
    for (auto it = l2_it; it != r2_it; ++it) {
      v2.push_back(*it);
    }
    
    for (auto it = l1_it; it != r1_it; ++it) {
      v1.push_back(*it);
    }
    
    odt.erase(odt.lower_bound({l1, 0, 0}), odt.upper_bound({r1, 0, 0}));
    odt.erase(odt.lower_bound({l2, 0, 0}), odt.upper_bound({r2, 0, 0}));

    int offset = l2 - l1;
    for (const auto node : v1) {
      odt.insert({node.l + offset, node.r + offset, node.v});
    }

    for (const auto node : v2) {
      odt.insert({node.l - offset, node.r - offset, node.v});
    }
  }

  void reverse(int l, int r) {
    split_range(l, r);
    vector<Node> tmp;
    auto it = odt.lower_bound({l, 0, 0});
    for (; it != odt.end() && it->l <= r; ++it) {
      tmp.push_back(*it);
    }
    odt.erase(odt.lower_bound({l, 0, 0}), odt.upper_bound({r, 0, 0}));
    for (int i = tmp.size() - 1; i >= 0; --i) {
      odt.insert({l + r - tmp[i].r, l + r - tmp[i].l, tmp[i].v});
    }
  }

  template <typename Func>
  void traverse(int l, int r, Func func) {
    split_range(l, r);
    auto it = odt.lower_bound({l, 0, 0});
    for (; it != odt.end() && it->l <= r; ++it) {
      func(it);
    }
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> vec[i];
  }

  ODT odt(vec.begin() + 1, vec.end());

  for (int i = 1; i <= m; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      cout << odt.sum(l, r) % mod << "\n";
    } else if (op == 2) {
      int l, r, v;
      cin >> l >> r >> v;
      odt.assign(l, r, v);
    } else if (op == 3) {
      int l, r, v;
      cin >> l >> r >> v;
      odt.traverse(l, r, [&](auto it) { it->v = (it->v + v) % mod; });
    } else if (op == 4) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      odt.copy(l1, r1, l2, r2);
    } else if (op == 5) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      odt.swap(l1, r1, l2, r2);
    } else {  // op == 6
      int l, r;
      cin >> l >> r;
      odt.reverse(l, r);
    }
  }

  int cnt = 0;
  for (const auto& node : odt.odt) {
    for (int i = node.l; i <= node.r; ++i) {
      cout << node.v % mod << " \n"[++cnt == n];
    }
  }
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}