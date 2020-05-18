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


const int MAX_N = 2005 * 4;


int nA, nB;
char a[MAX_N], b[MAX_N];
bool f[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];


bool cal(int i, int k) {
	if (i < 0 && k < 0) return true;
	if (i < 0) return f[0][k];
	if (k < 0) return f[i][0];
	if (visited[i][k]) return f[i][k];

	bool ans = false;
	if (a[i] == b[k]) ans |= cal(i-1, k-1);
	if (!ans && a[i] == '*') ans |= cal(i-1, k) | cal(i-1, k-1);
	if (!ans && b[k] == '*') ans |= cal(i, k-1) | cal(i-1, k-1);

	visited[i][k] = true;
	return f[i][k] = ans;
}


bool solve() {
	for (int i = 0; i <= nA; ++i)
		for (int k = 0; k <= nB; ++k) {
			f[i][k] = false;
			visited[i][k] = false;
		}
	for (int i = 1; i <= nA; ++i) {
		if (a[i] != '*') break;
		f[i][0] = true;
	}
	for (int k = 1; k <= nB; ++k) {
		if (b[k] != '*') break;
		f[0][k] = true;
	}
	f[0][0] = true;
	return cal(nA, nB);
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("B-small-attempt1.in", "r", stdin);
	// freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	string s, t;
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> s >> t;
		int nS = s.size();
		int nT = t.size();
		nA = nB = 0;
		for (int i = 0; i < nS; ++i) {
			a[++nA] = s[i];
			if (s[i] == '*')
				for (int k = 0; k < 3; ++k)
					a[++nA] = '*';
		}
		for (int i = 0; i < nT; ++i) {
			b[++nB] = t[i];
			if (t[i] == '*')
				for (int k = 0; k < 3; ++k)
					b[++nB] = '*';
		}
		ll ans = solve();
		cout << "Case #" << testid << ": " << (ans ? "TRUE" : "FALSE") << endl;
	}

	return 0;
}