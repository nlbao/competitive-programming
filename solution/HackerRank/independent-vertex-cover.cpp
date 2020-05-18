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


const int MAX_N = 2e5+55;
const ll MOD = 1e9+7;


int n;
int a[MAX_N], p[MAX_N];


int getRoot(int u) {
	return p[u]==u ? u : p[u]=getRoot(p[u]);
}


inline void unionRoot(int u, int v) {
	u=getRoot(u), v=getRoot(v);
	if (a[u]>a[v]) p[v]=u;
	else p[u]=v;
}


struct cmp {
	bool operator() (const int &u, int const &v) {
		if (a[u]!=a[v]) return a[u]<a[v];
		return 0;
	}
};

typedef set<int, cmp> Heap;
Heap qList, downList;


ll solve() {
	fori(i,1,n) {
		bool down=0;
		int tmp=a[i];
		Heap::iterator it=downList.lower_bound(i);
		if (it!=downList.end()) return 0;
		while (1) {
			it = qList.lower_bound(i);
			if (it==qList.end()) break;
			down=1;
			unionRoot(i, *it);
			a[i] = a[getRoot(i)]+1;
		}
		a[i]=tmp;
		if (down) downList.insert(i);
		qList.insert(i);
	}

	ll ans=1;
	fori(i,1,n) if (getRoot(i)==i) ans = (ans * 2LL) % MOD;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("independent-vertex-cover.in", "r", stdin);
	freopen("independent-vertex-cover.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		cin >> a[i];
		p[i]=i;
	}
	cout << solve() << endl;

	return 0;
}