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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const int MAX_N = 2e5+5;
const int oo = 1e9 + 10;


int n, m;
int d[MAX_N], f[MAX_N], g[MAX_N];
ll s[MAX_N];
vector<pii> e[MAX_N];
set<pii> heap;


void dijkstra(int s) {
	fori(i,1,n) d[i]=oo;
	d[s]=0;
	heap.clear();
	heap.insert(mp(d[s], s));
	while (!heap.empty()) {
		int u=heap.begin()->sc;
		heap.erase(heap.begin());
		foreach(it, e[u]) {
			int v=it->sc;
			int tmp=d[u]+it->fr;
			if (tmp<d[v]) {
				set<pii>::iterator p=heap.find(mp(d[v], v));
				if (p!=heap.end()) heap.erase(p);
				d[v]=tmp;
				heap.insert(mp(d[v],v));
			}
		}
	}
}


ll cal(ll limit) {
	int l=1, r=n, k=0;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (g[mid]<limit) {
			k=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return limit*k - s[k];
}


int main() {
#ifdef DEBUG
	freopen("roads-building.in", "r", stdin);
	freopen("roads-building.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,1,m) {
		int x, y, c;
		cin >> x >> y >> c;
		e[x].pb(mp(c, y));
		e[y].pb(mp(c, x));
	}

	dijkstra(1);
	fori(i,1,n) f[i]=d[i];
	dijkstra(n);
	fori(i,1,n) g[i]=d[i];
	sort(g+1, g+1+n);
	s[0]=0;
	fori(i,1,n) s[i]=s[i-1]+g[i];

	ll ans=0;
	int shortest=f[n];
	fori(i,1,n) {
		ll tmp=shortest-f[i]-1;
		ll c = cal(tmp);
		if (d[i] < tmp) c -= (tmp-d[i]);
		ans += c;
	}
	cout << ans << endl;

	return 0;
}
