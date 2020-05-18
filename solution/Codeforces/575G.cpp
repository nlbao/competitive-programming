#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


const int MAX_N = 1e5+5;
const int oo = 1e9+7;


int n, m;
vector<pii> e[MAX_N];
int q[MAX_N], trace[MAX_N], f[MAX_N], d[MAX_N], c[MAX_N], turn[MAX_N];
bool ok[MAX_N];


inline void update(int u, int v, int val) {
	c[v]=c[u]+1;
	trace[v]=u;
	f[u]=val;
}


int main() {
#ifdef DEBUG
	freopen("575G.in", "r", stdin);
	freopen("575G.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	fori(i,1,m) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		++x, ++y;
		e[x].pb(mp(c, y));
		e[y].pb(mp(c, x));
	}

	////////////////////////
	int l=1, r=1;
	q[1]=1;
	fori(i,1,n) d[i]=oo;
	d[1]=0;
	while (l<=r) {
		int rr=r;
		while (l<=rr) {
			int u=q[l++], tmp=d[u]+1;
			foreach(it, e[u]) {
				int v=it->sc;
				if (tmp>d[v]) continue;
				if (d[v]>=oo) q[++r]=v;
				d[v]=tmp;
			}
		}
	}

	////////////////////////
	filla(ok, 1);
	filla(trace, 0);
	filla(f, 0);
	fori(i,1,n) c[i]=oo;
	c[n]=ok[n]=0;
	l=r=1;
	q[1]=n;
	while (l<=r) {
		int u=q[l++];
		foreach(it, e[u]) {
			int v=it->sc;
			if (!ok[v] || it->fr>0) continue;
			ok[v]=0;
			q[++r]=v;
			c[v]=c[u]+1;
			trace[v]=u;
		}
	}
	int tmp=oo;
	fori(i,1,n) if (!ok[i]) tmp=min(tmp, d[i]);
	l=1, r=0;
	fori(i,1,n) if (!ok[i] && d[i]==tmp) q[++r]=i;

	int crrTurn=0;
	filla(turn, 0);
	while (l<=r) {
		int rr=r;
		pii tmp=mp(oo, oo);
		fori(i,l,rr) {
			int u=q[i];
			foreach(it, e[u]) {
				int v=it->sc;
				if (!ok[v]) continue;
				tmp=min(tmp, mp(d[v], it->fr));
			}
		}
		++crrTurn;
		while (l<=rr) {
			int u=q[l++];
			foreach(it, e[u]) {
				int v=it->sc;
				if (turn[v]==crrTurn) {
					if (mp(d[v], it->fr)==tmp && c[u]+1<c[v])
						update(u, v, tmp.sc);
					continue;
				}
				if (!ok[v] || mp(d[v], it->fr)>tmp) continue;
				ok[v]=0;
				q[++r]=v;
				update(u, v, tmp.sc);
				turn[v]=crrTurn;
			}
		}
	}

	////////////////////////
	vector<int> a, b;
	int u=1;
	while (u>0) {
		a.pb(u-1);
		if (u>1) b.pb(f[u]);
		u=trace[u];
	}
	while (!b.empty() && b.back()==0) b.pop_back();
	if (b.empty()) b.pb(0);
	ford(i,sz(b)-1,0) printf("%d", b[i]);
	printf("\n%d\n", sz(a));
	foreach(it, a) printf("%d ", *it);

	return 0;
}