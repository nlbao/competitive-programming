// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


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


const int MAX_N = 111;

EdmondMatching matching;


int main() {
#ifdef DEBUG
	freopen("SEAGRP.in", "r", stdin);
	freopen("SEAGRP.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		int n, m, x, y;
		cin >> n >> m;
		matching.init(n);
		while (m--) {
			cin >> x >> y;
			matching.addEdge(x, y);
		}
		int c=matching.getMatch();
		if (c*2==n) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}