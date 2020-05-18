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


const int MAX_N = 2022;
const ll MOD = 1e9+7;


int n, m;
int p[MAX_N], id[MAX_N], pos[MAX_N];
map<int, int> e, add[MAX_N], del[MAX_N];


int getRoot(int u) {
	return p[u]==u ? u : p[u]=getRoot(p[u]);
}


ll mpow(ll x, ll n) {
	if (n<1) return 1;
	if (n==1) return x%MOD;
	ll t=mpow(x,n>>1);
	t=(t*t)%MOD;
	if (n&1) return (t*x)%MOD;
	return t;
}


int main() {
#ifdef DEBUG
	freopen("MAGICSTR.in", "r", stdin);
	freopen("MAGICSTR.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n >> m;
		fori(i,1,n) {
			add[i].clear();
			del[i].clear();
			p[i]=i;
		}
		fori(i,1,n) {
			id[i]=n-i+1;
			pos[id[i]]=i;
		}

		while (m--) {
			int l, r;
			cin >> l >> r;
			int mid=(l+r)>>1;
			int d = pos[r] - l;
			r=mid;
			++add[l][d];
			++del[r][d];
		}

		e.clear();
		fori(i,1,n) {
			foreach(it, add[i]) e[it->fr] += it->sc;
			foreach(it, e) {
				int d=it->fr;
				int j=i+d;
				if (j<0) continue;
				if (j>n) break;
				p[getRoot(i)]=getRoot(id[j]);
			}
			foreach(it, del[i]) {
				int x=it->fr;
				e[x] -= it->sc;
				if (e[x]<1) e.erase(x);
			}
		}

		ll ans = 0;
		fori(i,1,n) if (getRoot(i)==i) ++ans;
		ans = mpow(26, ans);
		cout << ans << endl;
	}

	return 0;
}