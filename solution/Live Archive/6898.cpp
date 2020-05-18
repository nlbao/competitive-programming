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

struct point {
	int x,y,color;
	point() {x=y=color=0;}
	point(int x, int y, int color) : x(x), y(y), color(color) {}
};

const int MAX_N = 6e4 + 44;
const int MAX_F = 4*MAX_N;

int limit, id, pos, color;
int f[2][MAX_F][3][3], c[2][MAX_F][3];
int g[MAX_N][3];
point a[MAX_N];


bool cmpX(const point &a, const point &b) {
	return a.x < b.x;
}
bool cmpY(const point &a, const point &b) {
	return a.y < b.y;
}


void initTree() {
	filla(f, 0);
	filla(c, 0);
}


void update(int k, int l, int r) {
	if (l>r || l>pos || r<pos) return;
	++c[id][k][color];
	if (l==r) {
		fori(x,0,2) fori(y,0,2) {
			if (c[id][k][x] || c[id][k][y])
				f[id][k][x][y] = 1;
		}
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
	fori(x,0,2) {
		fori(y,0,2) {
			if (x==y) continue;
			f[id][k][x][y] = max(c[id][k][x], c[id][k][y]);
			int t1=f[id][kl][x][y] + c[id][kr][y];
			int t2=c[id][kl][x] + f[id][kr][x][y];
			f[id][k][x][y] = max(f[id][k][x][y], max(t1, t2));
		}
	}
}


int treeGet(int k, int x, int y) {
	return max(f[k][1][x][y], f[k][1][y][x]);
}


void treeInsert(int k, int x, int c) {
	id=k;
	pos=x;
	color=c;
	update(1,1,limit);
}


int sub_solve(int m) {
	int ans=0;
	initTree();
	fori(i,0,2) g[0][i]=0;
	fori(i,1,m) fori(k,0,2) g[i][k]=g[i-1][k]+(a[i].color==k);
	ford(i,m,0) {
		fori(k,0,2) {
			int x=(k+1)%3, y=(x+1)%3;
			ans=max(ans, g[i][k] + treeGet(0, x, y));
			ans=max(ans, g[i][k] + treeGet(1, x, y));
		}
		treeInsert(0, a[i].x, a[i].color);
		treeInsert(1, a[i].y, a[i].color);
	}
	return ans;
}


int solve(int m, bool (*cmp)(const point&, const point&)) {
	int ans=0;
	// inc
	sort(a+1,a+1+m,cmp);
	ans=max(ans, sub_solve(m));
	// dec
	for (int i=1, j=m; i<j; ++i, --j)
		swap(a[i], a[j]);
	ans=max(ans, sub_solve(m));
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6898.in", "r", stdin);
	freopen("6898.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n[3];
	map<int,int> q;
	int nTest=read();
	fori(testid,1,nTest) {
		fori(i,0,2) cin >> n[i];
		int m=0;
		q.clear();
		fori(i,0,2) {
			fori(k,1,n[i]) {
				int x, y;
				cin >> x >> y;
				a[++m]=point(x,y,i);
				q[x], q[y];
			}
		}
		int c=0;
		foreach(it,q) it->sc=++c;
		limit=c;
		fori(i,1,m) {
			a[i].x=q[a[i].x];
			a[i].y=q[a[i].y];
		}
		cout << max(solve(m, cmpX), solve(m, cmpY)) << endl;
	}

	return 0;
}