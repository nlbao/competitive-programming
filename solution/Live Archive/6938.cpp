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


const int MAX_N = 666;
const int MAX_D = 1e4+44;
const ll oo = 1e18;


int n;
int a[MAX_N], b[MAX_N], d[MAX_N], p[MAX_N];
ll f[MAX_N][MAX_N];


ll solve() {
	if (n==1) return d[1];
	set<int> q;
	q.insert(MAX_D);
	q.insert(-MAX_D);
	fori(i,1,n) {
		q.insert(a[i]);
		q.insert(b[i]);
	}
	int m=0;
	foreach(it, q) p[++m]=*it;

	filla(f, 0);
	fori(len,2,m) fori(i,1,m-len+1) {
		int j=i+len-1;
		int u=-1;
		fori(k,1,n) if (p[i]<a[k] && b[k]<p[j]) if (u<0 || d[k]>d[u]) u=k;
		if (u<0) continue;
		ll t=oo;
		int l=i, r=j;
		while (p[l]!=a[u]) ++l;
		while (p[r]!=b[u]) --r;
		fori(x,l,r) t=min(t, f[i][x] + d[u] + f[x][j]);
		f[i][j]=t;
	}
	return f[1][m];
}


int main() {
#ifdef DEBUG
	freopen("6938.in", "r", stdin);
	freopen("6938.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) cin >> a[i] >> b[i] >> d[i];
		cout << solve() << endl;
	}

	return 0;
}