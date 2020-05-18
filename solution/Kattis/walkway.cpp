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


struct node {
	int a, b, h;
	node() {}
	node(int a, int b, int h) : a(a), b(b), h(h) {}
	ll area() {
		return (a+b)*h;
	}
	node rotate() {
		return node(b, a, h);
	}
};


const int MAX_N = 1e3+33;
const ll oo=1e18;


int n;
node a[MAX_N][2];
ll d[MAX_N][2], g[MAX_N];
bool ok[MAX_N][2];


ll dijkstra(int s, int t) {
	fori(i,1,n) fori(j,0,1) {
		d[i][j]=oo;
		ok[i][j]=1;
	}
	d[s][0]=d[s][1]=0;
	while (1) {
		int u=-1, x;
		fori(i,1,n) fori(j,0,1) {
			if (!ok[i][j]) continue;
			if (u>-1 && d[i][j]>=d[u][x]) continue;
			u=i, x=j;
		}
		if (u==-1) break;
		if (u==t) return d[u][x];
		ok[u][x]=0;
		fori(v,1,n) fori(y,0,1) {
			if (!ok[v][y] || a[u][x].a != a[v][y].b) continue;
			d[v][y]=min(d[v][y], d[u][x]+g[v]);
		}
	}
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("walkway.in", "r", stdin);
	freopen("walkway.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);

	while (1) {
		cin >> n;
		if (n<1) break;
		int x, y, z, s=n+1, t=n+2;
		fori(i,1,n) {
			cin >> x >> y >> z;
			a[i][0]=node(x,y,z);
			a[i][1]=a[i][0].rotate();
		}
		n += 2;
		cin >> x >> y;
		a[s][0]=a[s][1]=node(x, 0, 0);
		a[t][0]=a[t][1]=node(0, y, 0);
		fori(i,1,n) g[i]=a[i][0].area();
		ll ans = dijkstra(s, t);
		cout << ans/100.0 << endl;
	}

	return 0;
}