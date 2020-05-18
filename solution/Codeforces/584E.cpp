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


const int MAX_N = 2011;


int n;
int a[MAX_N], b[MAX_N], p[MAX_N], e[MAX_N], d[MAX_N];
bool ok[MAX_N];
vector<pii> q;


ll solve(int s) {
	ok[s]=0;
	if (d[s]==0) return 0;
	ll t=d[s], sum=d[s];
	int u=e[s];
	while (u!=s) {
		ok[u]=0;
		t=max(t, 1LL*d[u]);
		sum+=d[u];
		u=e[u];
	}
	while (d[s]!=t) s=e[s];
	u=e[s];
	while (u!=s) {
		q.pb(mp(e[u], u));
		u=e[u];
	}
	return sum-t;
}


int main() {
#ifdef DEBUG
	freopen("584E.in", "r", stdin);
	freopen("584E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> a[i];
	fori(i,1,n) {
		cin >> b[i];
		p[b[i]]=i;
	}
	fori(i,1,n) {
		e[i]=p[a[i]];
		d[i]=abs(i-e[i]);
	}

	ll ans=0;
	filla(ok, 1);
	fori(i,1,n) if (ok[i]) ans+=solve(i);
	cout << ans << endl;

	n=q.size();
	cout << n << endl;
	reverse(q.begin(), q.end());
	fori(i,0,n-1) cout << q[i].fr << " " << q[i].sc << endl;

	return 0;
}