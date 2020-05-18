#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


namespace FFT {
typedef vector<ll> vi;

struct base {
	typedef double T;
	T re, im;
	base() : re(0), im(0) {}
	base(T re) : re(re), im(0) {}
	base(T re, T im) : re(re), im(im) {}
	base operator + (const base& o) const { return base(re + o.re, im + o.im); }
	base operator - (const base& o) const { return base(re - o.re, im - o.im); }
	base operator * (const base& o) const { return base(re * o.re - im * o.im, re * o.im + im * o.re); }
	base operator * (ld k) const { return base(re * k, im * k) ;}
	base conj() const { return base(re, -im); }
};

const int N = 21;
const int MAXN = (1<<N);
base w[MAXN];
base f1[MAXN];
int rev[MAXN];

void build_rev(int k) {
	static int rk = -1;
	if (k == rk) return;
	rk = k;
	for (int i = 1; i <= (1<<k); ++i) {
		int j = rev[i-1], t = k-1;
		while (t >= 0 && ((j>>t)&1)) j ^= 1<<t, --t;
		if (t >= 0) j ^= 1<<t, --t;
		rev[i] = j;
	}
}

void fft(base *a, int k) {
	build_rev(k);
	int n = 1 << k;
	for (int i = 0; i < n; ++i)
		if (rev[i] > i) swap(a[i], a[rev[i]]);
	for (int t = 2, tt = 1; t <= n; t += t, tt += tt) {
		if (w[tt].re == 0 && w[tt].im == 0) {
			ld angle = M_PI / tt;
			base ww(cosl(angle), sinl(angle));
			if (tt > 1)
				for (int j = 0; j < tt; ++j) {
					if (j&1) w[tt + j] = w[(tt+j)/2] * ww;
					else w[tt + j] = w[(tt+j)/2];
				}
			else w[tt] = base(1, 0);
		}
		for (int i = 0; i < n; i += t)
			for (int j = 0; j < tt; ++j) {
				base v = a[i + j], u = a[i + j + tt] * w[tt + j];
				a[i + j] = v + u;
				a[i + j + tt] = v - u;
			}
	}
}

vi mul(const vi& a, const vi& b) {
	int k = 1, na = a.size(), nb = b.size();
	while((1<<k) < na + nb) ++k;
	int n = (1<<k);
	for (int i = 0; i < n; ++i) f1[i] = base(0, 0);
	for (int i = 0; i < na; ++i) f1[i] = f1[i] + base(a[i], 0);
	for (int i = 0; i < nb; ++i) f1[i] = f1[i] + base(0, b[i]);
	fft(f1, k);
	for (int i = 0; i < 1 + n/2; ++i) {
		base p = f1[i] + f1[(n-i)%n].conj();
		base t = f1[(n-i)%n] - f1[i].conj();
		base q(t.im, t.re);
		f1[i] = (p * q) * 0.25;
		if(i > 0) f1[(n - i)] = f1[i].conj();
	}
	for (int i = 0; i < n; ++i) f1[i] = f1[i].conj();
	fft(f1, k);
	vi r(na + nb);
	for (int i = 0; i < (int)r.size(); ++i)
		r[i] = ll(f1[i].re / n + 0.5);
	return r;
}
}


const int MAX_N = 8088;
const int MAX_A = 66;


int n;
ll module;
ll a[MAX_N], b[MAX_N], ans[MAX_N];
ll fl[MAX_N][MAX_A], fr[MAX_N][MAX_A];


inline void add(ll &a, ll b) {
	a += b;
	if (a > b)
		a %= module;
}


void solve(int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (a[l] == 0) add(ans[1], 1);
		if (b[l] == 0) add(ans[1], 1);
		return;
	}
	int mid = (l+r)>>1;
	solve(l, mid);
	solve(mid+1, r);

	for (int x = 0; x < MAX_A; ++x)
		fl[mid][x] = fr[mid+1][x] = 0;
	add(fl[mid][a[mid]], 1);
	add(fl[mid][b[mid]], 1);
	for (int i = mid-1; i >= l; --i) {
		for (int x = 0; x < MAX_A; ++x) fl[i][x] = 0;
		for (int x = 0; x < MAX_A; ++x) {
			add(fl[i][a[i]^x], fl[i+1][x]);
			add(fl[i][b[i]^x], fl[i+1][x]);
		}
	}
	add(fr[mid+1][a[mid+1]], 1);
	add(fr[mid+1][b[mid+1]], 1);
	for (int i = mid+2; i <= r; ++i) {
		for (int x = 0; x < MAX_A; ++x) fr[i][x] = 0;
		for (int x = 0; x < MAX_A; ++x) {
			add(fr[i][a[i]^x], fr[i-1][x]);
			add(fr[i][b[i]^x], fr[i-1][x]);
		}
	}

	for (int x = 0; x < MAX_A; ++x) {
		vector<ll> pl(mid-l+2, 0);
		vector<ll> pr(r-mid+1, 0);
		for (int i = l; i <= mid; ++i)
			add(pl[mid-i+1], fl[i][x]);
		for (int i = mid+1; i <= r; ++i)
			add(pr[i-mid], fr[i][x]);
		vector<ll> t = FFT::mul(pl, pr);
		int m = min(r-l+1, (int)t.size()-1);
		for (int i = 1; i <= m; ++i)
			add(ans[i], t[i]);
	}
}


int main() {
#ifdef DEBUG
	freopen("white-falcon-and-xor.in", "r", stdin);
	freopen("white-falcon-and-xor.out", "w", stdout);
#endif
	n = read(), module = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	for (int i = 1; i <= n; ++i)
		b[i] = read();
	filla(ans, 0);
	solve(1, n);
	for (int i = 1; i <= n; ++i)
		printf("%d\n", (int)ans[i]);
	return 0;
}