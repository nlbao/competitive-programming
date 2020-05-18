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


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = int(2.5*1e5)+5;

int n;
int f[MAX_N];
set<pii> seg[MAX_N];


inline void update(int i, int x) {
	while (i<=n) {
		f[i]+=x;
		i+=lowbit(i);
	}
}


inline int get(int i) {
	int ans=0;
	while (i>0) {
		ans+=f[i];
		i-=lowbit(i);
	}
	return ans;
}


inline void updateRange(int l, int r, int val) {
	update(l, val);
	update(r+1, -val);
}


int main() {
#ifdef DEBUG
	freopen("MANYLIST.in", "r", stdin);
	freopen("MANYLIST.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nQ;
	cin >> n >> nQ;
	filla(f, 0);
	vector<pii> a, b;
	__typeof(seg[0].begin()) p, it;
	fori(i,1,nQ) {
		int t, u, v, x, pos;
		cin >> t;
		if (t==0) {
			cin >> u >> v >> x;
			a.clear();
			b.clear();
			b.pb(mp(u,v));
			if (!seg[x].empty()) {
				p=seg[x].lower_bound(mp(u, v));
				if (p==seg[x].end()) --p;
				while (p!=seg[x].begin() && p->sc>=u) --p;
				while (p!=seg[x].end() && p->sc<u) ++p;
				for (it=p; it!=seg[x].end(); ++it) {
					int l=it->fr, r=it->sc;
					if (l>v) break;
					a.pb(*it);
					if (l<u) b.pb(mp(l,u-1));
					if (r>v) b.pb(mp(v+1,r));
				}
			}
			foreach(it, a) {
				seg[x].erase(*it);
				updateRange(it->fr, it->sc, -1);
			}
			foreach(it, b) {
				seg[x].insert(*it);
				updateRange(it->fr, it->sc, 1);
			}
		}
		else {
			cin >> pos;
			cout << get(pos) << endl;
		}
	}

	return 0;
}