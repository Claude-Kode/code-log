```
vector<int> vis(n + 1), fa(n + 1); 
vector<vector<int>> dep(n + 1);
std::function <void(int,int, int)> dfs = [&](int u, int father, int depth) -> void{
  if (vis[u]) return;
  vis[u] = 1; dep[depth].push_back(u);fa[u] = father;
  for(const auto &v : adj[u]) dfs(v, u, depth + 1);
};
```
其实很简单 但是以后有个印象写会更好         