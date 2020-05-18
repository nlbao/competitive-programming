#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

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

////////////////////////////////////////////////////////////////////////////////////////


const int MAX_N = 2e5 + 5;
const int MAX_OK = 2e7 + 7;


int n;
ll s[MAX_N];
bool ok[MAX_OK];


ll solve_2() {
	int maxS = s[n];
	int nx = maxS + 1, ny = maxS - s[0] + 1;
	vector<ll> x(nx, 0), y(ny, 0);
	for (int i = 0; i <= n; ++i) {
		x[s[i]] = 1;
		y[maxS-s[i]] = 1;
	}
	vector<ll> t = FFT::mul(x, y);
	ll ans = 0;
	for (int i = maxS+1; i < (int)t.size(); ++i)
		if (t[i] > 0)
			++ans;
	return ans - 1;
}


ll solve_1() {
	ll ans = 0;
	filla(ok, false);
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j <= n; ++j) {
			ll x = s[j]-s[i];
			if (!ok[x]) {
				++ans;
				ok[x] = true;
			}
		}
	return ans - 1;
}


ll solve_0() {
	set<ll> q;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j <= n; ++j)
			q.insert(s[j]-s[i]);
	return q.size() - 1;
}


int main() {
#ifdef DEBUG
	freopen("FARASA.in", "r", stdin);
	freopen("FARASA.out", "w", stdout);
#endif
	n = read();
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		ll x;
		scanf("%lld", &x);
		s[i] = s[i-1] + x;
	}

	ll ans;
	if (n <= 2000) ans = solve_0();
	else if (n < 20000) ans = solve_1();
	else ans = solve_2();
	printf("%lld\n", ans);
	return 0;
}