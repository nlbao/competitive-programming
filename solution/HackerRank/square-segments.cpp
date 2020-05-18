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


const int MAX_N = 5e5+15;
const int MAX_A = 1e6+16;
const int MAX_P = 1e5;
const ll BASE = 1e4+7;


int nP;
ll crrHash;
int p[MAX_P], c[MAX_P], f[MAX_A], id[MAX_A];
ll h[MAX_P];
bool ok[MAX_A];
unordered_map<ll, int> q;


inline ll getHash(int a) {
	while (a>1) {
		int x=f[a];
		int i=id[x];
		a/=x;
		c[i]^=1;
		if (c[i]) crrHash += h[i];
		else crrHash -= h[i];
	}

	return crrHash;
}


int main() {
#ifdef DEBUG
	freopen("square-segments.in", "r", stdin);
	freopen("square-segments.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(ok, 1);
	nP=0;
	h[0]=1;
	fori(i,2,MAX_A-1) if (ok[i]) {
		p[++nP]=i;
		id[i]=nP;
		f[i]=i;
		h[nP] = h[nP-1] * BASE;
		for (ll j=i+i; j<MAX_A; j+=i) {
			ok[j]=0;
			f[j]=i;
		}
	}
	crrHash=0;
	filla(c, 0);
	q[0]=1;

	int n=read();
	ll ans=0;
	fori(i,1,n) {
		int a;
		cin >> a;
		ll h=getHash(a);
		if (has(q, h)) {
			ans += q[h];
			++q[h];
		}
		else q[h]=1;
	}
	cout << ans << endl;

	return 0;
}