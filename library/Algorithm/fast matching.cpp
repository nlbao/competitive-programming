struct Matching {
	static const int MAX_N = 2e5 + 55;

	int nx, ny, mx[MAX_N], my[MAX_N], d[MAX_N];
	vector<int> e[MAX_N];

	void init(int x, int y) {
		nx = x, ny = y;
		for (int i = 0; i <= nx; ++i)
			e[i].clear();
	}

	void addEdge(int u, int v) {	e[u].push_back(v);	}

	bool bfs_matching() {
		queue<int> q;
		for (int i = 1; i <= nx; ++i)
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
		filla(mx, 0);
		filla(my, 0);
		while (bfs_matching())
			for (int i = 1; i <= nx; ++i)
				if (!mx[i] && dfs_matching(i))
					++ans;
		return ans;
	}
};