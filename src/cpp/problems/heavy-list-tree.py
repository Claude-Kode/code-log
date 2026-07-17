def path_add(u, v, k):
	while top[u] != top[v]:          # 只要 u 和 v 不在同一条重链
		if dep[top[u]] < dep[top[v]]: # 让 u 是重链顶端更深的那个
			swap(u, v)
		# 此时 u 所在重链顶端更深
		segtree.add(dfn[top[u]], dfn[u], k)  # 处理这条重链上的区间
		u = fa[top[u]]               # 跳到上一条重链（轻边）

	# 现在 u 和 v 在同一条重链上了
	if dep[u] > dep[v]:
		swap(u, v)                   # 让 u 是较浅的那个
	segtree.add(dfn[u], dfn[v], k)   # 处理最后一段连续区间