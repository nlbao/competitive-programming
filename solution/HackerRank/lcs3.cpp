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


const int MAX_N = 3033;

struct Node {
	int x, y, z;
	Node() {}
	Node(int x, int y, int z) : x(x), y(y), z(z) {}
	bool operator < (const Node &o) const {
		return x!=o.x ? x<o.x : y!=o.y ? y<o.y : z<o.z;
	}
};


int n;
int a[3][MAX_N], f[MAX_N][MAX_N];
vector<int> e[3][MAX_N];
vector<Node> b, tmp;


inline void update(int i, int j, int val) {
	for (int x=i; x<=n; x+=lowbit(x))
		for (int y=j; y<=n; y+=lowbit(y))
			f[x][y]=max(f[x][y], val);
}


inline int get(int i, int j) {
	int ans=0;
	for (int x=i; x>0; x-=lowbit(x))
		for (int y=j; y>0; y-=lowbit(y))
			ans=max(ans, f[x][y]);
	return ans;
}


int solve() {
	fori(x,0,2) {
		fori(i,1,n) e[x][i].clear();
		fori(i,1,n) e[x][a[x][i]].pb(i);
	}
	b.clear();
	fori(i,1,n) {
		foreach(x, e[0][i]) foreach(y, e[1][i]) foreach(z, e[2][i]) {
			b.pb(Node(*x,*y,*z));
		}
	}
	sort(b.begin(), b.end());

	int ans=0, m=sz(b);
	filla(f, 0);
	tmp.clear();
	for (int i=0, j=0; i<m; i=j) {
		while (j<m && b[j].x==b[i].x) {
			int y=b[j].y, z=b[j].z;
			int t=get(y-1, z-1) + 1;
			ans=max(ans, t);
			tmp.pb(Node(t, y, z));
			++j;
		}
		foreach(it, tmp) update(it->y, it->z, it->x);
		tmp.clear();
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("lcs3.in", "r", stdin);
	freopen("lcs3.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n;
		fori(x,0,2) fori(i,1,n) cin >> a[x][i];
		cout << solve() << endl;
	}

	return 0;
}