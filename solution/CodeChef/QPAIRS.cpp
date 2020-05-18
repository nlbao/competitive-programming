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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+55;
const int MAX_M = 2*MAX_N;
const int oo = 1e9+9;


int n, m, nQ;
int b[MAX_N], ans[MAX_N];
pair<pii, int> a[MAX_N], q[MAX_N];
pii f[MAX_M];
map<int, int> id;



inline void update(int i, pii val) {
	while (i<=m) {
		f[i]=max(f[i], val);
		i+=lowbit(i);
	}
}


inline int get(int i) {
	pii ans(-2*oo, -oo);
	while (i>0) {
		ans=max(ans, f[i]);
		i-=lowbit(i);
	}
	return ans.sc;
}


int main() {
#ifdef DEBUG
	freopen("QPAIRS.in", "r", stdin);
	freopen("QPAIRS.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nQ;
	fori(i,1,n) {
		cin >> b[i];
		b[i]=-b[i];
	}
	fori(i,1,n) {
		int x;
		cin >> x;
		x=-x;
		id[x];
		a[i]=mp(mp(b[i], x), -i);
	}
	sort(a+1, a+1+n);

	fori(i,1,nQ) {
		int x, y;
		cin >> x >> y;
		x=-x, y=-y;
		q[i]=mp(mp(x,y), i);
		id[y];
	}
	sort(q+1, q+1+nQ);

	m=0;
	foreach(it, id) it->sc=++m;
	fori(i,0,m) f[i]=mp(-2*oo, -oo);

	int k=1;
	fori(i,1,nQ) {
		int x=q[i].fr.fr, y=q[i].fr.sc;
		while (k<=n && a[k].fr.fr <= x) {
			update(id[a[k].fr.sc], mp(a[k].fr.fr + a[k].fr.sc, a[k].sc));
			++k;
		}
		int p = get(id[y]);
		if (p<=-oo) p=-1;
		else p=-p;
		ans[q[i].sc]=p;
	}
	fori(i,1,nQ) cout << ans[i] << endl;

	return 0;
}