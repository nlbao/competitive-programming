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
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = int(2.5*1e5)+5;
const int MAX_F = 4*MAX_N;


struct Query {
	int t, l, r, x, pos;
	Query() {}
	Query(int t, int l, int r, int x) : t(t), l(l), r(r), x(x) {}
	Query(int t, int pos) : t(t), pos(pos) {}
};


int n, u, v, crrTurn, id, pos;
int f[MAX_F], g[MAX_F];
vector<pii> seg[MAX_N];
pii a[MAX_N];
Query q[MAX_N];


inline void segInsert(int l, int r) {
	if (!seg[id].empty() && seg[id].back().sc+1>=l) {
		seg[id].back().sc=r;
		return;
	}
	seg[id].pb(mp(l, r));
}


void updateIT(int k, int l, int r) {
	if (l>v || r<u || f[k]==crrTurn) return;
	if (u<=l && r<=v && g[k]!=crrTurn) {
		g[k]=crrTurn;
		f[k]=crrTurn;
		segInsert(l, r);
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	updateIT(kl, l, mid);
	updateIT(kr, mid+1, r);
	if (g[kl]==crrTurn || g[kr]==crrTurn) g[k] = crrTurn;
	if (f[kl]==crrTurn && f[kr]==crrTurn) f[k] = crrTurn;
}


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


int main() {
#ifdef DEBUG
	freopen("MANYLIST.in", "r", stdin);
	freopen("MANYLIST.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nQ, m=0;
	cin >> n >> nQ;
	fori(i,1,nQ) {
		int t, l, r, x, p;
		cin >> t;
		if (t==0) {
			cin >> l >> r >> x;
			q[i]=Query(0, l, r, x);
			a[++m]=mp(x, i);
		}
		else {
			cin >> p;
			q[i]=Query(1, p);
		}
	}

	crrTurn=0;
	sort(a+1,a+1+m);
	filla(f, 0);
	filla(g, 0);
	for (int i=1, j=1; i<=m; i=j) {
		++crrTurn;
		while (j<=m && a[j].fr==a[i].fr) {
			id=a[j].sc;
			u=q[id].l, v=q[id].r;
			updateIT(1,1,n);
			++j;
		}
	}

	filla(f, 0);
	fori(i,1,nQ) {
		if (q[i].t==0) {
			foreach(it, seg[i]) {
				int l=it->fr, r=it->sc;
				update(l, 1);
				update(r+1, -1);
			}
		}
		else cout << get(q[i].pos) << endl;
	}

	return 0;
}