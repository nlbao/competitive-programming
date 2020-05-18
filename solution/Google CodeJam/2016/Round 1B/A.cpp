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


const string STR_NUM[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const char CHAR[10] = {'Z','W','U','X','G','F','V','O','T','N'};
const char VAL[10] = {0, 2, 4, 6, 8, 5, 7, 1, 3, 9};


int c[10], ans[10];


int num(char x) {
	for (int i = 0; i < 10; ++i)
		if (CHAR[i] == x)
			return i;
	return -1;
}


void remove(int pos, int cnt) {
	if (cnt < 1) return;
	int val = VAL[pos];
	ans[val] += cnt;
	string s = STR_NUM[val];
	for (int i = 0; i < (int)s.size(); ++i) {
		int x = num(s[i]);
		if (x >= 0) c[x] -= cnt;
	}
}



int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	// freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	string s;
	for (int tid = 1; tid <= nTest; ++tid) {
		cin >> s;
		int n = s.size();
		filla(c, 0);
		for (int i = 0; i < n; ++i) {
			int x = num(s[i]);
			if (x >= 0) ++c[x];
		}

		filla(ans, 0);
		for (int i = 0; i < 10; ++i) {
			while (c[i] > 0) remove(i, 1);
		}

		// for (int i = 0; i < 10; ++i) {
		// 	if (c[i] != 0) {
		// 		cout << "!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		// 		cout << i << " " << c[i] << endl;
		// 	}
		// }

		cout << "Case #" << tid << ": ";
		for (int i = 0; i < 10; ++i)
			for (int k = 0; k < ans[i]; ++k)
				cout << i;
		cout << endl;
	}

	return 0;
}