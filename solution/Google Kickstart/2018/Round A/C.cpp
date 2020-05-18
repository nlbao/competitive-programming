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


const int MAX_N_DICT = 1001;
const int MAX_N = 1001;
const int MAX_CH = 30;
const ll BASE = 10007;


int nDict, N;
ll pBase[MAX_CH], f[MAX_N];
set<char> len1Strs;
set<ll> hashASets[MAX_CH][MAX_CH];
string a;
vector<string> words;


int getChCode(char x) {
	return int(x) - int('a');
}


ll getCharHash(char x) {
	return pBase[getChCode(x)];
}


ll getHash(const string &s, int l, int r) {
	ll ans = 0;
	for (int i = l; i <= r; ++i)
		ans += getCharHash(s[i]);
	return ans;
}


void processA() {
	len1Strs.clear();
	for (int i = 0; i < MAX_CH; ++i)
		for (int k = 0; k < MAX_CH; ++k)
			hashASets[i][k].clear();
	f[0] = getCharHash(a[0]);
	for (int i = 0; i < N; ++i) {
		len1Strs.insert(a[i]);
		if (i == 0) continue;
		f[i] = f[i-1] + getCharHash(a[i]);
		int y = getChCode(a[i]);
		for (int k = 0; k < i; ++k) {
			int x = getChCode(a[k]);
			hashASets[x][y].insert(f[i-1] - f[k]);
		}
	}
}


bool isHashInA(ll h, int ch1, int ch2) {
	set<ll> &hashSet = hashASets[ch1][ch2];
	return hashSet.find(h) != hashSet.end();
}


int solve() {
	int ans = 0;
	for (int i = 0; i < nDict; ++i) {
		string s = words[i];
		int len = s.length();
		if (len == 1)
			ans += int(len1Strs.find(s[0]) != len1Strs.end());
		else {
			ll h = getHash(s, 1, len-2);
			ans += int(isHashInA(h, getChCode(s[0]), getChCode(s[len-1])));
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("C.in", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	pBase[0] = 1;
	for (int i = 1; i < MAX_CH; ++i)
		pBase[i] = pBase[i-1] * BASE;

	int nTest = read();
	string s;
	for (int testid = 1; testid <= nTest; ++testid) {
		nDict = read();
		words.clear();
		for (int i = 0; i < nDict; ++i) {
			cin >> s;
			words.push_back(s);
		}
		a = "";
		for (int i = 0; i < 2; ++i) {
			cin >> s;
			a.push_back(s[0]);
		}
		ll A, B, C, D;
		cin >> N >> A >> B >> C >> D;
		f[0] = int(a[0]);
		f[1] = int(a[1]);
		for (int i = 2; i < N; ++i) {
			f[i] = (A*f[i-1] + B*f[i-2] + C) % D;
			char ch = char(97 + (f[i] % 26));
			a.push_back(ch);
		}

		// // DEBUG
		// a = "cdaghiklmacbdeff";
		// N = a.length();
		// cout << a << endl; // DEBUG
		// ///////////

		processA();
		int ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}