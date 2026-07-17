void Dijkstra(int x , int t) {

    struct edge { int u ; int v ; int w ; 
        bool operator< (edge other) const {
            return w < other.w ; 
        }
    } ; 
    
    int n , m ; cin >> n >> m ; 
    vector<int> dis(n + 1 , INT_MAX) , vis(n + 1 , 0) ; 
    vector<vectro<edge>> adj(n + 1) ; 
    for ( int i = 1 ; i <= m ; i ++ ) {
        int u , v , w ; cin >> u >> v >> w ; 
        adj[u].push_back(edge{u , v , w}) ;  
    }

    priority_queue<edge> pq ;
    for ( const auto &{u , v , w} : adj[s] ) {
        pq.emplace_back(edge{u , v , w}) ; 
    } 

    while (!pq.empty()) {
        auto [u , v , w] = pq.top() ; pq.pop() ; 
        if ( !vis[v] ) continue ; vis[v] = 1 ; 
        for (const auto& [uu , vv , ww] : adj[v] ) {
            
        }
    }

    cout << -1 << endl ; 

}



void Floyd(int s , int t) {
   int n ; cin >> n ; 
   vector<vector<int>> grid(n + 1 , vector<int>(n + 1 , INT_MAX)) ; 
   
   for ( int i = 1 ; i <= n - 1 ; i ++ ) {
        int u , v , w ; cin >> u >> v >> w ; 
        grid[u][v] = w ; 
        grid[v][u] = w ; 
   }
   
   for ( int i = 1 ; i <= n ; i ++ ) grid[i][i] = 0 ; 

   vector<vector<vector<int>>> f(n + 1 , vector<vector<int>(n + 1 , vector<int>(n + 1 , INT_MAX))) ; 

    for ( int k = 1 ; k <= n ; k ++ ) {
        for ( int i = 1 ; i <= n ; i ++ ) {
            for ( int j = 1 ; j <= n ; j ++ ) {
                f[k][i][j] = min(
                    f[k - 1][i][j] , 
                    f[k - 1][i][k] + f[k - 1][k][j] 
                ) ;
            }
        }
    }
   
    cout << f[n][s][t] << endl ;

}
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    memset(dis, 0x3f, sizeof(dis)); // 初始化
    dis[s] = 0;
    q.push({dis[s], s}); // 将起点加入队列
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u]) // 若 u 已访问，跳过
            continue;
        vis[u] = true;                          // 标记为已访问
        for (int j = 0; j < adj[u].size(); j++) // 遍历 u 可以去的所有点
        {
            int v = adj[u][j].to, w = adj[u][j].w;
            if (dis[v] > dis[u] + w) // 若从 u 去 v 更优，更改最短路，丢进队列
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}


bool bellman_ford(int s) {
    // 初始化距离数组
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    
    // 动态规划迭代n-1轮
    for (int i = 0; i < n - 1; i++) {  // 为什么是n-1？因为最短路径最多包含n-1条边
        bool updated = false;  // 优化：记录本轮是否有更新
        
        // 遍历所有边进行松弛操作
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            
            // 核心松弛操作：类似动态规划的状态转移
            // 用dist[a] + w更新dist[b]，这就是"动态规划更新"
            if (dist[a] != INF && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                updated = true;
            }
        }
        
        // 如果本轮没有任何更新，提前结束（优化）
        if (!updated) break;
    }
    
    // 检测负权环：再进行一次松弛，如果还能更新则存在负权环
    for (int j = 0; j < m; j++) {
        int a = edges[j].a, b = edges[j].b, w = edges[j].w;
        if (dist[a] != INF && dist[b] > dist[a] + w) {
            return true;  // 存在负权环
        }
    }
    return false;  // 不存在负权环
}


void bellman_ford() {
	int i, j;
	bool flag;//用于优化的
	int dis[203];//保存最短路径
	//初始化
	fill(dis,dis+n,MAX);//其他点为+∞
	dis[s] = 0;//源点初始化为0
	m = m<<1;//此处和m = 2*m是一样的，因为建立的无向图
	for(int i = 1; i < n ; i++) {  //进行|V|-1次 
		flag = false;//刚刚开始标记为假
		for(j=0;j<m;j++) { //对每个边
			//if  (v.d>u.d+w(u,v))
			if(dis[edge[j].u]>dis[edge[j].v]+edge[j].w){//进行松弛操作
				dis[edge[j].u] = dis[edge[j].v]+edge[j].w;//松弛成功
				flag = true;//若松弛成功则标记为真
			}
		}
		if(!flag)//若所有的边i的循环中没有松弛成功的
			break;//退出循环
		//此优化可以大大提高效率。
	}
	printf("%d\n",dis[t]==MAX?-1:dis[t]);//输出结果
}