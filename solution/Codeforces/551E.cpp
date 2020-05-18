#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 5*1e5 + 5;
const int MAX_LEN = 777;


int n, nQ, len, m;
pair<ll, int> a[MAX_N];
pii s[MAX_LEN];
ll c[MAX_LEN];


inline ll get(int id, int i) {
	return a[i].first + c[id];
}


void query1(int l, int r, ll value) {
	for (int i = 0; i < m; ++i) {
		int u = s[i].first, v = s[i].second - 1;
		if (v < l) continue;
		if (u > r) break;
		if (l <= u && v <= r)
			c[i] += value;
		else {
			for (int k = u; k <= v; ++k)
				if (l <= a[k].second && a[k].second <= r)
					a[k].first += value;
			sort(a+u, a+v+1);
		}
	}
}


bool has(ll value, int id) {
	int l = s[id].first, r = s[id].second-1;
	while (l <= r) {
		int mid = (l+r)>>1;
		ll t = get(id, mid);
		if (t == value) return true;
		if (t < value) l = mid+1;
		else r = mid-1;
	}
	return false;
}


int query2(ll value) {
	int u = -1;
	for (int i = 0; i < m; ++i)
		if (has(value, i)) {
			u = i;
			break;
		}
	if (u < 0) return -1;

	int v = u;
	for (int i = m-1; i > u; --i)
		if (has(value, i)) {
			v = i;
			break;
		}

	int minI = MAX_N;
	for (int i = s[u].first; i < s[u].second; ++i)
		if (get(u, i) == value)
			minI = min(minI, a[i].second);

	int maxI = -1;
	for (int i = s[v].first; i < s[v].second; ++i)
		if (get(v, i) == value)
			maxI = max(maxI, a[i].second);
	return maxI - minI;
}


int main() {
#ifdef DEBUG
	freopen("551E.in", "r", stdin);
	freopen("551E.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	for (int i = 0; i < n; ++i)
		a[i] = make_pair(read(), i);
	len = sqrt(n);
	m = 0;
	for (int i = 0, j = min(len, n); i < n; i += len, j = min(j+len, n)) {
		s[m++] = make_pair(i, j);
		sort(a+i, a+j);
	}
	filla(c, 0);

	while (nQ--) {
		int t = read();
		if (t == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			query1(l-1, r-1, x);
		}
		else {
			int x = read();
			printf("%d\n", query2(x));
		}
	}
	return 0;
}