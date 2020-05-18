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
const int MAX_X = 1e3+3;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};
const int oo=1e9;


int id[MAX_X][MAX_X], d[MAX_X][MAX_X];
int p[MAX_N];
queue<pii> q[2];
vector<pair<int, pii> > e;


inline bool onBoard(int x, int y) {
	return x>=0 && x<MAX_X && y>=0 && y<MAX_X;
}


int getRoot(int u) {
	if (p[u]<1) return u;
	return p[u]=getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("gridmst.in", "r", stdin);
	freopen("gridmst.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(id, 0);
	fori(i,0,MAX_X-1) fori(j,0,MAX_X-1) d[i][j]=oo;
	int n, c=0;
	cin >> n;
	fori(i,1,n) {
		int x,y;
		cin >> x >> y;
		if (id[x][y]) continue;
		id[x][y]=++c;
		d[x][y]=0;
		q[0].push(mp(x,y));
	}

	int t=0;
	ll ans=0;
	filla(p, 0);
	while (!q[t].empty()) {
		int tt=t;
		t^=1;
		e.clear();
		while (!q[t].empty()) q[t].pop();
		while (!q[tt].empty()) {
			pii u=q[tt].front();	q[tt].pop();
			int x=u.fr, y=u.sc, tmp=d[x][y]+1;
			fori(k,0,3) {
				int xx=x+dx[k], yy=y+dy[k];
				if (!onBoard(xx,yy)) continue;
				if (d[xx][yy]>=oo) {
					d[xx][yy]=tmp;
					id[xx][yy]=id[x][y];
					q[t].push(mp(xx,yy));
					continue;
				}
				int u=getRoot(id[x][y]);
				int v=getRoot(id[xx][yy]);
				if (u==v) continue;
				e.pb(mp(d[xx][yy]+tmp, mp(u,v)));
			}
		}
		sort(e.begin(), e.end());
		foreach(it, e) {
			int u=getRoot(it->sc.fr);
			int v=getRoot(it->sc.sc);
			if (u==v) continue;
			p[u]=v;
			ans += it->fr;
		}
	}
	cout << ans << endl;

	return 0;
}