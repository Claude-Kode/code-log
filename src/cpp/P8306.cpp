// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

// #define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 3e6 + 10;

int cnt_node = 0;
vector<int> cnt(N + 1);
vector<vector<int>> t(N, vector<int> (64, 0));

int to(char c) {
  if (c <= '9') return c - '0';
  if (c <= 'Z') return c - 'A' + 10;
  if (c <= 'z') return c - 'a' + 36;
}

void insert(string s) {
  int n = s.size(), p = 0;
  for(size_t i = 0; i < s.size(); i ++) {
    int c = to(s[i]);
    if (t[p][c] == 0) t[p][c] = ++cnt_node;
    p = t[p][c];
    cnt[p] ++;
  }
}

int ask(string s) {
  int n = s.size(), p = 0;
  for(size_t i = 0; i < s.size(); i ++) {
    int c = to(s[i]);
    if (t[p][c] == 0) return 0;
    p = t[p][c];
  }
  return cnt[p];
}

void clear_trie() {
  for (int i = 0; i <= cnt_node; i++) {
    for(int j = 0; j <= 63; j ++) {
      t[i][j] = 0;
    }
  }
  for(int i = 0; i <= cnt_node; i ++) cnt[i] = 0;
  cnt_node = 0;
}

void solve() { 
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i ++) {
    string temp; cin >> temp;
    insert(temp);
  }

  for(int i = 1; i <= m; i ++) {
    string temp; cin >> temp;
    cout << ask(temp) << endl;
  }
  clear_trie();
}

/*
trie 的 dep 就是单词的位置大小
比如单词的第一个字符就是字典树的第一层
但是注意 每次字典树更新字符都是直接 new 一个节点出来 节点的编号跟那个完全不是一回事的
字典树的节点本身没意义任何信息 字典树的边代表的是单词

这个矩阵写法好像有点难以理解
t的 第一维是一个节点的编号 第二维表示的是当前节点通往的字符 1 代表通往这个字符
我可以告诉你 在这个写法里面 一个节点只通往一个字符

在我们查询的时候 我们是使用字符进行查询的

其实你可以抽象理解成 每个节点都是一个有所有字符的 vector

其实本质上就是一个邻接表
t[node] = (char, nxt_nod_id); 
然后为了方便查询 把第一个 char 变成了桶

其实确实是 一个边 我们来想一下邻接表 
adj[u].push_back({v, w})
我们来想象一下 出边的下一个节点指向 v, w 就是字符
边的边权相当于字符
或者说是这样的 对于一个邻接矩阵
grid[i][j] = w 表示 从 i --> j 的边权是 w
我们用字典树的时候是要用单词的字母来查询 
本质上是一个

其实可以这样想 就是你查询这个节点的时候 能不能通过你当前想要查的字母到达下一个节点 这个可不可以

本质上 从 a 到 b 是可达的 , 和 从 a 节点, 查询 b 可以查到下一个节点 
这两者是逻辑等价的
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt; 
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}

