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


const int MAX_N = 2e4+14;


int n;
int a[MAX_N], q[MAX_N];
bool ok[MAX_N];
vector<pii> e[MAX_N];


int solve(int s) {
	int ans=s, l=1, r=0;
	fori(i,1,n) ok[i]=1;
	q[++r]=s;
	ok[s]=0;
	while (l<=r) {
		int maxVal=-1, m=0;
		while (l<=r) {
			int u=q[l++];
			foreach(it, e[u]) {
				int v=it->sc, val=it->fr;
				if (!ok[v]) continue;
				ok[v]=0;
				if (val==maxVal) a[++m]=v;
				else if (val>maxVal) {
					maxVal=val;
					a[m=1]=v;
				}
			}
		}
		l=1, r=0;
		if (m>0) ans=-1;
		fori(i,1,m) {
			ans=max(ans, a[i]);
			q[++r]=a[i];
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("little-alexeys-tree.in", "r", stdin);
	freopen("little-alexeys-tree.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n-1) {
		int x, y;
		char ch;
		cin >> x >> y >> ch;
		e[x].pb(mp(ch-'a', y));
		e[y].pb(mp(ch-'a', x));
	}

	fori(i,1,n) cout << solve(i) << " ";

	return 0;
}