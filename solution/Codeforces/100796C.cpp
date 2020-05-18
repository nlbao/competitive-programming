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


const int MAX_N = 1e5+55;
const int oo = 1e9+7;


int n, nLeaf, K;
int p[MAX_N], f[MAX_N], a[MAX_N];
bool isLeaf[MAX_N], b[MAX_N];
vector<int> e[MAX_N];


void dfs(int u) {
	if (isLeaf[u]) return void(f[u] = b[u] ? 0 : oo);
	f[u]=oo;
	int s=0;
	foreach(it, e[u]) {
		int v=*it;
		dfs(v);
		f[u]=min(f[u], f[v]+1);
		s=min(oo, s+f[v]);
	}
	f[u]=min(f[u], s);
}


int solve(int limit, bool isMax) {
	fori(i,1,n) {
		b[i]=0;
		if (!isMax && a[i]<=limit) b[i]=1;
		if (isMax && a[i]>=limit) b[i]=1;
	}
	dfs(1);
	return f[1];
}


int main() {
#ifdef DEBUG
	freopen("100796C.in", "r", stdin);
	freopen("100796C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> K;
	p[1]=-1;
	fori(i,2,n) {
		cin >> p[i];
		e[p[i]].pb(i);
	}
	nLeaf=0;
	fori(i,1,n) {
		cin >> a[i];
		isLeaf[i] = e[i].empty();
		if (isLeaf[i]) ++nLeaf;
	}

	int l, r, minAns=oo, maxAns=0;
	// min
	l=0, r=oo;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (solve(mid, 0)<=K) {
			minAns=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	// max
	K = n-nLeaf-K;
	l=0, r=oo;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (solve(mid, 1)<=K) {
			maxAns=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << minAns << " " << maxAns << endl;

	return 0;
}