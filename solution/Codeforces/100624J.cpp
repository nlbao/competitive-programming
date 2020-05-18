#pragma comment(linker, "/STACK:1024000000")
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


const int MAX_N = 1e6+66;
const int oo = 1e9;


int n, m;
int a[MAX_N], d[MAX_N], d0[MAX_N];
vector<int> e[MAX_N];
bool ok[MAX_N];
queue<int> q[2];


int solve(int color) {
	int ans=-1, t=color;
	fori(i,0,1) while (!q[i].empty()) q[i].pop();
	fori(i,1,n) {
		ok[i]=1;
		d[i]=d0[i];
		if (d[i]==0) q[a[i]].push(i);
	}

	while (!q[t].empty()) {
		++ans;
		int tt=t;
		t^=1;
		while (!q[tt].empty()) {
			int u=q[tt].front();	q[tt].pop();
			ok[u]=0;
			foreach(it, e[u]) {
				int v=*it;
				--d[v];
				if (d[v]==0) q[a[v]].push(v);
			}
		}
	}
	fori(i,1,n) if (ok[i]) return oo;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("100624J.in", "r", stdin);
	freopen("100624J.out", "w", stdout);
#endif
	int nTest;
	scanf("%d", &nTest);
	while (nTest--) {
		scanf("%d%d", &n, &m);
		fori(i,1,n) {
			d[i]=0;
			e[i].clear();
		}
		fori(i,1,n) {
			scanf("%d", &a[i]);
			--a[i];
		}
		fori(i,1,m) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].pb(y);
			++d[y];
		}
		fori(i,1,n) d0[i]=d[i];
		printf("%d\n", min(solve(0), solve(1)));
	}

	return 0;
}