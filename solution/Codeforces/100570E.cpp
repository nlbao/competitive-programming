#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5 + 5;
const int MAX_F = 4*MAX_N;
const ll BASE = 1e4 + 7;


int n, nQ, pos, u, v, value;
string s;
ll p[MAX_N], h[MAX_F], g[MAX_F], ansH, ansG;


void build(int k, int l, int r) {
	if (l > r) return;
	if (l == r) {
		h[k] = g[k] = s[l-1]-'a'+1;
		return;
	}
	int mid = (l+r)>>1;
	int kl = k<<1, kr = kl|1;
	build(kl, l, mid);
	build(kr, mid+1, r);
	h[k] = h[kl] * p[r-mid] + h[kr];
	g[k] = g[kl] + p[mid-l+1] * g[kr];
}


void update(int k, int l, int r) {
	if (l > pos || r < pos) return;
	if (l == r) {
		h[k] = g[k] = value;
		return;
	}
	int mid = (l+r)>>1;
	int kl = k<<1, kr = kl|1;
	update(kl, l, mid);
	update(kr, mid+1, r);
	h[k] = h[kl] * p[r-mid] + h[kr];
	g[k] = g[kl] + p[mid-l+1] * g[kr];
}


void get(int k, int l, int r) {
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		ansH = ansH * p[r-l+1] + h[k];
		ansG = ansG + g[k] * p[l-u];
		return;
	}
	int mid = (l+r)>>1;
	int kl = k<<1, kr = kl|1;
	get(kl, l, mid);
	get(kr, mid+1, r);
}


inline bool check(int l, int r) {
	u = l, v = r;
	ansH = ansG = 0;
	get(1, 1, n);
	return ansH == ansG;
}


int main() {
#ifdef DEBUG
	freopen("100570E.in", "r", stdin);
	freopen("100570E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;

	cin >> s >> nQ;
	n = s.length();
	build(1, 1, n);

	while (nQ--) {
		int t;
		cin >> t >> pos;
		if (t == 1) {
			char c;
			cin >> c;
			value = c-'a'+1;
			update(1, 1, n);
		}
		else if (t == 2) {
			int l = 1, r = min(pos-1, n-pos), ans = 1;
			while (l <= r) {
				int mid = (l+r)>>1;
				if (check(pos-mid, pos+mid)) {
					ans = 2*mid+1;
					l = mid+1;
				}
				else r = mid-1;
			}
			cout << ans << endl;
		}
		else {
			int l = 0, r = min(pos-1, n-pos-1), ans = -1;
			while (l <= r) {
				int mid = (l+r)>>1;
				if (check(pos-mid, pos+1+mid)) {
					ans = 2*mid+2;
					l = mid+1;
				}
				else r = mid-1;
			}
			cout << ans << endl;
		}
	}

	return 0;
}