void dfs(int u) {	// number of BCCs may > n
	num[u]=low[u]=++nTime;
	if (e[u].empty()) {
		bc[++nC]=vector<int>(1, u);
		return;
	}
	stk.push(u);
	foreach(it, e[u]) {
		int v=*it;
		if (v==p[u]) continue;  // no duplicate edges
		if (p[v]) low[u]=min(low[u], num[v]);
		else {
			p[v]=u;
			dfs(v);
			low[u]=min(low[u], low[v]);
			if (p[u]<0 || low[v]>=num[u]) {	// Init: p[u] = -1 <==> u is root.
				bc[++nC]=vector<int>(1, u);
				int x=-1;
				while (x!=v) {
					x=stk.top();	stk.pop();
					bc[nC].pb(x);
				}
			}
		}
	}
}