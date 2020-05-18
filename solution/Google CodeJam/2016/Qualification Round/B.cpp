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


const int MAX_N = 10;
const int MAX_F = 1<<MAX_N;
const int oo = 1e9;

int n, f[MAX_F];
string s;
queue<int> q;


inline void setBit(int &x, int i, int val) {
	if (val == 0) x &= ~(1<<i);
	else x |= 1<<i;
}


int flip(int x, int pos) {
	for (int i = 0; i <= pos; ++i)
		x ^= 1<<i;
	for (int i=0, j=pos; i<j; ++i, --j) {
		int ti = (x>>i)&1;
		setBit(x, i, (x>>j)&1);
		setBit(x, j, ti);
	}
	return x;
}


int main() {
#ifdef DEBUG
	freopen("B.in", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);


	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cout << "Case #" << testid << ": ";
		cin >> s;
		n = s.size();
		int m = 1<<n;
		for (int i = 0; i < m; ++i)
			f[i] = oo;

		int start = 0, finish = m-1;
		for (int i = 0; i < n; ++i)
			if (s[i] == '+')
				start |= 1<<i;
		f[start] = 0;

		while (!q.empty()) q.pop();
		q.push(start);
		while (!q.empty()) {
			int mask = q.front();
			q.pop();
			if (mask == finish) break;
			int tmp = f[mask] + 1;
			for (int i = 0; i < n; ++i) {
				int y = flip(mask, i);
				if (tmp < f[y]) {
					f[y] = tmp;
					q.push(y);
					// cout << mask << " --> " << y << " : " << f[y] << " by flip at " << i << endl;
				}
			}
		}

		cout << f[finish] << endl;
	}

	return 0;
}