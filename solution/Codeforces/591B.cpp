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


vector<int> a[55];
string s;
int n, m, ans[55];


int main() {
#ifdef DEBUG
	freopen("591B.in", "r", stdin);
	freopen("591B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,0,33) a[i].pb(i);
	cin >> n >> m;
	cin >> s;
	while (m--) {
		char u, v;
		cin >> u >> v;
		int x=u-'a', y=v-'a';
		if (x==y) continue;
		vector<int> b=a[y];
		a[y].clear();
		foreach(it, a[x]) a[y].pb(*it);
		a[x].clear();
		foreach(it, b) a[x].pb(*it);
	}

	fori(i,0,33) foreach(it, a[i]) ans[*it]=i;

	fori(i,0,n-1) {
		int x=s[i]-'a';
		s[i]=char(ans[x]+'a');
	}
	cout << s << endl;

	return 0;
}