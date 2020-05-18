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


const int MAX_N = 111;
const int MAX_K = 111;
const ll oo = 1e18+10;


int N, K;
ll P, f[MAX_N];
bool isFixed[MAX_N];
int val[MAX_N];


string solve() {
	string ans = "";
	for (int i = 0; i < N; ++i)
		if (isFixed[i]) ans.push_back(char(val[i]+int('0')));
		else ans.push_back('0');
	f[N] = 1;
	for (int i = N-1; i >= 0; --i) {
		f[i] = f[i+1];
		if (!isFixed[i]) {
			f[i] <<= 1;
			f[i] = min(oo, f[i]);
		}
		assert(f[i] >= 0);
	}
	ll remain = P;
	for (int i = 0; i < N; ++i) {
		if (isFixed[i]) continue;
		if (f[i+1] < remain) {
			ans[i] = '1';
			remain -= f[i+1];
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> N >> K >> P;
		filla(isFixed, false);
		for (int i = 0; i < K; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			assert(0 <= a && a < N);
			assert(a == b);
			assert(0 <= c && c <= 1);
			isFixed[a] = true;
			val[a] = c;
		}
		string ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;
		// test
		assert(int(ans.length()) == N);
		for (int i = 0; i < N; ++i)
			if (isFixed[i])
				assert(int(ans[i])-int('0') == val[i]);
	}

	return 0;
}