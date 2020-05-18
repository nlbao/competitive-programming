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


const int MAX_N = 1111 * 11;


int n;
map<string, int> varName;
string s;
vector<int> e[MAX_N];
int d[MAX_N], state[MAX_N];
bool hasAssignment[MAX_N];


int getID(const string &s) {
	if (varName.find(s) == varName.end())
		varName[s] = ++n;
	return varName[s];
}


vector<string> split(const string &s, const string &delims) {
	vector<string> ans;
	int n = s.size(), m = delims.size();
	string t = "";
	for (int i = 0; i < n; ++i) {
		bool ok = 1;
		for (int k = 0; k < m; ++k)
			if (s[i] == delims[k]) {
				ok = 0;
				break;
			}
		if (ok) t.push_back(s[i]);
		else {
			if (t != "") ans.push_back(t);
			t = "";
		}
	}
	if (t != "") ans.push_back(t);
	return ans;
}


void extract() {
	vector<string> a = split(s, "=(),");
	int v = getID(a[0]);
	for (int i = 2; i < (int)a.size(); ++i) {
		int u = getID(a[i]);
		e[u].push_back(v);
		++d[v];
	}
	hasAssignment[v] = 1;
}


bool dfs(int u) {
	if (state[u] == 2) return 1;
	if (state[u] == 1) return 0;
	state[u] = 1;
	foreach(it, e[u]) {
		if (!dfs(*it)) return 0;
	}
	state[u] = 2;
	return 1;
}


string solve() {
	filla(state, 0);
	for (int i = 1; i <= n; ++i) {
		if (!hasAssignment[i]) return "BAD";
		if (d[i] == 0)
			if (!dfs(i))
				return "BAD";
	}
	for (int i = 1; i <= n; ++i)
		if (state[i] == 0) return "BAD";
	return "GOOD";
}


int main() {
#ifdef DEBUG
	// freopen("C.in", "r", stdin);
	// freopen("C-small-practice.in", "r", stdin);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		int nLine = read();
		varName.clear();
		filla(d, 0);
		filla(hasAssignment, 0);
		for (int i = 0; i < MAX_N; ++i)
			e[i].clear();
		n = 0;
		for (int l = 0; l < nLine; ++l) {
			cin >> s;
			extract();
		}
		cout << "Case #" << testid << ": " << solve() << endl;
	}

	return 0;
}