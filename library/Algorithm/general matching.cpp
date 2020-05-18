struct EdmondMatching {    // O(V^3)
	static const int MAX_N = 333;
	int n;
	vector<int> e[MAX_N];
	int match[MAX_N], p[MAX_N], base[MAX_N], q[MAX_N];
	bool used[MAX_N], blossom[MAX_N], ok[MAX_N];

	void init(int nn) {
		n=nn;
		fori(i,0,n) e[i].clear();
	}

	void addEdge(int u, int v) {
		e[u].pb(v);		e[v].pb(u);
	}

	int lca(int a, int b) {
		filla(ok, 0);
		while (1) {
			a = base[a];
			ok[a] = 1;
			if (match[a] == -1) break;
			a = p[match[a]];
		}
		while (1) {
			b = base[b];
			if (ok[b]) return b;
			b = p[match[b]];
		}
	}

	void mark_path(int u, int b, int children) {
		while (base[u] != b) {
			blossom[base[u]] = blossom[base[match[u]]] = 1;
			p[u] = children;
			children = match[u];
			u = p[match[u]];
		}
	}

	int find_path(int root) {
		filla(used, 0);
		filla(p, -1);
		fori(i,1,n) base[i] = i;
		used[root] = 1;

		queue<int> q;
		q.push(root);
		while (!q.empty()) {
			int u = q.front();	  q.pop();
			foreach(it, e[u]) {
				int v = *it;
				if (base[u] == base[v] || match[u] == v)  continue;
				if (v == root || (match[v] != -1 && p[match[v]] != -1)) {
					int curbase = lca(u, v);
					filla(blossom, 0);
					mark_path(u, curbase, v);
					mark_path(v, curbase, u);
					fori(i,1,n) if (blossom[base[i]]) {
						base[i] = curbase;
						if (!used[i]) {
							used[i] = 1;
							q.push(i);
						}
					}
				}
				else if (p[v] == -1) {
					p[v] = u;
					if (match[v] == -1) return v;
					v = match[v];
					used[v] = 1;
					q.push(v);
				}
			}
		}
		return -1;
	}

	int getMatch() {
		filla(match, -1);
		fori(u,1,n) if (match[u] == -1)
			foreach(it, e[u]) {
				int v=*it;
				if (match[v] > -1) continue;
				match[v] = u;	match[u] = v;
				break;
			}
		fori(u,1,n) if (match[u] == -1) {
			int v = find_path(u);
			while (v != -1) {
				int pv = p[v],	ppv = match[pv];
				match[v] = pv;	match[pv] = v;
				v = ppv;
			}
		}
		int ans=0;
		fori(i,1,n) if (match[i] > -1) ++ans;
		return ans/2;	// the maximum matching
	}
};