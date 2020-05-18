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


ll ansX, ansY, ansD;
string vals[1111];


string toScore(ll x, int len) {
	string t = to_string(x);
	while ((int)t.size() < len) t = "0" + t;
	return t;
}


bool isMatch(const string &s, ll x) {
	string t = vals[x];
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] != '?' && s[i] != t[i])
			return 0;
	return 1;
}


inline void updateAns(ll x, ll y) {
	ll d = abs(x-y);
	if (d > ansD) return;
	if (d == ansD) {
		if (x > ansX) return;
		if (x == ansX && y > ansY) return;
	}
	ansX = x;	ansY = y;
	ansD = d;
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	string a, b;
	for (int tid = 1; tid <= nTest; ++tid) {
		cin >> a >> b;
		ansX = 1e18, ansY = -1e18, ansD = 1e18;
		int len = a.size();
		int limit = pow(10, len);

		for (int i = 0; i < limit; ++i)
			vals[i] = toScore(i, len);

		for (int x = 0; x < limit; ++x)
			for (int y = 0; y < limit; ++y)
				if (isMatch(a, x) && isMatch(b, y)) {
					updateAns(x, y);
				}
		cout << "Case #" << tid << ": " << toScore(ansX, len) << " " << toScore(ansY, len) << endl;
	}

	return 0;
}