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


const int MAX_N = 1e4+44;
const int MOD = 1013;
const int BASE = 31;


int n, nAns, code, p[MAX_N];
string s;
pii a[MAX_N], trace[MAX_N][MOD+4];
ll f[MAX_N][MOD+4];
vector<int> q[MAX_N];
char ans[MAX_N];


void getAns(int i, int x) {
	if (i<1) return;
	if (a[i].fr==0) ans[++nAns]=char(trace[i][x].sc);
	getAns(i-1, trace[i][x].fr);
}


void solve() {
	filla(trace, 0);
	filla(f, 0);
	f[0][0]=1;
	q[0].clear();
	q[0].pb(0);
	fori(i,1,n) {
		q[i].clear();
		if (a[i].fr==0) { // = ?
			foreach(it, q[i-1]) {
				int x=*it;
				fori(k,int('a'),int('z')) {
					int y=(x*BASE + k)%MOD;
					if (!f[i][y]) q[i].pb(y);
					f[i][y]+=f[i-1][x];
					trace[i][y]=mp(x, k);
				}
			}
		}
		else {
			foreach(it, q[i-1]) {
				int x=*it;
				int y=(x*a[i].fr + a[i].sc)%MOD;
				if (!f[i][y]) q[i].pb(y);
				f[i][y]+=f[i-1][x];
				trace[i][y]=mp(x, 0);
			}
		}
	}
	ll c=f[n][code];
	if (c!=1) {
		cout << c;
		return;
	}

	nAns=0;
	getAns(n, code);
	for (int i=0,k=1,len=sz(s); i<len; ++i) {
		if (s[i]=='?') cout << ans[k++];
		else cout << s[i];
	}
}


int main() {
#ifdef DEBUG
	freopen("100482E.in", "r", stdin);
	freopen("100482E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	p[0]=1;
	fori(i,1,MAX_N-1) p[i]=(p[i-1]*BASE)%MOD;

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> code;
		cin >> s;
		n=0;
		int len=sz(s);
		for (int i=0,j=0; i<len; i=j) {
			if (s[i]=='?') {
				a[++n]=mp(0, 0);
				++j;
				continue;
			}
			int h=0;
			while (j<len && s[j]!='?') h=(h*BASE+s[j++])%MOD;
			a[++n]=mp(p[j-i], h);
		}
		cout << "Case #" << testid << ": ";
		solve();
		cout << endl;
	}

	return 0;
}