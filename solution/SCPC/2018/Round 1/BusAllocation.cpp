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


const int MAX_N = 2e5+55;


int N, K;
int a[MAX_N], q[MAX_N];


bool check(int nQ) {
	// cout << nQ << endl;
	for (int i = 0; i < nQ; ++i)
		q[i] = -1;
	int pos = 0;
	for (int i = 0; i < N; ++i) {
		if (pos >= nQ) pos = 0;
		// cout << "	" << pos << " " << a[i] << endl;
		if (q[pos] == -1) q[pos] = a[i];
		else {
			if (a[i]-q[pos] <= K)
				return false;
			q[pos] = a[i];
		}
		++pos;
	}
	return true;
}


int solve() {
	sort(a, a+N);
	int ans = N, l = 1, r = N;
	while (l <= r) {
		int mid = (l+r)>>1;
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
	freopen("BusAllocation.in", "r", stdin);
	freopen("BusAllocation.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int i = 1; i <= nTest; ++i) {
		cin >> N >> K;
		for (int i = 0; i < N; ++i)
			cin >> a[i];
		int ans = solve();
		cout << "Case #" << i << endl << ans << endl;
	}

	return 0;
}