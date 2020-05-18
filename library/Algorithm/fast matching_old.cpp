struct Matching {
	int nX, nY;
	vector<vector<int> > e;
	vector<int> mx, my, d;
	queue<int> q;

	Matching(int nX, int nY) : nX(nX), nY(nY), d(nX+1), e(nX+1), mx(nX+1), my(nY+1)	{}

	void addEdge(int u, int v) {
		e[u].push_back(v);
	}

	bool bfs_matching() {
		while (!q.empty()) q.pop();
		for (int i = 1; i <= nX; ++i)
			if (!mx[i]) {
				d[i] = 1;
				q.push(i);
			}
			else d[i] = 0;
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();  q.pop();
			foreach(it, e[u]) {
				int v = *it;
				if (!d[my[v]]) {
					d[my[v]] = d[u] + 1;
					if (!my[v]) return true;
					q.push(my[v]);
				}
			}
		}
		return false;
	}

	bool dfs_matching(int u) {
		if (u == 0) return true;
		foreach(it, e[u]) {
			int v = *it;
			if (d[my[v]] == d[u]+1 && dfs_matching(my[v])) {
				mx[u] = v;
				my[v] = u;
				return true;
			}
		}
		d[u] = 0;
		return false;
	}

	int getMatch() {
		int ans = 0;
		fillv(mx, 0);
		fillv(my, 0);
		while (bfs_matching())
			for (int i = 1; i <= nX; ++i)
				if (!mx[i] && dfs_matching(i))
					++ans;
		return ans;
	}
};