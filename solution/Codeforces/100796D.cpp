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


const int MAX_N = 555;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};
const int oo = 1e9;


int n, m, cA, cB;
string a[MAX_N];
int g[MAX_N][MAX_N], d[MAX_N][MAX_N];
queue<pii> q;


inline bool ok(int x, int y) {
	if (x<0 || x>=n || y<0 || y>=m) return 0;
	if (g[x][y] || a[x][y]=='#') return 0;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100796D.in", "r", stdin);
	freopen("100796D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> m >> n;
	cin >> cA >> cB;
	fori(i,0,n-1) cin >> a[i];

	filla(g, 0);
	fori(i,0,n-1) fori(j,0,m-1) d[i][j]=oo;
	g[0][0]=1;
	d[0][0]=0;

	q.push(mp(0,0));
	while (!q.empty()) {
		int x=q.front().fr, y=q.front().sc;
		q.pop();
		fori(k,0,3) {
			int i=x+dx[k];
			int j=y+dy[k];
			if (!ok(i,j)) continue;
			int tmp=d[x][y];
			if (g[x][y]==1) {
				g[i][j]=2;
				tmp+=cB;
			}
			else {
				g[i][j]=1;
				tmp+=cA;
			}
			d[i][j]=tmp;
			q.push(mp(i,j));
		}
	}
	if (d[n-1][m-1] >= oo) cout << "IMPOSSIBLE\n";
	else cout << d[n-1][m-1] << endl;

	return 0;
}