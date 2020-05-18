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


const int MAX_N = 111;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};
const int oo = 1e9;


int n, m;
string a[MAX_N];
int d[MAX_N][MAX_N];
queue<pii> q;


inline bool ok(int x, int y) {
	return x>=0 && y>=0 && x<n && y<m && a[x][y]!='*';
}


int solve(int x, int y) {
	fori(i,0,n-1) fori(j,0,m-1) d[i][j]=oo;
	d[x][y]=-1;
	q.push(mp(x,y));
	while (!q.empty()) {
		pii p=q.front();	q.pop();
		x=p.fr, y=p.sc;
		if (a[x][y]=='C' && d[x][y]>-1) return d[x][y];
		fori(k,0,3) {
			int xx=x, yy=y;
			while (true) {
				xx+=dx[k], yy+=dy[k];
				if (!ok(xx, yy)) break;
				if (d[x][y]+1 < d[xx][yy]) {
					d[xx][yy]=d[x][y]+1;
					q.push(mp(xx, yy));
				}
			}
		}
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("MLASERP.in", "r", stdin);
	freopen("MLASERP.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> m >> n;
	fori(i,0,n-1) cin >> a[i];
	bool ok=0;
	fori(i,0,n-1) {
		if (ok) break;
		fori(j,0,m-1) if (a[i][j]=='C') {
			cout << solve(i, j) << endl;
			ok=1;
			break;
		}
	}

	return 0;
}