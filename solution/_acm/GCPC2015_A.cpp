#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;
const int MAX_P = 16;
const int MAX_MASK = 1<<MAX_P;
const int oo = 1e9+9;


int n, m, nP, totalTime, taxiTime;
int p[MAX_N], t[MAX_N], d[MAX_N];
int g[MAX_P][MAX_N], f[MAX_MASK][MAX_P][2];
vector<pii> e[MAX_N];
set<pii> heap;


void dijkstra(int s) {
	fori(i,1,n) d[i]=oo;
	d[s]=0;
	heap.clear();
	heap.insert(mp(d[s], s));
	while (!heap.empty()) {
		int u=heap.begin()->sc;
		heap.erase(heap.begin());
		foreach(it, e[u]) {
			int v=it->sc;
			int tmp=d[u]+it->fr;
			if (tmp<d[v]) {
				if (d[v]<oo) heap.erase(mp(d[v],v));
				d[v]=tmp;
				heap.insert(mp(d[v],v));
			}
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("GCPC2015_A.in", "r", stdin);
	freopen("GCPC2015_A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nP >> m >> totalTime >> taxiTime;
	fori(i,0,nP-1) {
		cin >> p[i] >> t[i];
		++p[i];
	}
	fori(i,1,m) {
		int x, y, c;
		cin >> x >> y >> c;
		++x, ++y;
		e[x].pb(mp(c, y));
		e[y].pb(mp(c, x));
	}

	fori(i,0,nP-1) {
		dijkstra(p[i]);
		fori(u,1,n) g[i][u]=d[u];
	}
	dijkstra(1);
	fori(u,1,n) g[nP][u]=d[u];

	int nMask=(1<<nP);
	fori(x,0,nMask-1)
		fori(i,0,nP-1)
			fori(j,0,1)
				f[x][i][j]=oo;
	fori(i,0,nP-1) {
		int x=(1<<i);
		f[x][i][0]=g[nP][p[i]] + t[i];
		f[x][i][1]=taxiTime + t[i];
	}
	fori(x,0,nMask-1) fori(i,0,nP-1) {
		fori(k,0,nP-1) {
			if (x&(1<<k)) continue;
			int y=x|(1<<k), tmp=g[i][p[k]];
			f[y][k][0]=min(f[y][k][0], f[x][i][0] + tmp + t[k]);
			f[y][k][1]=min(f[y][k][1], f[x][i][1] + tmp + t[k]);
			f[y][k][1]=min(f[y][k][1], f[x][i][0] + taxiTime + t[k]);
		}
	}

	int ans[2] = {oo, oo};
	fori(i,0,nP-1) {
		ans[0]=min(ans[0], f[nMask-1][i][0] + g[i][1]);
		ans[1]=min(ans[1], f[nMask-1][i][1] + g[i][1]);
		ans[1]=min(ans[1], f[nMask-1][i][0] + taxiTime);
	}
	if (ans[0]<=totalTime) cout << "possible without taxi" << endl;
	else if (ans[1]<=totalTime) cout << "possible with taxi" << endl;
	else cout << "impossible" << endl;

	return 0;
}