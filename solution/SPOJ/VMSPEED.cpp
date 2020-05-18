#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = 517;
const double oo = 1e12 + 10;
const double EPS = 1e-8;


struct edge {
	int v, s, t;
	double w;
	edge() {}
	edge(int v, int s, int t): v(v), s(s), t(t) {}
};


int n, m, top, nCount, nC;
vector<edge> e[MAX_N];
int sz[MAX_N];
int num[MAX_N], low[MAX_N], stack[MAX_N], c[MAX_N];
double d[MAX_N];
bool inQ[MAX_N], toN[MAX_N], from1[MAX_N];


bool findPath(int s, int t) {
	queue<int> q;
	fill(inQ, false);
	q.push(s);
	inQ[s] = true;
	while (!q.empty()) {
		int u = q.front();	q.pop();
		if (u == t) return true;
		for (int i = 0; i < sz[u]; ++i) {
			int v = e[u][i].v;
			if (!inQ[v]) {
				q.push(v);
				inQ[v] = true;
			}
		}
	}
	return false;
}


void dfs(int u) {
	inQ[u] = from1[u] = true;
	stack[++top] = u;
	num[u] = low[u] = ++nCount;
	for (int i = 0; i < sz[u]; ++i) {
		int v = e[u][i].v;
		if (!toN[v]) continue;
		if (num[v] == -1) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (inQ[v])
			low[u] = min(low[u], num[v]);
	}

	if (low[u] == num[u]) {
		++nC;
		int v = -1;
		while (top > 0 && v != u) {
			v = stack[top--];
			c[v] = nC;
			inQ[v] = false;
		}
	}
}


bool cmp(int x, int y) {
	return d[x] < d[y];
}

set<int, bool(*)(int, int)> q (cmp);


bool check(double limit) {
	double sum = 0;
	for (int u = 1; u <= n; ++u) {
		d[u] = oo;
		inQ[u] = false;
		if (!from1[u]) continue;
		for (int i = 0; i < sz[u]; ++i) {
			int v = e[u][i].v;
			if (!toN[v]) continue;
			e[u][i].w = double(e[u][i].s) - limit * double(e[u][i].t);
			if (e[u][i].w < 0) {
				if (c[u] == c[v]) {
					// cout << "!!! " << u << " " << v << endl;
					return true;
				}
				sum += e[u][i].w;
			}
		}
	}

	q.clear();
	d[1] = 0;
	q.insert(1);
	inQ[1] = true;

	while (!q.empty()) {
		int u = *(q.begin());
		q.erase(u);
		inQ[u] = false;

		if (d[u] + EPS < sum) return true;
		if (u == n && d[u] < EPS) return true;

		for (int i = 0; i < sz[u]; ++i) {
			int v = e[u][i].v;
			if (!toN[v]) continue;
			double tmp = d[u] + e[u][i].w;
			if (tmp + EPS < d[v]) {
				d[v] = tmp;
				if (inQ[v]) q.erase(v);
				else inQ[v] = true;
				q.insert(v);
			}
		}
	}
	return d[n] < EPS;
}


int main() {
#ifdef DEBUG
	freopen("VMSPEED.in", "r", stdin);
	freopen("VMSPEED.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	double l = 0, r = 0;
	for (int i = 0; i < m; ++i) {
		int u, v, s, t;
		scanf("%d%d%d%d", &u, &v, &s, &t);
		e[u].push_back(edge(v, s, t));
		r += double(max(s, t));
	}

	for (int i = 1; i <= n; ++i)
		sz[i] = (int)e[i].size();

	if (!findPath(1, n)) {
		printf("-1\n");
		return 0;
	}

	toN[1] = true;
	for (int i = 2; i <= n; ++i)
		toN[i] = findPath(i, n);

	for (int i = 1; i <= n; ++i) {
		from1[i] = inQ[i] = false;
		num[i] = -1;
	}
	nCount = top = nC = 0;
	dfs(1);

	double ans = -1;
	for (int id = 0; id < 77; ++id) {
		double mid = (l+r)/2.0;
		if (check(mid)) {
			ans = mid;
			r = mid;
		}
		else l = mid;
	}
	printf("%.6lf\n", ans);
	return 0;
}