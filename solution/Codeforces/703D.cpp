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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e6+6;


int n, nP, newID, startPos, blockSize;
ll a[MAX_N], f[MAX_N], fp[MAX_N], ans[MAX_N];
int blockID[MAX_N], p[MAX_N];
pair<pii, int> q[MAX_N];


inline ll getXor(int l, int r) {
	return f[r] ^ f[l-1];
}


void init() {
	nP = 0;
	while (startPos <= n && blockID[startPos] <= newID)
		++startPos;
	if (startPos > n) return;
	set<int> q;
	for (int i = startPos; i <= n; ++i) {
		if (q.find(a[i]) != q.end()) continue;
		q.insert(a[i]);
		p[++nP] = i;
	}
	fp[0] = 0;
	for (int i = 1; i <= nP; ++i)
		fp[i] = fp[i-1] ^ a[p[i]];
}


ll solve_small(int l, int r) {
	ll ans = 0;
	map<int, int> q;
	for (int i = l; i <= r; ++i)
		q[a[i]]++;
	foreach(it, q)
		if (!((it->sc)&1))
			ans ^= it->fr;
	return ans;
}


ll find(int maxPos) {
	ll ans = 0;
	int l = 1, r = nP;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (p[mid] <= maxPos) {
			ans = fp[mid];
			l = mid+1;
		}
		else r = mid-1;
	}
	ans ^= getXor(startPos, maxPos);
	return ans;
}


ll solve_big(int l, int r) {
	cout << "!!!" << endl;
	ll ans = 0;
	map<int, int> q;
	for (int i = l; blockID[i] == blockID[l]; ++i) {
		q[a[i]]++;
		cout << i << endl;
	}
	foreach(it, q)
		if (!((it->sc)&1))
			ans ^= it->fr;
	cout << ans << endl;
	return ans ^ find(r);
}


int main() {
#ifdef DEBUG
	freopen("703D.in", "r", stdin);
	freopen("703D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	a[0] = f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = f[i-1] ^ a[i];
	}

	// blocks
	blockSize = min(int(sqrt(n)+1), n);
	for (int i = 1, c = 0; i <= n; i += blockSize, ++c) {
		for (int k = 0; k < blockSize; ++k)
			blockID[i+k] = c;
	}

	// queries
	int m = read();
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		q[i] = mp(mp(x, y), i);
	}
	sort(q, q+m);

	newID = -1, startPos = 1;
	for (int i = 0; i < m; ++i) {
		ll res = 0;
		int l = q[i].fr.fr, r = q[i].fr.sc;
		if (blockID[l] > newID) {
			newID = blockID[l];
			init();
		}
		if (blockID[l] == blockID[r]) res = solve_small(l, r);
		else res = solve_big(l, r);
		ans[q[i].sc] = res;
	}

	for (int i = 0; i < m; ++i)
		cout << ans[i] << endl;

	return 0;
}