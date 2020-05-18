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


const int MAX_N=2e5+5;
const int MAX_T=1e6+6 + MAX_N;
const int oo = 1e9+MAX_T;

int n;
pii a[MAX_N], b[MAX_N];
int g[MAX_N], ans[MAX_N];
set<pii> heap;


bool check(int limit) {
	fori(i,1,n) {
		int d=limit-a[i].sc, t=a[i].fr;
		if (d<0) return 0;
		b[i]=mp(t,t+d);
	}
	int k=0, i=1;
	heap.clear();
	while (i<=n || !heap.empty()) {
		++k;
		if (i<=n) {
			if (b[i].sc<k) return 0;
			if (heap.empty()) k=max(k, b[i].fr);
			while (i<=n && b[i].fr<=k) {
				heap.insert(mp(b[i].sc, i));
				++i;
			}
		}
		int j=heap.begin()->sc;
		heap.erase(heap.begin());
		if (b[j].sc<k) return 0;
		g[j]=k;
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100090I.in", "r", stdin);
	freopen("100090I.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		int x, y;
		cin >> x >> y;
		a[i] = mp(x,y);
	}

	int l=0, r=oo, minCost=-1;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) {
			minCost=mid;
			fori(i,1,n) ans[i]=g[i];
			r=mid-1;
		}
		else l=mid+1;
	}
	// cout << minCost << endl;
	fori(i,1,n) cout << ans[i] << " ";

	return 0;
}