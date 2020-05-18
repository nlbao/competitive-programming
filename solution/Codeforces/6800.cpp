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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N=2e3+33;
const int oo=1e9+9;


int n, m, sum;
int d[MAX_N];
bool ok[MAX_N], to1[MAX_N];
vector<pii> e[MAX_N];
vector<int> e2[MAX_N];
queue<int> q;


bool solve() {
	fori(i,1,n) {
		d[i]=oo;
		ok[i]=1;
	}
	d[1]=ok[1]=0;
	while (!q.empty()) q.pop();
	q.push(1);
	while (!q.empty()) {
		int u=q.front();	q.pop();
		ok[u]=1;
		foreach(it, e[u]) {
			int v=it->sc, tmp=d[u]+it->fr;
			if (!to1[v] || d[v]<=tmp) continue;
			d[v]=tmp;
			if (d[v]<sum) return 1;
			if (ok[v]) {
				ok[v]=0;
				q.push(v);
			}
		}
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("6800.in", "r", stdin);
	freopen("6800.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		fori(i,1,n) {
			e[i].clear();
			e2[i].clear();
		}
		sum=0;
		fori(i,1,m) {
			int x, y, c;
			cin >> x >> y >> c;
			++x, ++y;
			if (c<0) sum+=c;
			e[x].pb(mp(c,y));
			e2[y].pb(x);
		}

		filla(to1, 0);
		to1[1]=1;
		while (!q.empty()) q.pop();
		q.push(1);
		while (!q.empty()) {
			int u=q.front();	q.pop();
			foreach(it, e2[u]) {
				int v=*it;
				if (to1[v]) continue;
				to1[v]=1;
				q.push(v);
			}
		}

		cout << "Case #" << testid << ": ";
		if (solve()) cout << "possible\n";
		else cout << "not possible\n";
	}

	return 0;
}