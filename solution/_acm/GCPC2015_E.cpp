#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5 + 55;
const int oo = 1e9;


int n, m, nA;
int a[MAX_N], d[MAX_N], trace[MAX_N];
bool multi[MAX_N];
vector<pii> e[MAX_N];
set<pii> heap;


bool solve() {
	for (int i = 1; i <= n; ++i) {
		d[i] = oo;
		multi[i] = false;
		trace[i] = -1;
	}
	d[1] = 0;
	heap.clear();
	heap.insert(pii(d[1], 1));
	while (!heap.empty()) {
		if (multi[n]) return true;
		int u = heap.begin()->second;
		heap.erase(heap.begin());
		foreach(it, e[u]) {
			int v = it->second;
			int tmp = d[u] + it->first;
			if (tmp > d[v]) continue;
			if (tmp == d[v]) {
				multi[v] = true;
				continue;
			}
			set<pii>::iterator p = heap.find(pii(d[v], v));
			if (p != heap.end()) heap.erase(p);
			d[v] = tmp;
			heap.insert(pii(d[v], v));
			trace[v] = u;
			if (!multi[u]) multi[v] = false;
			else multi[v] = true;
		}
	}
	return multi[n];
}


int main() {
#ifdef DEBUG
	freopen("GCPC2015_D.in", "r", stdin);
	freopen("GCPC2015_D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	cin >> n >> m >> nA;
	for (int i = 1; i <= nA; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		e[x].push_back(pii(c, y));
		e[y].push_back(pii(c, x));
	}

	if (solve()) cout << "yes\n";
	else cout << "no\n";
	return 0;
}