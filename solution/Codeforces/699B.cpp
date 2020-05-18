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


const int MAX_N = 1111;


int n, m, ansx, ansy;
string s[MAX_N];
int row[MAX_N], col[MAX_N];


bool solve() {
	filla(row, 0);
	filla(col, 0);
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j) {
			if (s[i][j]=='.') continue;
			++sum;
			++row[i];	++col[j];
		}
	}
	ansx=ansy=0;
	if (sum < 1) return 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int t = row[i] + col[j];
			if (s[i][j] == '*') --t;
			if (t == sum) {
				ansx = i, ansy = j;
				return 1;
			}
		}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("699B.in", "r", stdin);
	freopen("699B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	if (solve()) {
		cout << "YES\n";
		cout << ansx+1 << " " << ansy+1;
	}
	else cout << "NO\n";

	return 0;
}