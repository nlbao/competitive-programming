#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;


int n, nA, p[MAX_N];
vector<int> a[MAX_N];
vector<pii> ans;
bool ok[MAX_N];


bool solve() {
	ans.clear();
	int u=-1, v=-1;
	bool hasOdd=0;
	fori(i,1,nA) {
		int m=sz(a[i]);
		if (m==1) {
			u=a[i][0];
			break;
		}
		else if (m==2) {
			v=a[i][0];
		}
		if (m&1) hasOdd=1;
	}
	if (u>-1) {
		fori(i,1,n) if (i!=u) ans.pb(mp(i, u));
		return 1;
	}
	if (hasOdd) return 0;
	if (v==-1) return 0;
	u=p[v];
	ans.pb(mp(u,v));
	filla(ok, 1);
	fori(i,1,n) if (i!=u && i!=v && ok[i]) {
		int x=i, c=0;
		do {
			ok[x]=0;
			if (c) ans.pb(mp(x,u));
			else ans.pb(mp(x,v));
			c^=1;
			x=p[x];
		} while (x!=i);
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("577D.in", "r", stdin);
	freopen("577D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> p[i];
	nA=0;
	filla(ok, 1);
	fori(i,1,n) {
		int x=p[i];
		if (!ok[x]) continue;
		a[++nA].clear();
		do {
			a[nA].pb(x);
			ok[x]=0;
			x=p[x];
		} while (x!=p[i]);
	}
	if (!solve()) cout << "NO\n";
	else {
		cout << "YES\n";
		foreach(it, ans) cout << it->fr << " " << it->sc << endl;
	}

	return 0;
}