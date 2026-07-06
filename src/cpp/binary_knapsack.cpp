// binary knapsack

void solve() {
	int n, m ; cin >> n >> m ; 
	vector<pair<int, int>> vec(n + 1)  
	for (int i = 1 ; i <= n ; i ++) {
		cin >> vec[i].first >> vec[i].second ; 
	}

	// 发现一维属性不能描述的时候 可以考虑拓展维度
	// 当你发现有的维度可以优化的时候 要考虑降低维度 比如 Floyd
	// 注意 我们优化的是数组 , 而不是具体的状态的内容
	// 我们只是不关注状态的是对第几件进行取舍 但是状态的重量属性依旧是被限制的
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		int w = vec[i].first, c = vec[i].second; 
		for (int j = 0; j <= m ; j++) {
			dp[i][j] = dp[i - 1][j] ;
			if (j >= w) dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + c) ; 
		}
	}
	
	cout << *max_element(dp[n].begin(), dp[n].end()) << endl ; 

} 

// 当 01 背包优化成 1维的时候
// 二维的时候我们可以确保 i 层的数据一定是从 i-1 层更新上来的
// 也就是新的数据一定是以旧的数据作为基底更新上来的
// 所以说对于重量我们不能采取顺序便利了 我们采取逆序便利 
// 因为新数据对于旧的数据具有单调性 , 我们从大到小 , 新的数据已经不会比旧的数据小 
// 所以我们从大到小的便利过程中一定不会碰到新的数据
// 重点就是新的数据必须是从旧的数据更新上来的

void solve() {
	int n, m ; cin >> n >> m ; 
	vector<pair<int, int>> vec(n + 1)  
	for (int i = 1 ; i <= n ; i ++) {
		cin >> vec[i].first >> vec[i].second ; 
	}

	// 发现一维属性不能描述的时候 可以考虑拓展维度
	// 当你发现有的维度可以优化的时候 要考虑降低维度 比如 Floyd
	// 注意 我们优化的是数组 , 而不是具体的状态的内容
	// 我们只是不关注状态的是对第几件进行取舍 但是状态的重量属性依旧是被限制的
	vector<int> dp((m + 1, 0));
	for (int i = 1; i <= n; i++) {
		int w = vec[i].first, c = vec[i].second; 
		for (int j = m; j >= 0; j--) {
			if (j >= w) dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + c) ; 
		}
	}
	


} 

// un_boudned Kanpsack 
// 这个是存在这个物品可以被多次选中的 所以可以用新的数据来更新新的数据
// 也就是可以用已经选了这个物品的状态来接着更新
// 牛而逼之啊