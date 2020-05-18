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