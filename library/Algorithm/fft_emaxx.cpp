#include <complex>
typedef complex<double> base;

const double PI = acos(-1.0);

void fft(vector<base> &a, bool invert) {
	int n = (int)a.size();
	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			base w(1);
			for (int j = 0; j < len/2; ++j) {
				base u = a[i+j], v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}

	if (invert)
		for (int i = 0; i < n; ++i)
			a[i] /= n;
}

void multiply(const vector<ll> &a, const vector<ll> &b, vector<ll> &res) {
	vector<base> fa(a.begin(), a.end());
	vector<base> fb(b.begin(), b.end());
	int n = 1, limit = max(a.size(), b.size());
	while (n < limit) n <<= 1;
	n <<= 1;
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	res.resize(n);
	for (int i = 0; i < n; ++i)
		res[i] = ll(fa[i].real() + 0.5);
}