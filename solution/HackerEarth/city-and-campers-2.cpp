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

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;


int n;
int p[MAX_N];
multiset<int> s, d;


int getRoot(int u) {
	return p[u] < 0 ? u : p[u] = getRoot(p[u]);
}


inline void add(int x) {
	set<int>::iterator r = s.lower_bound(x), l = r;
	bool a = r != s.begin();
	bool b = r != s.end();
	if (a) --l, d.insert(abs(*l - x));
	if (b) d.insert(abs(x - *r));
	if (a && b) d.erase(d.find(abs(*r - *l)));
	s.insert(x);
}


inline void remove(int x) {
	set<int>::iterator it = s.lower_bound(x), l = it, r = it;
	if (it == s.end()) return;
	++r;
	bool a = it != s.begin();
	bool b = r != s.end();
	if (a) --l;
	if (a) d.erase(d.find(abs(*it - *l)));
	if (b) d.erase(d.find(abs(*it - *r)));
	if (a && b) d.insert(abs(*r - *l));
	s.erase(it);
}


int main() {
#ifdef DEBUG
	freopen("city-and-campers-2.in", "r", stdin);
	freopen("city-and-campers-2.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i) {
		p[i] = -1;
		add(1);
	}

	int nQ = read();
	while (nQ--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = getRoot(x), y = getRoot(y);
		if (x != y) {
			remove(-p[x]);
			remove(-p[y]);
			p[x] += p[y];
			p[y] = x;
			add(-p[x]);
		}
		int ans = 0;
		if (!d.empty())
			ans = *d.begin();
		printf("%d\n", ans);
	}
	return 0;
}