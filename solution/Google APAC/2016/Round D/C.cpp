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


const int MAX_N = 4001;
const ll MODULE = 1e9+7;


ll f[MAX_N];
set<string> seen;
map<string, int> nWords;

// ll p[MAX_LEN], cnt[MAX_CHAR];


// ll getHash() {
// 	ll ans = 0;
// 	for (int i = 0; i < MAX_CHAR; ++i) if (cnt[i])
// 		ans += 1LL * (i+1) * p[cnt[i]];
// 	return ans;
// }


// inline void add(char x) {
// 	++cnt[int(x) - int('a')];
// }


string getSorted(const string &s) {
	string ans = s;
	sort(ans.begin(), ans.end());
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
	for (int testid = 1; testid <= nTest; ++testid) {
		int nV, nS;
		string s, tmp;
		cin >> nV >> nS;
		seen.clear();
		nWords.clear();
		for (int i = 0; i < nV; ++i) {
			cin >> s;
			if (seen.find(s) != seen.end()) continue;
			seen.insert(s);
			// for (int k = 0; k < s.length(); ++k)
			// 	add(s[k]);
			++nWords[getSorted(s)];
		}

		cout << "Case #" << testid << ":";
		for (int qid = 0; qid < nS; ++qid) {
			cin >> s;
			int n = s.size();
			f[0] = 1;
			for (int i = 0; i < n; ++i) {
				f[i+1] = 0;
				for (int len = 1; len <= min(i+1, 20); ++len) {
					int k = i-len+1;
					tmp = getSorted(s.substr(k, len));
					if (nWords.find(tmp) == nWords.end()) continue;
					f[i+1] += (f[k] * nWords[tmp]) % MODULE;
					f[i+1] %= MODULE;
				}
			}
			cout << " " << f[n];
		}
		cout << endl;
	}

	return 0;
}