// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif

struct Node {
  int x, y;
  string name;
};
REGISTER_REFLECT(Node, x, y, name)

struct Edge {
  int u, v, w;
  vector<int> path;
};
REGISTER_REFLECT(Edge, u, v, w, path)

void solve() {
  int n = 5; cin >> n;
  vector<int> vec = {1, 2, 3, 4, 5};
  vector<vector<int>> g = {{1, 2}, {3}, {}};
  pair<int, string> p = {42, "hello"};
  map<int, string> mp = {{1, "a"}, {2, "b"}};
  unordered_map<string, int> ump = {{"x", 1}, {"y", 2}};
  set<int> st = {3, 1, 2};
  unordered_set<string> ust = {"b", "a"};
  multiset<int> mst = {2, 2, 1};

  Node nd{10, 20, "root"};
  vector<Node> nodes = {nd, {1, 2, "leaf"}};
  map<int, vector<pair<int, Node>>> nested = {
      {1, {{0, nd}, {1, {7, 8, "inner"}}}}};

  debug(n, vec, g, p, mp, ump, st, ust, mst, nd, nodes, nested);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
