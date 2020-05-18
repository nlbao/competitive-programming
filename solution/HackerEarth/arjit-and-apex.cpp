#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   cin >> x;   return x;   }


const int MAX_N = 1e5 + 55;


multiset<pii> qa, qb;
multiset<int> ha, hb;


int main() {
#ifdef DEBUG
	freopen("arjit-and-apex.in", "r", stdin);
	freopen("arjit-and-apex.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		int m, n;
		cin >> m >> n;
		qa.clear();
		qb.clear();
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			qa.insert(pii(x, y));
		}
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			qb.insert(pii(x, y));
		}

		int g, h, cg = 0, ch = 0;
		cin >> g >> h;
		ha.clear();
		hb.clear();
		foreach(it, qa) {
			pii u = *it;
			multiset<pii>::iterator it2 = qb.find(u);
			if (it2 == qb.end()) {
				ha.insert(u.first);
				continue;
			}
			qb.erase(it2);
			++cg, ++ch;
		}
		foreach(it, qb) hb.insert(it->first);
		foreach(it, ha) {
			int u = *it;
			multiset<int>::iterator it2 = hb.find(u);
			if (it2 != hb.end()) {
				++cg;
				hb.erase(it2);
			}
		}

		if (cg >= g && ch >= h) cout << "Great\n";
		else if (cg >= g) cout << "Good\n";
		else cout << ":(\n";
	}
	return 0;
}