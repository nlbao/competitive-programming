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


const int LIMIT = 1000;
const int MAX_N = 111*LIMIT;
const int MAX_A = 313;

int n, T, len, maxA;
int a[MAX_N];
ll f[MAX_A], g[MAX_A], p[MAX_A][MAX_A], r[MAX_A][MAX_A];


void update(int i, ll val) {
	while (i<=maxA) {
		g[i]=max(g[i], val);
		i+=lowbit(i);
	}
}


ll get(int i) {
	ll ans=0;
	while (i>0) {
		ans=max(ans, g[i]);
		i-=lowbit(i);
	}
	return ans;
}


ll solve(int K, int minVal) {
	len=n*K;
	fori(i,n+1,len) a[i]=a[i-n];
	ll ans=0;
	filla(g, 0);
	fori(i,1,len) if (a[i]>=minVal) {
		ll f=get(a[i])+1;
		ans=max(ans, f);
		update(a[i], f);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("583D.in", "r", stdin);
	freopen("583D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> T;
	map<int, int> q;
	fori(i,1,n) {
		cin >> a[i];
		q[a[i]];
	}
	maxA=0;
	foreach(it, q) it->sc=++maxA;
	fori(i,1,n) a[i]=q[a[i]];

	int nP=T/LIMIT, nR=T%LIMIT;
	filla(p, 0);
	filla(r, 0);
	fori(x,1,maxA) {
		solve(LIMIT, x);
		fori(y,x,maxA) p[x][y]=get(y);
		solve(nR, x);
		fori(y,x,maxA) r[x][y]=get(y);
	}

	ll ans=0;
	filla(f, 0);
	fori(i,1,nP) {
		ford(y,maxA,1) {
			ford(x,y,1) f[y]=max(f[y], f[x]+p[x][y]);
			f[y]=max(f[y], p[1][y]);
		}
	}
	ford(y,maxA,1) {
		ford(x,y,1) f[y]=max(f[y], f[x]+r[x][y]);
		f[y]=max(f[y], r[1][y]);
	}
	fori(i,1,maxA) ans=max(ans, f[i]);
	cout << ans << endl;

	return 0;
}