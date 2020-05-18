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


const int MAX_N = 2002;
const ll oo = 1e18;


int n;
ll x[MAX_N], y[MAX_N], z[MAX_N], r[MAX_N];
ll top[MAX_N], dright[MAX_N], front[MAX_N];
ll bot[MAX_N], dleft[MAX_N], back[MAX_N];
int color[MAX_N];
vector<int> e[MAX_N];


inline ll calculateLength(int minX, int minY, int minZ, int maxX, int maxY, int maxZ) {
	return max(max(maxX-minX, maxY-minY), maxZ-minZ);
}


bool dfs(int u) {
	foreach(it, e[u]) {
		int v = *it;
		if (color[v] < 0) {
			color[v] = 1-color[u];
			if (!dfs(v)) return false;
		}
		else if (color[v] == color[u])
			return false;
	}
	return true;
}


bool check(ll limit) {
	for (int i = 0; i < n; ++i)
		e[i].clear();
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j) {
			bool notInSameSet = false;
			if (max(top[i], top[j]) - min(bot[i], bot[j]) > limit) notInSameSet = true;
			if (max(dright[i], dright[j]) - min(dleft[i], dleft[j]) > limit) notInSameSet = true;
			if (max(front[i], front[j]) - min(back[i], back[j]) > limit) notInSameSet = true;
			if (notInSameSet) {
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	filla(color, -1);
	for (int i = 0; i < n; ++i)
		if (color[i] < 0) {
			color[i] = 0;
			if (!dfs(i)) return false;
		}
	return true;
}


ll solve() {
	ll l = 0;
	for (int i = 0; i < n; ++i)
		l = max(l, 2*r[i]);
	ll minX, minY, minZ, maxX, maxY, maxZ;
	for (int i = 0; i < n; ++i) {
		top[i] = y[i]+r[i];
		bot[i] = y[i]-r[i];
		dright[i] = x[i]+r[i];
		dleft[i] = x[i]-r[i];
		front[i] = z[i]+r[i];
		back[i] = z[i]-r[i];
		minX = min(minX, dleft[i]);
		minY = min(minY, bot[i]);
		minZ = min(minZ, back[i]);
		maxX = max(maxX, dright[i]);
		maxY = max(maxY, top[i]);
		maxZ = max(maxZ, front[i]);
	}
	ll r = calculateLength(minX, minY, minZ, maxX, maxY, maxZ);

	ll ans = r;
	while (l <= r) {
		ll mid = (l+r)>>1;
		if (check(mid)) {
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("C.in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid=1; testid <= nTest; ++testid) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i] >> z[i] >> r[i];
		}
		ll ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}