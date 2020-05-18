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



const int MAX_N = 1011;
const int oo = 1e9;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int n, m;
int a[MAX_N][MAX_N], d[MAX_N][MAX_N][4], f[4][4];
string s;
queue<pii> q;


inline bool ok(int x, int y) {
	if (x<1 || y<1 || x>n || y>m) return 0;
	return a[x][y]>-1;
}


void bfs(int val) {
	while (!q.empty()) q.pop();
	fori(i,1,n) fori(j,1,m) if (a[i][j]==val) {
		d[i][j][val]=0;
		q.push(mp(i, j));
	}
	while (!q.empty()) {
		int i=q.front().fr, j=q.front().sc;
		q.pop();
		int tmp = d[i][j][val]+1;
		fori(k,0,3) {
			int x=i+dx[k], y=j+dy[k];
			if (!ok(x, y) || d[x][y][val]<oo) continue;
			d[x][y][val] = tmp;
			if (a[x][y]>0) --d[x][y][val];
			q.push(mp(x, y));
		}
	}
}


int solve() {
	int ans=oo;
	fori(x,1,3) {
		fori(y,1,3) f[x][y]=oo;
		f[x][x]=0;
	}
	fori(i,1,n) fori(j,1,m)
		if (a[i][j] == 0) {
			fori(x,1,3) fori(y,1,3) if (y!=x) {
				f[x][y] = min(f[x][y], d[i][j][x] + d[i][j][y] - 1);
				f[x][y] = max(f[x][y], 0);
			}
		}
		else {
			int x = a[i][j];
			fori(y,1,3) if (y!=x) f[x][y] = min(f[x][y], d[i][j][y]);
		}
	fori(x,1,3) fori(y,1,3) f[x][y] = min(f[x][y], f[y][x]);

	fori(x,1,3) fori(y,1,3) if (y!=x) fori(z,1,3) if (z!=y && z!=x)
		ans = min(ans, f[x][y] + f[y][z]);
	fori(i,1,n) fori(j,1,m) if (a[i][j] == 0) {
		fori(x,1,3) {
			int y = (x==3) ? 1 : x+1;
			int z = (y==3) ? 1 : y+1;
			int t = min(oo, min(f[x][y] + f[y][z], f[x][z] + f[z][y]));
			ans = min(ans, d[i][j][x] + t);
			ans = min(1LL*ans, 1LL*d[i][j][x] + 1LL*d[i][j][y] + 1LL*d[i][j][z] - 2);
		}
	}
	return (ans>=oo) ? -1 : ans;
}


int main() {
#ifdef DEBUG
	freopen("591E.in", "r", stdin);
	freopen("591E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,1,n) {
		cin >> s;
		fori(j,1,m) {
			char x = s[j-1];
			a[i][j] = (x=='#') ? -1 : (x=='.') ? 0 : x-'0';
			fori(k,1,3) d[i][j][k]=oo;
		}
	}
	fori(i,1,3) bfs(i);
	cout << solve() << endl;

	return 0;
}