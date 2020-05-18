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


const int MAX_N = 1e5+15;

struct Query {
	int a, b, x, y, id;
	bool operator < (const Query &o) const {
		pii u=mp(a, b), v=mp(o.a, o.b);
		if (u!=v) return u<v;
		return id < o.id;
	}
};

int n, nQ, blockSize;
pair<pii, int> a[MAX_N];
Query q[MAX_N];
int finalAns[MAX_N], pos[MAX_N];
vector<pii> e[MAX_N];


inline int cntLessThan(int k, int val) {
	vector<pii>::iterator it = upper_bound(e[k].begin(), e[k].end(), mp(val, MAX_N+111));
	return it - e[k].begin();
}


int main() {
#ifdef DEBUG
	freopen("intervalsandqueries.in", "r", stdin);
	freopen("intervalsandqueries.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nQ;
	fori(i,1,n) {
		int x, y;
		cin >> x >> y;
		a[i]=mp(mp(x, y), i);
	}
	fori(i,1,nQ) {
		cin >> q[i].a >> q[i].b >> q[i].x >> q[i].y;
		q[i].id = i;
	}
	sort(a+1,a+1+n);
	sort(q+1,q+1+nQ);

	blockSize = min(n, int(sqrt(n)+4));
	for (int l=1, r, k=1; l<=n; l=r+1, ++k) {
		r=min(n, l+blockSize-1);
		fori(i,l,r) pos[i] = k;
		e[k].clear();
	}

	int p = n;
	ford(i,nQ,1) {
		int id = q[i].id, u = q[i].a, v = q[i].b, x = q[i].x, y = q[i].y;
		++x, ++y;
		while (p>0 && a[p].fr.fr >= u) {
			int k = pos[a[p].sc];
			e[k].pb(mp(a[p].fr.sc, a[p].sc));
			sort(e[k].begin(), e[k].end());
			--p;
		}
		int ans = 0;
		for (int l=1, r, k=1; l<=n; l=r+1, ++k) {
			r=min(n, l+blockSize-1);
			if (r<x) continue;
			if (l>y) break;
			if (x<=l && r<=y) {
				ans += cntLessThan(k, v);
				continue;
			}
			foreach(it, e[k]) {
				int i = it->sc;
				if (it->fr<=v && x <= i && i <= y) ++ans;
			}
		}
		finalAns[id] = ans;
	}
	fori(i,1,nQ) cout << finalAns[i] << endl;

	return 0;
}