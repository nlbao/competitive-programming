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


const int MAX_N = 1e5+55;


int n, m;
int p[MAX_N], a[MAX_N], id[MAX_N];
vector<int> e[MAX_N];
multiset<int> heap;


int getRoot(int u) {
	return p[u]==u ? u : p[u]=getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("RDRUG.in", "r", stdin);
	freopen("RDRUG.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n >> m;
		fori(i,1,n) {
			p[i]=i;
			e[i].clear();
		}
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			x=getRoot(x), y=getRoot(y);
			if (x!=y) p[x]=y;
		}
		fori(i,1,n) cin >> a[i];

		int nC=0;
		fori(i,1,n) if (getRoot(i)==i) id[i]=++nC;
		int s = 2*(nC-1);
		ll ans=0;
		if (s==0) {
			cout << ans << endl;
			continue;
		}

		heap.clear();
		fori(i,1,n) e[id[getRoot(i)]].pb(a[i]);
		fori(i,1,nC) {
			int p=0, len=sz(e[i]);
			sort(e[i].begin(), e[i].end());
			if (p<len) {
				ans += e[i][p++];
				--s;
			}
			while (p<len) heap.insert(e[i][p++]);
		}

		while (s>0 && !heap.empty()) {
			ans += *heap.begin();
			heap.erase(heap.begin());
			--s;
		}

		if (s>0) ans=-1;
		cout << ans << endl;
	}

	return 0;
}