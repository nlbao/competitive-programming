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


int colors[MAX_N], needs[MAX_N], cnt[MAX_N];
int nOK, n, m;


void update(int c, int val) {
	// int pre = cnt[c];
	// cnt[c] += val;
	// if (cnt[c] == needs[c] && pre != needs[c])
	// 	nOK += 1;
	// else if (cnt[c] != needs[c] && pre == needs[c])
	// 	nOK -= 1;
	cnt[c] += val;
	nOK = 0;
	for (int i = 1; i <= m; ++i)
		if (cnt[i] == needs[i])
			++nOK;
}


int main() {
#ifdef DEBUG
	freopen("958F1.in", "r", stdin);
	freopen("958F1.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> colors[i];
	int sNeed = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> needs[i];
		sNeed += needs[i];
	}
	if (sNeed > n) {
		cout << "NO";
		return 0;
	}

	bool found = false;
	nOK = 0;
	filla(cnt, 0);
	for (int i = 0; i < sNeed-1; ++i)
		update(colors[i], 1);
	for (int i = sNeed-1, k = 0; i < n; ++i, ++k) {
		update(colors[i], 1);
		if (nOK == m) {
			found = true;
			break;
		}
		// cout << "---" << endl;
		// for (int j = 1; j <= m; ++j)
		// 	cout << cnt[j] << " ";
		// cout << endl;
		// cout << "---" << endl;
		// cout << i << " " << nOK << endl;
		update(colors[k], -1);
	}
	if (found) cout << "YES";
	else cout << "NO";

	return 0;
}