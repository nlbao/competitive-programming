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


const int MAX_N = 104;
const int MAX_W = 104;
const int MAX_L = 12;
const int MAX_S = 1e4+44;
const int oo = 1e6;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


struct node {
	int l, x, y;
	node(int l, int x, int y) : l(l), x(x), y(y) {}
};


int L, H, W, n, S;
int d[MAX_L][MAX_W][MAX_W], id[MAX_L][MAX_W][MAX_W], a[MAX_N], f[MAX_S], p[MAX_N];
bool ok[MAX_L][MAX_W][MAX_W], up[MAX_L][MAX_W][MAX_W], down[MAX_L][MAX_W][MAX_W];;
queue<node> q;


inline bool onBoard(int l, int x, int y) {
	if (l<1 || l>L || x<1 || x>H || y<1 || y>W) return 0;
	return ok[l][x][y];
}


void bfs(int l, int x, int y) {
	fori(i,1,n) a[i]=oo;
	fori(k,1,L) fori(i,1,H) fori(j,1,W) d[k][i][j]=oo;
	d[l][x][y]=0;
	q.push(node(l, x, y));
	while (!q.empty()) {
		node u=q.front();	q.pop();
		l=u.l, x=u.x, y=u.y;
		int tmp=d[l][x][y];
		a[id[l][x][y]]=3*tmp;
		fori(k,0,3) {
			int i=x+dx[k], j=y+dy[k];
			if (!onBoard(l,i,j) || d[l][i][j]<oo) continue;
			d[l][i][j]=tmp+1;
			q.push(node(l,i,j));
		}
		int tl=l;
		if (up[tl][x][y]) {
			l=tl+1;
			if (onBoard(l,x,y) && d[l][x][y]>=oo) {
				d[l][x][y]=tmp+1;
				q.push(node(l,x,y));
			}
		}
		if (down[tl][x][y]) {
			l=tl-1;
			if (onBoard(l,x,y) && d[l][x][y]>=oo) {
				d[l][x][y]=tmp+1;
				q.push(node(l,x,y));
			}
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("5066.in", "r", stdin);
	freopen("5066.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	string s;
	while (nTest--) {
		int sl, sx, sy;
		cin >> L >> H >> W >> n >> S;
		filla(ok, 1);
		filla(up, 0);
		filla(down, 0);
		fori(k,1,L) fori(i,1,H) {
			cin >> s;
			fori(j,1,W) {
				char ch=s[j-1];
				if (ch=='X') {
					ok[k][i][j]=0;
					continue;
				}
				if (ch=='S') sl=k, sx=i, sy=j;
				else if (ch=='U') up[k][i][j]=1;
				else if (ch=='D') down[k][i][j]=1;
			}
		}
		filla(id, 0);
		fori(i,1,n) {
			int f, r, c;
			cin >> f >> r >> c >> p[i];
			id[f][r][c]=i;
		}
		bfs(sl, sx, sy);
		filla(f, 0);
		fori(i,1,n) ford(x,S-a[i],0) {
			int y=x+a[i];
			f[y]=max(f[y], f[x]+p[i]);
		}
		int ans=0;
		fori(i,0,S) ans=max(ans, f[i]);
		cout << ans << endl;
	}

	return 0;
}